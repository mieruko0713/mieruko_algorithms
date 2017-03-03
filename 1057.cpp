//
//  1057.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/3.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
using namespace std;
const int maxn = 100010;
const int sqr = 317;
int block[sqr];
int table[maxn];
stack<int> s;

void push(int x) {
    s.push(x);
    table[x]++;
    block[x/sqr]++;
}

void pop() {
    int x = s.top();
    printf("%d\n",x);
    s.pop();
    table[x]--;
    block[x/sqr]--;
}

void find_median(int k) {
    int sum=0,num=0,index;
    while(sum+block[num]< k) {
        sum += block[num];
        num++;
    }
    index = num*sqr;
    while(sum+table[index]<k) {
        sum += table[index];
        index++;
    }
    printf("%d\n",index);
}

int main() {
    int i,n,x,k,size;
    memset(block,0,sizeof(block));
    memset(table,0,sizeof(table));
    char cmd[20];
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",cmd);
        if(!strcmp(cmd,"Push")) {
            scanf("%d",&x);
            push(x);
        } else if(!strcmp(cmd,"Pop")) {
            if(s.empty()) {
                printf("Invalid\n");
                continue;
            }
            pop();
        } else if(!strcmp(cmd,"PeekMedian")) {
            if(s.empty()) {
                printf("Invalid\n");
            } else {
                size = s.size();
                if(size%2==1)
                k = (size + 1)/2;
                else k = size/2;
                find_median(k);
            }
            
        }
    }
    return 0;
}
