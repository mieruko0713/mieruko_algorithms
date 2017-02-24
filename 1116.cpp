//
//  1116.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<string>
#include<map>
#include<math.h>
#include<iostream>
using namespace std;
const int maxn = 10010;
bool in[maxn]={false},visit[maxn]={false};
int n,m;
map<int, string> ans;
string ranks[3] = {"Mystery Award", "Minion", "Chocolate"};


bool isPrime(int x) {
    if(x<=1) {
        return false;
    }
    int i,sqr = (int)sqrt(1.0*n);
    for(i=2;i<=sqr;i++) {
        if(x%i==0) {
            return false;
        }
    }
    return true;
}

int main() {
    int i,num,query,q_num;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d",&num);
        if(i==0) {
            ans[num] = ranks[0];
        } else if(isPrime(i+1)) {
            ans[num] = ranks[1];
        } else {
            ans[num] = ranks[2];
        }
        in[num] = true;
    }
    scanf("%d",&query);
    for(i=0;i<query;i++) {
        scanf("%d",&q_num);
        printf("%04d: ", q_num);
        if(in[q_num]) {
            if(visit[q_num]) {
                printf("Checked\n");
                continue;
            }
            cout << ans[q_num] << endl;
        } else{
            printf("Are you kidding?\n");
        }
        visit[q_num] = true;
    }
    return 0;
}

