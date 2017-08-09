//
//  1125.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/9.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 10010;

int main() {
    int n,i,nums[maxn],res;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&nums[i]);
    }
    sort(nums,nums+n);
    res = nums[0];
    for(i=1;i<n;i++) {
        res = round((res + nums[i])/2);
    }
    printf("%d",res);
    return 0;
}

