//
//  1126.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/14.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
using namespace std;
const int maxn = 510;
int degree[maxn];
vector<int> G[maxn];
int n,m,cnt=0;
bool visit[maxn] = {false};

void dfs(int index) {
    visit[index] = true;
    cnt++;
    for(int i=0;i<G[index].size();i++) {
        if(visit[G[index][i]] == false) {
            dfs(G[index][i]);
        }
    }
}

int main() {
    int i,v1,v2,num=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++) {
        scanf("%d %d",&v1,&v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
        degree[v1]++;
        degree[v2]++;
    }
    bool e = true;
    for(i=1;i<=n;i++) {
        printf("%d",degree[i]);
        if(i!=n) {
            printf(" ");
        } else {
            printf("\n");
        }
        if(degree[i]%2!=0) {
            e = false;
            num++;
        }
    }
    dfs(1);
    if(cnt!=n) {
        printf("Non-Eulerian");
        return 0;
    }
    if(e) {
        printf("Eulerian");
    } else if(!e&&num==2) {
        printf("Semi-Eulerian");
    } else {
        printf("Non-Eulerian");
    }
    return 0;
}
