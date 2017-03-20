//
//  1087.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

const int maxn = 210;
const int INF = 100000000;
int G[maxn][maxn],w[maxn],d[maxn];
int numPath = 0,maxW=-1,maxAvg=-1;
int n,k;
bool vis[maxn] = {false};
vector<int> tempPath,path,pre[maxn];
map<int,string> iToS;
map<string, int> sToI;

void Dijkstra(int s) {
    fill(d,d+maxn,INF);
    d[s] = 0;
    int i;
    for(i=0;i<n;i++) {
        int u=-1,MIN=INF,j;
        for(j=0;j<n;j++) {
            if(vis[j]==false&&d[j]<MIN) {
                u=j;
                MIN = d[j];
            }
        }
        if(u==-1) return;
        vis[u] = true;
        int v;
        for(v=0;v<n;v++) {
            if(vis[v]==false&&G[u][v]!=INF) {
                if(G[u][v]+d[u] < d[v]) {
                    d[v] = G[u][v]+d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(G[u][v]+d[u]==d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v) {
    if(v==0) {
        tempPath.push_back(v);
        numPath++;
        int tempW = 0;
        for(int i=tempPath.size()-1;i>=0;i--) {
            int id = tempPath[i];
            tempW += w[id];
        }
        
        double tempAvg = 1.0*tempW/(tempPath.size()-1);
//        printf("size:%d\n",tempPath.size()-1);
//        printf("avg:%lf\n",tempAvg);
        if(tempW>maxW) {
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        } else if(tempW == maxW&&tempAvg>maxAvg) {
            maxAvg = tempAvg;
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
    string start,c1,c2;
    cin >> n >> k >>start;
    iToS[0] = start;
    int i;
    for(i=1;i<n;i++) {
        cin >> c1 >> w[i];
        sToI[c1] = i;
        iToS[i] = c1;
    }
    fill(G[0],G[0]+maxn*maxn,INF);
    for(i=0;i<k;i++) {
        cin >> c1 >> c2;
        int id1 = sToI[c1],id2=sToI[c2];
        cin >> G[id1][id2];
        G[id2][id1] = G[id1][id2];
    }
    Dijkstra(0);
    DFS(sToI["ROM"]);
    printf("%d %d %d %d\n",numPath,d[sToI["ROM"]],maxW,maxAvg);
    for(i=path.size()-1;i>=0;i--) {
        cout << iToS[path[i]];
        if(i!=0) cout << "->";
    }
    return 0;
}

