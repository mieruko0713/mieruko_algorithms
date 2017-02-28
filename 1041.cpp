//
//  1041.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/28.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;
const int maxn1 = 10010;
const int maxn2 = 100010;
int Hash[maxn1] = {0};

int main(){
    int i,n,a[maxn2];
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        Hash[a[i]]++;
    }
    for(i=0;i<n;i++) {
        if(Hash[a[i]]==1) {
            printf("%d",a[i]);
            break;
        }
    }
    if(i==n) {
        printf("None");
    }
    
    return 0;
}