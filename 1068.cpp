//
//  1068.cpp
//  算法
//
//  Created by 王怡凡 on 2017/4/2.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10010;
const int maxv = 110;
int w[maxn],dp[maxv]={0};
bool choice[maxn][maxv],flag[maxn];
bool cmp(int a, int b) {
    return a>b;
}

int main() {
    int i,n,m,v,k,num;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) {
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1,cmp);
    for(i=1;i<=n;i++) {
        for(v=m;v>=w[i];v--) {
            if(dp[v]<=dp[v-w[i]]+w[i]) {
                dp[v] = dp[v-w[i]] + w[i];
                choice[i][v] = 1;
            } else {
                choice[i][v]=0;
            }
        }
    }
    if(dp[m]!=m) {
        printf("No Solution");
    } else {
        k=n,num=0,v=m;
        while(k>=0) {
            if(choice[k][v]==true) {
                flag[k] = true;
                v -= w[k];
                num++;
            }
            else flag[k]=false;
            k--;
        }
    }
    for(i=n;i>=1;i--) {
        if(flag[i]==true) {
            printf("%d",w[i]);
            num--;
            if(num>0) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
