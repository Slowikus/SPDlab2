//
// Created by Slowikus on 11.03.2021.
//
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include "Data.h"
#include "RandomNumberGenerator.h"


#ifndef LAB2_SCHRAGE_H
#define LAB2_SCHRAGE_H


class Schrage {
private:

public:

    //sortuje od najmniejszego do najwiekszego po r
   static bool compareR(const Data &a, const Data &b){
        return a.r < b.r;
    }
    //sortuje od najwiekszego do najmniejszego po q
    static bool compareQ(const Data &a, const Data &b){
        return a.q > b.q;
    }

    std::vector<Data> schrage(std::vector<Data> data) {
        long time =0;
        int cmax = 0;

        //sortuję po czasie przygotowania
        std::sort(data.begin(), data.end(), compareR);
        //wektor g
        std::vector<Data> g;
        //wektor wyjsciowy, optymlan kolejnosc
        std::vector<Data> pi;

        time += data[0].r;


        //std::cout << "DUPA" << std::endl;
        while(!g.empty() || !data.empty()) {
            while (!data.empty() && data[0].r <= time) {

                g.push_back(data[0]);
                data.erase(data.begin());
            }
            if (!g.empty()) {

                std::sort(g.begin(), g.end(), compareQ);
                pi.push_back(g[0]);
                cmax = fmax(cmax, time+g[0].q);
                g.erase(g.begin());
                time += pi[0].p;

            } else {

                time = data[0].r;
            }

        }
        std::cout << cmax << std::endl;
        return pi;
}


};


#endif //LAB2_SCHRAGE_H
