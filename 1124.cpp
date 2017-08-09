//
//  1124.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/9.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<map>
#include<iostream>

using namespace std;

const int maxn = 1010;
map<string,int> name;
string names[maxn];

int main() {
    int m, n, s, i;
    bool flag = false;
    scanf("%d %d %d",&m,&n,&s);
    for(i=0;i<m;i++) {
        cin >> names[i];
    }
    for(i=s-1;i<m;i+=n) {
        if(!name[names[i]]) {
            cout << names[i] << endl;
            flag = true;
            name[names[i]] = 1;
        } else {
            while(name[names[i]]&&i<m) {
                i++;
            }
            if(i<m) {
                cout << names[i]<<endl;
            }
        }
    }
    if(!flag) {
        cout<< "Keep going..." << endl;
    }
    return 0;
}
