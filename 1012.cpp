//
//  1012.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/18.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct stu {
    int id,c,m,e,a;
    int grade[4];
}stus[2010];

int Rank[1000000][4] = {0},now;
char course[4] = {'A','C','M','E'};

bool cmp(stu a, stu b) {
    return a.grade[now] > b.grade[now];
}

int main() {
    int n,m,i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%d %d %d %d",&stus[i].id,&stus[i].grade[1],&stus[i].grade[2],&stus[i].grade[3]);
        stus[i].grade[0] = round((stus[i].grade[1]+stus[i].grade[2]+stus[i].grade[3])/3.0);
    }
    for(now=0;now<4;now++) {
        sort(stus,stus+n,cmp);
        Rank[stus[0].id][now] = 1;
        for(i=1;i<n;i++) {
            if(stus[i].grade[now]==stus[i-1].grade[now]) {
                Rank[stus[i].id][now] = Rank[stus[i-1].id][now];
            } else {
                Rank[stus[i].id][now] = i + 1;
            }
        }
    }
    int query;
    for(i=0;i<m;i++) {
        scanf("%d",&query);
        if(Rank[query][0]==0) {
            printf("N/A\n");
        } else {
            int k = 0,j;
            for(j=0;j<4;j++) {
                if(Rank[query][j]<Rank[query][k]) {
                    k = j;
                }
            }
            printf("%d %c\n",Rank[query][k],course[k]);
        }
    }
    return 0;
}
