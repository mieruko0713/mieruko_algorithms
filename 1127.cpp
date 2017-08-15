//
//  1127.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/15.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 40;

struct node {
    int data;
    node* lchild;
    node* rchild;
    int layer;
};
int pre[maxn],in[maxn],post[maxn];
int n,allLayer;
vector<int> bfs[maxn];

//void BFS(node* root) {
//    int num=0;
//    queue<node*> q;
//    q.push(root);
//    while(!q.empty()) {
//        node* now = q.front();
//        q.pop();
//        if(now->layer%2==1){
//            printf("%d",now->data);
//            if(num!=n) {
//                printf(" ");
//            }
//        } else {
//            even.push_back(now->data);
//        }
//        
//        if(now->layer%2==1) {
//            
//        }
//        q.pop();
//        
//    }
//}

node* create(int postL, int postR, int inL, int inR, int layer) {
    if(postL>postR) {
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];
    root->layer = layer++;
    allLayer = max(root->layer,allLayer);
    bfs[root->layer].push_back(root->data);
    int k;
    for(k=inL;k<=inR;k++) {
        if(in[k]==post[postR]) {
            break;
        }
    }
    int numLeft = k-inL;
    root->lchild = create(postL,postL+numLeft-1,inL,k-1,layer);
    root->rchild = create(postL+numLeft, postR-1,k+1,inR,layer);
    return root;
}

int main() {
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++) {
        scanf("%d",&in[i]);
    }
    for(i=0;i<n;i++) {
        scanf("%d",&post[i]);
    }
    node* root = create(0,n-1,0,n-1,1);
    int num = 0;
    for(i=1;i<=allLayer;i++) {
//        printf("layer:%d\n",bfs[i].size());
        if(i%2==0) {
            for(int j=0;j<bfs[i].size();j++) {
                printf("%d",bfs[i][j]);
                num++;
                if(num!=n) {
                    printf(" ");
                }
            }
        } else {
            int size = bfs[i].size()-1;
            for(int j=size;j>=0;j--) {
                printf("%d",bfs[i][j]);
                num++;
                if(num!=n) {
                    printf(" ");
                }
            }
        }
    }
    return 0;
}
