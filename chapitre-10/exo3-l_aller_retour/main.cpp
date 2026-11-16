#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Corrige les valeurs qui seraient affichees -0.00
double corrigerZero(double valeur) {
    if (abs(valeur) < 0.005) {
        return 0.0;
    }

    return valeur;
}

int main() {

    // Dimensions de la fenetre
    double W, H;
    cin >> W >> H;

    // Etat initial de la camera
    double cx = 0.0;
    double cy = 0.0;
    double zoom = 1.0;

    string commande;

    // Lecture des commandes jusqu'a la fin de l'entree
    while (cin >> commande) {

        if (commande == "VERS_MONDE") {

            double px, py;
            cin >> px >> py;

            double mx = cx + (px - W / 2.0) / zoom;
            double my = cy + (py - H / 2.0) / zoom;

            cout << fixed << setprecision(2);
            cout << "MONDE "
                 << corrigerZero(mx) << " "
                 << corrigerZero(my) << "\n";
        }

        else if (commande == "VERS_PIXEL") {

            double mx, my;
            cin >> mx >> my;

            double px = (mx - cx) * zoom + W / 2.0;
            double py = (my - cy) * zoom + H / 2.0;

            cout << fixed << setprecision(2);
            cout << "PIXEL "
                 << corrigerZero(px) << " "
                 << corrigerZero(py) << "\n";
        }

        else if (commande == "DEPLACE") {

            double dx, dy;
            cin >> dx >> dy;

            cx = cx - dx / zoom;
            cy = cy - dy / zoom;
        }

        else if (commande == "ZOOM") {

            double f, px, py;
            cin >> f >> px >> py;

            // 1. Memoriser le point du monde sous le curseur
            double ax = cx + (px - W / 2.0) / zoom;
            double ay = cy + (py - H / 2.0) / zoom;

            // 2. Modifier le zoom
            zoom = zoom * f;

            // 3. Limiter le zoom
            if (zoom < 0.02) {
                zoom = 0.02;
            }

            if (zoom > 64.0) {
                zoom = 64.0;
            }

            // 4. Recalculer le centre pour garder le point fixe
            cx = ax - (px - W / 2.0) / zoom;
            cy = ay - (py - H / 2.0) / zoom;
        }

        else if (commande == "GRILLE") {

            double m;
            cin >> m;

            double s = 1.0;

            // Agrandir le pas jusqu'a atteindre la distance minimale
            while (s * zoom < m) {
                s *= 2.0;
            }

            // Chercher un pas plus petit s'il reste suffisamment grand
            while (s * 0.5 * zoom >= m) {
                s *= 0.5;
            }

            cout << fixed << setprecision(6);
            cout << "GRILLE " << s << "\n";
        }

        else if (commande == "ORIGINE") {

            cx = 0.0;
            cy = 0.0;
            zoom = 1.0;
        }
    }

    // Affichage de l'etat final de la camera
    cout << fixed << setprecision(2);

    cout << "CENTRE "
         << corrigerZero(cx) << " "
         << corrigerZero(cy) << "\n";

    cout << "ZOOM " << zoom << "\n";

    return 0;
}