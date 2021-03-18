

#include <algorithm>
#include "RandomNumberGenerator.h"
#include "Schrage.h"

int main() {
    RandomNumberGenerator data(1,6);
    //data.setSeedAndSize();
    data.create();
    data.print();
    std::vector<Data> test;

    Schrage metoda;
    metoda.schrageZPrzerwaniami(data.get());

    return 0;
}
