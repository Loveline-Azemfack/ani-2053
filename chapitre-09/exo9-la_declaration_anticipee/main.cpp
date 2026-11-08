#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int U;
    cin >> U;

    // Pourquoi créons-nous une map ?
    // Pour associer chaque type à sa décision et pouvoir retrouver cette décision rapidement.
    unordered_map<string, bool> types;

    // Pourquoi créons-nous un vector de strings ?
    // Pour conserver les types dans leur ordre de première apparition.
    vector<string> ordre;

    // Pourquoi utilisons-nous un booléen pour chaque type ?
    // Parce que false signifie ANTICIPER et true signifie INCLURE.

    // Pourquoi lisons-nous U emplois ?
    // Parce que chaque ligne nous apporte une information supplémentaire sur l'utilisation d'un type.
    for (int i = 0; i < U; i++) {
        string nom;
        string emploi;

        cin >> nom >> emploi;

        // Pourquoi vérifions-nous si le type existe déjà ?
        // Pour ne l'ajouter dans notre ordre qu'à sa première apparition.
        if (types.find(nom) == types.end()) {
            types[nom] = false;
            ordre.push_back(nom);
        }

        // Pourquoi recherchons-nous les emplois qui nécessitent une définition complète ?
        // Parce qu'un seul emploi exigeant la définition suffit pour imposer INCLURE.
        if (emploi == "VALEUR" ||
            emploi == "BASE" ||
            emploi == "CORPS" ||
            emploi == "TAILLE") {

            // Pourquoi attribuons-nous true au type ?
            // Parce que sa définition complète est nécessaire.
            types[nom] = true;
        }
    }

    // Pourquoi lisons-nous A ?
    // Parce qu'il représente le nombre de types actuellement inclus dans cet en-tête.
    int A;
    cin >> A;

    // Pourquoi utilisons-nous un unordered_set ?
    // Pour retrouver rapidement les types actuellement inclus
    // et éviter de compter deux fois un même type.
    unordered_set<string> inclus;

    // Pourquoi répétons-nous cette lecture A fois ?
    // Parce que chaque lecture correspond à une inclusion actuelle.
    for (int i = 0; i < A; i++) {
        string nom;
        cin >> nom;

        inclus.insert(nom);
    }

    // Pourquoi initialisons-nous ces compteurs à zéro ?
    // Parce qu'aucun type n'a encore été classé.
    int nombreInclure = 0;
    int nombreAnticiper = 0;
    int inclusionsRetirees = 0;

    // Pourquoi parcourons-nous le vector ordre ?
    // Pour afficher les types dans leur ordre de première apparition.
    for (const string& nom : ordre) {

        // Pourquoi vérifions-nous la valeur associée au type ?
        // Parce qu'elle nous indique si sa définition complète est nécessaire.
        if (types[nom]) {

            cout << nom << " INCLURE\n";

            // Pourquoi augmentons-nous nombreInclure ?
            // Parce que ce type nécessite obligatoirement son inclusion.
            nombreInclure++;

        } else {

            cout << nom << " ANTICIPER\n";

            // Pourquoi augmentons-nous nombreAnticiper ?
            // Parce qu'une déclaration anticipée suffit pour ce type.
            nombreAnticiper++;

            // Pourquoi vérifions-nous également inclus ?
            // Parce qu'une inclusion ne peut être retirée que si elle existe déjà.
            if (inclus.find(nom) != inclus.end()) {

                // Pourquoi augmentons-nous inclusionsRetirees ?
                // Parce que ce type est actuellement inclus alors qu'une déclaration anticipée suffit.
                inclusionsRetirees++;
            }
        }
    }

    // Pourquoi affichons-nous ces trois compteurs ?
    // Parce que l'énoncé demande le nombre de types à inclure,
    // le nombre de types à anticiper et le nombre d'inclusions pouvant être retirées.
    cout << "INCLURE " << nombreInclure << "\n";
    cout << "ANTICIPER " << nombreAnticiper << "\n";
    cout << "INCLUSIONS_RETIREES " << inclusionsRetirees << "\n";

    return 0;
}