// ÉTAPE 4 DE L'ÉNONCÉ : ÉCRIRE LE FICHIER crochets.cpp.

// Importe le fichier NkCanvasApp.h.
// Son rôle est de fournir la classe NkCanvasApp et les types nécessaires
// pour construire notre application avec le kit Canvas.
#include "NKCanvas/App/NkCanvasApp.h"
#include "NKWindow/NKMain.h"

// Importe la bibliothèque fstream.
// Son rôle est de permettre la création et l'écriture dans un fichier.
// Nous l'utilisons pour enregistrer les appels des crochets.
#include <fstream>

// Importe la bibliothèque iomanip.
// Son rôle est de contrôler la présentation des nombres.
// Nous l'utilisons pour afficher le temps avec trois chiffres après la virgule.
#include <iomanip>

// Permet d'utiliser directement les éléments de l'espace de noms nkentseu
// sans devoir écrire nkentseu:: devant chacun d'eux.
using namespace nkentseu;

// Permet d'utiliser directement les éléments de l'espace de noms renderer.
// Cet espace contient notamment la classe NkCanvasApp.
using namespace nkentseu::renderer;


// Déclare la classe MonJeu.
// Elle hérite publiquement de NkCanvasApp : elle récupère ainsi ses fonctionnalités
// et peut redéfinir ses méthodes virtuelles pour personnaliser le comportement.
class MonJeu : public renderer::NkCanvasApp {

private: // Début de la partie privée : les éléments suivants sont accessibles uniquement dans MonJeu.

    // Variable mOrdre :
    // C'est un entier qui mémorise le numéro de chaque appel enregistré.
    // Il commence à 0 et augmente de 1 à chaque passage dans Journal().
    int mOrdre = 0;

    // Variable mImage :
    // C'est un entier qui mémorise le numéro de l'image en cours.
    // Il commence à 0 et augmente à chaque appel de OnUpdate().
    int mImage = 0;


    // Fonction Journal :
    // Elle reçoit le nom du crochet appelé et enregistre ses informations
    // dans le fichier crochets-journal.txt.
    // Le paramètre nom contient le nom du crochet sous forme de texte.
    void Journal(const char* nom) {

        // Déclare un pointeur vers un fichier.
        // static permet de conserver le même fichier ouvert entre les appels
        // successifs de Journal(), au lieu de l'ouvrir à chaque appel.
        // std::ofstream permet d'écrire dans un fichier.
        // "crochets-journal.txt" est le nom du fichier créé.
        // std::ios::out autorise l'écriture.
        // std::ios::trunc efface l'ancien contenu à l'ouverture du fichier.
        static std::ofstream fichier(
            "crochets-journal.txt",
            std::ios::out | std::ios::trunc
        );

        // Vérifie que le fichier est correctement ouvert.
        // Si c'est le cas, le programme peut écrire dedans.
        if (fichier.is_open()) {

            // Augmente le numéro d'ordre de 1.
            // Chaque appel enregistré reçoit ainsi un numéro différent.
            ++mOrdre;

            // Écrit le numéro d'ordre dans le fichier.
            fichier << mOrdre

                    // Écrit un séparateur puis le nom du crochet appelé.
                    << " | " << nom

                    // Écrit le numéro de l'image actuellement traitée.
                    << " | Image : " << mImage

                    // Écrit le texte qui annonce la valeur du temps.
                    << " | Time : "

                    // Configure l'affichage pour conserver trois chiffres
                    // après la virgule.
                    << std::fixed << std::setprecision(3)

                    // Appelle Time(), une méthode de NkCanvasApp.
                    // Elle donne le temps écoulé depuis OnInit(), en secondes.
                    << Time()

                    // Ajoute l'unité seconde et passe à la ligne suivante.
                    << " s\n";

            // Force l'écriture immédiate des données dans le fichier.
            // Cela évite de garder les dernières lignes uniquement en mémoire.
            fichier.flush();
        }
    }


// ÉTAPE 4 DE L'ÉNONCÉ : REDÉFINIR LES CROCHETS VIRTUELS.
// protected permet à la classe de base et aux classes dérivées
// d'accéder à ces méthodes, sans les rendre publiques.
protected:

    // CROCHET 1 : OnCommandLine.
    // Il est appelé avant la création de la fenêtre.
    // Il reçoit les arguments transmis au lancement du programme.
    // Son rôle est de permettre le traitement des arguments de la commande.
    NkOptional<int> OnCommandLine(const NkVector<NkString>& args) override {

        // Indique au compilateur que le paramètre args n'est pas utilisé.
        // Cela évite un avertissement concernant une variable inutilisée.
        (void)args;

        // Enregistre l'appel de OnCommandLine dans le journal.
        Journal("OnCommandLine");

        // Retourne un résultat vide.
        // Cela signifie que nous ne demandons pas l'arrêt du programme
        // avec un code de retour particulier à cette étape.
        return {};
    }


    // CROCHET 2 : OnInit.
    // Il est appelé lorsque la fenêtre et la cible de rendu existent.
    // Son rôle est d'effectuer l'initialisation de notre application.
    bool OnInit() override {

        // Enregistre l'appel de OnInit dans le journal.
        Journal("OnInit");

        // Retourne true pour indiquer que l'initialisation a réussi
        // et que l'application peut continuer son exécution.
        return true;
    }


