//
//  1094.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
using namespace std;
const int maxn = 110;
vector<int> child[maxn];
int layer[maxn]={0};
int n,m,maxLayers=-1,maxId=1,maxNodes=-1,num=0;

void dfs(int index,int lay) {
    if(lay>maxLayers) {
        maxLayers = lay;
    }
    layer[lay] += 1;
    for(int i=0;i<child[index].size();i++) {
        dfs(child[index][i],lay+1);
    }
}

int main() {
    scanf("%d %d",&n,&m);
    int i;
    int k,id,v;
    for(i=0;i<m;i++) {
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++) {
            scanf("%d",&v);
            child[id].push_back(v);
        }
    }
    dfs(1,1);
    for(i=1;i<=maxLayers;i++) {
        if(layer[i]>maxNodes) {
            maxNodes = layer[i];
            maxId = i;
        }
    }
    printf("%d %d",maxNodes,maxId);
    return 0;
}
