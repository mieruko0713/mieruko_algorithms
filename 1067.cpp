//
//  1067.cpp
//  算法
//
//  Created by 王怡凡 on 2017/4/2.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int ans = 0;
int pos[maxn];

int main() {
    int n, i, maxn;
    scanf("%d",&n);
    int left = n-1,num;
    for(i=0;i<n;i++) {
        scanf("%d",&num);
        pos[num] = i;
        if(num==i) {
            left--;
        }
    }
    int k=1;
    while(left>0) {
        if(pos[0]==0) {
            while(k<n) {
                if(pos[k]!=k) {
                    swap(pos[0],pos[k]);
                    ans++;
                    break;
                }
                k++;
            }
        }
        while(pos[0]!=0) {
            swap(pos[0],pos[pos[0]]);
            ans++;
            left--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
