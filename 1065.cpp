//
//  1065.cpp
//  算法
//
//  Created by 王怡凡 on 2017/4/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;

int main() {
    long long a,b,c;
    bool big = true;
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a>0&&b>0&&a+b<0) {
            big = true;
//            printf("a+b:%d",a+b);
        } else if(a<0&&b<0&&a+b>=0) {
            big = false;
        } else {
            big = a+b>c?true:false;
        }
        if(big) {
            printf("Case #%d: true\n",i);
        } else {
            printf("Case #%d: false\n",i);
        }
    }
    
}
