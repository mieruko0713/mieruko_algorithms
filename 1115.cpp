//
//  1115.cpp
//  算法
// 
//  Created by 王怡凡 on 17/2/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1010;
int n, num[maxn]={0}, maxdepth=-1;
struct node {
    int data;
    node *left, *right;
};

void DFS(node *root, int depth) {
    if(root==NULL) {
        maxdepth = max(depth, maxdepth);
        return;
    }
    num[depth]++;
    DFS(root->left, depth+1);
    DFS(root->right, depth+1);
}

void insert(node* &root, int data) {
    if(root==NULL) {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return ;
    }
    if(data<=root->data) {
        insert(root->left, data);
        insert(root->right, data);
    }
}

int main() {
    int n,i,data;
    node *root = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&data);
        insert(root, data);
    }
    DFS(root,0);
    printf("%d + %d = %d", num[maxdepth-1], num[maxdepth-2],num[maxdepth-1]+num[maxdepth-2]);
    return 0;
}
