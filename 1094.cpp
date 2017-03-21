//
//  1094.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/21.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 110;
vector<int> Node[maxn];
int Hash[maxn] = {0};


void DFS(int index, int level) {
    Hash[level]++;
    for(int i=0;i<Node[index].size();i++) {
        DFS(Node[index][i],level+1);
    }
}

int main() {
    int n,m,parent,k,child;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<m;i++) {
        scanf("%d%d",&parent,&k);
        for(j=0;j<k;j++) {
            scanf("%d",&child);
            Node[parent].push_back(child);
        }
    }
    DFS(1,1);
    int maxlev = -1,maxNode = -1;
    for(i=1;i<=n;i++) {
        if(Hash[i]>maxNode) {
            maxlev = i;
            maxNode = Hash[i];
        }
    }
    printf("%d %d",maxNode,maxlev);
    return 0;
}
