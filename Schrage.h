//
// Created by Slowikus on 11.03.2021.
//
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <queue>
#include "Data.h"
#include "RandomNumberGenerator.h"


#ifndef LAB2_SCHRAGE_H
#define LAB2_SCHRAGE_H

//klasa zawierająca implementacje algorytmu Schrage.
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

    //funkcja przyjmująca wektor procesów i szeregująca go w optymalny sposób algorytmrm
    //Schrage. Zwraca wektor procesów w optymalnej koljenosci.
    std::vector<Data> schrage(std::vector<Data> data) {
        long time =0;
        int cmax = 0;

        //sortuję po czasie przygotowania
        std::sort(data.begin(), data.end(), compareR);
        //wektor g
        std::vector<Data> g;
        //
        //wektor wyjsciowy, optymlan kolejnosc
        std::vector<Data> pi;

        time += data[0].r;



        while(!g.empty() || !data.empty()) {
            while (!data.empty() && data[0].r <= time) {
                g.push_back(data[0]);
                data.erase(data.begin());
            }
            if (!g.empty()) {
                std::sort(g.begin(), g.end(), compareQ);
                pi.push_back(g[0]);
                time += g[0].p;
                cmax = fmax(cmax, time+g[0].q);
                g.erase(g.begin());
            } else {
                time = data[0].r;
            }
        }
        std::cout << cmax << std::endl;
        return pi;
}
    //algorytm schrage z przerwaniami, nic nie zwraca, wypisuje kolejnosc
    void schrageZPrzerwaniami(std::vector<Data> data) {
        long time =0;
        int cmax = 0;

        //sortuję po czasie przygotowania
        std::sort(data.begin(), data.end(), compareR);
        //kolejka g
        std::priority_queue<Data, std::vector<Data>, compareQforQueue> g;
        //wektor wyjsciowy, optymlan kolejnosc


        time += data[0].r;

        std::cout <<"Kolejnosc wykonania procesow: [ ";

        while(!g.empty() || !data.empty()) {
            while (!data.empty() && data[0].r <= time) {
                g.push(data[0]);
                data.erase(data.begin());

            }
            if (!g.empty()) {
                //wypisuję numer kolejnego zadania do wykonania
                std::cout << g.top().j << " ";
                time += g.top().p;
                Data h = g.top();
                g.pop();
                //////////////////////////////////////////////////////////// dodatek do przerwan
                while (!data.empty() && data[0].r <= time) {
                    g.push(data[0]);
                    data.erase(data.begin());
                }
                if (!g.empty()) {
                    if (g.top().q > h.q) {
                       // std::cout << g.top().j << std::endl;
                        h.p = time - g.top().r;
                        time -= h.p;
                        g.push(h);
                    } else {
                        cmax = fmax(cmax, time + (h.q));
                    }
                /////////////////////////////////////////////////////////////
                } else {
                    cmax = fmax(cmax, time + (h.q));
                }

            } else {
                time = data[0].r;
            }
        }
        std::cout <<" ]" << std::endl;
        std::cout <<"Cmax: " << cmax << std::endl;

    }

};


#endif //LAB2_SCHRAGE_H
