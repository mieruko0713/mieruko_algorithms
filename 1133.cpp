//
//  1133.cpp
//  算法
//
//  Created by 王怡凡 on 2018/2/20.
//  Copyright © 2018年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct node {
    int ad,v,next,order;
} nodes[maxn];
vector<node> ans;

bool cmp(node a, node b) {
    return a.order<b.order;
}

int main() {
    int st, n, k;
    int ad;
    scanf("%d%d%d",&st,&n,&k);
    int i,order=0;
    for(i=0;i<n;i++){
        scanf("%d", &ad);
        nodes[ad].ad = ad;
        scanf("%d%d",&nodes[ad].v,&nodes[ad].next);
    }
    int p = st;
    while(p!=-1) {
        node now = nodes[p];
        if(now.v<0) {
            now.order = order++;
            ans.push_back(now);
        } else if(now.v<=k) {
            now.order = order++ + maxn;
            ans.push_back(now);
        } else {
            now.order = order++ + 2*maxn;
            ans.push_back(now);
        }
        p = now.next;
    }
//    for(i=0;i<3;i++) {
//        for(int j=0;j<v[i].size();j++) {
//            ans.push_back(v[i][j]);
//        }
//    }
    sort(ans.begin(),ans.end(),cmp);
    for(i=0;i<ans.size()-1;i++) {
        printf("%05d %d %05d\n", ans[i].ad, ans[i].v, ans[i+1].ad);
    }
    printf("%05d %d -1\n", ans[i].ad, ans[i].v);
    return 0;
}
