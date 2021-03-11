
#include <iostream>
#include <stdlib.h>
#include "RandomNumberGenerator.h"

typedef struct {
    int j=0;
    int p=0; //czas wykonania
    int r=0; //czas przygotowania
} dane;

int compare (const void * a, const void * b)
{

    dane *daneA = (dane *)a;
    dane *daneB = (dane *)b;

    return ( daneA->r - daneB->r );
}

int main() {
    int seed = 0;
    std::cout << "Podaj seed:";
    std::cin >> seed;
    std::cout << std::endl;

    RandomNumberGenerator generator(seed);
    dane wart[10];
    int suma = 0;
    int test = 0;

    //generuję czasy wykoanania
    for (int i = 0; i < 10; ++i) {
        wart[i].j = i+1;
        wart[i].p = generator.nextInt(1,29);
        suma += wart[i].p;
    }
    //generuję czasy przygotowania
    for (int i = 0; i <10 ; ++i) {
        wart[i].r = generator.nextInt(1,suma);
        test += wart[i].r;
    }

    //wypisanie tabeli
    std::cout << "Wygenerowane Dane" << std::endl;
    std::cout << "j:  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << i+1 << "  ";
    }
    std::cout << std::endl;
    std::cout << "r:  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << wart[i].r << "  ";
    }
    std::cout << std::endl;
    std::cout << "p:  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << wart[i].p << "  ";
    }
    std::cout << std::endl;
    std::cout <<"/////////////////////////////////////" <<  std::endl;


    //sortuję po czasie przygotowania
    qsort(wart,10,sizeof(dane), compare);


    int czasWykonania = 0;

    //dodaje proces z najkrótszym czasem przygotowania
    czasWykonania = wart[0].r + wart[0].p;
    for (int i = 1; i < 10; ++i) {
        if(czasWykonania > wart[i].r) {
            czasWykonania += wart[i].p;
        } else {
            czasWykonania += (wart[i].r - czasWykonania + wart[i].p);
        }
    }


    //wypisanie tabeli
    std::cout << "Dane poszeregowane w optymalnej kolejnosci" << std::endl;
    std::cout << "j  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << wart[i].j << "  ";
    }
    std::cout << std::endl;
    std::cout << "r  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << wart[i].r << "  ";
    }
    std::cout << std::endl;
    std::cout << "p  ";
    for (int i = 0; i < 10; ++i) {
        std::cout << wart[i].p << "  ";
    }
    std::cout << std::endl;
    std::cout <<"/////////////////////////////////////" <<  std::endl;


    std::cout << "Czas minimalny wykonania zadan: "<< czasWykonania << std::endl;
    //std::cout << suma << std::endl;


    return 0;
}
