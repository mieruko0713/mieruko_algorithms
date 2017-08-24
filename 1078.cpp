//
//  1078.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cmath>
using namespace std;
const int maxn = 10010;
int Msize,n;
bool hashes[maxn] = {false};


bool isPrime(int x) {
    if(x<=1) return false;
    int sqr = int(sqrt(x*1.0));
    int i;
    for(i=2;i<=sqr;i++) {
        if(x%i==0) {
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d %d",&Msize,&n);
    int i,num;
    while(!isPrime(Msize)) {
        Msize++;
    }
    for(i=0;i<n;i++) {
        scanf("%d",&num);
        int M = num%Msize;
        if(hashes[M]==false) {
            printf("%d",M);
            hashes[M] = true;
        } else {
            bool flag = false;
            for(int j=1;j<Msize;j++) {
                M = (num+j*j)%Msize;
                if(hashes[M]==false) {
                    printf("%d",M%Msize);
                    hashes[M] = true;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                printf("-");
            }
        }
        if(i!=n-1) {
            printf(" ");
        }
    }
    return 0;
}
