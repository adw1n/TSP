//imput - number of vertices followed by adjacency matrix
//works both for symetric and asymetric
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
using namespace std;

typedef long long LL;
typedef vector<LL> VI;


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
//all credit goes to author of that post

//create generic class
class Graph{
    
    vector<VI > adj;//adjacency matrix
    VI parent;
    VI key;//distance to the set of chosen vertices so far
    vector<bool> visited;
    int size;
    const LL INF=1000000000; //infty
public:
    Graph(int size): size(size), adj(size,VI(size,0)),parent(size),key(size,INF),visited(size,false) {
    }
    void addEdge(int v1,int v2,int cost){
        //        if(v1<size and v2<size)
        adj[v1][v2]=cost;
        //else error
    }
    int findMinKey(){
        LL min=INF, best_vertex;
        REP(vertex,size)
        if( (!visited[vertex]) and key[vertex]<min)
            best_vertex=vertex,min=key[vertex];
        return best_vertex;
    }
    //add initializing everything - u might wanna change an edge and later ask about MST again
    void MST(){
        //        REP(x,size) key[x]=INF,visited[x]=false;
        key[0]=0;
        parent[0]=-1;
        REP(i,size-1){
            int curr_vertex=findMinKey();
            visited[curr_vertex]=true;
            REP(vertex,size)
            if(adj[curr_vertex][vertex] and visited[vertex]==false and adj[curr_vertex][vertex]<key[vertex])
                parent[vertex]=curr_vertex,key[vertex]=adj[curr_vertex][vertex];
        }
        printMST();
    }
    void printMST(){
        LL ans=0;
        //need to do dfs on graph
        FOR(vertex,1,size-1)  {
            cout<<vertex<<" "<<parent[vertex]<<" "<<endl;
            ans+=adj[parent[vertex]][vertex];
        }
        cout<<endl<<"min "<<ans<<endl;
    }
};
int main (int argc, char * const argv[]) {
#ifndef ONLINE_JUDGE
	if(!freopen("6cities_asymetric.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
	//if(!freopen("out.txt", "w", stdout)) cout<<"Blad pliku wyjsciowego"<<endl;
#endif
	ios_base::sync_with_stdio(0);
	LL num_of_vertices;
    
    cin>>num_of_vertices;
    Graph graph(num_of_vertices);
    LL cost;
    REP(row,num_of_vertices){
        REP(column, num_of_vertices){
            cin>>cost;
            graph.addEdge(row,column,cost);
        }
    }
    cout<<"WARNING! NO GUARANTEE FOR OPTIMAL SOLUTION!"<<endl;
    graph.MST();
    //    graph.printMST();
    //    FOREACH(it, vertices_order)
    //    cout<<*it<<" ";
    //    cout<<vertices_order[0];
    
    
    return 0;
}