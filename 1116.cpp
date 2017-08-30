//
//  1116.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cmath>
using namespace std;
const int maxn = 100010;
int hashes[maxn],n,hashes2[maxn];
int ranks[maxn];

bool isPrime(int x) {
    if(x==1) {
        return false;
    }
    int sqr = sqrt(x*1.0);
    for(int i=2;i<=sqr;i++) {
        if(x%i==0) {
            return false;
        }
    }
    return true;
}


int main() {
    scanf("%d",&n);
    int i,id;
    for(i=0;i<n;i++) {
        scanf("%d",&id);
        ranks[id] = i+1;
        hashes[id] = 1;
    }
    int k;
    scanf("%d",&k);
    for(i=0;i<k;i++) {
        scanf("%d",&id);
        printf("%04d: ",id);
        if(hashes[id]) {
            if(hashes2[id]) {
                printf("Checked\n");
            }else {
                hashes2[id] = 1;
                if(ranks[id]==1) {
                    printf("Mystery Award\n");
                } else if(isPrime(ranks[id])) {
                    printf("Minion\n");
                } else {
                    printf("Chocolate\n");
                }

            }
        } else {
            printf("Are you kidding?\n");
        }
    }
}
