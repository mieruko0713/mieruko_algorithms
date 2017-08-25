//
//  1087.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<iostream>
using namespace std;
map<string,int> city;
const int INF = 1000000000;
map<int,string> num;
const int maxn = 210;
int happy[maxn],G[maxn][maxn],d[maxn],maxHappy=-1,maxAvg,numPath=0;
int n,k,s=0;
bool vis[maxn]={false};
vector<int> path,tempPath,pre[maxn];

void dijkstra(int s) {
    fill(d,d+maxn,INF);
    d[s] = 0;
    for(int i=0;i<n;i++) {
        int u=-1,MIN = INF;
        for(int j=0;j<n;j++) {
            if(d[j]<MIN&&vis[j]==false) {
                u=j;
                MIN = d[j];
            }
        }
        if(u==-1) return;
        vis[u] = true;
        for(int v=0;v<n;v++) {
            if(vis[v]==false&&G[u][v]!=INF) {
                if(G[u][v]+d[u]<d[v]) {
                    d[v] = G[u][v] + d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(G[u][v]+d[u]==d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v) {
    if(v==s) {
        numPath++;
        tempPath.push_back(v);
        int sum=0;
        double avg;
        for(int i=int(tempPath.size())-2;i>=0;i--) {
            sum += happy[tempPath[i]];
        }
        avg = sum*1.0 / (tempPath.size()-1);
        if(sum>maxHappy) {
            maxHappy = sum;
            path = tempPath;
            maxAvg = avg;
        } else if(sum==maxHappy) {
            if(avg>maxAvg) {
                path = tempPath;
                maxAvg = avg;
            }
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
    cin>>n;
    cin>>k;
    cin>>num[0];
    int i;
    string cityname;
    city[num[0]] = 0;
    for(i=1;i<n;i++) {
        cin >> cityname;
        cin >> happy[i];
        city[cityname] = i;
        num[i] = cityname;
    }
    fill(G[0],G[0]+maxn*maxn,INF);
    for(i=0;i<k;i++){
        string name1,name2;
        int cost;
        cin >> name1;
        cin >> name2;
        cin >> cost;
        int id1=city[name1],id2=city[name2];
        G[id1][id2] = G[id2][id1] = cost;
    }
    dijkstra(0);
    dfs(city["ROM"]);
//    printf("%d\n",d[city["ROM"]]);
    int size =int(path.size());
//    printf("%d\n",size);
    int avg = maxHappy/(size-1);
    printf("%d %d %d %d\n",numPath,d[city["ROM"]],maxHappy,avg);
    for(i=size-1;i>=0;i--) {
        cout << num[path[i]];
        if(i!=0) {
            printf("->");
        }
    }
    return 0;
}

