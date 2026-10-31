// ============================================================
// EXERCICE 8 : LE COMPOSITE À TROIS NIVEAUX
// ============================================================
//
// Objectif de l'exercice :
//
// Construire une hiérarchie d'objets graphiques composée de
// trois niveaux : un premier parent, un deuxième parent et
// un sprite.
//
// Chaque objet possède sa propre transformation (position,
// rotation, échelle). Il faut composer ces transformations
// pour obtenir la position réelle du sprite dans le monde.
//
// Ensuite, nous devons :
// - Calculer la position théorique du sprite.
// - Mesurer sa position avec une sonde.
// - Vérifier visuellement le résultat avec une capture.
// - Reproduire l'ancien défaut de transformation.
// - Comparer les résultats pour montrer que le défaut est détecté.
//
// ============================================================


// ÉTAPE 1 : IMPORTATION DES FICHIERS NÉCESSAIRES
// ------------------------------------------------------------

// Contient la classe de base NkCanvasApp pour créer l'application.
#include <NKCanvas/App/NkCanvasApp.h>

// Contient la classe NkSprite utilisée pour représenter le sprite.
#include <NKCanvas/Renderer/Resources/NkSprite.h>

// Contient la classe NkTexture pour créer la texture du sprite.
#include <NKCanvas/Renderer/Resources/NkTexture.h>

// Contient les classes permettant de manipuler les transformations.
#include <NKCanvas/Renderer/Core/NkTransform.h>

// Contient le point d'entrée portable nkmain.
#include <NKWindow/NKMain.h>

// Permet de créer et d'écrire dans un fichier.
#include <fstream>

// Permet d'afficher les messages d'erreur dans la console.
#include <iostream>


// Évite de répéter les espaces de noms devant chaque classe.
using namespace nkentseu;
using namespace nkentseu::renderer;


// ============================================================
// ÉTAPE 2 : CRÉATION DE LA CLASSE COMPOSITE
// ============================================================
//
// Instruction de l'énoncé :
//
// Définir une classe qui hérite de NkTransformable et
// NkDrawable, qui contient un enfant et qui le dessine
// en composant les transformations.
//
// Explication :
//
// NkTransformable permet à notre objet de posséder une
// transformation : position, rotation et échelle.
//
// NkDrawable permet à notre objet d'être dessiné par le
// moteur graphique.
//
// La classe Composite va donc représenter un parent capable
// de contenir et de dessiner d'autres objets.
//
// ============================================================

class Composite : public NkTransformable, public NkDrawable {
public:

    // Ajoute un objet enfant dans le composite.
    //
    // L'enfant est stocké sous forme de pointeur vers NkDrawable.
    // Cela permet de contenir différents objets dessinables :
    // un autre Composite, un sprite ou une sonde.

    void AddChild(const NkDrawable& child) {

        // Vérifie qu'il reste une place dans le tableau.
        if (mChildCount < 3) {
            // Ajoute l'enfant et augmente le nombre d'enfants.
            mChildren[mChildCount++] = &child;
        }
    }


    // Méthode appelée par le moteur lorsqu'il doit dessiner
    // notre objet composite.
    //
    // target : la cible sur laquelle les objets seront dessinés.
    // states : les transformations et les autres états reçus
    //          du parent précédent.

    void Draw(
        NkRenderTarget& target,
        const NkRenderStates& states
    ) const override {

        // ÉTAPE 2.1 : COPIER L'ÉTAT REÇU
        //
        // On crée une copie pour ne pas modifier directement
        // les transformations reçues du parent.

        NkRenderStates composed = states;


        // ÉTAPE 2.2 : COMPOSER LES TRANSFORMATIONS
        //
        // On ajoute la transformation locale du composite
        // à celle qui a été reçue du parent.
        //
        // L'ordre est important :
        // la transformation locale est appliquée avant
        // la transformation du parent dans le repère du monde.
        //
        // Cette instruction est essentielle pour l'exercice.

        composed.transform *= GetTransform();


        // ÉTAPE 2.3 : DESSINER LES ENFANTS
        //
        // Chaque enfant reçoit maintenant la transformation
        // composée de tous les parents parcourus jusque-là.

        for (int i = 0; i < mChildCount; ++i) {

            // Demande au moteur de dessiner l'enfant avec
            // les transformations cumulées.
            target.Draw(*mChildren[i], composed);
        }
    }


private:

    // Tableau contenant les objets enfants du composite.
    const NkDrawable* mChildren[3] = {};

    // Indique combien d'enfants ont été ajoutés.
    int mChildCount = 0;
};


// ============================================================
// ÉTAPE 3 : CRÉATION DE LA SONDE DE MESURE
// ============================================================
//
// Instruction de l'énoncé :
//
// Placer une sonde comme le sprite et lui faire écrire
// sa position composée dans un fichier.
//
// Explication :
//
// La sonde est un objet dessinable qui ne sert pas à afficher
// une image. Elle sert à vérifier mathématiquement la position
// obtenue après composition des transformations.
//
// Nous allons créer deux comportements :
//
// 1. La sonde normale : elle tient compte des transformations
//    des parents et de sa propre transformation.
//
// 2. La sonde défectueuse : elle ignore les transformations
//    reçues et utilise uniquement sa transformation locale.
//
// ============================================================

