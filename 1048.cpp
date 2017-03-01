//
//  1048.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int all[maxn],m,n;

int upper_bound(int L, int R, int x) {
    int left = L, right = R;
    int mid;
    while(left<=right) {
        mid = (left + right)/2;
        if(all[mid]==x) {
            return mid;
        } else if(all[mid]>x){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int i,j=-1;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) {
        scanf("%d",&all[i]);
    }
    sort(all,all+n);
//    for(i=0;i<n;i++) {
//        printf("all[i]: %d\n",all[i]);
//    }
    for(i=0;i<n;i++) {
        j = upper_bound(i+1, n-1, m-all[i]);
        if(all[j]+all[i] == m) {
            break;
        }
    }
    if(j==-1) {
        printf("No Solution\n");
        return 0;
    }
    printf("%d %d",all[i],all[j]);
    return 0;
}
