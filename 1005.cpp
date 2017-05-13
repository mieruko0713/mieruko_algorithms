//
//  1005.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/13.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
char result[4];
char letters[10][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    char N[110];
    int i=0,sum=0;
    scanf("%s",N);
    for(i=0;i<strlen(N);i++) {
        sum += N[i] - '0';
    }
    string r = to_string(sum);
    for(i=0;i<r.length();i++) {
        cout << letters[r[i]-'0'];
        if(i!=r.length()-1) {
            cout << " ";
        }
    }
    return 0;
}
