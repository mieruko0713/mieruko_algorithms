//
//  1020.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<queue>
using namespace std;
const int maxn = 40;
int n,post[maxn],in[maxn];

struct node {
    int v;
    node *lchild, *rchild;
};

void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    int num=0;
    while(!q.empty()) {
        node* now = q.front();
        printf("%d",now->v);
        num++;
        if(num!=n) {
            printf(" ");
        }
        q.pop();
        if(now->lchild!=NULL) {
            q.push(now->lchild);
        }
        if(now->rchild!=NULL) {
            q.push(now->rchild);
        }
    }
}

node* create(int postL,int postR,int inL,int inR) {
    if(postL>postR) {
        return NULL;
    }
    node* root = new node;
    root->v = post[postR];
    int i,k;
    for(i=inL;i<=inR;i++) {
        if(in[i]==post[postR]) {
            k = i;
        }
    }
    int numLeft = k - inL;
    root->lchild = create(postL,postL+numLeft-1,inL,k-1);
    root->rchild = create(postL+numLeft,postR-1,k+1,inR);
    return root;
}

int main() {
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&post[i]);
    }
    for(i=0;i<n;i++) {
        scanf("%d",&in[i]);
    }
    node* root = create(0,n-1,0,n-1);
    bfs(root);
    return 0;
}
