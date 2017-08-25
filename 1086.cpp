//
//  1086.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
const int maxn = 50;
int n,in[maxn],pre[maxn];

struct Node {
    Node *lchild,*rchild;
    int data;
}node[maxn];

Node* create(int preL,int preR, int inL, int inR) {
    if(preL>preR) {
        return NULL;
    }
    Node* root = new Node;
    root->data = pre[preL];
    int k;
    for(k=inL;k<=inR;k++) {
        if(in[k]==pre[preL]) {
            break;
        }
    }
    int numLeft = k-inL;
    root -> lchild = create(preL+1,preL+numLeft,inL,k-1);
    root -> rchild = create(preL+numLeft+1,preR,k+1,inR);
    return root;
}
int num=0;

void postorder(Node* root) {
    if(root==NULL) {
        return ;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d",root->data);
    num++;
    if(num!=n) {
        printf(" ");
    }
}

int main() {
    scanf("%d",&n);
    stack<int> st;
    int i;
    string s;
    int id,numpre=0,numin=0;
    for(i=0;i<2*n;i++) {
        cin >> s;
        if(s[1]=='u') {
            cin >> id;
            st.push(id);
            pre[numpre++] = id;
        } else if(s[1]=='o'){
            int now = st.top();
            in[numin++] = now;
            st.pop();
        }
    }
    Node* root = create(0,n-1,0,n-1);
    postorder(root);
    return 0;
}
