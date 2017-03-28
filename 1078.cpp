//
//  1078.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N = 10010;
bool Hash[N] = {false};

bool isPrime(int x) {
    if(x==1) {
        return false;
    }
    int i,sqr = int(sqrt(x*1.0));
    for(i=2;i<=sqr;i++) {
        if(x%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, i,size, a;
    scanf("%d%d",&size,&n);
    while(!isPrime(size)) {
        size++;
    }
    for(i=0;i<n;i++) {
        scanf("%d",&a);
        int M = a%size;
        if(Hash[M]==false) {
            Hash[M] = true;
            if(i==0) {
                printf("%d",M);
            } else {
                printf(" %d",M);
            }
        } else {
            int step;
            for(step=1;step<size;step++) {
                M=(a+step*step)%size;
                if(Hash[M]==false){
                    Hash[M] = true;
                    if(i==0) {
                        printf("%d",M);
                    } else {
                        printf(" %d",M);
                    }
                    break;
                }
            }
            if(step==size) {
                if(i>0) {
                    printf(" -");
                } else {
                    printf("-");
                }
            }
        }
    }
    return 0;
}
