#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

int main() {
    
    random_device rd;
    mt19937 gen(rd());

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int V, E;
    fin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        fin >> edges[i].u >> edges[i].v;
    }

    int vertices = V;   

    while (vertices > 2) {
    
        uniform_int_distribution<> dist(0, edges.size() - 1);
        int i = dist(gen);

        int u = edges[i].u;
        int v = edges[i].v;

        for (auto &e : edges) {
            if (e.u == v) e.u = u;
            if (e.v == v) e.v = u;
        }

        
        vector<Edge> newEdges;
        for (auto &e : edges) {
            if (e.u != e.v)
                newEdges.push_back(e);
        }

        edges = newEdges;
        vertices--;
    }

   
    for (auto &e : edges) {
        fout << e.u << " " << e.v << "\n";
    }

    fin.close();
    fout.close();
cout<<edges.size()<<endl;
    return 0;
}