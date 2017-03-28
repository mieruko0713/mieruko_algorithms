//
//  1059.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 100010;

bool isPrime(int x){
    if(x==1) {
        return false;
    }
    int i,sqr = (int)sqrt(1.0*x);
    for(i=2;i<=sqr;i++) {
        if(x%i==0) {
            return false;
        }
    }
    return true;
}

int prime[maxn],pNum=0;

void Find_Primes() {
    int i;
    for(i=2;i<maxn;i++) {
        if(isPrime(i)==true) {
            prime[pNum++] = i;
        }
    }
}

struct factor {
    int x, cnt;
}fac[maxn];

int main() {
    Find_Primes();
    int n, i,num=0;
    scanf("%d",&n);
    if(n==1) {
        printf("1=1");
    } else {
        printf("%d=",n);
        int sqr = (int)sqrt(n*1.0);
        for(i=0;i<pNum&&prime[i]<=sqr;i++) {
            if(n%prime[i]==0) {
                fac[num].x = prime[i];
                while(n%prime[i]==0) {
                    fac[num].cnt++;
                    n/=prime[i];
                }
                num++;
            }
            if(n==1) {
                break;
            }
        }
        if(n!=1){
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for(i=0;i<num;i++) {
            if(i>0) {
                printf("*");
            }
            printf("%d",fac[i].x);
            if(fac[i].cnt>1) {
                printf("^%d",fac[i].cnt);
            }
        }
    }
    return 0;
}
