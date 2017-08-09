//
//  1123.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/9.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<queue>
using namespace std;

int n;
bool isComplete = true;


struct node {
    int v, height;
    node *lchild, *rchild;
};

node* newNode(int v) {
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node* root) {
    if(root==NULL) return 0;
    return root->height;
}

int getBalanceFactor(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* &root) {
    root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

void L(node* &root) {
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node* &root) {
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int v) {
    if(root==NULL) {
        root = newNode(v);
        return;
    }
    if(v<root->v) {
        insert(root->lchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==2) {
            if(getBalanceFactor(root->lchild)==1) {
                R(root);
            } else if(getBalanceFactor(root->lchild)==-1) {
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==-2) {
            if(getBalanceFactor(root->rchild)==1) {
                R(root->rchild);
                L(root);
            } else if(getBalanceFactor(root->rchild)==-1) {
                L(root);
            }
        }
    }
}

node* create(int data[], int n) {
    node* root = NULL;
    for(int i=0;i<n;i++) {
        insert(root,data[i]);
    }
    return root;
}

void layerOrder(node* root) {
    int num = 0;
    int test = 0;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* now = q.front();
        q.pop();
        printf("%d",now->v);
        num++;
        if(num!=n) {
            printf(" ");
        } else {
            printf("\n");
        }
        if(now->lchild!=NULL)
        {
           q.push(now->lchild);
            if(test) {
                isComplete = false;
            }
        } else {
            test = 1;
        }
        if(now->rchild!=NULL) {
            q.push(now->rchild);
            if(test) {
                isComplete = false;
            }
        }else {
            test = 1;
        }

    }
}

int main() {
    int v;
    scanf("%d",&n);
    node* root = NULL;
    int i;
    for(i=0;i<n;i++) {
        scanf("%d",&v);
        insert(root,v);
    }
    layerOrder(root);
    if(isComplete) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
