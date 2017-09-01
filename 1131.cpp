//
//  1131.cpp
//  算法
//
//  Created by 王怡凡 on 2017/9/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 10010;
const int INF = 1000000000;
int line[maxn][maxn],n,mintrans=INF,minnum=INF;
vector<int> sta[maxn],tempPath,path;
bool vis[maxn];

void dfs(int st, int ed) {
    if(st==ed) {
        tempPath.push_back(st);
        int trans = 0, num=int(tempPath.size()-1);
        for(int i=1;i<tempPath.size()-1;i++) {
            if(line[tempPath[i]][tempPath[i-1]]!=line[tempPath[i]][tempPath[i+1]]) {
                trans++;
            }
        }
        if(num<minnum) {
            minnum = num;
            path = tempPath;
            mintrans = trans;
        } else if(num==minnum){
            if(trans<mintrans) {
                mintrans = trans;
                path = tempPath;
            }
        }
        tempPath.pop_back();
        return ;
    }
    vis[st] = true;
    tempPath.push_back(st);
    for(int i=0;i<sta[st].size();i++) {
        if(!vis[sta[st][i]]) {
            dfs(sta[st][i],ed);
        }
    }
    vis[st] = false;
    tempPath.pop_back();
}

int main() {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) {
        int k,v,u;
        scanf("%d %d",&k,&v);
        for(int j=1;j<k;j++) {
            scanf("%d",&u);
            line[u][v] = line[v][u] = i;
            sta[u].push_back(v);
            sta[v].push_back(u);
            v=u;
        }
    }
    int query,st,ed;
    scanf("%d",&query);
    for(i=0;i<query;i++) {
        scanf("%d%d",&st,&ed);
        mintrans=INF,minnum=INF;
        memset(vis,false,sizeof(vis));
        dfs(st,ed);
        printf("%d\n",minnum);
        for(int j=0;j<path.size()-1;j++) {
            if(j==0) {
                printf("Take Line#%d from %04d to ",line[path[j]][path[j+1]],path[j]);
            } else if(line[path[j]][path[j-1]]!=line[path[j+1]][path[j]]){
                printf("%04d.\n",path[j]);
                printf("Take Line#%d from %04d to ",line[path[j]][path[j+1]],path[j]);
            }
        }
        printf("%04d.\n",ed);
    }
    
}
