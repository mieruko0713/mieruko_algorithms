//
//  1006.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/14.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

char ans1[16],ans2[16];
int in=24*3600,out = -1;

struct person {
    char id[16];
    int hh;
    int mm;
    int ss;
    int time;
};

vector<person> people;

int changeToTime(int hh, int mm, int ss) {
    return hh*3600+mm*60+ss;
}


bool cmp(person a, person b) {
    return a.time < b.time;
}

int main(){
    int m,i;
    scanf("%d",&m);
    for(i=0;i<m;i++) {
        person p;
        scanf("%s",p.id);
        scanf("%d:%d:%d",&p.hh,&p.mm,&p.ss);
        p.time = changeToTime(p.hh,p.mm,p.ss);
        if(p.time<in) {
            strcpy(ans1,p.id);
            in = p.time;
        }
        scanf("%d:%d:%d",&p.hh,&p.mm,&p.ss);
        p.time = changeToTime(p.hh, p.mm, p.ss);
        if(p.time>out) {
            strcpy(ans2,p.id);
            out = p.time;
        }
    }
    printf("%s ", ans1);
    printf("%s",ans2);
    return 0;
}
