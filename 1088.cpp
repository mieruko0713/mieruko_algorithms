//
//  1088.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/29.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstdlib>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return b==0?a:gcd(b,a%b);
}

struct Fraction {
    ll up,down;
};

Fraction reduction(Fraction result) {
    if(result.down<0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up==0) {
        result.down = 1;
    } else {
        ll d = gcd(abs(result.up),abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}

Fraction add(Fraction a, Fraction b) {
    Fraction result;
    result.up = a.up*b.down + b.up*a.down;
    result.down = a.down*b.down;
    return reduction(result);
}

void showResult(Fraction r) {
    r = reduction(r);
    if(r.up<0) {
        printf("(");
    }
    if(r.down==1) {
        printf("%lld",r.up);
    }else if(abs(r.up)>r.down) {
        printf("%lld %lld/%lld",r.up/r.down,abs(r.up%r.down),r.down);
    } else {
        printf("%lld/%lld",r.up,r.down);
    }
    if(r.up<0) {
        printf(")");
    }
}

Fraction difference(Fraction a, Fraction b) {
    Fraction result;
    result.up = a.up*b.down - b.up*a.down;
    result.down = a.down*b.down;
    return reduction(result);
}

Fraction multiple(Fraction a, Fraction b) {
    Fraction result;
    result.up = a.up*b.up;
    result.down = a.down*b.down;
    return reduction(result);
}

Fraction divide(Fraction a, Fraction b) {
    Fraction result;
    result.up = a.up * b.down;
    result.down = a.down * b.up;
    return reduction(result);
}

int main() {
    Fraction a, b;
    scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a,b));
    printf("\n");
    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(difference(a,b));
    printf("\n");
    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multiple(a,b));
    printf("\n");
    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up==0) {
        printf("Inf\n");
    } else{
        showResult(divide(a,b));
    }
    return 0;
}
