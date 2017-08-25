//
//  1080.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 40010;
const int maxm = 110;
int n,m,k,all[maxm];

struct Stu {
    int ge,gi,rank,id;
    double avg;
    int sc[5];
}stu[maxn];

struct Sc {
    int stu[maxn],count;
}sc[maxm];

bool cmp(Stu a, Stu b) {
    if(a.avg!=b.avg) {
        return a.avg > b.avg;
    }
    return a.ge > b.ge;
}


int main() {
    scanf("%d%d%d",&n,&m,&k);
    int i;
    for(i=0;i<m;i++) {
        scanf("%d",&all[i]);
    }
//    for(i=0;i<m;i++) {
//        printf("%d\n",all[i]);
//    }
    for(i=0;i<n;i++){
        scanf("%d%d",&stu[i].ge,&stu[i].gi);
        stu[i].avg = (stu[i].gi+stu[i].ge)*1.0/2;
        for(int j=0;j<k;j++) {
            scanf("%d",&stu[i].sc[j]);
        }
        stu[i].id = i;
    }
    sort(stu,stu+n,cmp);
    stu[stu[0].id].rank = 0;
    for(i=1;i<n;i++) {
        if(stu[i].avg==stu[i-1].avg&&stu[i].ge==stu[i-1].ge) {
            stu[stu[i].id].rank = stu[stu[i-1].id].rank;
        } else {
            stu[stu[i].id].rank = i;
        }
    }
    for(i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            int scid = stu[i].sc[j];
            int count = sc[scid].count;
            if(stu[i].id==9) {
//                printf("count: %d\n",count);
            }
            if(count<all[scid]) {
//                printf("入\n");
                sc[scid].stu[count++] = stu[i].id;
                sc[scid].count = count;
                break;
            } else {
//                printf("入\n");
                if(stu[stu[i].id].rank==stu[sc[scid].stu[count-1]].rank) {
                    sc[scid].stu[count++] = stu[i].id;
                    sc[scid].count = count;
                    break;
                }
            }
        }
    }
    for(i=0;i<m;i++) {
        if(sc[i].count==0) {
            printf("\n");
        } else{
//            printf("%d\n",sc[i].count);
            sort(sc[i].stu,sc[i].stu+sc[i].count);
            for(int j=0;j<sc[i].count;j++) {
                printf("%d",sc[i].stu[j]);
                if(j!=sc[i].count-1) {
                    printf(" ");
                } else {
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
