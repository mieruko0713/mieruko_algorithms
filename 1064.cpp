//
//  1064.cpp
//  算法
//
//  Created by 王怡凡 on 2017/4/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int n,number[maxn],CBT[maxn];
int idx=0;

void inOrder(int root) {
    if(root>n) {
        return;
    }
    inOrder(root*2);
    CBT[root] = number[idx++];
    inOrder(root*2+1);
}

int main() {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) {
        scanf("%d",&number[i]);
    }
    sort(number,number+n);
    inOrder(1);
    for(i=1;i<=n-1;i++){
        printf("%d ",CBT[i]);
    }
    printf("%d",CBT[n]);
    return 0;
}
