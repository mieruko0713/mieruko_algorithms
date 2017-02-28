//
//  1029.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1e7;
long int a[maxn], b[maxn];
int INF = 0x7fffffff;

int main(){
    int n,m,i,mid;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%ld",&a[i]);
    }
    a[n] = INF;
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%ld",&b[i]);
    }
    b[m] = INF;
    mid = (n+m-1)/2;
    int count=0,j=0,k=0;
    while(count<mid) {
        if(a[j]<b[k]) j++;
        else k++;
        count++;
    }
    if(a[j]<b[k]) {
        printf("%ld\n",a[j]);
    } else {
        printf("%ld\n",b[k]);
    }
    
    return 0;
}
