//
//  1139.cpp
//  算法
//
//  Created by 王怡凡 on 2018/2/18.
//  Copyright © 2018年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int m, n;
const int maxn = 10010;
bool arr[maxn][maxn];
vector<int> v[maxn];

struct node {
    int a, b;
};

bool cmp(node x, node y) {
    if(x.a!=y.a) {
        return x.a < y.a;
    }
    return x.b < y.b;
}

int main() {
    scanf("%d %d", &n, &m);
    int i,k;
    string a,b;
    for(i=0;i<m;i++) {
        cin >> a >> b;
        if(a.length() == b.length()) {
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a))][abs(stoi(b))] = arr[abs(stoi(b))][abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for(int i=0;i<k;i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for(int j=0;j<v[abs(c)].size();j++) {
            for(int k=0;k<v[abs(d)].size();k++) {
                if(v[abs(c)][j]==abs(d)||v[abs(d)][k]==abs(c)) {
                    continue;
                }
                if(arr[v[abs(c)][j]][v[abs(d)][k]] == true) {
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j=0;j<ans.size();j++) {
            printf("%04d %04d\n", ans[j].a, ans[j].b);
        }
    }
    return 0;
}
