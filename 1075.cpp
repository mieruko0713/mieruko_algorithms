//
//  1075.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,k,m;
const int maxn = 10010;
bool hashes[maxn]={false};
int all[6];


struct Stu {
    int id,score[6],rank,sum,perf;
    bool flag;
}stu[maxn];

vector<Stu> ans;

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
            if(sc!=-1) {
                stu[sid].flag = true;
            }
        }
    }
    for(i=1;i<=n;i++) {
        if(stu[i].flag) {
            for(int j=1;j<=k;j++) {
                        if(stu[i].score[j]==all[j]) {
                            stu[i].perf++;
                        }
                if(stu[i].score[j]!=-1&&stu[i].score[j]!=-2) {
                   stu[i].sum += stu[i].score[j];
                } else if(stu[i].score[j]==-1){
                    stu[i].score[j] = 0;
                }
            }
            ans.push_back(stu[i]);

        }
    }
    sort(ans.begin(),ans.end(),cmp);
    ans[0].rank = 0;
    int rank = 0;
    for(i=1;i<ans.size();i++) {
        rank++;
        if(ans[i].sum == ans[i-1].sum) {
            ans[i].rank = ans[i-1].rank;
        } else {
            ans[i].rank = rank;
        }
    }
    for(i=0;i<=ans.size()-1;i++) {
            printf("%d %05d %d",ans[i].rank+1,ans[i].id,ans[i].sum);
            for(int j=1;j<=k;j++) {
                int score = ans[i].score[j];
                if(ans[i].score[j]==-2) {
                    printf(" -");
                } else {
                    printf(" %d",ans[i].score[j]);
                }
                if(j==k) {
                    printf("\n");
                }
            }
        }
    return 0;
}
