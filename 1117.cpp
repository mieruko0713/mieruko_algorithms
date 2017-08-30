//
//  1117.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 100010;
int miles[maxn],days[maxn];
int n;
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
                days[j] = n-1-(i-1);
//                printf("miles: %d times:%d\n",j,days[j]);
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
