#include <bits/stdc++.h>
#define pii pair <int, int>
#define INF 1e9
using namespace std;

map <int, vector <pii> > edges;
int d[100009], visited[100009];

int prims(int n, int s){
    int v, c; pii u;
    for (int i=1; i<=n; i++)    { visited[i]=-1; d[i]=INF; }
    d[s]=0;
    priority_queue < pii, vector <pii>, greater <pii> > pq;
    pq.push(pii(0, s));
    while(!pq.empty()){
        u = pq.top(); pq.pop();
        for (int i=0; i<edges[u.second].size(); i++){
            v = edges[u.second][i].first;
            c = edges[u.second][i].second;
            if (c < d[v] && visited[v]==-1){
                d[v] = c;
                pq.push(pii(c, v));
            }
        }
        visited[u.second] = 1;
    }
}

int main(){
    int n, m, u, v, w;
    cin>>n>>m;
    for (int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges[u].push_back(pii(v, w));
        edges[v].push_back(pii(u, w));
    }
    int sum = 0;
    prims(n, 1);
    for (int i=1; i<=n; i++)
        sum += d[i];
    cout<<sum;
}
