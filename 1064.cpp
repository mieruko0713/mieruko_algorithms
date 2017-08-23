//
//  1064.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/22.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n,CBT[maxn],in[maxn];
int idex=1;

void inorder(int root) {
    if(root>n) {
        return ;
    }
    inorder(2*root);
    CBT[root] = in[idex++];
    inorder(2*root+1);
}

int main() {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) {
        scanf("%d",&in[i]);
    }
    sort(in+1,in+n+1);
    inorder(1);
    for(i=1;i<=n;i++) {
        printf("%d",CBT[i]);
        if(i!=n) {
            printf(" ");
        }
    }
    return 0;
}
