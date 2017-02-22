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
#include <chrono>

using namespace std;
using namespace chrono;
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
vector<VI > tab;

int main (int argc, char * const argv[]) {
	if(!freopen(argc>=2 ? argv[1] : "../../tests/50cities_asymmetric.txt", "r", stdin)) cout<<"Input file not found."<<endl;
    ios_base::sync_with_stdio(0);
    time_point<system_clock> start,end;
    start=system_clock::now();	LL num_of_vertices;
    const LL INF=1000000000; //infty
    cin>>num_of_vertices;
	VI vertices_order;
    vector<bool> visited(num_of_vertices,false);
    graph.resize(num_of_vertices);
    tab.resize(num_of_vertices,VI(num_of_vertices,0));

    LL cost;
//    O(num_of_vertices^2*log(num_of_vertices)) this loops
    REP(row,num_of_vertices){
        REP(column, num_of_vertices){
            cin>>cost;
            if(cost<=0) cost=INF;
            graph[row].insert(MP(cost,column));
            tab[row][column]=cost;
        }
    }
    LL num_of_visited_vertices=0;
    LL min_cost=100000000001;
    VI best_order;
    //try all vertices as the starting point
    REP(starting_vertex,num_of_vertices){
        int current_vertex=starting_vertex;
        num_of_visited_vertices=1;
        cost =0;
        visited=vector<bool>(num_of_vertices,false);
        vertices_order.clear();
        vertices_order.PB(current_vertex);
        visited[current_vertex]=true;

        while (num_of_visited_vertices<num_of_vertices) {

            FOREACH(it, graph[current_vertex]){
                if(!visited[it->second]){
                    visited[it->second]=true;
                    num_of_visited_vertices++;
                    cost+=it->first;
                    current_vertex=it->second;
                    break;
                }
            }
            vertices_order.PB(current_vertex);
        }
        cost+=tab[vertices_order[0]][vertices_order[SIZE(vertices_order)-1]];
        vertices_order.PB(vertices_order[0]);
        if(cost<min_cost){
            best_order=vertices_order;
            min_cost=cost;
        }
    }
    end=system_clock::now();
    duration<double> elapsed_time=end-start;
    cout<<"WARNING! NO GUARANTEE FOR OPTIMAL SOLUTION! ALGORITHM: repetitive nearest neighbour"<<endl;
    cout<<"Computed in: "<<elapsed_time.count()<<" seconds."<<endl;

    cout<<"min cost "<<min_cost<<endl<<"vertices order: ";
    FOREACH(it, best_order)
    cout<<*it<<" ";
		cout<<endl;



    return 0;
}
