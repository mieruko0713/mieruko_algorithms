//
//  1023.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
using namespace std;
char num[22];


int main() {
    scanf("%s",num);
    int nums[22];
    int i=0,length=strlen(num),count[10]={0};
    int carry = 0;
    for(i=length-1;i>=0;i--) {
//        printf("%d\n",num[i]-'0');
        int temp = num[i]-'0';
        nums[i] = temp*2 + carry;
        if(nums[i]>=10) {
            carry = nums[i]/10;
        } else {
            carry = 0;
        }
        nums[i] = nums[i] % 10;
    }
//    for(i=0;i<length;i++) {
//        printf("%d",nums[i]);
//    }
    if(carry!=0) {
        printf("No\n");
        printf("%d",carry);
        for(i=0;i<length;i++) {
            printf("%d",nums[i]);
        }
    } else {
        int trans;
        for(i=0;i<length;i++) {
            trans = num[i] - '0';
            count[trans] += 1;
        }
        for(i=0;i<length;i++) {
            count[nums[i]] -= 1;
        }
        bool flag = true;
        for(i=0;i<10;i++) {
            if(count[i]!=0) {
                printf("No\n");
                flag = false;
                break;
            }
        }
        if(flag)  {
            printf("Yes\n");
        }
        for(i=0;i<length;i++) {
            printf("%d",nums[i]);
        }
    }
    return 0;
}