class Sonde : public NkTransformable, public NkDrawable {
public:

    // Initialise la sonde.
    //
    // nom : permet de reconnaître la sonde dans le fichier.
    //
    // ignorerEtat : indique si la sonde doit reproduire
    // volontairement l'ancien défaut.

    Sonde(const char* nom, bool ignorerEtat = false)
        : mNom(nom), mIgnorerEtat(ignorerEtat) {
    }


    // Associe le fichier dans lequel la sonde doit enregistrer
    // la position qu'elle a calculée.

    void SetOutput(std::ofstream* fichier) {
        mFichier = fichier;
    }


    // Méthode appelée lorsque le moteur dessine la sonde.
    //
    // Nous utilisons cette méthode pour calculer la position
    // de l'origine de la sonde dans le repère du monde.

    void Draw(
        NkRenderTarget& target,
        const NkRenderStates& states
    ) const override {

        // La sonde ne dessine aucune forme graphique.
        // Le paramètre target n'est donc pas utilisé.
        (void)target;


        // Vérifie que le fichier existe et qu'une mesure
        // n'a pas déjà été enregistrée.
        if (!mFichier || !mFichier->is_open() || mMesureEffectuee) {
            return;
        }


        // Variable qui recevra la position calculée.
        NkVec2f position;


        // ÉTAPE 3.1 : REPRODUCTION DE L'ANCIEN DÉFAUT
        //
        // Lorsque mIgnorerEtat vaut true, la sonde ignore
        // complètement les transformations reçues du parent.
        //
        // Elle utilise uniquement sa propre transformation.
        //
        // Elle ne tient donc pas compte de la position et
        // de la rotation des deux parents.

        if (mIgnorerEtat) {

            // Transforme l'origine avec la transformation locale
            // de la sonde uniquement.
            position = GetTransform().TransformPoint({0.f, 0.f});

        } else {


            // ÉTAPE 3.2 : MESURE AVEC COMPOSITION CORRECTE
            //
            // On commence par récupérer la transformation
            // cumulée reçue des deux parents.

            NkTransform transform = states.transform;


            // On ajoute la transformation locale de la sonde.
            //
            // La sonde étant placée comme le sprite, elle doit
            // subir les mêmes transformations locales.

            transform *= GetTransform();


            // TransformPoint calcule les coordonnées du point
            // (0, 0) après application de toutes les transformations.
            //
            // On obtient ainsi sa position réelle dans le monde.

            position = transform.TransformPoint({0.f, 0.f});
        }


        // ÉTAPE 3.3 : ENREGISTREMENT DE LA POSITION
        //
        // On écrit le nom de la sonde et les coordonnées
        // obtenues dans le fichier de mesures.

        *mFichier << mNom << " : ("
                  << position.x << ", "
                  << position.y << ")\n";


        // Force l'écriture immédiate dans le fichier.
        mFichier->flush();


        // Indique que la mesure a déjà été effectuée.
        // Cela évite de répéter la même écriture à chaque image.

        mMesureEffectuee = true;
    }


private:

    // Nom de la sonde affiché dans le fichier de mesures.
    const char* mNom;

    // Indique si cette sonde reproduit l'ancien défaut.
    bool mIgnorerEtat = false;

    // Indique si la position a déjà été mesurée.
    mutable bool mMesureEffectuee = false;

    // Pointeur vers le fichier qui reçoit les mesures.
    std::ofstream* mFichier = nullptr;
};


// ============================================================
// ÉTAPE 4 : CRÉATION DE L'APPLICATION
// ============================================================
//
// Cette classe permet de lancer notre démonstration graphique.
// Elle initialise les ressources, construit la hiérarchie,
// puis demande au moteur de dessiner le premier parent.
//
// ============================================================

class ApplicationComposite : public NkCanvasApp {
public:

    // Configure les caractéristiques de la fenêtre.
    ApplicationComposite() {

        // Définit le titre de la fenêtre.
        Config().title = "Composite a trois niveaux";

        // Définit la largeur de la fenêtre.
        Config().width = 800;

        // Définit la hauteur de la fenêtre.
        Config().height = 600;

        // Définit la couleur de fond.
        Config().clearColor = NkColor2D{25, 25, 35, 255};
    }


protected:

    // ========================================================
    // ÉTAPE 5 : INITIALISATION DES OBJETS ET DE LA HIÉRARCHIE
    // ========================================================
    //
    // On crée ici la texture, le sprite et les sondes.
    // Ensuite, on définit les positions et la rotation
    // des deux parents avant de construire la hiérarchie.
    //
    // ========================================================

