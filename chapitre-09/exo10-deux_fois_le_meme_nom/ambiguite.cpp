#include <iostream>

// Premier espace de noms
namespace a
{
    class NkEvent
    {
    public:
        void afficher()
        {
            std::cout << "Evenement du systeme" << std::endl;
        }
    };
}

// Deuxieme espace de noms
namespace b
{
    class NkEvent
    {
    public:
        void afficher()
        {
            std::cout << "Evenement de synchronisation" << std::endl;
        }
    };
}

// Les deux espaces de noms sont rendus accessibles
using namespace a;
using namespace b;

int main()
{
    // NkEvent evenement;
    // ERREUR : le compilateur ne sait pas s'il doit choisir a::NkEvent ou b::NkEvent.

    // Correction : qualification explicite des noms
    a::NkEvent evenementSysteme;
    b::NkEvent evenementSynchronisation;

    evenementSysteme.afficher();
    evenementSynchronisation.afficher();

    return 0;
}