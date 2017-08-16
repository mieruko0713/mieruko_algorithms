//
//  1130.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/16.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;

const int maxn = 40;

int root=0,n;

bool child[maxn];

struct node {
    int lchild,rchild;
    string val;
} v[maxn];

string dfs(int index) {
    if(index==-1) {
        return "";
    }
    string val = dfs(v[index].lchild) + v[index].val+dfs(v[index].rchild);
    if(index!=root&&v[index].rchild!=-1) {
        val = "(" + val + ")";
    }
    return val;
}


int main() {
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        cin >> v[i].val >> v[i].lchild >> v[i].rchild;
        if(v[i].lchild!=-1) child[v[i].lchild] = true;
        if(v[i].rchild!=-1) child[v[i].rchild] = true;
    }
    i=1;
    while(i<=n&&child[i]) {
        i++;
    }
    root = i;
    cout << dfs(root);
    return 0;
}
