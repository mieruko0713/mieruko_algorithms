//
//  1099.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=110;
struct node {
    int data;
    int lchild, rchild;
}Node[maxn];

int n, in[maxn],num=0;

void inOrder(int root) {
    if(root==-1) {
        return;
    }
    inOrder(Node[root].lchild);
    Node[root].data = in[num++];
    inOrder(Node[root].rchild);
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    num = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        printf("%d",Node[now].data);
        num++;
        if(num<n) {
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

int main() {
    int lchild, rchild;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        scanf("%d%d",&lchild,&rchild);
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    for(i=0;i<n;i++) {
        scanf("%d",&in[i]);
    }
    sort(in,in+n);
    inOrder(0);
    BFS(0);
    return 0;
}
