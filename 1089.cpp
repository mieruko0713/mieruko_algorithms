//
//  1089.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
int n,maxdep=-1,num=0;
double p,r;

void dfs(int index, int dep) {
    if(child[index].size()==0) {
        if(dep>maxdep) {
            maxdep = dep;
            num = 1;
        } else if(dep==maxdep) {
            num++;
        }
        return ;
    }
    for(int i=0;i<child[index].size();i++) {
        dfs(child[index][i],dep+1);
    }
}

int main(){
    scanf("%d %lf %lf",&n,&p,&r);
    r = r/100;
    int i,root;
    int sup;
    for(i=0;i<n;i++) {
        scanf("%d",&sup);
        if(sup!=-1) {
           child[sup].push_back(i);
        } else {
            root = i;
        }
        
    }
    dfs(root,0);
    double ans = p*pow(1+r,maxdep);
    printf("%.2lf %d",ans,num);
    return 0;
}
