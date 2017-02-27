//
//  1027.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>

char c[14] = {"0123456789ABC"};
void change(int x) {
    char ans[4]={"000"};
    int i,num=0;
    do {
        ans[num++] = c[x%13];
//        printf("%d\n",ans[num]);
        x = x/13;
    }
    while(x!=0);
    for(i=1;i>=0;i--) {
        printf("%c",ans[i]);
    }
}

int main() {
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("#");
    change(a);
    change(b);
    change(c);
}
