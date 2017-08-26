//
//  1007.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
const int maxn = 100010;
int n,all[maxn],d[maxn];

int main() {
    int i,left=0,len=0,maxres,maxleft=0,maxlen=0;
    scanf("%d",&n);
    bool flag=false;
    for(i=0;i<n;i++) {
        scanf("%d",&all[i]);
        if(all[i]>=0){
            flag = true;
        }
    }
    if(!flag) {
        printf("0 %d %d",all[0],all[n-1]);
    } else {
        d[0] = all[0];
        maxres = d[0];
        for(i=1;i<n;i++) {
            if(d[i-1]<0) {
                left = i;
                len = 0;
                d[i] = all[i];
            } else {
                d[i] = all[i]+d[i-1];
                len++;
            }
            if(d[i]>maxres) {
                maxres = d[i];
                maxleft = left;
                maxlen = len;
            }
        }
        printf("%d %d %d",maxres,all[maxleft],all[maxleft+maxlen]);
    }
    
    return 0;
}
