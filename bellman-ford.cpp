#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u,v,w;
};

vector <edge> e;
int d[1000];

int bellmanFord(int n, int s, int dst){
    int i,j,u,v,w;
    for (i=0; i<n; i++) d[i]=INT_MAX;
    d[s]=0;
    for (i=0; i<n-1; i++){
        for (j=0; j<e.size(); j++){
            u=e[j].u; v=e[j].v; w=e[j].w;
            if (d[u]!=INT_MAX && d[v]>d[u]+w)
                d[v]=d[u]+w;
        }
    }
    for (i=0; i<e.size(); i++){
        u=e[i].u; v=e[i].v;
        if (d[v]>d[u]+e[i].w){
            cout<< "Negative Cycle ase"<<endl;
            return 0;
        }
    }
    return d[dst];
}

int main(){
    int n,m,i,u,v,w,s,dst;
    cin>>n>>m;
    for (i=0; i<m; i++){
        cin>>u>>v>>w;
        edge tmp;
        tmp.u=u; tmp.v=v; tmp.w=w;
        e.push_back(tmp);
    }
    int path1,path2;
    cin>>s>>dst;
    path1=bellmanFord(n,s,dst);
    path2=bellmanFord(n,dst,s);
    cout<<min(path1,path2)<<endl;
}
