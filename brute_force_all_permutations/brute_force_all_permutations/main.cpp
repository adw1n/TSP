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
LL graph[1000][1000];
int main (int argc, char * const argv[]) {
#ifndef ONLINE_JUDGE
	if(!freopen("10cities_symmetric.txt", "r", stdin)) cout<<"Blad odczytu in.txt"<<endl;
	//if(!freopen("out.txt", "w", stdout)) cout<<"Blad pliku wyjsciowego"<<endl;
#endif
	ios_base::sync_with_stdio(0);
    time_point<system_clock> start,end;
    start=system_clock::now();
	LL num_of_vertices;
    const LL INF=1000000000; //infty
    cin>>num_of_vertices;
	VI vertices;
    vertices.reserve(num_of_vertices);
    REP(x,num_of_vertices) vertices.PB(x);
    LL cost;
    REP(row,num_of_vertices)
    REP(column, num_of_vertices)
    {
        cin>>cost;
        if(cost<=0) cost=INF;//u might want to change this, in some cases
        graph[row][column]=cost;
    }
    VI best_vertices_order;
    LL min_cost=INF;
    
    //does SIZE(ALL(vertices))! permutations = num_of_vertices!
    while (next_permutation(ALL(vertices))) {
        //calculate the cost
        LL cost=0;
        REP(index,num_of_vertices){
            if(index==num_of_vertices-1){
                cost+=graph[vertices[num_of_vertices-1]][vertices[0]];
            }
            else{
                cost+=graph[vertices[index]][vertices[index+1]];
            }
        }
        if(cost<min_cost)
            best_vertices_order=vertices,min_cost=cost;
    }
    end=system_clock::now();
    duration<double> elapsed_time=end-start;
    if(min_cost>=INF) cout<<"NO HAMILTON CYCLE!"<<endl;
    else{
        cout<<"Computed in: "<<elapsed_time.count()<<" seconds."<<endl;
        cout<<"min cost "<<min_cost<<endl<<"vertices order: ";
        FOREACH(it, best_vertices_order)
            cout<<*it<<" ";
        cout<<best_vertices_order[0]<<endl;
    }
    return 0;
}