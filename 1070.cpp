//
//  1070.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/9.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1100;

struct cake {
    int ton;
    double price;
}cakes[maxn];

bool cmp(cake a, cake b) {
    return a.price/a.ton > b.price/b.ton;
}

int main() {
    int i,n,sum;
    double profit=0.0;
    scanf("%d%d",&n,&sum);
    for(i=0;i<n;i++) {
        scanf("%d",&cakes[i].ton);
    }
    for(i=0;i<n;i++) {
        scanf("%lf",&cakes[i].price);
    }
    sort(cakes,cakes+n,cmp);
    for(i=0;i<n;i++) {
        if(sum >=  cakes[i].ton) {
            sum = sum-cakes[i].ton;
            profit += cakes[i].price;
        } else if(sum < cakes[i].ton ) {
            profit += cakes[i].price * (sum*1.0/cakes[i].ton);
            break;
        }
    }
    printf("%.2lf\n",profit);
    return 0;
}
