

#include <algorithm>
#include "RandomNumberGenerator.h"
#include "Schrage.h"

bool compareP(const Data &a, const Data &b){
    return a.p < b.p;
}
bool compareR(const Data &a, const Data &b){
    return a.r < b.r;
}
bool compareQ(const Data &a, const Data &b){
    return a.q < b.q;
}

int main() {
    RandomNumberGenerator data;
    //data.setSeedAndSize();
    data.create();
    //data.print();
    Schrage metoda;

    data.print(metoda.schrage(data.get()));



//    //test wyswietlania elementow
//    std::vector<Data> test = data.get();
//    std::sort(test.begin(), test.end(), compareP);
//    std::cout << test[1].j << std::endl;
//    //test usuwania elementów
//    data.print(test);
//    test.erase(test.begin()+2);
//    data.print(test);

    return 0;
}
