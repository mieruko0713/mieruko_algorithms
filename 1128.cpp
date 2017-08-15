//
//  1128.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/15.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cmath>
using namespace std;
int k;
const int maxn = 1010;




int main() {
    scanf("%d",&k);
    int i,n,j,l;
    for(i=0;i<k;i++) {
        scanf("%d",&n);
        int r[maxn] = {0};
        bool flag = true;
        for(j=1;j<=n;j++) {
            scanf("%d",&r[j]);
            for(l=1;l<j;l++) {
                if(r[l]==r[j]||l-j==r[l]-r[j]||l-j==r[j]-r[l]) {
                    flag = false;
                }
            }
        }
        
        if(flag) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
