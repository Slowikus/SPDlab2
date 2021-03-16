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

   static bool compareR(const Data &a, const Data &b){
        return a.r < b.r;
    }
    static bool compareQ(const Data &a, const Data &b){
        return a.q > b.q;
    }

    std::vector<Data> schrage(std::vector<Data> data) {
        long time =0;
        long Cmax =0;
        int count =0;
        //sortuję po czasie przygotowania
        std::sort(data.begin(), data.end(), compareR);
        //wektor g
        std::vector<Data> g;
        std::vector<Data> pi;



        g.push_back(data[0]);

        pi.push_back(data[0]);
        data.erase(data.begin());

        time += g[0].r;

        while(!g.empty() || !data.empty()) {
            while (!data.empty() && data[0].r <= time) {
                g.push_back(data[0]);
                data.erase(data.begin());
            }
            if(g.empty()){
                time = data[0].r;
            } else {
                pi[count] =
            }
        }




        return pi;
}




};


#endif //LAB2_SCHRAGE_H
