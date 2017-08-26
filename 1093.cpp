//
//  1093.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;
const int maxn = 100010;

int main() {
    string s;
    cin >> s;
    long long size = s.length();
    long long ans=0;
    long long i,left[maxn]={0},right[maxn]={0},numl=0,numr=0;
    for(i=0;i<size;i++) {
        if(s[i]=='P') {
             numl++;
        }
        if(s[i]=='A') {
            left[i] = numl;
        }
    }
    for(i=size-1;i>=0;i--) {
        if(s[i]=='T') {
            numr++;
        }
        if(s[i]=='A') {
            right[i] = numr;
            ans += right[i]*left[i];
        }
    }
    ans %= 1000000007;
    printf("%lld",ans);
    return 0;
}
