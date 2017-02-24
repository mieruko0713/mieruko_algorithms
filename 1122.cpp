//
//  1122.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 210;
int G[maxn][maxn],n,m;
vector<int> temp;

bool connected(vector<int> v) {
    int i;
    for(i=0;i<=v.size()-2;i++) {
        if(G[v[i]][v[i+1]]!=1) {
            return false;
        }
    }
    return true;
}

bool repeat(vector<int> v ) {
    int i;
    sort(v.begin(),v.end());
    for(i=0;i<=v.size()-2;i++) {
        if(v[i]==v[i+1]) {
            return false;
        }
    }
    return true;
}

int main(){
    int i,j,a,b,query,k,c;
    scanf("%d",&n);
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        scanf("%d%d",&a,&b);
        G[a][b]=1;
        G[b][a]=1;
    }
    scanf("%d",&query);
    for(i=0;i<query;i++) {
        scanf("%d",&k);
        for(j=0;j<k;j++) {
            scanf("%d",&c);
            temp.push_back(c);
        }
        if(temp.size()!=n+1) {
            printf("NO\n");
            temp.clear();
            continue;
        }
        if(temp[temp.size()-1]!=temp[0]) {
            printf("NO\n");
            temp.clear();
            continue;
        }
        if(repeat(temp)) {
            printf("NO\n");
            temp.clear();
            continue;
        }
        if(!connected(temp)) {
            printf("NO\n");
            temp.clear();
            continue;
        }
        printf("YES\n");
    }
    return 0;
}
