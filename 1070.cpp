//
//  1070.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int n;
double all;

struct inv{
    double d,price,price2;
}invs[maxn];

bool cmp(inv a, inv b) {
    return a.price2 > b.price2;
}

int main(){
    scanf("%d%lf",&n,&all);
    int i;
    for(i=0;i<n;i++) {
        scanf("%lf",&invs[i].d);
    }
    for(i=0;i<n;i++) {
        scanf("%lf",&invs[i].price);
        invs[i].price2 = invs[i].price/invs[i].d;
    }
    sort(invs,invs+n,cmp);
    double sum = 0,pro=0;
    for(i=0;i<n;i++) {
//        if(sum+invs[i].d>all) {
//            pro += (all-sum)*invs[i].price2;
//            sum = all;
//        } else if(sum+invs[i].d<=all) {
//            pro += invs[i].price;
//            sum += invs[i].d;
//        }
//        if(sum==all) {
//            printf("%.2lf\n",pro);
//            break;
//        }
        if(invs[i].d<=all) {
            all -= invs[i].d;
            pro += invs[i].price;
        } else {
            pro += invs[i].price2*all;
            break;
        }
    }
    printf("%.2lf\n",pro);
    return 0;
}
