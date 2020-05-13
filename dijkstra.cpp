#include <bits/stdc++.h>
using namespace std;

struct data {
    int node, cost;
    bool operator < (const data &p) const { return cost>p.cost; }
};

vector <int> edge[1000], cost[1000];
int d[1000]; const int inf=1000000000;

int dijkstra(int n, int src, int dst){
    int i;  data u,v;
    for (i=1; i<=n; i++)     d[i]=inf;
    u.node=src; d[src]=0; u.cost=0;
    priority_queue <data> que;
    que.push(u);
    while (!que.empty()){
        u=que.top(); que.pop();
        for (i=0; i<edge[u.node].size(); i++){
            v.node=edge[u.node][i]; v.cost=cost[u.node][i]+d[u.node];
            if (d[v.node]>v.cost){
                d[v.node]=v.cost;
                que.push(v);
            }
        }
    }
    return d[dst];
}

int main(){
    int u,v,w,i,j,n,m,src,dst;
    cin>>n>>m;
    for (i=0; i<m; i++){
        cin>>u>>v>>w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    cin>> src>> dst;
    cout<<dijkstra(n,src,dst);
}

/**
5 6
1 2 2
1 3 9
1 4 6
2 5 8
3 5 3
4 5 7
*/
