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
using namespace std;

typedef vector<int> VI;
typedef long long LL;

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
vector<set<pair<LL,LL> > > graph; //pair::first cost, pair::second vertex num
int main (int argc, char * const argv[]) {
#ifndef ONLINE_JUDGE
	if(!freopen("11cities_symetric.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
	//if(!freopen("out.txt", "w", stdout)) cout<<"Blad pliku wyjsciowego"<<endl;
#endif
	ios_base::sync_with_stdio(0);
	LL num_of_vertices;
    const LL INF=1000000000; //infty
    cin>>num_of_vertices;
	VI vertices_order;
    vector<bool> visited(num_of_vertices,false);//1 means that you have visited
    graph.resize(num_of_vertices);
    LL cost;
    REP(row,num_of_vertices){
        REP(column, num_of_vertices){
            cin>>cost;
            if(cost<=0) cost=INF;
            graph[row].insert(MP(cost,column));
        }
    }
    LL num_of_visited_vertices=0;
    //chosing vertex num 0 always as the starting vertex
    LL current_vertex=0;
    cost=0;
    while (num_of_visited_vertices<num_of_vertices) {
        vertices_order.PB(current_vertex);
        FOREACH(it, graph[current_vertex]){
            if(!visited[it->second]){//vertex has not been visited yet
                visited[it->second]=true;
                num_of_visited_vertices++;
                cost+=it->first;
                current_vertex=it->second;
                break;
            }
        }
    }
    
    cout<<"WARNING! NO GUARANTEE FOR OPTIMAL SOLUTION!"<<endl;
    cout<<"min cost "<<cost<<endl<<"vertices order: ";
    FOREACH(it, vertices_order)
    cout<<*it<<" ";
    cout<<vertices_order[0];
    
    
    return 0;
}