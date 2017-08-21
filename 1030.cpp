//
//  1030.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/21.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int n,m,s,d,minC=INF;
int G[maxn][maxn],c[maxn][maxn],dis[maxn];
bool vis[maxn]={false};
vector<int> pre[maxn],path,tempPath;

void Dijkstra(int s) {
    fill(dis,dis+maxn,INF);
    dis[s] = 0;
    for(int i=0;i<n;i++) {
        int MIN = INF,u=-1;
        for(int j=0;j<n;j++) {
            if(dis[j]<MIN&&vis[j]==false) {
                MIN = dis[j];
                u = j;
            }
        }
        if(u==-1) {
            return ;
        }
        vis[u] = true;
        for(int j=0;j<n;j++) {
            if(vis[j]==false&&G[u][j]!=INF) {
                if(dis[u] + G[u][j]<dis[j]) {
                    dis[j] = dis[u] + G[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);

                } else if(dis[u] + G[u][j]==dis[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}

void dfs(int v) {
    if(v==s) {
        tempPath.push_back(v);
        int cost=0;
        for(int i=int(tempPath.size()-1);i>0;i--) {
            cost += c[tempPath[i]][tempPath[i-1]];
        }
        if(cost<minC) {
            minC = cost;
            path = tempPath;
        }
        tempPath.pop_back();
        return ;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++) {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main() {
    scanf("%d%d%d%d",&n,&m,&s,&d);
    int i,u,v;
    fill(G[0],G[0]+maxn*maxn,INF);
    fill(c[0],c[0]+maxn*maxn,INF);
    for(i=0;i<m;i++) {
        scanf("%d%d",&u,&v);
        scanf("%d%d",&G[u][v],&c[u][v]);
        G[v][u] = G[u][v];
        c[v][u] = c[u][v];
    }
    Dijkstra(s);
    dfs(d);
    for(int i=int(path.size()-1);i>=0;i--) {
        printf("%d ",path[i]);
    }
    printf("%d %d",dis[d],minC);
    return 0;
}
