//
//  1037.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/22.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int ac[maxn],ap[maxn];
int nc,np;


int main() {
    scanf("%d",&nc);
    int i,ans=0;
    for(i=0;i<nc;i++) {
        scanf("%d",&ac[i]);
    }
    scanf("%d",&np);
    for(i=0;i<np;i++) {
        scanf("%d",&ap[i]);
    }
    sort(ac,ac+nc);
    sort(ap,ap+np);
    i=0;
    int j=0;
    while(i<nc&&j<np&&ac[i]<0&&ap[j]<0) {
        ans += ac[i]*ap[j];
        i++;
        j++;
    }
    i=nc-1,j=np-1;
    while(i>=0&&j>=0&&ac[i]>0&&ap[j]>0) {
        ans += ac[i]*ap[j];
        i--;
        j--;
    }
    printf("%d",ans);
}

