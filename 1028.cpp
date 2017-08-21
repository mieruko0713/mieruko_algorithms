//
//  1028.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/21.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int n,c;

struct stus{
    char num[7],name[9];
    int grade;
}stu[100010];

//bool cmp1(stus a, stus b) {
//    if(strcmp(a.num,b.num)<0) {
//        return true;
//    }
//    return false;
//}

bool cmp1(stus a, stus b) {
    if(strcmp(a.num,b.num)<0) {
        return true;
    }
    return false;
}

bool cmp2(stus a, stus b) {
    if(strcmp(a.name,b.name)!=0) {
        return strcmp(a.name,b.name)<0;
    }
    return strcmp(a.num,b.num)<0;
}

bool cmp3(stus a, stus b) {
    if(a.grade!=b.grade) {
        return a.grade < b.grade;
    }
    return strcmp(a.num,b.num)<0;
}

int main() {
    scanf("%d%d",&n,&c);
    int i;
    for(i=0;i<n;i++) {
        scanf("%s %s %d",stu[i].num,stu[i].name,&stu[i].grade);
    }
    if(c==1) {
        sort(stu,stu+n,cmp1);
    } else if(c==2) {
        sort(stu,stu+n,cmp2);
    } else {
        sort(stu,stu+n,cmp3);
    }
    for(i=0;i<n;i++) {
        printf("%s %s %d\n",stu[i].num,stu[i].name,stu[i].grade);
    }
    return 0;
}
