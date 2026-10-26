#include <NKCanvas/App/NkCanvasApp.h>
#include <NKWindow/NKMain.h>
#include <NKCanvas/Renderer/Targets/NkRenderWindow.h>

#include <cstdint>
#include <fstream>
#include <iostream>

using namespace nkentseu;
using namespace renderer;

// Paramètres à modifier pour les différentes mesures.
constexpr int32 CADENCE = 0;
constexpr bool JOURNAL_ACTIF = false;

class Sonde : public NkCanvasApp
{
private:
    uint64_t compteur = 0;
    bool mesureTerminee = false;

public:
    Sonde()
    {
        Config().title = "Exercice 6 - La sonde qui compte";
        Config().width = 800;
        Config().height = 600;
        Config().clearColor = NkColor2D{30, 30, 30, 255};

        Config().imagesParSeconde = CADENCE;
    }

    bool OnInit() override
    {
        compteur = 0;
        mesureTerminee = false;

        return true;
    }

    void OnRender(NkRenderWindow& target) override
    {
        if (mesureTerminee)
        {
            return;
        }

        ++compteur;

        const float32 temps = Time();

        // Ligne de journal : à désactiver pour les deux dernières mesures.
        if (JOURNAL_ACTIF)
        {
            std::cout
                << "Passage : " << compteur
                << " | Temps : " << temps << " s"
                << std::endl;
        }

        if (temps >= 10.0f)
        {
            std::ofstream fichier(
                "sonde_resultat.txt",
                std::ios::app
            );

            if (fichier.is_open())
            {
                fichier
                    << "Cadence : " << CADENCE
                    << " | Journal : "
                    << (JOURNAL_ACTIF ? "oui" : "non")
                    << " | Compte : " << compteur
                    << " | Temps : " << temps
                    << " s" << '\n';

                fichier.close();
            }
            else
            {
                std::cerr
                    << "Impossible d'ecrire le fichier de resultat."
                    << std::endl;
            }

            std::cout
                << "Mesure terminee. Compte : "
                << compteur
                << " | Temps : " << temps
                << " s" << std::endl;

            mesureTerminee = true;
            Quit();
        }
    }
};

int nkmain(const NkEntryState& state)
{
    return NkCanvasApp::Run<Sonde>(state);
}