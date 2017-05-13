//
//  1004.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/13.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 110;
int leaf[maxn],maxh=0;
vector<int> level[maxn];

void DFS(int index, int h) {
    maxh = max(h,maxh);
    if(level[index].size()==0) {
        leaf[h]++;
        return ;
    }
    for(int i=0;i<level[index].size();i++) {
        DFS(level[index][i],h+1);
    }
}

int main() {
    int n,m,k,parent,child;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<m;i++) {
        scanf("%d%d",&parent,&k);
        for(j=0;j<k;j++) {
            scanf("%d",&child);
            level[parent].push_back(child);
        }
    }
    DFS(1,0);
    for(i=0;i<=maxh;i++) {
        printf("%d",leaf[i]);
        if(i!=maxh) {
            printf(" ");
        }
    }
    return 0;
}
