#include <iostream>
#include <string>

using namespace std;

int main()
{
    int v, N;
    cin >> v >> N;

    bool space = false;
    bool left = false;
    bool right = false;

    int xe = 0;
    int xi = 0;

    int sautsEvenements = 0;
    int sautsInterrogation = 0;
    int manques = 0;

    for (int i = 1; i <= N; i++)
    {
        int k;
        cin >> k;

        bool appuiSpace = false;

        for (int j = 0; j < k; j++)
        {
            string evenement;
            cin >> evenement;

            if (evenement == "+SPACE")
            {
                space = true;
                sautsEvenements++;
                appuiSpace = true;
            }
            else if (evenement == "-SPACE")
            {
                space = false;
            }
            else if (evenement == "+RIGHT")
            {
                right = true;
                xe += v;
            }
            else if (evenement == "-RIGHT")
            {
                right = false;
            }
            else if (evenement == "+LEFT")
            {
                left = true;
                xe -= v;
            }
            else if (evenement == "-LEFT")
            {
                left = false;
            }
        }

        if (appuiSpace && !space)
        {
            manques++;
        }

        if (space)
        {
            sautsInterrogation++;
        }

        if (right)
        {
            xi += v;
        }

        if (left)
        {
            xi -= v;
        }

        cout << i << " " << xe << " " << xi << "\n";
    }

    cout << "SAUTS EVENEMENTS " << sautsEvenements << "\n";
    cout << "SAUTS INTERROGATION " << sautsInterrogation << "\n";
    cout << "MANQUES " << manques << "\n";

    return 0;
}