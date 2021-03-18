

#include <algorithm>
#include "RandomNumberGenerator.h"
#include "Schrage.h"

int main() {
    RandomNumberGenerator data(1451,10);
    //data.setSeedAndSize();
    data.create();
    data.print();
    std::vector<Data> test;

    Schrage metoda;
    metoda.schrageZPrzerwaniami(data.get());

    return 0;
}
