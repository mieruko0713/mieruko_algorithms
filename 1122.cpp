//
//  1122.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/14.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<set>
using namespace std;
const int maxn = 210;
int G[maxn][maxn];
int n,m;

bool isConnected(int n, vector<int> query){
    int u,x,y;
    for(u=0;u<n-1;u++) {
        x = query[u];
        y = query[u+1];
        if(!G[x][y]) {
//            printf("not connected\n");
            return false;
        }
    }
    return true;
}

bool isCycle(int n, vector<int> query) {
    if(query[n-1] == query[0]) {
        return true;
    }
//    printf("not cycle\n");
    return false;
}

bool isAll(vector<int> query) {
    set<int> simple(query.begin(),query.end());
    if(simple.size()==n&&n==(query.size()-1)) {
        return true;
    }
//    printf("set:%d n: %d query: %d\n", simple.size(), n, query.size()-1);
    return false;
}


int main() {
    scanf("%d%d",&n,&m);
    int i,j,v1,v2,k,v,num;
    for(i=0;i<m;i++) {
        scanf("%d%d",&v1,&v2);
        G[v1][v2] = G[v2][v1] = 1;
    }
    scanf("%d",&k);
    for(i=0;i<k;i++) {
        scanf("%d",&num);
        vector<int> query;
        for(j=0;j<num;j++) {
            scanf("%d",&v);
            query.push_back(v);
        }
        if(!isCycle(num,query)) {
            printf("NO\n");
            continue;
        }
        if(!isConnected(num,query)) {
            printf("NO\n");
            continue;
        }
        if(!isAll(query)) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }
    return 0;
}
