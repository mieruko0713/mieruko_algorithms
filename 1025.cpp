//
//  1025.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/21.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;

struct stu{
    char num[15];
    int score,rank1,rank2,location;
} stus[30010];

bool cmp1(stu a, stu b) {
    if(a.score!=b.score) {
        return a.score>b.score;
    }
    return strcmp(a.num,b.num)<0;
}

int main() {
    int n,k,all=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            scanf("%s %d",stus[all].num,&stus[all].score);
            stus[all].location = i+1;
            all++;
        }
        sort(stus+all-k,stus+all,cmp1);
        int rank1=1;
        stus[all-k].rank1 = rank1++;
        for(int j=all-k+1;j<all;j++) {
            if(stus[j].score==stus[j-1].score) {
                stus[j].rank1 = stus[j-1].rank1;
            } else {
                stus[j].rank1 = rank1;
            }
            rank1++;
        }
    }
    printf("%d\n",all);
    sort(stus,stus+all,cmp1);
    int rank2 = 1;
    stus[0].rank2 = 1;
    printf("%s %d %d %d\n",stus[0].num,stus[0].rank2,stus[0].location,stus[0].rank1);
    rank2++;
    for(int i=1;i<all;i++) {
        if(stus[i].score==stus[i-1].score) {
            stus[i].rank2 = stus[i-1].rank2;
        } else {
            stus[i].rank2 = rank2;
        }
        rank2++;
        printf("%s %d %d %d\n",stus[i].num,stus[i].rank2,stus[i].location,stus[i].rank1);
    }
    return 0;
}
