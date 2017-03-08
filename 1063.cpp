//
//  1063.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/7.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<set>
#include<vector>
using namespace std;
const int maxn = 51;
set<int> st[maxn];

void compare(int x, int y) {
    int totalNum = st[y].size(), sameNum=0;
    for(set<int>::iterator it=st[x].begin();it!=st[x].end();it++) {
        if(st[y].find(*it)!=st[y].end()) sameNum++;
        else totalNum++;
    }
    printf("%.1f%%\n",sameNum*100.0/totalNum);
}

int main() {
    int n,m,k,q,v,s1,s2,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            scanf("%d",&v);
            st[i].insert(v);
        }
    }
    scanf("%d",&q);
    for(i=0;i<q;i++) {
        scanf("%d%d",&s1,&s2);
        compare(s1,s2);
    }
    return 0;
}