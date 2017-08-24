//
//  1079.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100010;
double ans = 0;
int n;
double price,per;

struct Node {
    double data;
    vector<int> child;
}node[maxn];

void dfs(int index, int dep) {
    if(node[index].child.size()==0) {
        ans += node[index].data * price*pow(1+per,dep);
        return ;
    }
    for(int i=0;i<node[index].child.size();i++) {
        dfs(node[index].child[i],dep+1);
    }
}

int main() {
    int child;
    scanf("%d %lf %lf",&n,&price,&per);
    per = per /100;
    int i;
    for(i=0;i<n;i++) {
        int k;
        scanf("%d",&k);
        if(k==0) {
            scanf("%lf",&node[i].data);
            continue;
        }
        for(int j=0;j<k;j++) {
            scanf("%d",&child);
            node[i].child.push_back(child);
        }
    }
    dfs(0,0);
    printf("%.1f",ans);
}
