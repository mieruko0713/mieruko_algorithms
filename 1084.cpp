//
//  1084.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,bool> hashes;

int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
//    printf("%d",hashes['1']);
    int i;
    for(i=0;i<s1.length();i++) {
        for(int j=0;j<s2.length();j++) {
            if(s1[i]>='a'&&s1[i]<='z') {
                s1[i]=s1[i]-32;
            }
            if(s2[j]>='a'&&s2[j]<='z') {
                s2[j]=s2[j]-32;
            }
            if(s1[i]==s2[j]) {
                s1.erase(i,1);
            }
        }
    }
    for(i=0;i<s1.length();i++) {
        if(s1[i]>='a'&&s1[i]<'z') {
            s1[i] = s1[i] - 32;
        }
        if(!hashes[s1[i]]) {
            hashes[s1[i]] = true;
            printf("%c",s1[i]);
        }
    }

    return 0;
}
