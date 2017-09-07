//
//  1117.cpp
//  算法
//
//  Created by 王怡凡 on 2017/9/7.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
int n,days[maxn],miles[maxn];
vector<int> ans;

int main() {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) {
        scanf("%d",&miles[i]);
    }
    sort(miles,miles+n);
    for(int j=0;j<miles[0];j++) {
        days[j] = n;
        if(days[j]>=j) {
            ans.push_back(j);
        }
    }
    for(i=1;i<n;i++) {
        if(miles[i]>miles[i-1]) {
            for(int j=miles[i-1];j<miles[i];j++) {
                if(j>=maxn) {
                    break;
                }
                days[j] = n-i;
                if(days[j]>=j) {
                    ans.push_back(j);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()!=0) {
        printf("%d",ans[(ans.size()-1)]);
    }
    printf("\n");
    return 0;
}
