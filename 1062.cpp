//
//  1062.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/6.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100010;

int n,l,h;
struct stu {
    int id,t,v;
} stus[maxn];
vector<stu> sages,noblemen,fool,other;

bool cmp(stu a, stu b) {
    int totala = a.t + a.v;
    int totalb = b.t + b.v;
    if(totala==totalb) {
        if(a.v==b.v) {
            return a.id < b.id;
        }
        return a.v > b.v;
    }
    return totala > totalb;
}

int main() {
    scanf("%d%d%d",&n,&l,&h);
    int i,id,t,v,num=0;
    for(i=0;i<n;i++) {
        scanf("%d%d%d",&id,&v,&t);
        if(t>=l&&v>=l) {
            num++;
            stus[i].t = t;
            stus[i].v = v;
            stus[i].id = id;
            if(t>=h&&v>=h) {
                sages.push_back(stus[i]);
            } else if(v>=h) {
                noblemen.push_back(stus[i]);
            } else if(v<h&&t<h&&v>=t) {
                fool.push_back(stus[i]);
            } else {
                other.push_back(stus[i]);
            }
        }
    }
    printf("%d\n",num);
    sort(sages.begin(),sages.end(),cmp);
    for(i=0;i<sages.size();i++) {
        printf("%08d %d %d\n",sages[i].id,sages[i].v,sages[i].t);
    }
    sort(noblemen.begin(),noblemen.end(),cmp);
    for(i=0;i<noblemen.size();i++) {
        printf("%08d %d %d\n",noblemen[i].id,noblemen[i].v,noblemen[i].t);
    }
    sort(fool.begin(),fool.end(),cmp);
    for(i=0;i<fool.size();i++) {
        printf("%08d %d %d\n",fool[i].id,fool[i].v,fool[i].t);
    }
    sort(other.begin(),other.end(),cmp);
    for(i=0;i<other.size();i++) {
        printf("%08d %d %d\n",other[i].id,other[i].v,other[i].t);
    }
    return 0;
}

