#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    // Pourquoi utilisons-nous une map ?
    // Pour retrouver rapidement l'indice d'un fichier à partir de son nom.
    unordered_map<string, int> indices;

    // Pourquoi conservons-nous les noms dans un vector ?
    // Pour respecter l'ordre de lecture des fichiers.
    vector<string> fichiers(N);

    // Pourquoi créons-nous un tableau de vectors de strings ?
    // Parce que nous devons conserver les noms des inclusions avant
    // de pouvoir déterminer si elles appartiennent à notre liste.
    vector<vector<string>> inclusions(N);

    // Pourquoi créons-nous un graphe inversé ?
    // Parce que nous voulons retrouver les fichiers qui dépendent
    // d'un fichier donné, directement ou indirectement.
    vector<vector<int>> dependants(N);

    // Pourquoi lisons-nous chaque fichier et ses inclusions ensemble ?
    // Parce que l'entrée présente les informations fichier par fichier.
    for (int i = 0; i < N; i++) {
        cin >> fichiers[i];

        // Pourquoi associons-nous le nom à son indice ?
        // Pour retrouver rapidement un fichier lors de la construction du graphe.
        indices[fichiers[i]] = i;

        int k;
        cin >> k;

        // Pourquoi répétons-nous cette lecture k fois ?
        // Parce que k représente le nombre de fichiers inclus.
        for (int j = 0; j < k; j++) {
            string nom;
            cin >> nom;

            // Pourquoi conservons-nous les noms sans construire immédiatement le graphe ?
            // Parce qu'un fichier inclus peut apparaître plus loin dans la liste.
            inclusions[i].push_back(nom);
        }
    }

    // Pourquoi construisons-nous le graphe après la lecture complète ?
    // Parce que tous les fichiers sont maintenant connus.
    for (int i = 0; i < N; i++) {

        // Pourquoi parcourons-nous les inclusions de chaque fichier ?
        // Pour établir les relations de dépendance entre les fichiers connus.
        for (const string& nom : inclusions[i]) {

            // Pourquoi vérifions-nous l'existence du nom ?
            // Parce que les fichiers externes comme cstdio doivent être ignorés.
            if (indices.find(nom) != indices.end()) {
                int indiceInclus = indices[nom];

                // Pourquoi ajoutons-nous i dans dependants[indiceInclus] ?
                // Parce que le fichier i inclut indiceInclus.
                dependants[indiceInclus].push_back(i);
            }
        }
    }

    // Pourquoi créons-nous cette lambda ?
    // Pour réutiliser le même calcul lors des questions et de la recherche du plus lourd.
    auto compterRecompilations = [&](int depart) {

        // Pourquoi utilisons-nous visited ?
        // Pour éviter de compter plusieurs fois un même fichier atteint par différents chemins.
        vector<bool> visited(N, false);

        // Pourquoi utilisons-nous une pile ?
        // Pour parcourir toutes les dépendances sans récursion.
        vector<int> pile;

        pile.push_back(depart);
        visited[depart] = true;

        int total = 0;

        // Pourquoi continuons-nous tant que la pile contient des éléments ?
        // Parce que nous devons explorer toutes les dépendances accessibles.
        while (!pile.empty()) {
            int courant = pile.back();
            pile.pop_back();

            // Pourquoi vérifions-nous l'extension .cpp ?
            // Parce que seuls les fichiers sources C++ doivent être recompilés.
            if (fichiers[courant].size() >= 4 &&
                fichiers[courant].substr(fichiers[courant].size() - 4) == ".cpp") {
                total++;
            }

            // Pourquoi parcourons-nous les dépendants du fichier courant ?
            // Pour retrouver les fichiers qui l'incluent.
            for (int suivant : dependants[courant]) {

                // Pourquoi vérifions-nous visited ?
                // Pour ne jamais traiter deux fois le même fichier.
                if (!visited[suivant]) {
                    visited[suivant] = true;
                    pile.push_back(suivant);
                }
            }
        }

        return total;
    };

    int Q;
    cin >> Q;

    // Pourquoi répétons-nous cette boucle Q fois ?
    // Parce que nous devons répondre à chaque question dans l'ordre.
    for (int i = 0; i < Q; i++) {
        string nom;
        cin >> nom;

        int indice = indices[nom];

        int resultat = compterRecompilations(indice);

        cout << nom << " " << resultat << "\n";
    }

    // Pourquoi initialisons-nous le nom à AUCUN ?
    // Parce qu'il est possible qu'aucun fichier .h ne soit présent.
    string plusLourd = "AUCUN";

    // Pourquoi utilisons-nous -1 ?
    // Pour permettre au premier en-tête, même avec un poids de zéro, d'être sélectionné.
    int maximum = -1;

    // Pourquoi parcourons-nous les fichiers une nouvelle fois ?
    // Pour déterminer quel en-tête entraîne le plus de recompilations.
    for (int i = 0; i < N; i++) {

        // Comment reconnaissons-nous un en-tête ?
        // Grâce à son extension .h.
        if (fichiers[i].size() >= 2 &&
            fichiers[i].substr(fichiers[i].size() - 2) == ".h") {

            int resultat = compterRecompilations(i);

            // Pourquoi utilisons-nous > et non >= ?
            // Pour conserver le premier en-tête en cas d'égalité.
            if (resultat > maximum) {
                maximum = resultat;
                plusLourd = fichiers[i];
            }
        }
    }

    // Pourquoi avons-nous deux possibilités d'affichage ?
    // Parce que l'énoncé impose un format particulier lorsqu'aucun .h n'existe.
    if (plusLourd == "AUCUN") {
        cout << "PLUS_LOURD AUCUN\n";
    } else {
        cout << "PLUS_LOURD " << plusLourd << " " << maximum << "\n";
    }

    return 0;
}