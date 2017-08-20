//
//  1018.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
vector<int> pre[maxn],tempPath,path;
int G[maxn][maxn],d[maxn];
bool vis[maxn] = {false};
int cap,ed,n,m,c[maxn],minSend=INF,minBack=INF;

void dijkstra(int s) {
    fill(d,d+maxn,INF);
    d[s] = 0;
    int i,j,v;
    for(i=0;i<=n;i++) {
        int u=-1,MIN=INF;
        for(j=0;j<=n;j++) {
            if(vis[j]==false&&d[j]<MIN ) {
                u = j;
                MIN = d[j];
            }
        }
        if(u==-1) return ;
        vis[u] = true;
        for(v=0;v<=n;v++) {
            if(vis[v]==false&&G[u][v]!=INF) {
                if(d[u]+G[u][v]<d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u]+G[u][v]==d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v) {
    if(v==0) {
        tempPath.push_back(v);
        int send=0,back=0,i,all=0,stand=cap/2,remain=0;
        for(i=int(tempPath.size()-1);i>=0;i--) {
            int id = tempPath[i];
            if(c[id]>0) {
                remain += c[id];
//                printf("remain:%d",remain);
            } else {
                if(remain>=abs(c[id])) {
                    remain -= abs(c[id]);
                } else {
                    send += abs(c[id]) - remain;
                    remain = 0;
                }
            }
        }
        if(send<minSend) {
            minSend = send;
            path = tempPath;
            minBack = remain;
        } else if(send==minSend&&remain<minBack) {
            minBack = remain;
            path = tempPath;
        }
        tempPath.pop_back();
        return ;
    }
    tempPath.push_back(v);
    int i;
    for(i=0;i<pre[v].size();i++) {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}


int main() {
    int u,v,i,dis;
    scanf("%d%d%d%d",&cap,&n,&ed,&m);
    for(i=0;i<n;i++) {
        scanf("%d",&c[i+1]);
        c[i+1] -= cap/2;
    }
    fill(G[0],G[0]+maxn*maxn,INF);
    for(i=0;i<m;i++) {
        scanf("%d%d%d",&v,&u,&dis);
        G[u][v] = G[v][u] = dis;
    }
    dijkstra(0);
    dfs(ed);
    printf("%d ",minSend);
    for(i=int(path.size()-1);i>=0;i--) {
        printf("%d",path[i]);
        if(i!=0) {
            printf("->");
        }
    }
    printf(" %d",minBack);
    return 0;
}
