//
//  1079.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100010;
struct node {
    int data;
    vector<int> child;
}Node[maxn];
int n;
double p, r, ans=0;

void DFS(int index, int depth) {
    if(Node[index].child.size()==0) {
        ans += Node[index].data * pow(1+r,depth)*p;
        return ;
    }
    int i;
    for(i=0;i<Node[index].child.size();i++) {
        DFS(Node[index].child[i],depth+1);
    }
}

int main() {
    scanf("%d%lf%lf",&n,&p,&r);
    r = r / 100;
    int i,k,j,id;
    for(i=0;i<n;i++) {
        scanf("%d",&k);
        if(k==0) {
            scanf("%d",&Node[i].data);
            continue;
        }
        for(j=0;j<k;j++) {
            scanf("%d",&id);
            Node[i].child.push_back(id);
        }
    }
    DFS(0,0);
    printf("%.1lf",ans);
    return 0;
}
