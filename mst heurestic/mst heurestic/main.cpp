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
using namespace std;

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
//all credit goes to the author of that post
template<class T>
class Graph{
    vector<vector<T> > adj;//adjacency matrix
    VI parent;
    vector<T> key;//distance to the set of chosen vertices so far
    vector<bool> visited;
    int size;
    const int INF=1000000000; //infty
public:
    Graph(int size): size(size), adj(size,vector<T>(size,0)) {
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
    T MST(){
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
        T ans=0;
        FOR(vertex,1,size-1)  {
            ans+=adj[parent[vertex]][vertex];
        }
        return ans;
    }

};
int main (int argc, char * const argv[]) {
#ifndef ONLINE_JUDGE
	if(!freopen("12cities_symetric.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
	//if(!freopen("out.txt", "w", stdout)) cout<<"Blad pliku wyjsciowego"<<endl;
#endif
	ios_base::sync_with_stdio(0);
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
    cout<<"WARNING! NO GUARANTEE FOR OPTIMAL SOLUTION!"<<endl;
    int ans=graph.MST();
    cout<<ans<<"<=optimal tour length<="<<2*ans <<endl;
    return 0;
}