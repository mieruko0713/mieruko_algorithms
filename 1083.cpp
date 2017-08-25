//
//  1083.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/25.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n;

struct Stu {
    char name[11],id[11];
    int grade;
}stu[maxn];

bool cmp(Stu a, Stu b) {
    return a.grade>b.grade;
}

int main() {
    int grade1,grade2;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%s%s%d",stu[i].name,stu[i].id,&stu[i].grade);
    }
    scanf("%d %d",&grade1,&grade2);
    sort(stu,stu+n,cmp);
    int num=0;
    for(int i=0;i<n;i++) {
        if(stu[i].grade>=grade1&&stu[i].grade<=grade2) {
            printf("%s %s\n",stu[i].name,stu[i].id);
            num++;
        }
        if(stu[i].grade<grade1) {
            break;
        }
    }
    if(num==0) {
        printf("NONE");
    }
    return 0;
}
