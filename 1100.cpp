//
//  1100.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/29.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int n;
string mars[2][13] = {
    {"tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
    {"tret","tam", "hel","maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
};
map<string,int> earth[2];

void func1(string data) {
    int ans=0,res[2];
    for(int i=0;i<data.length();i++) {
        ans = ans*10 + (data[i]-'0');
    }
    if(ans==0) {
        printf("tret\n");
        return ;
    }
    int num=0;
    while(ans!=0) {
        res[num++] = ans%13;
        ans /= 13;
    }
    if(num==2) {
        string all;
        if(res[0]==0) {
           all = mars[1][res[1]];
        } else {
           all = (mars[1][res[1]] + " " +mars[0][res[0]]);
        }
        cout << all <<endl;
    } else {
        cout << mars[0][res[0]] << endl;
    }
}

void func2(string data) {
    if(data=="tret") {
        printf("0\n");
        return ;
    }
    int ans;
    if(data.length()==3) {
        ans = earth[0][data]==0?earth[1][data]*13:earth[0][data];
    } else {
        string s1 = data.substr(0,3);
        string s2 = data.substr(4,3);
        ans = earth[1][s1]*13 + earth[0][s2];
    }
    printf("%d\n",ans);
}

int main() {
    cin >> n;
    getchar();
    string data;
    for(int i=0;i<2;i++) {
        for(int j=0;j<13;j++) {
            earth[i][mars[i][j]] = j;
        }
    }
    for(int i=0;i<n;i++) {
        getline(cin,data);
        if(data[0]>='0'&&data[0]<='9') {
            func1(data);
        } else {
            func2(data);
        }
    }
    return 0;
}
