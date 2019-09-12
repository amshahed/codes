bfs.txt
Type
Text
Size
898 bytes
Storage used
898 bytes
Location
Codes
Owner
me
Modified
Aug 15, 2016 by me
Opened
Jan 20, 2019 by me
Created
Aug 15, 2016 with Google Drive Web
Add a description
Viewers can download

#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int dist[100000];
vector <int> graph[100000];

void bfs(int s){
    parent[s]=-1;
    dist[s]=0;
    queue <int> que;
    que.push(s);
    while (!que.empty()){
        int i,v,u=que.front();
        que.pop();
        for (i=0; i<graph[u].size(); i++){
            v=graph[u][i];
            if (dist[v]==-1){
                parent[v]=u;
                dist[v]=dist[u]+1;
                que.push(v);
            }
        }
    }
}

int main(){
    memset(dist,-1,sizeof(dist));
    int i,x,y,n,m;
    cin>>n>>m;
    for (i=0; i<m; i++)
    {
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (i=1; i<=n; i++){
        if (dist[i]==-1)    bfs(i);
    }
    for (i=1; i<=n; i++)
        cout<< "Distance of "<< i<< " is: "<<dist[i]<<endl;
}
