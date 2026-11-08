#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Pourquoi créons-nous une structure Variable ?
// Parce que chaque variable du programme doit conserver
// l'objet qu'elle possède actuellement, ou indiquer qu'elle est nulle.
struct Variable {
    string nom;

    // Pourquoi utilisons-nous un entier pour représenter l'objet possédé ?
    // Parce que chaque objet possède un numéro unique.
    // La valeur -1 signifie que la variable ne possède aucun objet.
    int objet;
};

int main() {

    // Pourquoi lisons-nous N ?
    // Parce que l'énoncé nous indique exactement combien
    // de lignes d'instructions nous devons rejouer.
    int N;
    cin >> N;

    // Pourquoi créons-nous ces deux vecteurs ?
    // Parce que nous devons mémoriser toutes les variables rencontrées
    // et conserver leur ordre de première apparition.
    vector<Variable> variables;

    // Pourquoi créons-nous un compteur d'objets ?
    // Parce que chaque instruction NEW crée un nouvel objet
    // qui doit recevoir un numéro unique.
    int nombreObjets = 0;

    // Pourquoi comptons-nous les objets détruits ?
    // Parce que le bilan final doit indiquer combien d'objets
    // ont effectivement été détruits.
    int nombreDetruits = 0;

    // Pourquoi comptons-nous les utilisations nulles ?
    // Parce que chaque instruction USE sur une variable nulle
    // doit être signalée et comptabilisée.
    int nombreNuls = 0;

    // Pourquoi créons-nous un vecteur pour les destructions ?
    // Parce que nous devons mémoriser l'ordre exact dans lequel
    // les objets meurent afin de pouvoir afficher le résultat.
    vector<int> destructions;

    // Pourquoi créons-nous un vecteur pour les lignes COPY ?
    // Parce que si une seule copie existe, nous devons refuser
    // tout le programme avant d'afficher les autres événements.
    vector<int> copies;

    // Pourquoi créons-nous une fonction de recherche sous forme de lambda ?
    // Parce que plusieurs instructions utilisent le nom d'une variable.
    // Cette recherche nous évite de répéter le même parcours.
    auto rechercherVariable = [&](string nom) {

        // Pourquoi parcourons-nous toutes les variables ?
        // Parce que nous devons vérifier si ce nom a déjà été rencontré.
        for (int i = 0; i < (int)variables.size(); i++) {

            if (variables[i].nom == nom) {
                return i;
            }
        }

        // Pourquoi retournons-nous -1 ?
        // Parce que cette valeur indique que la variable
        // n'existe pas encore dans notre liste.
        return -1;
    };

    // Pourquoi utilisons-nous une boucle de N répétitions ?
    // Parce que l'entrée contient exactement N instructions.
    for (int ligne = 1; ligne <= N; ligne++) {

        string commande;
        cin >> commande;

        // Pourquoi traitons-nous COPY en premier ?
        // Parce qu'une seule instruction COPY suffit à rendre
        // tout le programme invalide.
        // Nous devons donc mémoriser ces lignes avant tout affichage.
        if (commande == "COPY") {

            string source, destination;
            cin >> source >> destination;

            copies.push_back(ligne);
        }

        // Pourquoi traitons-nous NEW ?
        // Parce que cette instruction crée un nouvel objet
        // et le fait posséder par une variable.
        else if (commande == "NEW") {

            string nom;
            cin >> nom;

            // Pourquoi recherchons-nous la variable ?
            // Parce qu'elle peut déjà posséder un objet
            // qui devra être détruit avant de recevoir le nouveau.
            int indice = rechercherVariable(nom);

            // Pourquoi créons-nous la variable si elle n'existe pas ?
            // Parce que l'énoncé précise qu'une variable jamais vue
            // existe déjà et qu'elle est initialement nulle.
            if (indice == -1) {

                variables.push_back({nom, -1});

                indice = (int)variables.size() - 1;
            }

            // Pourquoi incrémentons-nous le compteur d'objets ?
            // Parce que chaque instruction NEW crée un nouvel objet
            // dont le numéro suit l'ordre de création.
            nombreObjets++;

            // Pourquoi vérifions-nous si la variable possède déjà un objet ?
            // Parce que l'arrivée d'un nouvel objet provoque
            // la destruction de l'ancien objet possédé.
            if (variables[indice].objet != -1) {

                destructions.push_back(variables[indice].objet);

                nombreDetruits++;
            }

            // Pourquoi attribuons-nous le nouveau numéro à la variable ?
            // Parce qu'après NEW, elle doit posséder le nouvel objet créé.
            variables[indice].objet = nombreObjets;
        }

        // Pourquoi traitons-nous MOVE ?
        // Parce que cette instruction transfère la possession
        // d'un objet d'une variable vers une autre.
        else if (commande == "MOVE") {

            string source, destination;
            cin >> source >> destination;

            // Pourquoi recherchons-nous les deux variables ?
            // Parce que nous devons connaître l'objet possédé
            // par la source et celui possédé par la destination.
            int indiceSource = rechercherVariable(source);
            int indiceDestination = rechercherVariable(destination);

            // Pourquoi créons-nous les variables absentes ?
            // Parce que toute variable jamais rencontrée
            // existe initialement à l'état nul.
            if (indiceSource == -1) {

                variables.push_back({source, -1});

                indiceSource = (int)variables.size() - 1;
            }

            if (indiceDestination == -1) {

                variables.push_back({destination, -1});

                indiceDestination = (int)variables.size() - 1;
            }

            // Pourquoi récupérons-nous l'objet de la source ?
            // Parce que nous devons conserver temporairement sa valeur
            // avant de vider la variable source.
            int objetTransfere = variables[indiceSource].objet;

            // Pourquoi rendons-nous la source nulle ?
            // Parce qu'un déplacement transfère la possession :
            // la source ne doit plus posséder l'objet après MOVE.
            variables[indiceSource].objet = -1;

            // Pourquoi vérifions-nous si la destination possède déjà un objet ?
            // Parce que recevoir un nouvel objet détruit
            // l'ancien objet que la destination possédait.
            if (variables[indiceDestination].objet != -1) {

                destructions.push_back(variables[indiceDestination].objet);

                nombreDetruits++;
            }

            // Pourquoi attribuons-nous l'objet transféré à la destination ?
            // Parce que MOVE donne à la destination la possession
            // de l'ancien objet de la source, même si celui-ci est nul.
            variables[indiceDestination].objet = objetTransfere;
        }

        // Pourquoi traitons-nous RESET ?
        // Parce que cette instruction demande à une variable
        // de libérer immédiatement l'objet qu'elle possède.
        else if (commande == "RESET") {

            string nom;
            cin >> nom;

            // Pourquoi recherchons-nous la variable ?
            // Parce que nous devons connaître l'objet qu'elle possède.
            int indice = rechercherVariable(nom);

            // Pourquoi créons-nous une variable absente ?
            // Parce qu'une variable jamais vue est considérée comme nulle.
            if (indice == -1) {

                variables.push_back({nom, -1});

                indice = (int)variables.size() - 1;
            }

            // Pourquoi vérifions-nous si elle possède un objet ?
            // Parce que RESET sur une variable nulle
            // ne doit provoquer aucune destruction.
            if (variables[indice].objet != -1) {

                destructions.push_back(variables[indice].objet);

                nombreDetruits++;

                // Pourquoi remettons-nous la variable à -1 ?
                // Parce qu'après RESET, elle ne possède plus aucun objet.
                variables[indice].objet = -1;
            }
        }

        // Pourquoi traitons-nous USE ?
        // Parce que cette instruction vérifie si une variable
        // possède encore un objet utilisable.
        else if (commande == "USE") {

            string nom;
            cin >> nom;

            // Pourquoi recherchons-nous la variable ?
            // Parce que nous devons vérifier son état actuel.
            int indice = rechercherVariable(nom);

            // Pourquoi créons-nous la variable si elle est inconnue ?
            // Parce qu'une variable jamais vue est initialement nulle.
            if (indice == -1) {

                variables.push_back({nom, -1});

                indice = (int)variables.size() - 1;
            }

            // Pourquoi vérifions-nous si son objet vaut -1 ?
            // Parce que -1 représente une variable qui ne possède rien.
            if (variables[indice].objet == -1) {

                // Pourquoi comptabilisons-nous cette utilisation ?
                // Parce que l'énoncé demande de compter
                // toutes les utilisations effectuées sur une variable nulle.
                nombreNuls++;

                // Pourquoi affichons-nous NUL avec le numéro de ligne ?
                // Parce que nous devons identifier précisément
                // l'instruction USE qui a rencontré une variable nulle.
                cout << "NUL " << ligne << " " << nom << '\n';
            }
        }
    }

    // Pourquoi vérifions-nous les copies après la lecture complète ?
    // Parce que le programme doit être refusé entièrement
    // dès qu'une instruction COPY apparaît.
    if (!copies.empty()) {

        // Pourquoi affichons-nous uniquement les lignes COPY ?
        // Parce que l'énoncé interdit tout affichage de destruction
        // ou d'utilisation nulle lorsque le programme est refusé.
        for (int ligne : copies) {

            cout << "REFUSE " << ligne << '\n';
        }

        return 0;
    }

    // Pourquoi parcourons-nous les variables à l'envers ?
    // Parce que l'énoncé impose de détruire les variables
    // dans l'ordre inverse de leur première apparition.
    for (int i = (int)variables.size() - 1; i >= 0; i--) {

        // Pourquoi vérifions-nous si la variable possède encore un objet ?
        // Parce qu'une variable nulle ne peut détruire aucun objet.
        if (variables[i].objet != -1) {

            destructions.push_back(variables[i].objet);

            nombreDetruits++;

            // Pourquoi remettons-nous la variable à -1 ?
            // Parce que son objet vient d'être détruit.
            variables[i].objet = -1;
        }
    }

    // Pourquoi affichons-nous les destructions mémorisées ?
    // Parce que nous devons présenter les événements dans leur ordre réel,
    // y compris ceux qui se sont produits pendant les instructions.
    for (int objet : destructions) {

        cout << "DETRUIT " << objet << '\n';
    }

    // Pourquoi affichons-nous le nombre d'objets créés ?
    // Parce que chaque instruction NEW a créé exactement un objet.
    cout << "CREES " << nombreObjets << '\n';

    // Pourquoi affichons-nous le nombre d'objets détruits ?
    // Parce que nous devons vérifier combien d'objets ont effectivement
    // été libérés pendant les instructions et à la fin du programme.
    cout << "DETRUITS " << nombreDetruits << '\n';

    // Pourquoi affichons-nous le nombre d'utilisations nulles ?
    // Parce que ce compteur représente le nombre de USE
    // effectués sur des variables ne possédant aucun objet.
    cout << "NULS " << nombreNuls << '\n';

    return 0;
}