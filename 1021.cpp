//
//  1021.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/29.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 100010;
int n,maxdep;
vector<int> G[maxn],a,b;
set<int> ans;
bool vis[maxn] = {false};

void dfs(int index) {
    vis[index] = true;
    for(int i=0;i<G[index].size();i++) {
        if(vis[G[index][i]]==false) {
            dfs(G[index][i]);
        }
    }
}

int DFSTrave() {
    int num=0;
    for(int i=1;i<=n;i++) {
        if(vis[i]==false) {
            dfs(i);
            num++;
        }
    }
    return num;
}

void dfs_deep(int index, int dep,vector<int> &vi) {
    if(dep>maxdep) {
        maxdep = dep;
        vi.clear();
        vi.push_back(index);
//        printf("%d\n",maxdep);
    } else if(dep==maxdep) {
        vi.push_back(index);
    }
    vis[index] = true;
    for(int i=0;i<G[index].size();i++){
        if(vis[G[index][i]]==false) {
            dfs_deep(G[index][i],dep+1,vi);
        }
    }
}

int main() {
    scanf("%d",&n);
    int i,u,v;
    for(i=0;i<n-1;i++) {
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int num = DFSTrave();
    if(num>1) {
        printf("Error: %d components\n",num);
    } else {
        memset(vis,false,sizeof(vis));
        maxdep = 0;
        dfs_deep(1,0,a);
        memset(vis,false,sizeof(vis));
        dfs_deep(a[0],0,b);
        for(i=0;i<a.size();i++) {
            ans.insert(a[i]);
        }
        for(i=0;i<b.size();i++) {
            ans.insert(b[i]);
        }
        for(auto it=ans.begin();it!=ans.end();it++) {
            printf("%d\n",*it);
        }
    }
}
