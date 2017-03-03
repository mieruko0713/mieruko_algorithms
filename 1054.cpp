//
//  1054.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/2.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<map>
using namespace std;

map<int,int> Hash;

int main() {
    int m,n,i,j,color,temp=0,half;
    scanf("%d%d",&m,&n);
    half = m*n/2;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d",&color);
            Hash[color]++;
            if(Hash[color]>half) {
                printf("%d",color);
            }
        }
    }
    return 0;
}