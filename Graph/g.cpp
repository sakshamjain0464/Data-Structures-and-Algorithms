#include <bits/stdc++.h>

using namespace std;

class graph {
    public:
    unordered_map<int, vector<int> > adj;

    void addEdge(int from, int to, bool direction){
        adj[from].push_back(to); //Adding edge to graph from -> to

        if(!direction){
            // If it is an undirected graph, we also have to add  to->from because it is bidirectional
            adj[to].push_back(from);
        }

        cout<<"Edge added from"<<from<<"to"<<to<<endl;
    }

    void printGraph(){
        cout<<"The Graph is:"<<endl;
        for(auto i : adj){
            cout<<i.first<<": ";
            for(auto j : i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        } 

        cout<<endl;
    }
};


int main(){

    int n;
    graph g1;

    cout<<"Enter number of edges : ";
    cin>>n;

    for(int i = 0; i<n; i++){
        int from, to;
        cout<<"Enter From and to : ";
        cin>>from>>to;
        g1.addEdge(from, to, 0);
    }

    g1.printGraph();
    return 0;
}
