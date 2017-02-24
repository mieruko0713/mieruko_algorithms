//
//  1100.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<map>
#include<string>
#include <cctype>
#include<iostream>
using namespace std;
const int maxn = 110;
using namespace std;
int n,num[3];
char strs[maxn][10];
string numToStr[24] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int> strToNum;

void func1(string s) {
    int len = s.length(),i,num=0;
    for(i=0;i<len;i++) {
        num = num*10 + (s[i]-'0');
    }
    if(num==0) {
        printf("tret");
    }
    if(num/13!=0) {
        cout << numToStr[num/13+12-1]<<" "<<numToStr[num%13-1] <<endl;
    } else {
        cout << numToStr[num%13-1] <<endl;
    }
    
//    printf("num: %d\n",num);
}

void func2(string str) {
    int len = str.length(), num;
    if(len==4) {
        printf("0\n");
    } else if(len==3) {
        num = strToNum[str];
        cout << num << endl;
    } else if(len == 7) {
        string temp1 = str.substr(0,3);
        string temp2 = str.substr(4,3);
        num = (strToNum[temp1]%12)*13 + strToNum[temp2];
        printf("%d\n",num);
    }
}

void init() {
    int i;
    for(i=0;i<24;i++) {
        strToNum[numToStr[i]] = i+1;
//        printf("str:%s to num: %d\n",numToStr[i],strToNum[numToStr[i]]);
    }
}

int main() {
    init();
    int n,i;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++) {
        string s;
        getline(cin, s);
        if(isdigit(s[0])) {
            func1(s);
        } else {
            func2(s);
        }
    }
    return 0;
}
