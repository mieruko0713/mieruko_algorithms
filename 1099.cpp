//
//  1099.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 110;
int in[maxn],num=0,n;
struct node {
    int data;
    int lchild, rchild;
}Node[maxn];

void BFS(int root) {
    int now;
    queue<int> q;
    q.push(root);
    num = 0;
    while(!q.empty()) {
        now = q.front();
        q.pop();
        num++;
        printf("%d",Node[now].data);
        if(num!=n) {
            printf(" ");
        }
        if(Node[now].lchild!=-1) {
            q.push(Node[now].lchild);
        }
        if(Node[now].rchild!=-1) {
            q.push(Node[now].rchild);
        }
    }
}

void inorder(int root) {
    if(root==-1) {
        return ;
    }
    inorder(Node[root].lchild);
    Node[root].data = in[num++];
    inorder(Node[root].rchild);
}

int main() {
    int i,left,right;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d",&left,&right);
        Node[i].lchild = left;
        Node[i].rchild = right;
    }
    for(i=0;i<n;i++) {
        scanf("%d",&in[i]);
    }
    sort(in,in+n);
    inorder(0);
    BFS(0);
}

