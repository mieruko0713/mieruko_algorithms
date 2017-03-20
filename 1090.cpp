//
//  1090.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

const int maxn = 100010;
vector<int> child[maxn];
double p, r;

int n,maxDepth=-1,num=0;

void DFS(int index, int depth) {
    if(child[index].size()==0) {
        if(depth>maxDepth){
            maxDepth = depth;
            num = 1;
        } else if(depth == maxDepth) {
            num++;
        }
        return ;
    }
    for(int i=0;i<child[index].size();i++) {
        DFS(child[index][i],depth+1);
    }
}

int main() {
    int father,root;
    scanf("%d %lf %lf",&n,&p,&r);
    r = r/100;
//    printf("p:%lf\n",p);
    for(int i=0;i<n;i++) {
        scanf("%d",&father);
        if(father!=-1) {
            child[father].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root,0);
    printf("%.2lf %d",p*pow(1+r,maxDepth),num);
    return 0;
}
