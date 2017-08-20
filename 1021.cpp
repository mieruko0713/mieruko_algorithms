//
//  1021.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<set>
using namespace std;
int n,num=0,maxDepth=-1;
const int maxn = 10010;
vector<int> tree[maxn];;
bool vis[maxn] = {false};
bool visit[maxn] = {false};

void dfs(int root) {
    int i;
    vis[root] = true;
    for(i=0;i<tree[root].size();i++) {
        if(vis[tree[root][i]]==false) {
            dfs(tree[root][i]);
        }
        
    }
}


void DFSTrave(int root) {
    int i;
    for(i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i);
            num++;
        }
    }
}

void DFSDepth(int root, int depth,vector<int> &a) {
    if(tree[root].size()==1&&visit[tree[root][0]]) {
        if(maxDepth<depth) {
            maxDepth = depth;
            a.clear();
            a.push_back(root);
        } else if(depth == maxDepth) {
            a.push_back(root);
        }
        return;
    }
    visit[root] = true;
    for(int i=0;i<tree[root].size();i++) {
        if(!visit[tree[root][i]]) {
            DFSDepth(tree[root][i],depth+1,a);
        }
    }
    visit[root] = false;
}


int main() {
    scanf("%d",&n);
    if(n<=0) {
        return 0;
    }
    int i,v,u;
    for(i=0;i<n-1;i++) {
        scanf("%d%d",&v,&u);
        tree[v].push_back(u);
        tree[u].push_back(v);
    }
    DFSTrave(1);
    if(num>1) {
        printf("Error: %d components",num);
        return 0;
    }
    vector<int> a,b;
    DFSDepth(1,1,a);
    DFSDepth(a[0],1,b);
    set<int> res;
    for(i=0;i<a.size();i++) {
        res.insert(a[i]);
    }
    for(i=0;i<b.size();i++) {
        res.insert(b[i]);
    }
    for(auto j=res.begin();j!=res.end();j++) {
        printf("%d\n",*j);
    }
    return 0;
}
