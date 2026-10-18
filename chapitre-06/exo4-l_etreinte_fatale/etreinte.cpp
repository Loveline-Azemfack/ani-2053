#include <iostream>
#include <NKThreading/NkThread.h>
#include <NKThreading/NkMutex.h>
#include <NKThreading/NkScopedLock.h>
#include <NKTime/NkChrono.h>

using namespace nkentseu;
using namespace nkentseu::threading;
using namespace nkentseu::time;

/*
VERSION INITIALE QUI SE BLOQUE

int main()
{
    NkMutex m1;
    NkMutex m2;

    NkThread a([&m1, &m2](void*)
    {
        NkScopedLock<NkMutex> verrou1(m1);
        NkChrono::SleepMilliseconds(100);
        NkScopedLock<NkMutex> verrou2(m2);
    });

    NkThread b([&m1, &m2](void*)
    {
        NkScopedLock<NkMutex> verrou1(m2);
        NkChrono::SleepMilliseconds(100);
        NkScopedLock<NkMutex> verrou2(m1);
    });

    a.Join();
    b.Join();

    return 0;
}

Explication :
Le fil A prend m1 puis attend m2.
Le fil B prend m2 puis attend m1.
Chaque fil attend un verrou détenu par l'autre :
le programme se bloque.
*/

/*
CORRECTION :
Les deux fils prennent les verrous dans le même ordre :
m1, puis m2.
*/

int main()
{
    NkMutex m1;
    NkMutex m2;

    NkThread a([&m1, &m2](void*)
    {
        std::cout << "Fil A : tentative de prise de m1" << std::endl;
        nkentseu::threading::NkScopedLock<NkMutex> verrou1(m1);
        std::cout << "Fil A : m1 obtenu" << std::endl;

        NkChrono::SleepMilliseconds(100);

        std::cout << "Fil A : tentative de prise de m2" << std::endl;
        nkentseu::threading::NkScopedLock<NkMutex> verrou2(m2);
        std::cout << "Fil A : m2 obtenu" << std::endl;
    });

    NkThread b([&m1, &m2](void*)
    {
        std::cout << "Fil B : tentative de prise de m1" << std::endl;
        nkentseu::threading::NkScopedLock<NkMutex> verrou1(m1);
        std::cout << "Fil B : m1 obtenu" << std::endl;

        NkChrono::SleepMilliseconds(100);

        std::cout << "Fil B : tentative de prise de m2" << std::endl;
        nkentseu::threading::NkScopedLock<NkMutex> verrou2(m2);
        std::cout << "Fil B : m2 obtenu" << std::endl;
    });

    std::cout << "Attente de la fin des deux fils..." << std::endl;

    a.Join();
    b.Join();

    std::cout << "Les deux fils ont termine." << std::endl;

    return 0;
}