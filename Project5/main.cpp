/*
Bryant Conquest

This creates a cool thing to find the shortest distance between 2 points
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <fstream>
 
using namespace std;
 
struct Edge
{
    int source, destination, weight, time;
};
 
struct Graph
{
    int V, E;
 
    struct Edge* edge;
};
 
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
 
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
void FinalSolution(int dist[][2], int n, int destination,int maxCost)
{
    if(dist[destination][0]<=maxCost)
    {
        cout<<"\t"<<dist[destination][1]<<endl;
    }
    else
    {
        cout<<"\t0"<<endl;
    }
}
 
void BellmanFord(struct Graph* graph, int source, int destination, int maxCost)
{
    int V = graph->V;
    int E = graph->E;
    int StoreDistance[V][2];
 
    int i,j;
 
 
    for (i = 0; i < V; i++)
        StoreDistance[i][0] = INT_MAX;
 
    StoreDistance[source][0] = 0;
 
   
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
 
            int v = graph->edge[j].destination;
 
            int weight = graph->edge[j].weight;
            int time = graph->edge[j].time;
            if (StoreDistance[u][0] + weight < StoreDistance[v][0] && StoreDistance[u][0] + weight < maxCost)
                StoreDistance[v][0] = StoreDistance[u][0] + weight;
                StoreDistance[v][1] = StoreDistance[u][1] + time;
        }
    }
 
    for (i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
 
        int v = graph->edge[i].destination;
 
        int weight = graph->edge[i].weight;
        int time = graph->edge[j].time;

        if (StoreDistance[u][0] + weight < StoreDistance[v][0])
        {   
            cout<< StoreDistance[u][0] + weight << "-" <<StoreDistance[v][0]<<endl;
            cout<< u << "-" << v << endl;
            StoreDistance[v][0] = StoreDistance[u][0] + weight;
            StoreDistance[v][1] = StoreDistance[u][1] + time;
        }
    }
 
    FinalSolution(StoreDistance, V, destination, maxCost);
 
    return;
}
 
int main(int argc, char* argv[])
{
    int V,E;  //V = no.of Vertices, E = no.of Edges
 
    fstream file;
    file.open(argv[1]);

    file >> V >> E;
 
    struct Graph* graph = createGraph(V, E);    //calling the function to allocate space to these many vertices and edges
 
    int i;
    for(i=0;i<E;i++){
        file>>graph->edge[i].source;
        file>>graph->edge[i].destination;
        file>>graph->edge[i].weight;
        file>>graph->edge[i].time;
    }
 
    BellmanFord(graph, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
 
    return 0;
}