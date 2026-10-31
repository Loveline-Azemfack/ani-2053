// ============================================================
// EXERCICE 6 : LE SINGLETON ET LE TEST
// Fichier : banc.cpp
//
// Objectif :
// Comparer une fonction qui utilise directement le Singleton
// NkInput avec une fonction qui reçoit ses dépendances
// en paramètres, afin de faciliter les tests.
// ============================================================


// ------------------------------------------------------------
// 1. INCLUSION DES BIBLIOTHEQUES ET DES FICHIERS NECESSAIRES
// ------------------------------------------------------------

// Permet d'utiliser la classe NkCanvasApp et ses méthodes.
// Sans cet en-tête, nous ne pourrions pas définir notre
// application en héritant de NkCanvasApp.
#include <NKCanvas/App/NkCanvasApp.h>

// Contient les déclarations nécessaires au point d'entrée
// et à l'état de lancement de l'application.
#include <NKWindow/NKMain.h>

// Donne accès à NkInput, NkInputQuery et NkKey.
// Nous en avons besoin pour interroger l'état du clavier.
#include <NKEvent/NkEventDispatcher.h>

// Fournit std::ofstream pour créer et écrire dans un fichier.
// Sans cette bibliothèque, nous ne pourrions pas utiliser
// std::ofstream pour enregistrer les résultats.
#include <fstream>


// ------------------------------------------------------------
// 2. ESPACE DE NOMS
// ------------------------------------------------------------

// Permet d'utiliser les éléments de l'espace de noms nkentseu
// sans devoir écrire nkentseu:: devant chacun d'eux.
//
// Sans cette directive, il faudrait par exemple écrire :
// nkentseu::NkInput
// nkentseu::NkKey
using namespace nkentseu;


// ------------------------------------------------------------
// 3. VERSION DIRECTE : UTILISATION DU SINGLETON
// ------------------------------------------------------------

// Cette fonction détermine si le personnage peut sauter.
//
// Paramètre :
// estAuSol : indique si le personnage se trouve au sol.
//
// Fonctionnement :
// 1. Vérifier si le personnage est au sol.
// 2. Interroger directement NkInput pour savoir si
//    la barre Espace est enfoncée.
// 3. Retourner true uniquement si les deux conditions
//    sont satisfaites.
//
// Pourquoi cette version ?
// Elle représente une fonction qui dépend directement
// d'un objet global accessible partout.
//
// Limite :
// Pour tester cette fonction, il faut pouvoir contrôler
// l'état du clavier utilisé par NkInput.
bool PeutSauterDirectement(bool estAuSol)
{
    return estAuSol && NkInput.IsKeyDown(NkKey::NK_SPACE);
}


// ------------------------------------------------------------
// 4. VERSION TESTABLE : INJECTION DES DEPENDANCES
// ------------------------------------------------------------

// Cette fonction détermine également si le personnage
// peut sauter, mais elle ne consulte plus directement NkInput.
//
// Paramètres :
// estAuSol       : indique si le personnage est au sol.
// espaceEnfoncee : indique si la barre Espace est enfoncée.
//
// Pourquoi cette version ?
// Elle reçoit directement les informations dont elle a besoin.
// Nous pouvons donc lui transmettre des valeurs choisies
// pour simuler différentes situations.
//
// Avantage :
// Elle peut être testée sans utiliser le clavier réel
// ni dépendre du Singleton NkInput.
//
// Règle de jeu :
// Le personnage saute uniquement s'il est au sol
// ET si la barre Espace est enfoncée.
bool PeutSauter(bool estAuSol, bool espaceEnfoncee)
{
    return estAuSol && espaceEnfoncee;
}


// ------------------------------------------------------------
// 5. CREATION DU BANC DE TEST
// ------------------------------------------------------------

// Notre classe hérite de NkCanvasApp.
//
// Pourquoi ?
// Parce que l'énoncé demande de créer une application
// NkCanvasApp afin d'utiliser son point d'entrée
// OnCommandLine().
//
// Le banc de test est chargé de lancer les vérifications,
// d'enregistrer les résultats et de retourner le nombre
// de tests échoués.
//
// Nous n'avons pas besoin de créer notre propre boucle
// graphique pour effectuer ces tests.
class BancDeTest : public renderer::NkCanvasApp
{
protected:

    // --------------------------------------------------------
    // 6. EXECUTION DES TESTS AVANT LA CREATION DE LA FENETRE
    // --------------------------------------------------------

