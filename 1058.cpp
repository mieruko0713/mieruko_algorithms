//
//  1058.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/3.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;

int main() {
    int i,a[3],b[3],ans[3];
    scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
    scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
    for(i=0;i<3;i++) {
        ans[i] = a[i] + b[i];
    }
    if(ans[2]/29>0) {
        ans[1]+= ans[2]/29;
        ans[2]= ans[2]%29;
    }
    if(ans[1]/17>0) {
        ans[0] += ans[1]/17;
        ans[1] = ans[1]%17;
    }
    printf("%d.%d.%d",ans[0],ans[1],ans[2]);
    return 0;
}
