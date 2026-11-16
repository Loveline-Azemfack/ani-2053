#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Configuration
{
    bool textures = false;
    bool sources = false;
};

Configuration lireConfiguration(const string& ligne)
{
    Configuration config;
    istringstream flux(ligne);

    string operation;
    string tableau;

    flux >> operation;

    while (flux >> tableau)
    {
        if (tableau == "textures")
            config.textures = true;
        else if (tableau == "sources")
            config.sources = true;
    }

    return config;
}

void ajouter(vector<string>& tableau, const string& nom)
{
    tableau.push_back(nom);
}

void supprimer(vector<string>& tableau, const vector<int>& indices)
{
    for (int k = static_cast<int>(indices.size()) - 1; k >= 0; --k)
    {
        int index = indices[k];

        if (index >= 0 && index < static_cast<int>(tableau.size()))
            tableau.erase(tableau.begin() + index);
    }
}

void echanger(vector<string>& tableau, int i, int j)
{
    if (i >= 0 && j >= 0 &&
        i < static_cast<int>(tableau.size()) &&
        j < static_cast<int>(tableau.size()))
    {
        swap(tableau[i], tableau[j]);
    }
}

int main()
{
    vector<string> modele;
    vector<string> textures;
    vector<string> sources;

    string ligne;

    getline(cin, ligne);
    Configuration configAjout = lireConfiguration(ligne);

    getline(cin, ligne);
    Configuration configSuppression = lireConfiguration(ligne);

    getline(cin, ligne);
    Configuration configEchange = lireConfiguration(ligne);

    int N;
    cin >> N;

    // Exécuter exactement N opérations.
    for (int k = 0; k < N; ++k)
    {
        string commande;
        cin >> commande;

        if (commande == "AJOUTE")
        {
            string nom;
            cin >> nom;

            ajouter(modele, nom);

            if (configAjout.textures)
                ajouter(textures, nom);

            if (configAjout.sources)
                ajouter(sources, nom);
        }
        else if (commande == "SUPPRIME")
        {
            int c;
            cin >> c;

            vector<int> indices(c);

            for (int j = 0; j < c; ++j)
                cin >> indices[j];

            supprimer(modele, indices);

            if (configSuppression.textures)
                supprimer(textures, indices);

            if (configSuppression.sources)
                supprimer(sources, indices);
        }
        else if (commande == "MONTE")
        {
            int i;
            cin >> i;

            if (i + 1 < static_cast<int>(modele.size()))
            {
                echanger(modele, i, i + 1);

                if (configEchange.textures)
                    echanger(textures, i, i + 1);

                if (configEchange.sources)
                    echanger(sources, i, i + 1);
            }
        }
        else if (commande == "DESCEND")
        {
            int i;
            cin >> i;

            if (i > 0)
            {
                echanger(modele, i, i - 1);

                if (configEchange.textures)
                    echanger(textures, i, i - 1);

                if (configEchange.sources)
                    echanger(sources, i, i - 1);
            }
        }
    }

    size_t longueur = max(
        modele.size(),
        max(textures.size(), sources.size())
    );

    int decales = 0;

    for (size_t i = 0; i < longueur; ++i)
    {
        string m = i < modele.size() ? modele[i] : "-";
        string t = i < textures.size() ? textures[i] : "-";
        string s = i < sources.size() ? sources[i] : "-";

        cout << i << " " << m << " " << t << " " << s << '\n';

        if (m != t || m != s)
            ++decales;
    }

    cout << "DECALES " << decales << '\n';

    return 0;
}