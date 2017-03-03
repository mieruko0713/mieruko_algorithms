//
//  1053.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,s;
const int maxn = 110;
int path[maxn];
struct node {
    int weight;
    vector<int> childs;
}Nodes[maxn];

bool cmp(int a, int b) {
    return Nodes[a].weight > Nodes[b].weight;
}

void DFS(int index, int numNode, int sum) {
    if(sum>s) {
        return ;
    }
    if(sum==s) {
        if(Nodes[index].childs.size()!=0) {
            return ;
        }
        for(int i=0;i<numNode;i++) {
            printf("%d",Nodes[path[i]].weight);
            if(i<numNode-1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
        return ;
    }
    for(int i=0;i<Nodes[index].childs.size();i++) {
        int child = Nodes[index].childs[i];
        path[numNode] = child;
        DFS(Nodes[index].childs[i],numNode+1,sum+Nodes[child].weight);
    }
}

int main() {
    int i,pr,j,k,child;
    scanf("%d%d%d",&n,&m,&s);
    for(i=0;i<n;i++) {
        scanf("%d",&Nodes[i].weight);
    }
    for(i=0;i<m;i++) {
        scanf("%d%d",&pr,&k);
        for(j=0;j<k;j++){
            scanf("%d",&child);
            Nodes[pr].childs.push_back(child);
            sort(Nodes[pr].childs.begin(),Nodes[pr].childs.end(),cmp);
        }
    }
    DFS(0,1,Nodes[0].weight);
    return 0;
}
