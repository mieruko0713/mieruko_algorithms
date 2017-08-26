//
//  1092.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main() {
    string s1,s2;
    cin>>s1;
    cin>>s2;
    bool  flag;
    int num2=0;
    int size2 = int(s2.length());
    for(int i=0;i<size2;i++) {
        flag = false;
        int size1 = int(s1.length());
        for(int j=0;j<size1;j++) {
            if(s1[j]==s2[i]) {
                flag = true;
                s1.erase(j,1);
                break;
            }
        }
        if(!flag) {
            num2++;
        }
    }
    if(num2==0) {
        printf("Yes %d\n",int(s1.length()));
    } else {
        printf("No %d\n",num2);
    }
    return 0;
}
