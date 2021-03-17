

#include <algorithm>
#include "RandomNumberGenerator.h"
#include "Schrage.h"

int main() {
    RandomNumberGenerator data(1,10);
    //data.setSeedAndSize();
    data.create();
    data.print();
    std::vector<Data> test;
//    test.push_back(Data());
//    test[0].j = 1;
//    test[0].r = 1;
//    test[0].p = 2;
//    test[0].q = 5;
//    test.push_back(Data());
//    test[1].j = 2;
//    test[1].r = 2;
//    test[1].p = 3;
//    test[1].q = 4;
//    test.push_back(Data());
//    test[2].j = 3;
//    test[2].r = 8;
//    test[2].p = 1;
//    test[2].q = 6;
//    test.push_back(Data());
//    test[3].j = 4;
//    test[3].r = 7;
//    test[3].p = 2;
//    test[3].q = 3;
//    test.push_back(Data());
//    test[4].j = 5;
//    test[4].r = 6;
//    test[4].p = 3;
//    test[4].q = 7;
//    test.push_back(Data());
//    test[5].j = 6;
//    test[5].r = 4;
//    test[5].p = 4;
//    test[5].q = 1;
//    data.print(test);
    Schrage metoda;
    data.print(metoda.schrage(data.get()));



    return 0;
}
