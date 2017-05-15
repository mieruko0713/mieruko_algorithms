//
//  1008.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/15.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
using namespace std;

vector<int> num;

int main(){
    int n,i,number,sum=0;
    scanf("%d",&n);
    num.push_back(0);
    for(i=1;i<=n;i++) {
        scanf("%d",&number);
        num.push_back(number);
        if(num[i]>num[i-1]) {
            sum += (num[i]- num[i-1])*6;
        } else {
            sum += (num[i-1] - num[i]) * 4;
        }
    }
    sum += n*5;
    printf("%d",sum);
    return 0;
}
