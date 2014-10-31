//DP O(n^2 * 2^n) solution for problem uva 10496 Collecting Beepers
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
typedef int LL;

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

int tab[1<<max_num_of_vertices][max_num_of_vertices];
//bitmask - set of visited vertices, end - the last vertex to visit
int solve(int bitmask,int end){
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
	if(!freopen("10496CollectingBeepers.in", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
#endif
	ios_base::sync_with_stdio(0);
    int num_of_test_cases;
    cin>>num_of_test_cases;
    while(num_of_test_cases--){
        memset(tab, -1, sizeof(tab));
        
        int x_size_of_the_board,y_size_of_the_board;
        cin>>x_size_of_the_board>>y_size_of_the_board;//usless - i don't use the board size info anywhere
        
        int x,y;
        cin>>x>>y;
        vector<pair<int,int> > points;
        points.PB(MP(x,y));
        int num_of_beepers;
        cin>>num_of_beepers;
        num_of_vertices=num_of_beepers+1;
        REP(num_of_beeper,num_of_beepers){
            cin>>x>>y;
            points.PB(MP(x,y));
        }
        REP(i,SIZE(points))
        REP(j,SIZE(points))
        {
            if(i==j) graph[i][j]=0;
            //Manhattan distance
            else graph[i][j]=abs(points[i].ST-points[j].ST)+abs(points[i].ND-points[j].ND);
        }
       
        REP(vertex,num_of_vertices)
            tab[1<<vertex][vertex]=graph[source][vertex];
        
        cout<<"The shortest path has length "<<solve( (1<<num_of_vertices) -1 ,source)<<endl;
    }
    return 0;
}