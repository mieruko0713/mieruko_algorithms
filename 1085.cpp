//
//  1085.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n;
long long p,all[maxn];


int main() {
    scanf("%d %lld",&n,&p);
    int i,max = 1;
    for(i=0;i<n;i++) {
        scanf("%lld",&all[i]);
    }
    sort(all,all+n);
    int count=1;
    for(i=0;i<n-1;i++) {
        long long m = all[i];
        for(int j=i+max;j<n;j++) {
            if(all[j]<=m*p) {
                count = j-i+1;
                if(count>max) {
                    max = count;
                }
            } else {
                break;
            }
        }
    }
    printf("%d",max);
    return 0;
}
