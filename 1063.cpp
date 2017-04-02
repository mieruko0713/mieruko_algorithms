//
//  1063.cpp
//  算法
//
//  Created by 王怡凡 on 2017/4/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<set>
using namespace std;

const int maxn = 60;
set<int> st[maxn];
int n,m;


void compare(int query1, int query2) {
    int same=0,all=st[query1].size();
    for(set<int>::iterator it=st[query2].begin();it!=st[query2].end();it++) {
        if(st[query1].find(*it)!=st[query1].end()) {
            same++;
        } else {
            all++;
        }
    }
//    printf("same:%d\n",same);
//    printf("all:%d\n",all);
    printf("%.1f%%\n",same*100.0/all);
}

int main() {
    scanf("%d",&n);
    int i,j,data,k,query1,query2;
    for(i=1;i<=n;i++) {
        scanf("%d",&m);
        for(j=0;j<m;j++) {
            scanf("%d",&data);
            st[i].insert(data);
        }
    }
    scanf("%d",&k);
    for(i=0;i<k;i++) {
        scanf("%d%d",&query1,&query2);
        compare(query1,query2);
    }
    return 0;
}
