#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Pourquoi créons-nous une structure Objet ?
// Parce que nous devons conserver les informations de chaque objet
// pendant toute l'exécution du programme.
struct Objet {
    string nom;

    // Pourquoi avons-nous besoin de cette information ?
    // Parce qu'un objet déjà libéré ne doit pas être libéré une deuxième fois.
    bool libere;

    // Pourquoi conservons-nous les dépendances de chaque objet ?
    // Parce que lorsqu'un objet est libéré, nous devons vérifier
    // si les objets dont il dépend sont encore disponibles.
    vector<int> dependances;
};

// Pourquoi créons-nous une structure Bloc ?
// Parce que chaque bloc possède ses propres objets locaux.
// Nous devons connaître les objets appartenant à chaque bloc
// pour pouvoir les détruire à la rencontre de }.
struct Bloc {
    vector<int> objets;
};

int main() {

    // Pourquoi créons-nous ces deux vecteurs ?
    // Parce que nous devons conserver tous les objets créés
    // et connaître les blocs auxquels ils appartiennent.
    vector<Objet> objets;
    vector<Bloc> blocs;

    // Pourquoi créons-nous un premier bloc dès le départ ?
    // Parce que les premières déclarations appartiennent au bloc
    // de la fonction, même si aucune accolade n'est présente dans l'entrée.
    blocs.push_back({});

    string commande;

    // Pourquoi utilisons-nous while(cin >> commande) ?
    // Parce que l'énoncé demande de lire les instructions jusqu'à
    // la fin de l'entrée, sans connaître leur nombre à l'avance.
    while (cin >> commande) {

        // Pourquoi traitons-nous DECL ?
        // Parce que cette instruction introduit un nouvel objet
        // dans le bloc actuellement ouvert.
        if (commande == "DECL") {
            string nom;
            cin >> nom;

            // Pourquoi créons-nous un nouvel objet ?
            // Parce que chaque déclaration représente un objet
            // qui possède sa propre durée de vie.
            objets.push_back({nom, false, {}});

            // Pourquoi enregistrons-nous son indice dans le bloc courant ?
            // Parce qu'à la fermeture de ce bloc, nous devrons détruire
            // uniquement les objets qui y ont été déclarés.
            blocs.back().objets.push_back(objets.size() - 1);
        }

        // Pourquoi traitons-nous DEPEND ?
        // Parce que cette instruction indique qu'un objet a besoin
        // d'un autre objet pour être correctement libéré.
        else if (commande == "DEPEND") {
            string nomA, nomB;
            cin >> nomA >> nomB;

            int indiceA = -1;
            int indiceB = -1;

            // Pourquoi recherchons-nous les indices des deux objets ?
            // Parce que les dépendances doivent être conservées sous forme
            // de références vers les objets concernés, et non seulement leurs noms.
            for (int i = (int)objets.size() - 1; i >= 0; i--) {

                if (objets[i].nom == nomA && indiceA == -1) {
                    indiceA = i;
                }

                if (objets[i].nom == nomB && indiceB == -1) {
                    indiceB = i;
                }

                if (indiceA != -1 && indiceB != -1) {
                    break;
                }
            }

            // Pourquoi ajoutons-nous indiceB aux dépendances de A ?
            // Parce que l'objet A doit vérifier que B n'a pas déjà été libéré
            // au moment où A sera détruit.
            objets[indiceA].dependances.push_back(indiceB);
        }

        // Pourquoi traitons-nous FERME ?
        // Parce que cette instruction demande la libération immédiate
        // d'un objet, avant la fermeture naturelle de son bloc.
        else if (commande == "FERME") {
            string nom;
            cin >> nom;

            int indice = -1;

            // Pourquoi recherchons-nous l'objet par son nom ?
            // Parce que FERME identifie l'objet à libérer grâce à son nom.
            for (int i = (int)objets.size() - 1; i >= 0; i--) {
                if (objets[i].nom == nom) {
                    indice = i;
                    break;
                }
            }

            // Pourquoi vérifions-nous si l'objet est déjà libéré ?
            // Parce que l'énoncé précise qu'un deuxième FERME
            // sur un objet déjà libéré ne produit aucun affichage.
            if (!objets[indice].libere) {

                // Pourquoi parcourons-nous les dépendances dans leur ordre ?
                // Parce que l'énoncé impose de vérifier les lignes DEPEND
                // dans leur ordre de lecture.
                for (int dependance : objets[indice].dependances) {

                    // Pourquoi vérifions-nous l'état de la dépendance ?
                    // Parce que l'objet que nous libérons a besoin de cette ressource.
                    // Si elle est déjà libérée, le programme plante.
                    if (objets[dependance].libere) {

                        cout << "PLANTAGE "
                             << objets[indice].nom << " "
                             << objets[dependance].nom << '\n';

                        // Pourquoi arrêtons-nous immédiatement ?
                        // Parce que l'énoncé exige de s'arrêter au premier plantage.
                        return 0;
                    }
                }

                // Pourquoi libérons-nous l'objet après les vérifications ?
                // Parce que nous devons d'abord nous assurer
                // que toutes ses dépendances sont encore disponibles.
                objets[indice].libere = true;

                // Pourquoi affichons-nous FERME ?
                // Parce que la libération vient d'être effectuée
                // explicitement par le programme.
                cout << "FERME " << nom << '\n';
            }
        }

        // Pourquoi traitons-nous l'ouverture d'un bloc ?
        // Parce que chaque accolade ouvrante crée une nouvelle portée.
        // Les objets déclarés ensuite appartiendront à ce nouveau bloc.
        else if (commande == "{") {
            blocs.push_back({});
        }

        // Pourquoi traitons-nous la fermeture d'un bloc ?
        // Parce que les objets locaux de ce bloc doivent être détruits
        // immédiatement, avant de continuer dans le bloc extérieur.
        else if (commande == "}") {

            // Pourquoi récupérons-nous le dernier bloc ?
            // Parce que c'est le bloc actuellement ouvert qui doit être fermé.
            Bloc bloc = blocs.back();

            // Pourquoi parcourons-nous ses objets à l'envers ?
            // Parce que C++ détruit les objets locaux dans l'ordre inverse
            // de leur déclaration : le dernier déclaré meurt en premier.
            for (int i = (int)bloc.objets.size() - 1; i >= 0; i--) {

                int indice = bloc.objets[i];

                // Pourquoi ignorons-nous les objets déjà libérés ?
                // Parce qu'un objet qui a déjà été libéré explicitement
                // ne doit pas être détruit une deuxième fois.
                if (objets[indice].libere) {
                    continue;
                }

                // Pourquoi vérifions-nous les dépendances avant la destruction ?
                // Parce qu'un objet ne peut pas être libéré si l'un des objets
                // dont il a besoin a déjà été libéré.
                for (int dependance : objets[indice].dependances) {

                    if (objets[dependance].libere) {

                        cout << "PLANTAGE "
                             << objets[indice].nom << " "
                             << objets[dependance].nom << '\n';

                        // Pourquoi arrêtons-nous ici ?
                        // Parce qu'une destruction incorrecte a été détectée.
                        return 0;
                    }
                }

                // Pourquoi marquons-nous l'objet comme libéré ?
                // Parce que sa destruction vient d'être effectuée.
                objets[indice].libere = true;

                // Pourquoi affichons-nous DETRUIT ?
                // Parce que cette libération est provoquée automatiquement
                // par la fermeture du bloc, et non par un appel explicite.
                cout << "DETRUIT " << objets[indice].nom << '\n';
            }

            // Pourquoi supprimons-nous le bloc de la pile ?
            // Parce que sa durée de vie est terminée.
            // Le programme revient maintenant au bloc extérieur.
            blocs.pop_back();
        }
    }

    // Pourquoi effectuons-nous ce dernier parcours ?
    // Parce que la fin de l'entrée correspond à la fermeture du bloc
    // de la fonction. Ses objets doivent donc être détruits eux aussi.
    //
    // Pourquoi utilisons-nous while ?
    // Parce qu'il peut rester plusieurs blocs ouverts, notamment
    // si le bloc de la fonction contient des blocs intérieurs déjà fermés.
    while (!blocs.empty()) {

        Bloc bloc = blocs.back();

        // Pourquoi parcourons-nous les objets à l'envers ?
        // Parce que l'ordre de destruction reste l'inverse
        // de l'ordre de déclaration, même à la fin de la fonction.
        for (int i = (int)bloc.objets.size() - 1; i >= 0; i--) {

            int indice = bloc.objets[i];

            // Pourquoi sautons-nous les objets déjà libérés ?
            // Parce qu'ils ne doivent pas subir une deuxième destruction.
            if (objets[indice].libere) {
                continue;
            }

            // Pourquoi vérifions-nous encore les dépendances ?
            // Parce que la destruction finale doit respecter
            // exactement les mêmes règles que la destruction d'un bloc.
            for (int dependance : objets[indice].dependances) {

                if (objets[dependance].libere) {

                    cout << "PLANTAGE "
                         << objets[indice].nom << " "
                         << objets[dependance].nom << '\n';

                    return 0;
                }
            }

            // Pourquoi marquons-nous l'objet comme libéré ?
            // Parce que nous venons de terminer sa destruction.
            objets[indice].libere = true;

            cout << "DETRUIT " << objets[indice].nom << '\n';
        }

        // Pourquoi retirons-nous le bloc après sa destruction ?
        // Parce que tous ses objets ont maintenant été traités.
        blocs.pop_back();
    }

    // Pourquoi affichons-nous PROPRE ?
    // Parce que tous les objets ont été détruits correctement
    // sans qu'aucune dépendance ne soit utilisée après sa libération.
    cout << "PROPRE\n";

    return 0;
}