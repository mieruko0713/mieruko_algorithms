//
//  1101.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<set>
using namespace std;
const int maxn = 100010;
int n,num[maxn],left[maxn]={0},right[maxn]={0};
set<int> ans;

int main() {
    scanf("%d",&n);
    int i;
    left[0] = 1;
    int maxleft = -1;
    for(i=0;i<n;i++) {
        scanf("%d",&num[i]);
        if(num[i]>=maxleft) {
            left[i] = 1;
            maxleft = num[i];
        }
    }
    right[n-1]=1;
    int minright = num[n-1];
    for(i=n-1;i>=0;i--) {
        if(num[i]<=minright) {
            right[i]=1;
            minright = num[i];
            if(left[i]==1) {
                ans.insert(num[i]);
            }
        }
    }
    i=0;
    printf("%d\n",int(ans.size()));
    for(set<int>::iterator it=ans.begin();it!=ans.end();it++) {
        printf("%d",*it);
        if(i!=int(ans.size())-1) {
            printf(" ");
        }
        i++;
    }
    printf("\n");
    return 0;
}
