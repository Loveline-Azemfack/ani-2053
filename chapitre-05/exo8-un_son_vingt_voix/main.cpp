#include <iostream>
#include <string>

int main() {

    int D, C, t, j = 0;
    std::cin >> D >> C;

    int N;
    std::cin >> N;

    int VOIX_MAX = 0;
    int RETARD_MAX = 0;
    int COUPES = 0;

    // Enregistrer les instants de lecture.
    int temps[1000];

    for (int i = 0; i < N; i++) {
        std::cin >> temps[i];
    }

    // Mémoriser la fin du chargement précédent.
    int fin_chargement = 0;

    // Traiter chaque lecture.
    for (int i = 0; i < N; i++) {

        t = temps[i];

        // Compter les voix encore actives.
        int voix = 0;

        for (int j = 0; j <= i; j++) {
            if (temps[j] + D > t) {
                voix++;
            }
        }

        // Mettre à jour le nombre maximal de voix.
        if (voix > VOIX_MAX) {
            VOIX_MAX = voix;
        }

        // Calculer le début du chargement.
        int debut_chargement = t;

        if (fin_chargement > debut_chargement) {
            debut_chargement = fin_chargement;
        }

        // Calculer la fin du chargement et le retard.
        fin_chargement = debut_chargement + C;
        int retard = fin_chargement - t;

        // Mettre à jour le retard maximal.
        if (retard > RETARD_MAX) {
            RETARD_MAX = retard;
        }

        // Déterminer si la lecture sera coupée.
        std::string etat = "ENTIER";

        if (i + 1 < N && temps[i + 1] < t + D) {
            etat = "COUPE";
            COUPES++;
        }

        // Afficher les informations de cette lecture.
        std::cout << t << " "<< voix << " "<< retard << " "<< etat << std::endl;
    }

    // Afficher les bilans.
    std::cout << "VOIX_MAX " << VOIX_MAX << std::endl;
    std::cout << "RETARD_MAX " << RETARD_MAX << std::endl;
    std::cout << "COUPES " << COUPES << std::endl;

    return 0;
}