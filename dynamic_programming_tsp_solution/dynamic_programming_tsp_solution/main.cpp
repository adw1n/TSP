//DP O(n^2 * 2^n) solution for tsp problem
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
const int max_num_of_vertices=18;
LL graph[max_num_of_vertices][max_num_of_vertices];//graph[i][j] - cost of edge from i to j
const LL INF=1000000000; //infty
const int source=0;//home vertex, it could be any vertex
LL num_of_vertices;

LL tab[1<<max_num_of_vertices][max_num_of_vertices];
//bitmask - set of visited vertices, end - the last vertex to visit
LL solve(int bitmask,int end){
    if(tab[bitmask][end]!=-1) return tab[bitmask][end];
    tab[bitmask][end]=INF;
    REP(vertex,num_of_vertices)
    if(vertex!=end and bitmask & (1<<vertex))
        tab[bitmask][end]=min(tab[bitmask][end],
                              solve(bitmask xor (1<<end), vertex )+graph[vertex][end]);
    return tab[bitmask][end];
}
int main (int argc, char * const argv[]) {
#ifndef ONLINE_JUDGE
	if(!freopen("12cities_symetric.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
#endif
	ios_base::sync_with_stdio(0);
    
    memset(tab, -1, sizeof(tab));
    
    cin>>num_of_vertices;
	
    LL cost;
    REP(row,num_of_vertices)
    REP(column, num_of_vertices)
    {
        cin>>cost;
        if(cost<=0) cost=INF;
        graph[row][column]=cost;
    }
    
    
    REP(vertex,num_of_vertices)
    tab[1<<vertex][vertex]=graph[source][vertex];
    time_point<system_clock> start,end;
    start=system_clock::now();
    LL min_cost=solve( (1<<num_of_vertices) -1 ,source);
    end=system_clock::now();
    duration<double> elapsed_time=end-start;
    if(min_cost>=INF) cout<<"NO HAMILTON CYCLE!"<<endl;
    else{
        cout<<"min cost "<<min_cost<<endl;
        cout<<"Computed in: "<<elapsed_time.count()<<" seconds.";
    }
    return 0;
}