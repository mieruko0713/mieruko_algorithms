//
//  1064.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/7.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1100;
int num[maxn],CBT[maxn],idx=0,n;


void inOrder(int root) {
    if(root>n) {
        return ;
    }
    inOrder(root*2);
    CBT[root] = num[idx++];
    inOrder(root*2+1);
}


int main() {
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    inOrder(1);
    for(int i=1;i<=n;i++) {
        printf("%d",CBT[i]);
        if(i<n) {
            printf(" ");
        }
    }
    return 0;
}