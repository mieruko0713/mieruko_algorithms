//
//  1060.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int n;
string a,b,s3,s4;

string deal(string s ,int& e) {
    int k=0;
    while(s.length()>0&&s[0]=='0') {
        s.erase(s.begin());
    }
    if(s[0]=='.') {
        s.erase(s.begin());
        while(s.length()>0&&s[0]=='0') {
            s.erase(s.begin());
            e--;
        }
    } else {
        while(k<s.length()&&s[k]!='.') {
            k++;
            e++;
        }
        if(k<s.length()) {
            s.erase(s.begin()+k);
        }
    }
    if(s.length()==0) {
        e=0;
    }
    int num = 0;
    k=0;
    string res;
    while(num<n) {
        if(k<s.length()) res+=s[k++];
        else res += '0';
        num++;
    }
    return res;
}

int main() {
    scanf("%d",&n);
    cin >> a >> b;
    int e1=0,e2=0;
    s3 = deal(a,e1);
    s4 = deal(b,e2);
    if(s3==s4&&e1==e2) {
        cout << "YES 0."<< s3 << "*10^"<<e1 << endl;
    }else {
        cout << "NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
    }
    return 0;
}
