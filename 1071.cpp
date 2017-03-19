//
//  1071.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/16.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cctype>
#include<iostream>
#include<map>
using namespace std;

int main() {
    string s,t;
    int i;
    getline(cin,s);
    map<string, int> m;
    for(i=0;i<s.length();i++) {
        if(isalnum(s[i])) {
            t += tolower(s[i]);
        } else {
            if(t.length()) {
                m[t]++;
            }
            t="";
        }
    }
    if(t.length()) m[t]++;
    int maxn = 0;
    for(map<string, int>::iterator it=m.begin();it!=m.end();it++) {
        if(it->second > maxn) {
            maxn = it->second;
            t = it->first;
        }
    }
    cout << t << " " << maxn;
    return 0;
}

