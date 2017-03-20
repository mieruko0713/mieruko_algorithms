//
//  1018.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/19.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn=510;
const int INF = 1000000000;
int G[maxn][maxn],d[maxn],w[maxn];
vector<int> pre[maxn];
vector<int> tempPath, path;
bool vis[maxn] =  {false};
int c,n,sp,m,minNeed=INF,minRemain=INF;

void Dijkstra(int s) {
    int i,j;
    fill(d,d+maxn,INF);
    d[s] = 0;
    for(i=0;i<=n;i++) {
        int MIN=INF,u=-1;
        for(j=0;j<=n;j++) {
            if(d[j]<MIN&&vis[j]==false) {
                u=j;
                MIN = d[j];
            }
        }
        if(u==-1) return;
        vis[u] = true;
        for(int v=0;v<=n;v++) {
            if(G[u][v]!=INF&&vis[v]==false) {
                if(G[u][v]+d[u]<d[v]){
                    d[v] = G[u][v]+d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u]+G[u][v]==d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if(v==0) {
        tempPath.push_back(v);
        int need=0,remain=0;
        for(int i=tempPath.size()-1;i>=0;i--) {
            int id = tempPath[i];
            if(w[id]>0) {
                remain+=w[id];
            } else {
                if(remain>abs(w[id])) {
                    remain -= abs(w[id]);
                } else {
                    need += abs(w[id]) - remain;
                    remain=0;
                }
            }
        }
        if(need<minNeed) {
            minNeed = need;
            minRemain = remain;
            path = tempPath;
        } else if(need==minNeed&&remain<minRemain) {
            minRemain = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return ;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main() {
    scanf("%d %d %d %d",&c,&n,&sp,&m);
    int i,u,v;
    fill(G[0],G[0]+maxn*maxn,INF);
    for(i=1;i<=n;i++) {
        scanf("%d",&w[i]);
        w[i] -= c/2;
    }
    for(i=0;i<m;i++) {
        scanf("%d%d",&u,&v);
        scanf("%d",&G[v][u]);
        G[u][v] = G[v][u];
    }
    Dijkstra(0);
    DFS(sp);
    printf("%d ",minNeed);
    for(int i=path.size()-1;i>=0;i--) {
        printf("%d",path[i]);
        if(i>0) printf("->");
    }
    printf(" %d",minRemain);
    return 0;
}