    // CROCHET 3 : OnUpdate.
    // Il est appelé pendant la boucle principale du programme.
    // Son rôle est de mettre à jour les données de l'application à chaque image.
    // deltaTime représente le temps écoulé depuis la mise à jour précédente.
    void OnUpdate(float32 deltaTime) override {

        // Indique au compilateur que deltaTime n'est pas utilisé ici.
        // Nous le conservons dans la signature parce que la méthode de base
        // impose ce paramètre.
        (void)deltaTime;

        // Augmente le numéro de l'image de 1.
        // Chaque mise à jour correspond ici à une nouvelle image comptabilisée.
        ++mImage;

        // Enregistre l'appel de OnUpdate dans le journal.
        Journal("OnUpdate");
    }


    // CROCHET 4 : OnRender.
    // Il est appelé pour effectuer le rendu de l'image.
    // target représente la fenêtre ou la cible sur laquelle le rendu est effectué.
    void OnRender(NkRenderWindow& target) override {

        // Indique au compilateur que nous n'utilisons pas directement target.
        // Le paramètre reste présent pour respecter la signature de la méthode.
        (void)target;

        // Enregistre l'appel de OnRender dans le journal.
        Journal("OnRender");

        // Vérifie si le compteur d'images a atteint 5.
        if (mImage >= 5) {

            // Demande l'arrêt de l'application.
            // Quit() demande à la boucle principale de s'arrêter.
            // L'image en cours peut terminer son traitement.
            Quit();
        }
    }


    // CROCHET 5 : OnShutdown.
    // Il est appelé lorsque l'application arrive à sa phase d'arrêt.
    // Son rôle est de permettre d'effectuer les opérations finales.
    void OnShutdown() override {

        // Enregistre l'appel de OnShutdown dans le journal.
        Journal("OnShutdown");
    }


    // CROCHET 6 : OnEvent.
    // Il reçoit les événements bruts transmis à l'application.
    // event contient les informations concernant l'événement reçu.
    // La méthode retourne un booléen indiquant si l'événement est consommé.
    bool OnEvent(const NkEvent& event) override {

        // Indique que nous n'utilisons pas les informations de event.
        (void)event;

        // Enregistre l'appel de OnEvent dans le journal.
        Journal("OnEvent");

        // Retourne false pour indiquer que nous ne consommons pas l'événement.
        return false;
    }


    // CROCHET 7 : OnPointer.
    // Il reçoit les interactions provenant du pointeur.
    // Il peut s'agir notamment de mouvements ou d'actions de la souris
    // et des interactions tactiles.
    bool OnPointer(const NkPointer& pointer) override {

        // Indique que nous n'utilisons pas les informations de pointer.
        (void)pointer;

        // Enregistre l'appel de OnPointer dans le journal.
        Journal("OnPointer");

        // Retourne false pour indiquer que nous ne consommons pas l'interaction.
        return false;
    }


    // CROCHET 8 : OnKeyPress.
    // Il reçoit les événements correspondant à la pression d'une touche.
    // event contient les informations sur la touche concernée.
    bool OnKeyPress(const NkKeyPressEvent& event) override {

        // Indique que nous n'utilisons pas les informations de event.
        (void)event;

        // Enregistre l'appel de OnKeyPress dans le journal.
        Journal("OnKeyPress");

        // Retourne false pour indiquer que nous ne consommons pas l'événement.
        return false;
    }


    // CROCHET 9 : OnLayout.
    // Il est appelé lorsque les informations de disposition changent.
    // layout contient notamment les informations de taille,
    // de zone de sécurité et de densité d'affichage.
    void OnLayout(const NkLayoutInfo& layout) override {

        // Indique que nous n'utilisons pas directement les informations de layout.
        (void)layout;

        // Enregistre l'appel de OnLayout dans le journal.
        Journal("OnLayout");
    }


    // CROCHET 10 : OnCloseRequested.
    // Il est appelé lorsqu'une demande de fermeture de la fenêtre est reçue.
    // Son rôle est de permettre à l'application d'accepter ou de refuser
    // cette demande de fermeture.
    bool OnCloseRequested() override {

        // Enregistre l'appel de OnCloseRequested dans le journal.
        Journal("OnCloseRequested");

        // Retourne true pour accepter la demande de fermeture.
        return true;
    }


    // CROCHET 11 : OnPause.
    // Il est appelé lorsque l'application est mise en arrière-plan
    // ou perd le focus, selon le commentaire de la classe de base.
    // Son rôle est de signaler la mise en pause de l'application.
    void OnPause() override {

        // Enregistre l'appel de OnPause dans le journal.
        Journal("OnPause");
    }


    // CROCHET 12 : OnResume.
    // Il est appelé lorsque l'application reprend son activité.
    // Son rôle est de signaler la reprise de l'application.
    void OnResume() override {

        // Enregistre l'appel de OnResume dans le journal.
        Journal("OnResume");
    }
};


// ÉTAPE 4 DE L'ÉNONCÉ : DÉCLARER LE POINT D'ENTRÉE DE L'APPLICATION.
// nkmain est la fonction appelée pour lancer notre application avec le kit.
int nkmain(const NkEntryState& state) {

    // Appelle la méthode Run de NkCanvasApp.
    // Run reçoit notre classe MonJeu comme type de programme à exécuter.
    // state contient les informations nécessaires au lancement de l'application.
    // La valeur retournée correspond au code de fin de l'application.
    return renderer::NkCanvasApp::Run<MonJeu>(state);
}