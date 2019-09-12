#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<pair<int, pii> > edges;
int parent[100008];

int find(int v){
    return (parent[v]==v) ? v : find(parent[v]);
}

int kruskal(int n){
    int u, v, sum = 0;
    for (int i=1; i<=n; i++)    parent[i] = i;
    sort(edges.begin(), edges.end());
    for (vector<pair<int, pii> >::iterator it=edges.begin(); it!=edges.end(); it++){
        u = find(it->second.first);
        v = find(it->second.second);
        if (u!=v){
            parent[v] = u;
            sum += it->first;
        }
    }
    return sum;
}

int main(){
    int n, m, u, v, w;
    cin>>n>>m;
    for (int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges.push_back({w, {u, v}});
    }
    cout<<kruskal(n);
}

/*
sample input:
7 11
1 2 7
1 4 5
2 3 8
2 5 7
2 4 9
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
sample output:
39
*/

