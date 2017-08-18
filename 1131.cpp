//
//  1131.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/17.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
using namespace std;
const int maxn=10010;
const int INF = 1000000000;
int line[maxn][maxn];
vector<int> v[maxn];
vector<int> tempPath, path;
int minNum = INF;
int minChg = INF;
int visit[maxn] = {0};

void dfs(int st, int ed) {
    if(st==ed) {
        int chg=0,num=int(tempPath.size())-1;
        if(num<minNum) {
            minNum = num;
            path = tempPath;
        } else if(num==minNum) {
            for(int i=1;i<tempPath.size()-1;i++) {
                int pre = tempPath[i-1];
                int next = tempPath[i];
                int nnext = tempPath[i+1];
//                if(line[pre][next]!=preline) {
//                    chg++;
//                    preline = line[tempPath[i-1]][tempPath[i]];
//                }
                if(line[pre][next]!=line[next][nnext]) {
                    chg++;
//                    printf("pre:%d next:%d nnext: %d\n",pre,next,nnext);
                }
            }
            if(chg<minChg) {
//                printf("chg:%d\n",chg);
                minChg = chg;
                path = tempPath;
//                for(int j=0;j<tempPath.size();j++) {
//                    printf("%d\n",tempPath[j]);
//                }
            }
        }
        return;
    }
    for(int i=0;i<v[st].size();i++) {
        if(!visit[v[st][i]]) {
            visit[v[st][i]] = 1;
            tempPath.push_back(v[st][i]);
            dfs(v[st][i],ed);
            visit[v[st][i]] = 0;
            tempPath.pop_back();
        }
    }
}

int main() {
    int i,j,n,m,pre,next,k,st,ed;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&m);
        scanf("%d",&pre);
        for(j=1;j<m;j++) {
            scanf("%d",&next);
            v[pre].push_back(next);
            v[next].push_back(pre);
            line[pre][next] = line[next][pre] = i+1;
            pre = next;
        }
    }
    scanf("%d",&k);
    for(i=0;i<k;i++) {
        scanf("%d%d",&st,&ed);
        minNum = INF;
        minChg = INF;
        visit[st] = 1;
        tempPath.push_back(st);
        dfs(st,ed);
        visit[st] = 0;
        tempPath.pop_back();
        printf("%d\n",minNum);
        int first=0,last=0;
        first = path[0];
        for(j=1;j<path.size();j++) {
            if(j==path.size()-1) {
                last = path[j];
                printf("Take Line#%d from %04d to %04d.\n",line[path[j]][path[j-1]],first,last);
                break;
            }
            if(line[path[j]][path[j-1]]!=line[path[j]][path[j+1]]) {
                last = path[j];
                printf("Take Line#%d from %04d to %04d.\n",line[path[j-1]][path[j]],first,last);
                first = path[j];
            }
            
        }
    }
    return 0;
}
