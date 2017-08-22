//
//  1036.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/22.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
const int maxn = 10010;
int n;

struct stu {
    char name[12],sex,id[12];
    int grade;
}stus[maxn];

int main() {
    scanf("%d",&n);
    int i,min1=101,max2=-1,idx1=0,idx2=0;
    for(i=0;i<n;i++) {
        scanf("%s %c %s %d",stus[i].name,&stus[i].sex,stus[i].id,&stus[i].grade);
//        printf("%s %c %s %d\n",stus[i].name,stus[i].sex,stus[i].id,stus[i].grade);
        if(stus[i].sex=='M'&&stus[i].grade<min1) {
            min1 = stus[i].grade;
            idx1 = i;
        }
        if(stus[i].sex=='F'&&stus[i].grade>max2){
            max2 = stus[i].grade;
            idx2 = i;
        }

    }
    if(max2==-1) {
        printf("Absent\n");
    } else {
        printf("%s %s\n",stus[idx2].name,stus[idx2].id);
    }
    if(min1==101) {
        printf("Absent\n");
    } else {
        printf("%s %s\n",stus[idx1].name,stus[idx1].id);
    }
    if(max2==-1||min1==101) {
        printf("NA");
    } else {
        printf("%d",stus[idx2].grade-stus[idx1].grade);
    }
}
