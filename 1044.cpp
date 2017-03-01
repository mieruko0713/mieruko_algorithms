//
//  1044.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/28.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
//int num[maxn];
int sum[maxn];
int n,s,nearS = 1000000010;

int upper_bound(int L, int R, int x) {
    int left = L, right = R,mid;
    while(left<right) {
        mid = (left+right)/2;
        if(sum[mid]>x) {
            right = mid;
        } else {
            left = mid+1;
        }
    }
    return left;
}

int main() {
    int i;
    scanf("%d %d",&n,&s);
    sum[0] = 0;
    for(i=1;i<=n;i++) {
        scanf("%d",&sum[i]);
        sum[i] += sum[i-1];
    }
    for(i=1;i<=n;i++) {
        int j = upper_bound(i,n+1,sum[i-1]+s);
        if(sum[j-1]-sum[i-1]==s) {
            nearS = s;
            break;
        } else if(j<=n&&sum[j]-sum[i-1]<nearS) {
            nearS = sum[j] - sum[i-1];
        }
    }
    for(i=1;i<=n;i++) {
        int j = upper_bound(i,n+1,sum[i-1]+nearS);
        if(sum[j-1]-sum[i-1]==nearS) {
            printf("%d-%d\n",i,j-1);
        }
    }
    return 0;
}
