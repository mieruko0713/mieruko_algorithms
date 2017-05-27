//
//  1017.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//


#include<cstdio>
#include<algorithm>
using namespace std;
int n, k;
const int maxn = 11000;
struct person {
    int hh,mm,ss,p,end,start;
}people[maxn];
int sum=0;
int windows[110];

int convertTime(int hh, int mm, int ss) {
    return hh*3600 + mm*60 + ss;
}

bool cmp(person a, person b) {
    return convertTime(a.hh, a.mm, a.ss) < convertTime(b.hh, b.mm, b.ss);
}



int main() {
    scanf("%d %d",&n,&k);
    int i;
    for(i=0;i<n;i++) {
        scanf("%d:%d:%d %d",&people[i].hh,&people[i].mm,
              &people[i].ss,&people[i].p);
    }
    sort(people,people+n,cmp);
    for(i=0;i<k;i++) {
        windows[i] = convertTime(8,0,0);
    }
    
    for(i=0;i<n;i++) {
        int j,minTime=1<<30,minIdx=-1;
        for(j=0;j<k;j++) {
            if(minTime > windows[j]) {
                minTime = windows[j];
                minIdx = j;
            }
        }
        if(convertTime(people[i].hh,people[i].mm,people[i].ss)<=minTime) {
            people[i].start = minTime;
        } else {
            people[i].start = convertTime(people[i].hh,people[i].mm,people[i].ss);
        }
        windows[minIdx] = people[i].start + people[i].p*60;
//        printf("people:%d %d %d\n",people[i].start/3600,people[i].start%3600/60, people[i].start%60);
    }
    int num=0;
    for(i=0;i<n;i++) {
        if(convertTime(people[i].hh,people[i].mm,people[i].ss)>convertTime(17,0,0)) {
            continue;
        }
        sum += people[i].start - convertTime(people[i].hh,people[i].mm,people[i].ss);
        num++;
    }
    printf("%.1f",sum/60.0/num);
    return 0;
}
