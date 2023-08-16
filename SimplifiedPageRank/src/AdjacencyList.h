//
// Created by Caleb Everett on 10/24/22.
//

#ifndef SIMPLIFIEDPAGERANK_ADJACENCYLIST_H
#define SIMPLIFIEDPAGERANK_ADJACENCYLIST_H

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <iterator>
using namespace std;


class AdjacencyList {
private:
    //Necessary variables
    map<string, map<string, double>> graph;
    int v;
    int e;
public:
    AdjacencyList();

    int getV();

    int getE();

    map<string, double> pageRank(int n);

    map<string, double> powerItr(map<string, double> r);

    void insertEdge(string from, string to);

    void findOutdegrees();
    //Necessary functions
};

#endif //SIMPLIFIEDPAGERANK_ADJACENCYLIST_H
