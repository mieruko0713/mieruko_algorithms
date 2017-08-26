//
//  1091.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<queue>;
using namespace std;
const int maxx = 1230;
const int maxy = 130;
const int maxz = 62;
bool inq[maxx][maxy][maxz] = {false};
int matrix[maxx][maxy][maxz];
int m,n,l,t;
int X[6] = {0,0,0,0,1,-1};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {1,-1,0,0,0,0};

struct Node {
    int x,y,z;
}node;

bool judge(int x, int y, int z) {
    if(x>=n||x<0||y>=m||y<0||z>=l||z<0) {
        return false;
    }
    if(matrix[x][y][z]==0 || inq[x][y][z]==true) {
        return false;
    }
    return true;
}

int BFS(int x, int y, int z) {
    int tot = 0;
    queue<Node> q;
    node.x=x,node.y=y,node.z=z;
    q.push(node);
    inq[node.x][node.y][node.z] = true;
    while(!q.empty()) {
        Node top = q.front();
        q.pop();
        tot++;
        for(int i=0;i<6;i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];
            if(judge(newX,newY,newZ)) {
                node.x=newX,node.y=newY,node.z=newZ;
                q.push(node);
                inq[newX][newY][newZ] = true;
            }
        }
    }
    if(tot>=t) {
        return tot;
    } else return 0;
}
           
int main() {
    scanf("%d%d%d%d",&m,&n,&l,&t);
    int i,j,k;
    for(i=0;i<l;i++) {
        for(j=0;j<m;j++) {
            for(k=0;k<n;k++) {
                scanf("%d",&matrix[k][j][i]);
            }
        }
    }
    int ans = 0;
    for(i=0;i<l;i++) {
        for(j=0;j<m;j++) {
            for(k=0;k<n;k++) {
                if(matrix[k][j][i]==1&&inq[k][j][i]==false) {
                    ans += BFS(k,j,i);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
