//
//  1080.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 40010;

struct Student {
    int ge,gi,sum;
    int r,id;
    int cho[6];
}stu[maxn];

struct School {
    int quota;
    int stunum;
    int id[40010];
    int lastAdmit;
}sch[110];

bool cmpStu(Student a, Student b) {
    if(a.sum!=b.sum) {
        return a.sum > b.sum;
    } else {
        return a.ge > b.ge;
    }
}

bool cmpId(int a, int b) {
    return a<b;
}

int main() {
    int i,n,m,k,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<m;i++) {
        scanf("%d",&sch[i].quota);
        sch[i].lastAdmit = -1;
//        printf("num:%d\n",sch[i].stunum);
    }
    for(i=0;i<n;i++) {
        stu[i].id = i;
        scanf("%d%d",&stu[i].ge,&stu[i].gi);
        stu[i].sum = stu[i].ge + stu[i].gi;
        int j;
        for(j=0;j<k;j++) {
            scanf("%d",&stu[i].cho[j]);
        }
    }
    sort(stu,stu+n,cmpStu);
//    for(i=0;i<n;i++) {
//        printf("id:%d\n",stu[i].id);
//    }
    for(i=0;i<n;i++) {
        if(stu[i].sum == stu[i-1].sum&&stu[i].ge==stu[i-1].ge) {
            stu[i].r = stu[i-1].r;
        } else {
            stu[i].r = i;
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<k;j++) {
            int choice = stu[i].cho[j];
            int num = sch[choice].stunum;
            int lastNum = sch[choice].lastAdmit;
            if(num<sch[choice].quota||stu[i].r==stu[lastNum].r) {
                sch[choice].id[num] = stu[i].id;
                sch[choice].stunum++;
                sch[choice].lastAdmit = i;
                break;
            }
        }
    }
    for(i=0;i<m;i++) {
        if(sch[i].stunum>0) {
            sort(sch[i].id,sch[i].id+sch[i].stunum,cmpId);
            for(j=0;j<sch[i].stunum;j++) {
                printf("%d",sch[i].id[j]);
                if(j!=sch[i].stunum-1) {
                    printf(" ");
                } else {
                    printf("\n");
                }
            }
        } else {
            printf("\n");
        }
    }
    return 0;
}
