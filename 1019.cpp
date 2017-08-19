//
//  1019.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/19.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector> 
using namespace std;
int n,b;

int main() {
    scanf("%d%d",&n,&b);
    int num;
    vector<int> result;
    do {
        num = n%b;
        result.push_back(num);
        n /= b;
    } while(n!=0);
    int length = int(result.size());
    bool flag = true;
    for(int i=length-1;i>=0;i--) {
        if(result[i]!=result[length-1-i]) {
            flag = false;
            break;
        }
    }
    if(!flag) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    for(int i=length-1;i>=0;i--) {
        printf("%d",result[i]);
        if(i!=0) {
            printf(" ");
        }
    }
    return 0;
}
