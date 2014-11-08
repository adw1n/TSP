#ifndef __mst_heurestic__Tree__
#define __mst_heurestic__Tree__
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
//template<class T>
class Tree{
    vector<vector<int>> adj;
    vector<bool> visited;
    int start;
    vector<vector<int> > ans;
public:
    Tree(int size){
        adj.resize(size);
        ans.resize(size);
    }
    void addEdge(int v1,int v2){
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        cout<<"pushbacknalem "<<endl;
    }
    vector<vector<int> > dfs_all(){
        
        for( start=0; start<adj.size();start++){
            cout<<"start "<<start<< endl;
            visited=vector<bool>(adj.size(),false);
            dfs(start);
            ans[start].push_back(start);
        }
        return ans;
    }
    void dfs(int vertex){
        ans[start].push_back(vertex);
        visited[vertex]=true;
        for(vector<int>::iterator it=adj[vertex].begin(); it!=adj[vertex].end(); it++){
//            cout<<"start: "<<start<<" vertex "<<vertex <<"possible "<<*it<<endl;
            if(!visited[*it]){
                cout<<"start: "<<start<<" vertex "<<vertex <<"it "<<*it<<endl;
                dfs(*it);
            }
        }
    }
};
#endif /* defined(__mst_heurestic__Tree__) */
