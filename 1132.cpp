//
//  1132.cpp
//  算法
//
//  Created by 王怡凡 on 2017/11/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;

void judge(string s) {
    int len = int(s.length());
    long long num1=0,num2=0,num=0;
    for(int i=0;i<len;i++) {
        if(i<len/2) {
            num1 = num1*10 + (s[i]-'0');
        } else {
            num2 = num2*10 + (s[i]-'0');
        }
        num = num*10 + (s[i]-'0');
    }
//    cout<<num<<endl;
//    cout<<num1<<endl;
//    cout<<num2<<endl;
//    cout<<num/num1<<endl;
    if(num1==0||num2==0) {
        printf("No\n");
        return;
    }
    if(num%num1==0&&num/num1%num2==0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    int n;
    scanf("%d",&n);
    string s;
    for(int i=0;i<n;i++) {
        cin>>s;
        judge(s);
    }
    
    return 0;
}
