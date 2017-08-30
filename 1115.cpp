//
//  1115.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
int n;
const int maxn = 1010;
int layer[maxn] = {0},maxlayer;

struct Node {
    int data;
    Node *lchild,*rchild;
};

void insert(Node* &root, int data) {
    if(root==NULL) {
        root = new Node;
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return ;
    }
    if(data<=root->data) {
        insert(root->lchild,data);
    } else {
        insert(root->rchild,data);
    }
}

void dfs(Node *root, int num) {
    if(root==NULL) {
        return ;
    }
    if(num>maxlayer) {
        maxlayer=num;
    }
    layer[num++] += 1;
    dfs(root->lchild,num);
    dfs(root->rchild,num);
}

int main() {
    scanf("%d",&n);
    int i,data;
    Node *root;
    for(i=0;i<n;i++) {
        scanf("%d",&data);
        insert(root,data);
    }
    dfs(root,0);
    printf("%d + %d = %d",layer[maxlayer],layer[maxlayer-1],layer[maxlayer]+layer[maxlayer-1]);
    return 0;
}
