//realizuje brut - sprawdzanie wszystkich permutacji na grafie pelnym
//przyjmuje input w formie liczba_wierzcholkow i tablica liczba_wierzcholkow x liczba_wierzcholkow gdzie komorka o indeksach i,j odpowiada kosztowi przejscia z i do
//dziala poprawnie dla symetrycznego i niesymetrycznego
//bez postojow
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
LL graph[1000][1000];
int main (int argc, char * const argv[]) {
#ifndef ONLINE_JUDGE
	if(!freopen(argc>=2 ? argv[1] :"../../tests/10496CollectingBeepers.in", "r", stdin)) cout<<"Input file not found."<<endl;
#endif
	ios_base::sync_with_stdio(0);
    int num_of_test_cases;
    cin>>num_of_test_cases;
    while(num_of_test_cases--){
        //usless - i dont use the board size info anywhere
        int x_size_of_the_board,y_size_of_the_board;
        cin>>x_size_of_the_board>>y_size_of_the_board;

        int x,y;
        cin>>x>>y;
        vector<pair<int,int> > points;
        points.PB(MP(x,y));
        int num_of_beepers;
        cin>>num_of_beepers;
        REP(num_of_beeper,num_of_beepers){
            cin>>x>>y;
            points.PB(MP(x,y));
        }
        REP(i,SIZE(points))
        REP(j,SIZE(points))
        {
            if(i==j) graph[i][j]=0;
            else graph[i][j]=abs(points[i].ST-points[j].ST)+abs(points[i].ND-points[j].ND);
        }
        LL num_of_vertices=num_of_beepers+1;
        const LL INF=1000000000; //infty
        VI vertices;
        vertices.reserve(num_of_vertices);
        REP(x,num_of_vertices) vertices.PB(x);

        LL min_cost=INF;
        while (next_permutation(ALL(vertices))) {
            LL cost=0;
            REP(index,num_of_vertices)
            if(index==num_of_vertices-1)
                cost+=graph[vertices[num_of_vertices-1]][vertices[0]];
            else
                cost+=graph[vertices[index]][vertices[index+1]];
            if(cost<min_cost)
                min_cost=cost;
        }
        cout<<"The shortest path has length "<<min_cost<<endl;
    }
    return 0;
}
