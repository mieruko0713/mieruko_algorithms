//
//  1024.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/21.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int k;
struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d,0,sizeof(d));
        len = 0;
    }
};

bign change(char str[]) {
    bign a;
    a.len = int(strlen(str));
    for(int i=0;i<a.len;i++) {
        a.d[i] = str[a.len-i-1] - '0';
    }
    return a;
}


bign add(bign a, bign b) {
    bign c;
    int carry=0;
    for(int i=0;i<a.len||i<b.len;i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }
    if(carry!=0) {
        c.d[c.len++] = carry;
    }
    return c;
}

bool Judge(bign a) {
    for(int i=0;i<=a.len/2;i++) {
        if(a.d[i]!=a.d[a.len-1-i]) {
            return false;
        }
    }
    return true;
}

void print(bign a) {
    for(int i=a.len-1;i>=0;i--) {
        printf("%d",a.d[i]);
    }
    printf("\n");
}

int main() {
    char str[1000];
    int i=0;
    scanf("%s %d",str,&k);
    bign a = change(str);
    while(i<k&&Judge(a)==false) {
        bign b = a;
        reverse(b.d,b.d+b.len);
        a = add(a,b);
        i++;
    }
    print(a);
    printf("%d",i);
    return 0;
}

