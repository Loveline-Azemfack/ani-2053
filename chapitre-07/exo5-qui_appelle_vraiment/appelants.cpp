// Inclut la declaration de NkCanvasApp.
// Cette classe fournit la structure de base de notre application.
#include <NKCanvas/App/NkCanvasApp.h>

// Inclut la declaration de NkDrawable.
// Nous en avons besoin pour creer notre propre objet dessinable.
#include <NKCanvas/Renderer/Core/NkDrawable.h>

// Inclut les types utilises pour le rendu 2D.
// Ce fichier declare notamment NkVertex et NkPrimitiveType.
#include <NKCanvas/Renderer/Core/NkRenderer2DTypes.h>

// Inclut NkRenderTarget et ses differentes surcharges de Draw.
// Nous devons pouvoir transmettre notre objet et nos sommets au renderer.
#include <NKCanvas/Renderer/Targets/NkRenderTarget.h>

// Inclut NkRenderWindow, la fenetre qui expose les fonctionnalites
// du renderer et permet de dessiner dans la fenetre.
#include <NKCanvas/Renderer/Targets/NkRenderWindow.h>

// Rend les noms du namespace renderer accessibles sans ecrire
// nkentseu::renderer:: devant chaque classe ou type concerne.
// Cela suppose que les declarations utilisees se trouvent bien dans ce namespace.
using namespace nkentseu::renderer;


// Declare notre classe MonDessin.
// L'heritage public signifie qu'un MonDessin est aussi un NkDrawable.
// C'est necessaire pour utiliser la surcharge Draw qui accepte un NkDrawable.
class MonDessin : public NkDrawable
{
public: // Les membres qui suivent sont accessibles depuis l'exterieur.

    // Redefinit la methode virtuelle pure de NkDrawable.
    // target : renderer auquel nous transmettons les sommets.
    // states : parametres de rendu recus par la methode.
    // const : cette methode ne modifie pas l'etat ordinaire de MonDessin.
    // override : le compilateur verifie que la methode redefinit bien une methode heritee.
    void Draw(
        NkRenderTarget& target,
        const NkRenderStates& states
    ) const override
    {
        // Cree un tableau constant contenant exactement quatre sommets.
        // NkVertex est un alias de NkVertex2D.
        // Chaque sommet contient x, y, u, v, r, g, b et a.
        const NkVertex vertices[4] =
        {
            // Sommet 1 : position (100, 100), couleur blanche opaque.
            {100.0f, 100.0f, 0.0f, 0.0f, 255, 255, 255, 255},

            // Sommet 2 : position (200, 100), couleur blanche opaque.
            {200.0f, 100.0f, 0.0f, 0.0f, 255, 255, 255, 255},

            // Sommet 3 : position (200, 200), couleur blanche opaque.
            {200.0f, 200.0f, 0.0f, 0.0f, 255, 255, 255, 255},

            // Sommet 4 : position (100, 200), couleur blanche opaque.
            {100.0f, 200.0f, 0.0f, 0.0f, 255, 255, 255, 255}
        };

        // Envoie les sommets au renderer.
        // vertices : adresse du premier element du tableau.
        // 4 : nombre de sommets transmis.
        // NK_LINES : les sommets sont interpretes par paires pour former des lignes.
        // states : conserve les parametres de rendu recus par notre methode.
        target.Draw(
            vertices,
            4,
            NkPrimitiveType::NK_LINES,
            states
        );
    }
};


// La classe d'application qui contiendra notre objet MonDessin
// et demandera son affichage pendant le rendu.
// Sa methode de demarrage doit etre adaptee a l'API exacte du kit.
class MonApplication : public NkCanvasApp
{
public:

    // Attribut membre : l'objet a dessiner.
    // Il existe tant que l'instance de MonApplication existe.
    // Nous pourrons le passer a target.Draw(objet) pendant le rendu.
    MonDessin objet;

    // La methode OnRender devra etre redefinie ici avec la signature
    // exacte de NkCanvasApp, puis appeler target.Draw(objet).
    // Nous completerons ce bloc apres verification du demarrage du kit.
};