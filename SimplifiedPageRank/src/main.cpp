#include <iostream>
#include <iterator>
#include "AdjacencyList.h"
using namespace std;

int main()
{
    int no_of_lines, power_iterations = 0;
    std::string from, to = "";
    std::cin >> no_of_lines;
    std::cin >> power_iterations;
    AdjacencyList createdGraph;

    //Gets input
    for(int i = 0; i < no_of_lines; i++)
    {
        std::cin >> from;
        std::cin >> to;
        createdGraph.insertEdge(from, to);
    }
    //Calls the outdegrees of the graph
    createdGraph.findOutdegrees();

    //Prints out necessary info
    createdGraph.pageRank(power_iterations);
}