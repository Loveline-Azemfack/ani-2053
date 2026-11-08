#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Pourquoi créons-nous une structure Methode ?
// Parce que l'énoncé nous donne plusieurs informations sur chaque méthode.
// Nous devons les regrouper pour pouvoir les analyser facilement.
struct Methode {
    string nom;                 // Pourquoi conservons-nous le nom ?
                                // Parce que nous devons identifier chaque méthode
                                // et retrouver les méthodes qu'elle appelle.

    bool declareeConst;         // Pourquoi conservons-nous cette information ?
                                // Parce qu'une méthode déjà déclarée const ne doit
                                // apparaître ni dans POURRAIT ni dans RACINES.

    bool modifie;               // Pourquoi conservons-nous cette information ?
                                // Parce qu'une méthode qui modifie directement
                                // un membre de l'objet ne peut pas devenir const.

    vector<string> appels;      // Pourquoi conservons-nous les méthodes appelées ?
                                // Parce qu'une méthode ne peut devenir const que si
                                // toutes les méthodes qu'elle appelle sont const
                                // ou peuvent elles-mêmes le devenir.
};

int main() {
    int N;

    // Pourquoi lisons-nous N ?
    // Parce que la première ligne de l'entrée indique le nombre de méthodes
    // appartenant à la classe que nous devons analyser.
    cin >> N;

    // Pourquoi créons-nous un vector de N méthodes ?
    // Parce que nous devons conserver les informations de toutes les méthodes
    // avant de pouvoir étudier leurs dépendances.
    vector<Methode> methodes(N);

    // Pourquoi parcourons-nous les N méthodes ?
    // Parce que l'énoncé fournit une ligne d'informations pour chaque méthode.
    for (int i = 0; i < N; i++) {
        string declaration;
        int modification;
        int k;

        // Pourquoi lisons-nous ces quatre informations ?
        // Parce que chaque ligne contient le nom, l'état const,
        // la modification directe et le nombre de méthodes appelées.
        cin >> methodes[i].nom >> declaration >> modification >> k;

        // Pourquoi comparons-nous declaration à "const" ?
        // Parce que l'entrée utilise du texte pour indiquer si une méthode
        // est déjà const. Nous transformons cette information en booléen
        // pour faciliter les vérifications.
        methodes[i].declareeConst = (declaration == "const");

        // Pourquoi transformons-nous modification en booléen ?
        // Parce que l'entrée utilise 1 ou 0 pour indiquer si la méthode
        // modifie directement un membre de l'objet.
        methodes[i].modifie = (modification == 1);

        // Pourquoi lisons-nous k méthodes appelées ?
        // Parce que k indique combien de dépendances possède la méthode.
        // Cette information est nécessaire pour déterminer si elle peut devenir const.
        for (int j = 0; j < k; j++) {
            string appel;

            cin >> appel;

            // Pourquoi ajoutons-nous chaque nom dans appels ?
            // Parce que nous devons pouvoir vérifier ultérieurement
            // si chacune des méthodes appelées est compatible avec const.
            methodes[i].appels.push_back(appel);
        }
    }

    // Pourquoi créons-nous le tableau pourrait avec des valeurs true ?
    // Parce que nous commençons par considérer les méthodes comme potentiellement
    // admissibles, puis nous éliminons celles qui ne respectent pas les règles.
    vector<bool> pourrait(N, true);

    // Pourquoi effectuons-nous cette première vérification ?
    // Parce que l'énoncé exclut immédiatement deux catégories :
    // les méthodes déjà déclarées const et celles qui modifient directement l'objet.
    for (int i = 0; i < N; i++) {
        if (methodes[i].declareeConst || methodes[i].modifie) {
            pourrait[i] = false;
        }
    }

    // Pourquoi utilisons-nous une boucle while ?
    // Parce qu'une méthode qui ne peut pas devenir const peut empêcher
    // toutes les méthodes qui l'appellent de le devenir également.
    // Nous devons donc répéter les vérifications jusqu'à ce qu'il n'y ait plus
    // de nouvelle méthode à exclure.
    bool changement = true;

    while (changement) {
        changement = false;

        for (int i = 0; i < N; i++) {

            // Pourquoi ignorons-nous les méthodes déjà exclues ?
            // Parce qu'elles ne peuvent plus être candidates à const.
            if (!pourrait[i]) {
                continue;
            }

            // Pourquoi examinons-nous les appels de cette méthode ?
            // Parce que l'énoncé impose que toutes les méthodes appelées
            // soient déclarées const ou puissent le devenir.
            for (const string& nomAppel : methodes[i].appels) {

                for (int j = 0; j < N; j++) {

                    // Pourquoi recherchons-nous le nom de la méthode appelée ?
                    // Parce que l'entrée conserve les dépendances sous forme de noms.
                    // Nous devons retrouver la méthode correspondante pour connaître son état.
                    if (methodes[j].nom == nomAppel &&
                        !methodes[j].declareeConst &&
                        !pourrait[j]) {

                        // Pourquoi excluons-nous cette méthode ?
                        // Parce qu'elle appelle une méthode qui ne pourra jamais devenir const.
                        pourrait[i] = false;

                        // Pourquoi indiquons-nous qu'un changement a eu lieu ?
                        // Parce que cette exclusion peut entraîner celle d'autres appelants
                        // lors des prochaines vérifications.
                        changement = true;

                        break;
                    }
                }

                if (!pourrait[i]) {
                    break;
                }
            }
        }
    }

    // Pourquoi affichons-nous POURRAIT ?
    // Parce que cette liste doit contenir les méthodes qui ne sont pas encore const
    // et qui respectent toutes les conditions pour pouvoir le devenir.
    cout << "POURRAIT";

    bool aucune = true;

    for (int i = 0; i < N; i++) {
        if (pourrait[i]) {
            cout << " " << methodes[i].nom;
            aucune = false;
        }
    }

    // Pourquoi affichons-nous AUCUN lorsque la liste est vide ?
    // Parce que le format de sortie impose explicitement ce mot
    // lorsqu'aucune méthode ne peut devenir const.
    if (aucune) {
        cout << " AUCUN";
    }

    cout << '\n';

    // Pourquoi recherchons-nous les racines ?
    // Parce que l'énoncé distingue les méthodes qui peuvent devenir const
    // immédiatement de celles qui doivent attendre d'autres méthodes.
    cout << "RACINES";

    bool aucuneRacine = true;

    for (int i = 0; i < N; i++) {

        // Pourquoi ignorons-nous les méthodes qui ne sont pas dans POURRAIT ?
        // Parce qu'une racine doit obligatoirement appartenir à cette liste.
        if (!pourrait[i]) {
            continue;
        }

        // Pourquoi considérons-nous d'abord cette méthode comme une racine ?
        // Parce qu'elle peut être une racine si toutes ses dépendances
        // sont déjà déclarées const.
        bool racine = true;

        for (const string& nomAppel : methodes[i].appels) {
            for (int j = 0; j < N; j++) {

                // Pourquoi vérifions-nous declareeConst ?
                // Parce qu'une racine ne peut appeler que des méthodes
                // déjà déclarées const, et non simplement des méthodes
                // qui pourraient le devenir plus tard.
                if (methodes[j].nom == nomAppel &&
                    !methodes[j].declareeConst) {

                    racine = false;
                    break;
                }
            }

            if (!racine) {
                break;
            }
        }

        // Pourquoi affichons-nous cette méthode si racine vaut true ?
        // Parce qu'elle peut être déclarée const dès la première passe.
        if (racine) {
            cout << " " << methodes[i].nom;
            aucuneRacine = false;
        }
    }

    if (aucuneRacine) {
        cout << " AUCUN";
    }

    cout << '\n';

    // Pourquoi créons-nous dejaDeclaree ?
    // Parce que nous devons suivre l'état de chaque méthode pendant les passes.
    // Ce tableau indique si une méthode est déjà const au départ
    // ou si elle a été déclarée const pendant une passe précédente.
    vector<bool> dejaDeclaree(N, false);

    // Pourquoi initialisons-nous ce tableau avec les déclarations initiales ?
    // Parce que les méthodes déjà const sont considérées comme disponibles
    // dès le début de l'algorithme.
    for (int i = 0; i < N; i++) {
        dejaDeclaree[i] = methodes[i].declareeConst;
    }

    int passes = 0;
    int nombreRestant = 0;

    // Pourquoi comptons-nous les méthodes restantes ?
    // Parce que nous devons savoir combien de méthodes admissibles
    // attendent encore de pouvoir être déclarées const.
    for (int i = 0; i < N; i++) {
        if (pourrait[i]) {
            nombreRestant++;
        }
    }

    // Pourquoi continuons-nous tant qu'il reste des méthodes ?
    // Parce que chaque passe permet de déclarer const les méthodes
    // dont toutes les dépendances sont déjà déclarées const.
    while (nombreRestant > 0) {

        // Pourquoi créons-nous une liste temporaire aDeclarer ?
        // Parce que l'énoncé exige que les méthodes d'une même passe
        // soient déclarées const simultanément.
        // Nous devons donc les identifier toutes avant de modifier leur état.
        vector<int> aDeclarer;

        for (int i = 0; i < N; i++) {

            // Pourquoi ignorons-nous ces méthodes ?
            // Parce qu'une méthode exclue ne peut pas devenir const,
            // et qu'une méthode déjà déclarée const n'a plus besoin d'être corrigée.
            if (!pourrait[i] || dejaDeclaree[i]) {
                continue;
            }

            // Pourquoi considérons-nous d'abord que la méthode est prête ?
            // Parce que nous allons vérifier si toutes ses dépendances
            // sont déjà déclarées const.
            bool prets = true;

            for (const string& nomAppel : methodes[i].appels) {
                for (int j = 0; j < N; j++) {

                    // Pourquoi vérifions-nous dejaDeclaree ?
                    // Parce qu'une méthode appelée doit être déjà const
                    // avant que sa méthode appelante puisse l'être.
                    if (methodes[j].nom == nomAppel && !dejaDeclaree[j]) {
                        prets = false;
                        break;
                    }
                }

                if (!prets) {
                    break;
                }
            }

            // Pourquoi ajoutons-nous cette méthode dans aDeclarer ?
            // Parce que toutes les méthodes qu'elle appelle sont déjà const.
            // Elle peut donc être déclarée const pendant cette passe.
            if (prets) {
                aDeclarer.push_back(i);
            }
        }

        // Pourquoi effectuons-nous les changements seulement maintenant ?
        // Parce que toutes les méthodes de la passe doivent être traitées
        // ensemble. Aucune ne doit profiter d'une modification effectuée
        // quelques lignes plus tôt pendant la même passe.
        for (int indice : aDeclarer) {
            dejaDeclaree[indice] = true;

            // Pourquoi diminuons-nous nombreRestant ?
            // Parce que cette méthode vient d'être déclarée const.
            nombreRestant--;
        }

        // Pourquoi augmentons-nous passes ?
        // Parce que nous venons de terminer une passe de correction.
        passes++;
    }

    // Pourquoi affichons-nous PASSES ?
    // Parce que l'énoncé demande le nombre total de passes nécessaires
    // pour déclarer const toutes les méthodes de POURRAIT.
    // Si aucune méthode n'est admissible, nombreRestant vaut zéro
    // dès le départ et aucune passe n'est effectuée.
    cout << "PASSES " << passes << '\n';

    return 0;
}