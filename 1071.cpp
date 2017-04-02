//
//  1071.cpp
//  算法
//
//  Created by 王怡凡 on 2017/4/2.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;

bool check(char c) {
    if(c>='0'&&c<='9') {
        return true;
    }
    if(c>='A'&&c<='Z') {
        return true;
    }
    if(c>='a'&&c<='z') {
        return true;
    }
    return false;
}

int main() {
    map<string,int> count;
    string str;
    getline(cin, str);
    int i=0;
    while(i<str.length()) {
        string word;
        while(i<str.length()&&check(str[i])==true) {
            if(str[i]>='A'&&str[i]<='Z') {
                str[i] += 32;
            }
            word += str[i];
            i++;
        }
        if(word!="") {
//            if(count.find(word)==count.end()) {
//                count[word]=1;
//            } else {
//                count[word]++;
//            }
            count[word]++;
        }
        while(i<str.length()&&check(str[i])==false) {
            i++;
        }
    }
    string ans;
    int max=0;
    for(map<string,int>::iterator it=count.begin();it!=count.end();it++) {
        if(it->second>max) {
            max = it->second;
            ans = it->first;
        }
    }
    cout <<  ans << " " << max << endl;
    return 0;
}
