#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> ordre;

    int prochainIdentifiant = 1;

    int occasions = 0;
    int repercutes = 0;
    int recherches = 0;

    int N;
    cin >> N;

    for (int k = 0; k < N; ++k)
    {
        string commande;
        cin >> commande;

        if (commande == "AJOUTE")
        {
            ordre.push_back(prochainIdentifiant);
            ++prochainIdentifiant;
        }
        else if (commande == "SUPPRIME")
        {
            int c;
            cin >> c;

            vector<int> indices(c);

            for (int i = 0; i < c; ++i)
                cin >> indices[i];

            // Supprimer du plus grand index au plus petit.
            for (int i = c - 1; i >= 0; --i)
            {
                ordre.erase(ordre.begin() + indices[i]);
            }

            ++occasions;
            repercutes += 2 * c;
        }
        else if (commande == "MONTE")
        {
            int i;
            cin >> i;

            if (i + 1 < static_cast<int>(ordre.size()))
            {
                swap(ordre[i], ordre[i + 1]);

                ++occasions;
                repercutes += 2;
            }
        }
        else if (commande == "DESCEND")
        {
            int i;
            cin >> i;

            if (i > 0)
            {
                swap(ordre[i], ordre[i - 1]);

                ++occasions;
                repercutes += 2;
            }
        }
        else if (commande == "DESSINE")
        {
            recherches += static_cast<int>(ordre.size());
        }
    }

    cout << "ORDRE";

    if (ordre.empty())
    {
        cout << " AUCUN";
    }
    else
    {
        for (int identifiant : ordre)
            cout << " " << identifiant;
    }

    cout << '\n';
    cout << "OCCASIONS " << occasions << '\n';
    cout << "REPERCUTES " << repercutes << '\n';
    cout << "RECHERCHES " << recherches << '\n';

    return 0;
}