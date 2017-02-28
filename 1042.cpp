//
//  1042.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/28.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;
const int maxn = 55;
int start[maxn],end[maxn],scan[maxn];
char A[6] = {"SHCDJ"};

int main() {
    int repeat,i,j;
    scanf("%d",&repeat);
    for(i=1;i<maxn;i++) {
        end[i] = i;
        scanf("%d",&scan[i]);
    }
    for(i=0;i<repeat;i++) {
        for(j=1;j<maxn;j++) {
            start[j] = end[j];
        }
        for(j=1;j<maxn;j++) {
            end[scan[j]] = start[j];
        }
    }
    for(i=1;i<maxn;i++) {
        end[i] = end[i]-1;
        printf("%c%d", A[end[i]/13], end[i]%13+1);
        if(i!=maxn-1) {
            printf(" ");
        }
    }
    
    return 0;
}
