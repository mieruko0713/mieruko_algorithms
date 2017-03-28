//
//  1057.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int sqrN = 317;

stack<int> st;
int block[sqrN];
int table[maxn];

void peekMedian(int k) {
//    printf("p\n");
    int sum = 0;
    int idx = 0;
    while(sum+block[idx]<k) {
        sum+=block[idx++];
    }
    int num = idx*sqrN;
    while(sum+table[num]<k) {
        sum += table[num++];
    }
    printf("%d\n",num);
}

void Push(int x) {
    st.push(x);
    block[x/sqrN]++;
    table[x]++;
}

void Pop() {
    int x = st.top();
    st.pop();
    block[x/sqrN]--;
    table[x]--;
    printf("%d\n",x);
}

int main() {
    int x,i,query;
    memset(block,0,sizeof(block));
    memset(table,0,sizeof(table));
    char cmd[20];
    scanf("%d",&query);
    for(i=0;i<query;i++) {
        scanf("%s",cmd);
        if(strcmp(cmd,"Push")==0) {
            scanf("%d",&x);
            Push(x);
        } else if(strcmp(cmd,"Pop")==0) {
            if(st.empty()==true) {
                printf("Invalid\n");
            } else {
                Pop();
            }
        } else {
            if(st.empty()==true) {
                printf("Invalid\n");
            } else {
                int k = st.size();
//                printf("%d:k",k);
                if(k%2==1) {
                    k = (k+1)/2;
                } else {
                    k = k/2;
                }
                peekMedian(k);
            }
        }
    }
    return 0;
}
