//
//  1102.cpp
//  算法
//
//  Created by 王怡凡 on 2017/9/6.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<queue>
using namespace std;
const int maxn = 20;
int n,root,num=0;

struct Node {
    int left,right;
}node[maxn];
int notroot[maxn];

void bfs(int root) {
    queue<int> q;
    q.push(root);
    int num = 0;
    while(!q.empty()) {
        int now = q.front();
        printf("%d",now);
        num++;
        if(num!=n) {
            printf(" ");
        } else {
            printf("\n");
        }
        q.pop();
        if(node[now].right!=-1) {
            q.push(node[now].right);
        }
        if(node[now].left!=-1) {
            q.push(node[now].left);
        }
    }
}

void inorder(int index) {
    if(index==-1) {
        return ;
    }
    inorder(node[index].right);
    printf("%d",index);
    num++;
    if(num!=n) {
        printf(" ");
    } else {
        printf("\n");
    }
    inorder(node[index].left);
}

int main() {
    scanf("%d",&n);
    int i;
    char left, right;
    for(i=0;i<n;i++) {
        getchar();
        scanf("%c %c",&left,&right);
        if(left=='-') {
            node[i].left = -1;
        } else {
            node[i].left = left - '0';
            notroot[node[i].left] = 1;
        }
        if(right=='-') {
            node[i].right = -1;
        } else {
            node[i].right = right - '0';
            notroot[node[i].right] = 1;
        }
//        printf("%d %d\n",node[i].left,node[i].right);
    }
    for(i=0;i<n;i++) {
        if(notroot[i]==0) {
            root = i;
            break;
        }
    }
    bfs(root);
    inorder(root);
    return 0;
}
