//
//  1095.cpp
//  算法
//
//  Created by 王怡凡 on 2017/9/3.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
#include<string>
using namespace std;
int n,k,maxTime=-1;
const int maxn = 10010;
vector<string> ans;
map<string, int> parkTime;

struct Car {
    char id[8];
    int time;
    bool status;
}cars[maxn],valid[maxn];


bool cmp(Car a, Car b) {
    if(strcmp(a.id,b.id)) {
        return strcmp(a.id,b.id)<0;
    } else {
        return a.time<b.time;
    }
}

bool cmpByTime(Car a, Car b) {
    return a.time < b.time;
}

int timeToInt(int hh, int mm, int ss) {
    return hh*3600+mm*60+ss;
}

int main() {
    int hh,mm,ss;
    char status[4];
    scanf("%d %d",&n,&k);
    int i=0;
    for(i=0;i<n;i++) {
        scanf("%s %d:%d:%d %s",cars[i].id,&hh,&mm,&ss,status);
        cars[i].time = timeToInt(hh,mm,ss);
        if(strcmp(status,"in")==0) {
            cars[i].status = true;
        } else {
            cars[i].status = false;
        }
    }
    sort(cars,cars+n,cmp);
    int num1=0;
    for(i=0;i<n-1;i++) {
        if(!strcmp(cars[i].id,cars[i+1].id)&&cars[i].status==true&&cars[i+1].status==false) {
            valid[num1++]=cars[i];
            valid[num1++]=cars[i+1];
            int inTime = cars[i+1].time - cars[i].time;
            string id = cars[i].id;
//            if(parkTime.count(id)==0) {
//                parkTime[id] = 0;
//            }
            parkTime[id] += inTime;
            if(maxTime<parkTime[id]) {
                maxTime = parkTime[id];
            }
        }
    }
    sort(valid,valid+num1,cmpByTime);
    int num=0,j=0;
    for(i=0;i<k;i++) {
        scanf("%d:%d:%d",&hh,&mm,&ss);
        int time = timeToInt(hh,mm,ss);
        for(;j<num1;j++) {
            if(valid[j].time>time) {
                break;
            } else {
                if(valid[j].status) {
                    num++;
                } else {
                    num--;
                }
            }
        }
        printf("%d\n",num);
    }
        map<string,int>::iterator it;
        for(it=parkTime.begin();it!=parkTime.end();it++) {
            if(it->second==maxTime) {
                printf("%s ",it->first.c_str());
            }
        }
        printf("%02d:%02d:%02d",maxTime/3600,maxTime%3600/60,maxTime%60);
    return 0;
}
