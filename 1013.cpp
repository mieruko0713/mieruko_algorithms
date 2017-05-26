//
//  1013.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 1111;
vector<int> G[N];
bool vis[N];

int currentPoint;
void dfs(int v) {
    if(v==currentPoint) {
        return ;
    }
    vis[v] = true;
    for(int i=0;i<G[v].size();i++) {
        if(vis[G[v][i]]==false) {
            dfs(G[v][i]);
        }
    }
}




int n,m,k,i,query;
int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++) {
        int a,b;
        scanf("%d %d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(query=0;query<k;query++) {
        scanf("%d",&currentPoint);
        memset(vis,false,sizeof(vis));
        int block = 0;
        for(i=1;i<=n;i++) {
            if(i!=currentPoint&&vis[i]==false) {
                dfs(i);
                block++;
            }
        }
        printf("%d\n",block-1);
    }
    
    return 0;
}
