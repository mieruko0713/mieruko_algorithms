//
//  1138.cpp
//  算法
//
//  Created by 王怡凡 on 2018/2/15.
//  Copyright © 2018年 王怡凡. All rights reserved.
//

#include <stdio.h>

const int maxn = 50010;
int pre[maxn], in[maxn];
int n;

struct Node {
    Node *left, *right;
    int data;
} *root;

Node* create(int preL,int preR, int inL, int inR) {
    if(preL > preR) {
        return NULL;
    }
    Node* root = new Node;
    int k;
    for(k=inL;k<=inR;k++) {
        if(in[k]==pre[preL]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->left = create(preL+1, preL+numLeft, inL, k-1);
    root->right = create(preL+numLeft+1, preR, k+1, inR);
    root->data = pre[preL];
    return root;
}

bool flag= false;
void postOrder(Node* root) {
    if(root==NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    if(!flag) {
        printf("%d", root->data);
        flag = true;
    } else {
        return ;
    }
}


int main() {
    scanf("%d", &n);
    int i;
    for(i=0;i<n;i++) {
        scanf("%d", &pre[i]);
    }
    for(i=0;i<n;i++) {
        scanf("%d", &in[i]);
    }
    root = create(0, n-1, 0, n-1);
    postOrder(root);
    return 0;
}
