//
//  1038.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/28.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
const int maxn = 100010;

bool cmp(string a, string b) {
    return a+b<b+a;
}

int main() {
    int n,i;
    string s[maxn],ans;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        cin >> s[i];
    }
    sort(s,s+n,cmp);
    for(i=0;i<n;i++) {
        ans += s[i];
    }
    int j=0;
    while(ans[j]=='0'&&ans.size()!=0) {
        ans.erase(j,1);
    }
    if(ans.size()==0) {
        printf("0");
    } else {
        cout << ans;
    }
    return 0;
}
