//
//  1112.cpp
//  算法
//
//  Created by 王怡凡 on 2018/2/20.
//  Copyright © 2018年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<char, int> countNum;
map<char, bool> hashes;
int k;
vector<char> ans;
string s;
const int maxn = -10010;

int main() {
    cin >> k >> s;
    int i;
    int count=1;
    for(i=1;i<s.size();i++) {
        if(s[i]==s[i-1]) {
            count++;
        } else {
            if(count%k!=0) {
                countNum[s[i-1]] = maxn;
            } else {
                countNum[s[i-1]] += count/k;
            }
            count = 1;
        }
    }
    if(count%k!=0) {
        countNum[s[i-1]] = maxn;
    } else {
        countNum[s[i-1]] += count/k;
    }
    count = 1;
    for(i=0;i<s.size();i++) {
        if(countNum[s[i]]>=1&&(!hashes[s[i]])) {
            cout << s[i];
            hashes[s[i]] = true;
        }
    }
    cout<<endl;
    for(i=0;i<s.size();i++) {
        cout << s[i];
        if(countNum[s[i]]>=1) {
            i += k-1;
        }
    }
    cout<<endl;
    return 0;
}
