#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

struct Image
{
    string nom;
    bool selectionnee = false;
};

struct Conception
{
    vector<string> planche;
    set<int> selectionIndices;
    set<string> selectionIds;
};

void retirerIndices(vector<string>& planche, const set<int>& indices)
{
    for (int i = static_cast<int>(planche.size()) - 1; i >= 0; --i)
    {
        if (indices.count(i))
            planche.erase(planche.begin() + i);
    }
}

void afficherListe(const vector<string>& noms)
{
    if (noms.empty())
    {
        cout << "AUCUN";
        return;
    }

    for (const string& nom : noms)
        cout << " " << nom;
}

vector<string> selectionDansItem(const vector<Image>& planche)
{
    vector<string> resultat;

    for (const Image& image : planche)
    {
        if (image.selectionnee)
            resultat.push_back(image.nom);
    }

    return resultat;
}

vector<string> selectionParIndex(const Conception& conception)
{
    vector<string> resultat;

    for (int i = 0; i < static_cast<int>(conception.planche.size()); ++i)
    {
        if (conception.selectionIndices.count(i))
            resultat.push_back(conception.planche[i]);
    }

    return resultat;
}

vector<string> selectionParId(const Conception& conception)
{
    vector<string> resultat;

    for (const string& nom : conception.planche)
    {
        if (conception.selectionIds.count(nom))
            resultat.push_back(nom);
    }

    return resultat;
}

int main()
{
    vector<Image> dansItem;
    Conception parIndex;
    Conception parId;

    string ligne;

    while (getline(cin, ligne))
    {
        istringstream flux(ligne);
        string commande;

        if (!(flux >> commande))
            continue;

        if (commande == "AJOUTE")
        {
            string nom;
            flux >> nom;

            dansItem.push_back({nom, false});
            parIndex.planche.push_back(nom);
            parId.planche.push_back(nom);
        }
        else if (commande == "CLIC")
        {
            int i;
            flux >> i;

            for (Image& image : dansItem)
                image.selectionnee = false;

            parIndex.selectionIndices.clear();
            parId.selectionIds.clear();

            if (i >= 0 && i < static_cast<int>(dansItem.size()))
                dansItem[i].selectionnee = true;

            if (i >= 0 && i < static_cast<int>(parIndex.planche.size()))
                parIndex.selectionIndices.insert(i);

            if (i >= 0 && i < static_cast<int>(parId.planche.size()))
                parId.selectionIds.insert(parId.planche[i]);
        }
        else if (commande == "AJOUTE_SEL")
        {
            int i;
            flux >> i;

            if (i >= 0 && i < static_cast<int>(dansItem.size()))
                dansItem[i].selectionnee = true;

            if (i >= 0 && i < static_cast<int>(parIndex.planche.size()))
                parIndex.selectionIndices.insert(i);

            if (i >= 0 && i < static_cast<int>(parId.planche.size()))
                parId.selectionIds.insert(parId.planche[i]);
        }
        else if (commande == "ECHANGE")
        {
            int i, j;
            flux >> i >> j;

            if (i >= 0 && j >= 0 &&
                i < static_cast<int>(dansItem.size()) &&
                j < static_cast<int>(dansItem.size()))
            {
                swap(dansItem[i], dansItem[j]);
            }

            if (i >= 0 && j >= 0 &&
                i < static_cast<int>(parIndex.planche.size()) &&
                j < static_cast<int>(parIndex.planche.size()))
            {
                swap(parIndex.planche[i], parIndex.planche[j]);
            }

            if (i >= 0 && j >= 0 &&
                i < static_cast<int>(parId.planche.size()) &&
                j < static_cast<int>(parId.planche.size()))
            {
                swap(parId.planche[i], parId.planche[j]);
            }
        }
        else if (commande == "RETIRE")
        {
            int i;
            flux >> i;

            if (i >= 0 && i < static_cast<int>(dansItem.size()))
                dansItem.erase(dansItem.begin() + i);

            if (i >= 0 && i < static_cast<int>(parIndex.planche.size()))
                parIndex.planche.erase(parIndex.planche.begin() + i);

            if (i >= 0 && i < static_cast<int>(parId.planche.size()))
                parId.planche.erase(parId.planche.begin() + i);
        }
        else if (commande == "SUPPRIME")
        {
            dansItem.erase(
                remove_if(
                    dansItem.begin(),
                    dansItem.end(),
                    [](const Image& image)
                    {
                        return image.selectionnee;
                    }
                ),
                dansItem.end()
            );

            retirerIndices(parIndex.planche, parIndex.selectionIndices);
            parIndex.selectionIndices.clear();

            parId.planche.erase(
                remove_if(
                    parId.planche.begin(),
                    parId.planche.end(),
                    [&parId](const string& nom)
                    {
                        return parId.selectionIds.count(nom) > 0;
                    }
                ),
                parId.planche.end()
            );

            parId.selectionIds.clear();
        }
    }

    vector<string> plancheDansItem;
    for (const Image& image : dansItem)
        plancheDansItem.push_back(image.nom);

    vector<string> selectionItem = selectionDansItem(dansItem);
    vector<string> selectionIndex = selectionParIndex(parIndex);
    vector<string> selectionId = selectionParId(parId);

    cout << "DANS_ITEM PLANCHE";
    afficherListe(plancheDansItem);
    cout << '\n';

    cout << "DANS_ITEM SELECTION";
    afficherListe(selectionItem);
    cout << '\n';

    cout << "PAR_INDEX PLANCHE";
    afficherListe(parIndex.planche);
    cout << '\n';

    cout << "PAR_INDEX SELECTION";
    afficherListe(selectionIndex);
    cout << '\n';

    cout << "PAR_ID PLANCHE";
    afficherListe(parId.planche);
    cout << '\n';

    cout << "PAR_ID SELECTION";
    afficherListe(selectionId);
    cout << '\n';

    vector<string> faux;

    if (parIndex.planche != plancheDansItem ||
        selectionIndex != selectionItem)
    {
        faux.push_back("PAR_INDEX");
    }

    if (parId.planche != plancheDansItem ||
        selectionId != selectionItem)
    {
        faux.push_back("PAR_ID");
    }

    cout << "FAUX";
    afficherListe(faux);
    cout << '\n';

    return 0;
}