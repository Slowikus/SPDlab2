

#include <algorithm>
#include "RandomNumberGenerator.h"
#include "Schrage.h"
#include "Carlier.h"

int main() {
    RandomNumberGenerator data(1,6);
    data.setSeedAndSize();
    data.create();
    data.print();
    Schrage::schrageZPrzerwaniami(data.get());

    return 0;
}
