//
//  1033.cpp
//  算法
//
//  Created by 王怡凡 on 2017/9/4.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 510;
double cmax,d,davg;
int n;
const int INF = 1000000000;

struct sta {
    double dis,price;
}st[maxn];

bool cmp(sta a, sta b) {
    return a.dis<b.dis;
}

int main() {
    scanf("%lf%lf%lf%d",&cmax,&d,&davg,&n);
    int i;
    for(i=0;i<n;i++) {
        scanf("%lf%lf",&st[i].price,&st[i].dis);
    }
    st[n].price = 0;
    st[n].dis = d;
    sort(st,st+n+1,cmp);
    int now=0;
    double need,nowTank=0,ans=0;
    if(st[0].dis!=0) {
        printf("The maximum travel distance = 0.00");
    } else {
        while(now<n) {
            int k=-1, MIN = INF,dmax=cmax*davg;
            for(int j=now+1;(st[j].dis-st[now].dis)<=dmax&&j<=n;j++) {
                if(st[j].price<MIN) {
                    MIN = st[j].price;
                    k=j;
                    if(MIN<st[now].price) {
                        break;
                    }
                }
            }
            if(k==-1) {
                break;
            }
            need = (st[k].dis - st[now].dis)/davg;
            if(MIN<st[now].price) {
                if(nowTank>=need) {
                    nowTank -= need;
                } else {
                    ans += (need-nowTank)*st[now].price;
                    nowTank = 0;
                }
            } else {
                ans += (cmax-nowTank)*st[now].price;
                nowTank = cmax - need;
            }
            now = k;
        }
        if(now!=n) {
            printf("The maximum travel distance = %.2lf",st[now].dis+cmax*davg);
        } else {
            printf("%.2lf",ans);
        }
    }
    
}
