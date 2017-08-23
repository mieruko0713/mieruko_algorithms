//
//  1068.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int num[maxn],d[110]={0};
bool flag[maxn] ={false};
int choice[maxn][110]={0};
int n,m;

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;i++) {
        scanf("%d",&num[i]);
    }
    sort(num+1,num+n+1,cmp);
    for(i=1;i<=n;i++) {
        for(j=m;j>=num[i];j--) {
            if(d[j-num[i]]+num[i]>=d[j]) {
                d[j] = d[j-num[i]] + num[i];
                choice[i][j] = 1;
            }
        }
    }
    if(d[m]!=m) {
        printf("No Solution");
    } else {
        int k=n,v=m,cnt=0;
        while(k>0) {
            if(choice[k][v]==1) {
                flag[k]=true;
                v -= num[k];
                cnt++;
            } else {
                flag[k]=false;
            }
            k--;
        }
        for(int i=n;i>=1;i--) {
            if(flag[i]==true) {
                printf("%d",num[i]);
                cnt--;
                if(cnt>0) {
                    printf(" ");
                }
            }
        }
    }
    return 0;
}
