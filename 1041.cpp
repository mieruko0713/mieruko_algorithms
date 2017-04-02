//
//  1041.cpp
//  算法
//
//  Created by 王怡凡 on 2017/4/2.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;
const int maxn = 100010;
int hash[maxn],num[maxn];
int n;

int main() {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) {
        scanf("%d",&num[i]);
        hash[num[i]]++;
    }
    for(i=0;i<n;i++) {
//        printf("num:%d hash:%d\n",num[i],hash[num[i]]);
        if(hash[num[i]]==1) {
            printf("%d\n",num[i]);
            break;
        }
    }
    if(i==n) {
        printf("None\n");
    }
    return 0;
}
