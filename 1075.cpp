//
//  1075.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
int n,k,m;
const int maxn = 10010;
bool hashes[maxn]={false};
int all[6];

struct Stu {
    int id,score[6],rank,sum,perf;
}stu[maxn];

bool cmp(Stu a, Stu b) {
    if(a.sum!=b.sum) {
        return a.sum > b.sum;
    }
    if(a.perf!=b.perf) {
        return a.perf > b.perf;
    }
    return a.id < b.id;
}

int main() {
    scanf("%d %d %d",&n,&k,&m);
    int i,sid,pid,sc;
    for(i=1;i<=k;i++) {
        scanf("%d",&all[i]);
    }
    for(i=1;i<=n;i++) {
        fill(stu[i].score,stu[i].score+6,-2);
    }
    for(i=0;i<m;i++) {
        scanf("%d %d %d",&sid,&pid,&sc);
        stu[sid].id = sid;
        if(stu[sid].score[pid]<sc) {
            stu[sid].score[pid] = sc;
        }
    }
    for(i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(stu[i].score[j]!=-1&&stu[i].score[j]!=-2) {
                if(!hashes[i]) {
                    hashes[i] = true;
                }
            }
            if(stu[i].score[j]==-1) {
                stu[i].score[j] = 0;
            } else if(stu[i].score[j]==all[j]) {
                stu[i].perf++;
            } else if(stu[i].score[j]==-2) {
                continue;
            }
            stu[i].sum += stu[i].score[j];
        }
    }
    sort(stu+1,stu+n+1,cmp);
    stu[1].rank = 1;
    int rank = 1;
    for(i=2;i<=n;i++) {
        if(hashes[stu[i].id]) {
            rank++;
        }
        if(stu[i].sum == stu[i-1].sum) {
            stu[i].rank = stu[i-1].rank;
        } else {
            stu[i].rank = rank;
        }
    }
    for(i=1;i<=n;i++) {
        if(hashes[stu[i].id]) {
            printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].sum);
            for(int j=1;j<=k;j++) {
                int score = stu[i].score[j];
                if(score==-1) {
                    printf(" 0");
                } else if(stu[i].score[j]==-2) {
                    printf(" -");
                } else {
                    printf(" %d",stu[i].score[j]);
                }
                if(j==k) {
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