    bool OnInit() override {

        // Récupère le moteur de rendu de la fenêtre.
        // Il sera nécessaire pour créer la texture.

        NkIRenderer2D* renderer = Target().GetRenderer();


        // Vérifie que le moteur de rendu est disponible.
        if (!renderer) {
            std::cerr << "Renderer indisponible.\n";
            return false;
        }


        // ÉTAPE 5.1 : CRÉATION DE LA TEXTURE
        //
        // Le sprite a besoin d'une texture pour être visible
        // dans la capture d'écran.
        //
        // On crée donc une texture blanche de 32 x 32 pixels.

        if (!mTexture.Create(
                *renderer,
                32,
                32,
                NkColor2D{255, 255, 255, 255}
            )) {

            std::cerr << "Impossible de creer la texture.\n";
            return false;
        }


        // ÉTAPE 5.2 : POSITION DU SPRITE
        //
        // Le sprite représente le troisième niveau
        // de notre hiérarchie.
        //
        // Sa position est définie dans le repère local
        // de son parent, le deuxième composite.

        mSprite.SetTexture(mTexture);
        mSprite.SetPosition(20.f, 10.f);


        // Les deux sondes sont placées exactement comme
        // le sprite afin de comparer leurs résultats.

        mSondeNormale.SetPosition(20.f, 10.f);
        mSondeDefectueuse.SetPosition(20.f, 10.f);


        // ÉTAPE 5.3 : OUVERTURE DU FICHIER DE MESURES
        //
        // Ce fichier recevra les positions calculées
        // par les deux sondes.

        mMesures.open("composite-mesures.txt", std::ios::trunc);


        // Vérifie que le fichier a bien été ouvert.
        if (!mMesures.is_open()) {
            std::cerr << "Impossible de creer le fichier de mesures.\n";
            return false;
        }


        // Associe chaque sonde au fichier de mesures.
        mSondeNormale.SetOutput(&mMesures);
        mSondeDefectueuse.SetOutput(&mMesures);


        // ÉTAPE 5.4 : CONFIGURATION DU DEUXIÈME NIVEAU
        //
        // Le deuxième parent est placé en (50, 30).
        // Il effectue également une rotation de 90 degrés.
        //
        // Tous ses enfants subiront cette transformation.

        mParent2.SetPosition(50.f, 30.f);
        mParent2.SetRotation(math::NkAngle(90.f));


        // Ajoute le sprite et les deux sondes au deuxième parent.
        //
        // Ils possèdent chacun leur propre position locale,
        // mais héritent également de la transformation du parent.

        mParent2.AddChild(mSprite);
        mParent2.AddChild(mSondeNormale);
        mParent2.AddChild(mSondeDefectueuse);


        // ÉTAPE 5.5 : CONFIGURATION DU PREMIER NIVEAU
        //
        // Le premier parent est placé en (100, 80).
        // Il contient le deuxième parent.
        //
        // Sa transformation sera donc également appliquée
        // à tous les objets situés dans les niveaux inférieurs.

        mParent1.SetPosition(100.f, 80.f);


        // Construction de la hiérarchie :
        // Parent 1 contient Parent 2.
        // Parent 2 contient le sprite et les deux sondes.

        mParent1.AddChild(mParent2);


        // Signale que l'initialisation est terminée.
        return true;
    }


    // ========================================================
    // ÉTAPE 6 : AFFICHAGE DE LA HIÉRARCHIE
    // ========================================================
    //
    // L'énoncé demande de vérifier le sprite dans une capture
    // d'image. Cette méthode réalise le dessin de la hiérarchie.
    //
    // ========================================================

    void OnRender(NkRenderWindow& target) override {

        // Efface l'image précédente.
        target.Clear(NkColor2D{25, 25, 35, 255});


        // Dessine le premier parent.
        //
        // Le composite transmet automatiquement les
        // transformations aux objets descendants.
        //
        // Il n'est donc pas nécessaire de dessiner séparément
        // chaque enfant ici.

        target.Draw(mParent1);
    }


    // ========================================================
    // ÉTAPE 7 : FERMETURE DU FICHIER
    // ========================================================
    //
    // Cette méthode est appelée lorsque l'application
    // se termine. On ferme le fichier de mesures proprement.
    //
    // ========================================================

    void OnShutdown() override {

        if (mMesures.is_open()) {
            mMesures.close();
        }
    }


private:

    // Texture utilisée pour rendre le sprite visible.
    NkTexture mTexture;

    // Sprite représentant le troisième niveau.
    NkSprite mSprite;


    // Sonde correcte : mesure la position avec toutes
    // les transformations de la hiérarchie.
    Sonde mSondeNormale{"Sonde normale"};


    // Sonde défectueuse : ignore les transformations reçues
    // et ne conserve que sa transformation locale.
    Sonde mSondeDefectueuse{"Sonde defectueuse", true};


    // Premier et deuxième parents de la hiérarchie.
    Composite mParent1;
    Composite mParent2;


    // Fichier dans lequel les deux sondes enregistrent
    // leurs résultats.
    std::ofstream mMesures;
};


// ============================================================
// ÉTAPE 8 : POINT D'ENTRÉE DU PROGRAMME
// ============================================================
//
// L'énoncé demande une application construite avec NkCanvasApp.
// On utilise donc Run pour lancer notre classe d'application.
//
// ============================================================

int nkmain(const NkEntryState& state) {

    // Lance l'application et lui transmet les informations
    // reçues au démarrage du programme.

    return NkCanvasApp::Run<ApplicationComposite>(state);
}