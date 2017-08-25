//
//  1088.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstdlib>
using namespace std;

struct Node {
    long long moth,chil,inte;
}node[2];

long long gcd(long long a, long long b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}

void print(Node a) {
    if(a.inte!=0) {
        if(a.inte<0) {
            printf("(%lld",a.inte);
            if(a.chil!=0) {
                printf(" %lld/%lld)",a.chil,a.moth);
            } else {
                printf(")");
            }
        } else {
            printf("%lld",a.inte);
            if(a.chil!=0) {
                printf(" %lld/%lld",a.chil,a.moth);
            }
        }
    } else {
        if(a.chil!=0) {
            if(a.chil<0) {
               printf("(%lld/%lld)",a.chil,a.moth);
            } else {
               printf("%lld/%lld",a.chil,a.moth);
            }
        } else {
            printf("0");
        }
    }
}

Node change(Node a) {
    long long  gc = gcd(a.chil,a.moth);
    if(gc!=0) {
        a.chil /= gc;
        a.moth /= gc;
    }
    a.inte = a.chil / a.moth;
    a.chil = a.chil % a.moth;
    int num=0;
    if(a.inte!=0) {
        a.chil = abs(a.chil % a.moth);
        a.moth = abs(a.moth);
    } else {
        if(a.chil<0) {
            num++;
        }
        if(a.moth<0) {
            num++;
        }
        if(num==1) {
            a.moth = abs(a.moth);
            a.chil = -abs(a.chil);
        } else {
            a.moth = abs(a.moth);
            a.chil = abs(a.chil);
        }
    }
    return a;
}

int main() {
    scanf("%lld/%lld %lld/%lld",&node[0].chil,&node[0].moth,&node[1].chil,&node[1].moth);
    long long res[4];
    Node a = node[0];
    Node b = node[1];
    bool flag = false;
    long long chil,moth;
    long long lc = a.moth*b.moth/gcd(node[0].moth,node[1].moth);
    res[0] = a.chil*(lc/a.moth) + b.chil*(lc/b.moth);
    res[1] = a.chil*(lc/a.moth) - b.chil*(lc/b.moth);
    res[2] = a.chil*(lc/a.moth) * b.chil*(lc/b.moth);
    if(b.chil==0) {
        flag = true;
    } else {
        chil =  a.chil*b.moth;
        moth = a.moth*b.chil;
    }
    a = change(a);
    b = change(b);
    char fu[4] = {'+','-','*','/'};
    for(int i=0;i<3;i++) {
        Node r;
        r.chil = res[i];
        if(i<2) {
            r.moth = lc;
        } else {
            r.moth = lc*lc;
        }
        
        print(a);
        printf(" %c ",fu[i]);
        print(b);
        printf(" = ");
        r = change(r);
        print(r);
        printf("\n");
    }
    print(a);
    printf(" %c ",fu[3]);
    print(b);
    printf(" = ");
    if(flag) {
        printf("Inf");
    } else {
        Node r;
        r.chil = chil;
        r.moth = moth;
        r = change(r);
        print(r);
    }
    return 0;
}
