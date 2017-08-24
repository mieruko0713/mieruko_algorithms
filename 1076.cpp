//
//  1076.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1010;
bool inq[maxn] = {false};
int n,l;
struct Node {
    int id,layer;
};

vector<Node> adj[maxn];



void bfs(int s, int l) {
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while(!q.empty()) {
        Node now = q.front();
        q.pop();
        int u = now.id;
        for(int i=0;i<adj[u].size();i++) {
            Node next = adj[u][i];
            next.layer = now.layer+1;
            if(inq[next.id]==false&&next.layer<=l) {
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    printf("%d\n",numForward);
}

int main() {
    scanf("%d %d",&n,&l);
    int i,k,v;
    Node user;
    for(i=1;i<=n;i++) {
        user.id = i;
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            scanf("%d",&v);
            adj[v].push_back(user);
        }
    }
    int query,q;
    scanf("%d",&query);
    for(i=0;i<query;i++){
        memset(inq,false,sizeof(inq));
        scanf("%d",&q);
        bfs(q,l);
    }
    return 0;
}