    // OnCommandLine() est appelée au démarrage de l'application,
    // avant la création de la fenêtre.
    //
    // La valeur retournée permet d'indiquer le résultat
    // de l'exécution au programme appelant.
    //
    // Si cette méthode retourne une valeur, l'application
    // s'arrête avec ce code de sortie, conformément à l'énoncé.
    NkOptional<int> OnCommandLine(const NkVector<NkString>& args) override
    {
        // ----------------------------------------------------
        // 7. CREATION DU FICHIER DE RESULTATS
        // ----------------------------------------------------

        // Crée le fichier banc-resultats.txt en mode écriture.
        //
        // Si le fichier n'existe pas, il est créé.
        // S'il existe déjà, son ancien contenu est remplacé.
        //
        // Sans cette instruction, nous ne pourrions pas
        // enregistrer les résultats dans ce fichier.
        std::ofstream fichier("banc-resultats.txt");

        // Vérifie que le fichier a bien été ouvert.
        //
        // Si l'ouverture échoue, nous ne pouvons pas écrire
        // les résultats. Nous arrêtons donc le programme
        // en retournant un code d'erreur.
        if (!fichier.is_open())
        {
            return 1;
        }


        // ----------------------------------------------------
        // 8. INITIALISATION DU COMPTEUR D'ECHECS
        // ----------------------------------------------------

        // Cette variable compte le nombre de tests échoués.
        //
        // Elle commence à zéro parce qu'aucun test n'a encore
        // été exécuté.
        //
        // Sans ce compteur, nous ne pourrions pas transmettre
        // facilement le nombre total d'échecs.
        int echecs = 0;


        // ----------------------------------------------------
        // 9. ESSAI DE LA VERSION DIRECTE
        // ----------------------------------------------------

        // Nous essayons la version qui interroge directement
        // le Singleton NkInput.
        //
        // Ici, nous indiquons que le personnage est au sol.
        // Mais l'état de la barre Espace dépend toujours
        // du système d'entrée réel.
        //
        // Ce résultat est donc observé et enregistré.
        // Il ne constitue pas un test entièrement contrôlé.
        bool resultatDirect = PeutSauterDirectement(true);

        fichier << "Version directe : "
                << (resultatDirect ? "true" : "false")
                << '\n';


        // ----------------------------------------------------
        // 10. TEST DE LA VERSION TESTABLE
        // ----------------------------------------------------

        // CAS 1 :
        // Le personnage est au sol et la barre Espace
        // est enfoncée.
        //
        // Résultat attendu : true.
        bool resultat1 = PeutSauter(true, true);

        // Enregistre le résultat du premier test.
        fichier << "Cas 1 - Au sol avec Espace : "
                << (resultat1 == true ? "SUCCES" : "ECHEC")
                << '\n';

        // Si le résultat est différent du résultat attendu,
        // nous augmentons le compteur d'échecs.
        if (resultat1 != true)
        {
            echecs++;
        }


        // CAS 2 :
        // Le personnage est au sol, mais la barre Espace
        // n'est pas enfoncée.
        //
        // Résultat attendu : false.
        bool resultat2 = PeutSauter(true, false);

        fichier << "Cas 2 - Au sol sans Espace : "
                << (resultat2 == false ? "SUCCES" : "ECHEC")
                << '\n';

        if (resultat2 != false)
        {
            echecs++;
        }


        // CAS 3 :
        // Le personnage est en l'air et la barre Espace
        // est enfoncée.
        //
        // Résultat attendu : false, car le personnage
        // ne peut pas sauter une deuxième fois.
        bool resultat3 = PeutSauter(false, true);

        fichier << "Cas 3 - En l'air avec Espace : "
                << (resultat3 == false ? "SUCCES" : "ECHEC")
                << '\n';

        if (resultat3 != false)
        {
            echecs++;
        }


        // CAS 4 :
        // Le personnage est en l'air et la barre Espace
        // n'est pas enfoncée.
        //
        // Résultat attendu : false.
        bool resultat4 = PeutSauter(false, false);

        fichier << "Cas 4 - En l'air sans Espace : "
                << (resultat4 == false ? "SUCCES" : "ECHEC")
                << '\n';

        if (resultat4 != false)
        {
            echecs++;
        }


        // ----------------------------------------------------
        // 11. ENREGISTREMENT DU BILAN
        // ----------------------------------------------------

        // Inscrit le nombre total de tests échoués.
        //
        // Cela permet de connaître rapidement le résultat
        // général de notre banc de test.
        fichier << "\nNombre d'echecs : " << echecs << '\n';


        // ----------------------------------------------------
        // 12. FERMETURE DU FICHIER
        // ----------------------------------------------------

        // Ferme le fichier après avoir terminé les écritures.
        //
        // Cela permet de libérer les ressources utilisées
        // et de terminer correctement l'enregistrement.
        fichier.close();


        // ----------------------------------------------------
        // 13. RETOUR DU CODE DE SORTIE
        // ----------------------------------------------------

        // Retourne le nombre de tests échoués.
        //
        // 0 signifie que tous les tests sont réussis.
        // Une valeur supérieure à 0 indique des échecs.
        //
        // Ce code sera utilisé comme code de sortie
        // du programme.
        return echecs;
    }
};


// ------------------------------------------------------------
// 14. POINT D'ENTREE DU PROGRAMME
// ------------------------------------------------------------

// nkmain est le point d'entrée de notre application.
//
// Il reçoit l'état de lancement du programme.
//
// Run<BancDeTest>() demande à NkCanvasApp de lancer
// notre application BancDeTest.
//
// C'est ainsi que le framework appelle OnCommandLine()
// et exécute nos tests.
int nkmain(const NkEntryState& state)
{
    return renderer::NkCanvasApp::Run<BancDeTest>(state);
}