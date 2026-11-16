#include <iostream>

#include "D:/Projets/Rihen/Nkentseu/Applications/NkRef/src/NkRef/NkRefView.h"
#include "D:/Projets/Rihen/Nkentseu/Applications/NkRef/src/NkRef/NkRefBoard.h"
#include "D:/Projets/Rihen/Nkentseu/Applications/NkRef/src/NkRef/NkRefFile.h"

using namespace nkref;
using namespace nkentseu;

int main()
{
    NkRefBoard board;

    NkString source1;
    NkString source2;

    board.AddItem({12.5f, -7.25f}, 640, 480, source1);
    board.AddItem({-35.0f, 18.5f}, 320, 240, source2);

    board.items[0].scale = 1.25f;
    board.items[0].rotationDeg = 15.0f;
    board.items[0].opacity = 0.8f;

    board.items[1].scale = 0.75f;
    board.items[1].rotationDeg = -30.0f;
    board.items[1].mirrorX = true;

    NkRefStroke stroke;
    stroke.r = 255;
    stroke.g = 80;
    stroke.b = 40;
    stroke.a = 255;
    stroke.widthWorld = 4.5f;
    stroke.points.PushBack({10.0f, 20.0f});
    stroke.points.PushBack({30.0f, 45.0f});

    board.strokes.PushBack(stroke);

    const uint8 sourceData1[] = {10, 20, 30, 40, 50};
    const uint8 sourceData2[] = {60, 70, 80, 90, 100, 110, 120};

    NkRefFileImage images[2] = {
        {sourceData1, sizeof(sourceData1)},
        {sourceData2, sizeof(sourceData2)}
    };

    NkRefView view;
    view.center.x = 125.5f;
    view.center.y = -80.25f;
    view.zoom = 1.5f;

    NkVector<uint8> original;

    NkRefSerialize(original, board, images, view, true, true);

    NkVector<NkRefLoadedItem> loadedItems;
    NkVector<NkRefStroke> loadedStrokes;
    NkRefView loadedView;
    bool loadedDark = false;
    bool loadedGrid = false;

    bool readBack = NkRefDeserialize(
        original.Data(),
        original.Size(),
        loadedItems,
        loadedStrokes,
        loadedView,
        loadedDark,
        loadedGrid
    );

    NkRefBoard reconstructed;
    NkRefFileImage loadedImages[2];

    if (readBack)
    {
        for (usize i = 0; i < loadedItems.Size(); ++i)
        {
            reconstructed.items.PushBack(loadedItems[i].item);

            loadedImages[i].data = loadedItems[i].src.Data();
            loadedImages[i].size = loadedItems[i].src.Size();
        }

        for (usize i = 0; i < loadedStrokes.Size(); ++i)
            reconstructed.strokes.PushBack(loadedStrokes[i]);
    }

    NkVector<uint8> rewritten;

    if (readBack)
    {
        NkRefSerialize(
            rewritten,
            reconstructed,
            loadedImages,
            loadedView,
            loadedDark,
            loadedGrid
        );
    }

    bool identical = readBack &&
                     original.Size() == rewritten.Size();

    if (identical)
    {
        for (usize i = 0; i < original.Size(); ++i)
        {
            if (original[i] != rewritten[i])
            {
                identical = false;
                break;
            }
        }
    }

    std::cout << "bytes : " << original.Size()
              << ", read back : " << (readBack ? "YES" : "NO")
              << ", identical : " << (identical ? "YES" : "NO")
              << '\n';

    return 0;
}