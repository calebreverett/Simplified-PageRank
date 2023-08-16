#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    v = 0;
    e = 0;
}

map<string, double> AdjacencyList::pageRank(int n){
    map<string, double> r;
    //For-loop creates first r to be multiplied with the other list
    for(auto itr = graph.begin(); itr != graph.end(); itr++){
        r[itr->first] = double(1.0 / v);
    }

    //if the n = 1, just prints out initial r
    if(n == 1){
        for(auto itr = graph.begin(); itr != graph.end(); itr++){
            double tempNum = r[itr->first];
            tempNum *= 100.0;
            tempNum = round(tempNum);
            tempNum /= 100.0;
            r[itr->first] = tempNum;
            cout << itr->first << " ";
            printf("%.2f", r[itr->first]);
            cout << "\n";
        }
        return r;
    }
    else {
        n--;
    }

    //Goes through the power iterations
    for(int i = 0; i < n; i++){
        r = powerItr(r);
    }

    //Prints out and returns
    for(auto itr = graph.begin(); itr != graph.end(); itr++){
        double tempNum = r[itr->first];
        tempNum *= 100.0;
        tempNum = round(tempNum);
        tempNum /= 100.0;
        r[itr->first] = tempNum;
        cout << itr->first << " ";
        printf("%.2f", r[itr->first]);
        cout << "\n";
    }

    return r;
} // prints the PageRank of all pages after p powerIterations in ascending alphabetical order of webpages and rounding rank to two decimal places

map<string, double> AdjacencyList::powerItr(map<string, double> r) {
    map<string, double> rFinal;

    //Multiplies the two lists together then returns the list
    for(auto itr = graph.begin(); itr != graph.end(); itr++){
        double rVal = 0.0;
        for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++){
            rVal += itr2->second * r[itr2->first];
        }
        rFinal[itr->first] = rVal;
    }

    return rFinal;
}

void AdjacencyList::insertEdge(string from, string to) {
    //Inserts edge in a backward manner, where it finds whats pointing to it (makes multiplying easier)
    if(graph.find(to) == graph.end()) {
        v++;
        graph[to] = {};
    }
    graph[to][from] =  (1.0 / v);
    if(graph.find(from) == graph.end()) {
        graph[from] = {};
        v++;
    }
    e++;
}

void AdjacencyList::findOutdegrees() {
    //Finds and sets the outdegrees of all of the pages
    for(auto itr = graph.begin(); itr != graph.end(); itr++){
        int tempNum = 0;

        //Finds the outdegree
        for(auto itr2 = graph.begin(); itr2 != graph.end(); itr2++){
            if(itr2->second.find(itr->first) != itr2->second.end()){
                tempNum++;
            }
        }

        //Sets the outdegree
        double outdegree = 0.0;
        if(tempNum != 0)
            outdegree = double(1.0 / tempNum);

        //Replaces the temp numbers to the outdegrees for all of the values that have the website
        for(auto itr2 = graph.begin(); itr2 != graph.end(); itr2++){
            if(itr2->second.find(itr->first) != itr2->second.end()){
                itr2->second[itr->first] = outdegree;
            }
        }
    }
}

//Getters (just in case)
int AdjacencyList::getV(){
    return v;
}

int AdjacencyList::getE(){
    return e;
}