#include <iostream>
#include <string>

using namespace std;

int main() {

    int N;
    cin >> N;

    int restants = 0;
    int changes = 0;

    for (int i = 1; i <= N; i++) {

        int id;
        double x, y, echelle, rotation, opacite;
        int miroirX, miroirY;
        int largeur, hauteur;
        int selectionne;
        string chemin;
        unsigned long long octets;

        // Lecture des treize champs de l'image
        cin >> id
            >> x >> y
            >> echelle
            >> rotation
            >> opacite
            >> miroirX >> miroirY
            >> largeur >> hauteur
            >> selectionne
            >> chemin
            >> octets;

        // Une image sans octets ne peut pas être rouverte
        if (octets == 0) {
            cout << "ITEM " << i << " SAUTE\n";
            continue;
        }

        // L'image est récupérée
        restants++;

        cout << "ITEM " << i << " " << restants;

        int changementsImage = 0;

        // Vérification de l'identifiant
        if (id != 0) {
            cout << " id";
            changementsImage++;
        }

        // Vérification de la sélection
        if (selectionne == 1) {
            cout << " selected";
            changementsImage++;
        }

        // Vérification du chemin source
        if (chemin != "-") {
            cout << " sourcePath";
            changementsImage++;
        }

        // Aucun champ n'a changé
        if (changementsImage == 0) {
            cout << " AUCUN";
        }

        cout << "\n";

        changes += changementsImage;
    }

    cout << "RESTENT " << restants << "\n";
    cout << "CHANGES " << changes << "\n";

    return 0;
}