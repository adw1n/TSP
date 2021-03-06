//imput - number of vertices followed by adjacency matrix
//works only for symetric
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <numeric>
#include <utility>
#include <map>
#include <cmath>
#include <functional>
#include <tuple>
#include <cassert>
#include <chrono>

#include "Tree.h"
using namespace std;
using namespace chrono;
typedef vector<int> VI;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
//kinda implemented http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
//all credit goes to the author of that post or Prim
template<class T>
class Graph{
    vector<vector<T> > adj;//adjacency matrix
    VI parent;
    vector<T> key;//distance to the set of chosen vertices so far
    vector<bool> visited;
    int size;
    const int INF=1000000000; //infty
    Tree tree;
public:
    Graph(int size): size(size), adj(size,vector<T>(size,0)),tree(size) {
    }
    void addEdge(int v1,int v2,int cost){
        assert(v1<size and v2<size);
        adj[v1][v2]=cost;
    }
    int findMinKey(){
        int min=INF, best_vertex=-1;
        REP(vertex,size)
        if( (!visited[vertex]) and key[vertex]<min)
            best_vertex=vertex,min=key[vertex];
        return best_vertex;
    }
    void init(){
        parent=VI(size,0);
        key=vector<T>(size,INF);
        visited=vector<bool>(size,false);
    }
    pair<T,vector<int>> MST(){
        init();
        key[0]=0;
        parent[0]=-1;
        REP(i,size-1){
            int curr_vertex=findMinKey();
            visited[curr_vertex]=true;
            REP(vertex,size)
            if(adj[curr_vertex][vertex] and visited[vertex]==false and adj[curr_vertex][vertex]<key[vertex])
                parent[vertex]=curr_vertex,key[vertex]=adj[curr_vertex][vertex];
        }
        FOR(vertex,1,size-1)
            tree.addEdge(parent[vertex], vertex);

        vector<vector<int> > possible_traversals=tree.dfs_all();
        int best_start=0;
        T min=INF;
        REP(start,SIZE(possible_traversals)){
            T poss_min=0;
//            cout<<"start: "<<start<<endl;
            REP(vertex,SIZE(possible_traversals[start])){
//                cout<<possible_traversals[start][vertex]<<" ";
                poss_min+=adj[possible_traversals[start][vertex]][possible_traversals[start][vertex+1]];
            }
            if(poss_min<min){
                min=poss_min;
                best_start=start;
            }
//            cout<<"mozliwa wart min: "<<poss_min<<endl;
        }
        return make_pair(min,possible_traversals[best_start]);
    }

};
int main (int argc, char * const argv[]) {
	if(!freopen(argc>=2 ? argv[1] :"../../tests/12cities_symmetric.txt", "r", stdin)) cout<<"Input file not found."<<endl;

	ios_base::sync_with_stdio(0);
    time_point<system_clock> start,end;
    start=system_clock::now();
	int num_of_vertices;

    cin>>num_of_vertices;
    Graph<int> graph(num_of_vertices);
    int cost;
    REP(row,num_of_vertices){
        REP(column, num_of_vertices){
            cin>>cost;
            graph.addEdge(row,column,cost);
        }
    }

    auto ans=graph.MST();
    end=system_clock::now();
    duration<double> elapsed_time=end-start;
    cout<<"WARNING! NO GUARANTEE FOR OPTIMAL SOLUTION!"<<endl;
    cout<<"Optimal tour length found by mst heuristics: "<<ans.ST <<endl;
    cout<<"Computed in: "<<elapsed_time.count()<<" seconds."<<endl;
//    cout<<"Do you want to see the optimal tour? (yes/no)";
//    string odp;
//    cin>>odp;
//    if(odp=="Yes" or odp=="yes" or odp=="y" or odp=="YES")
    {
    cout<<"Optimal tour found by MST heuristics: ";
    FOREACH(it, ans.ND)
    cout<<*it<<" ";
    cout<<endl;
    }
    return 0;
}
