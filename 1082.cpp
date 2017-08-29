//
//  1082.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/29.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
using namespace std;
char str[12];
char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][5] = {"Shi","Bai","Qian","Wan","Yi"};

int main() {
    gets(str);
    int len = int(strlen(str));
    int left = 0, right = len-1;
    if(str[0]=='-') {
        printf("Fu");
        left++;
    }
    while(right-4>=left) {
        right -= 4;
    }
    while(left<len){
        bool flag = false;
        bool isPrint = false;
        while(left<=right) {
            if(left>0&&str[left]=='0') {
                flag = true;
            } else {
                if(flag==true){
                    printf(" ling");
                    flag = false;
                }
                if(left>0) {
                    printf(" ");
                }
                printf("%s", num[str[left]-'0']);
                isPrint = true;
                if(left!=right) {
                    printf(" %s",wei[right-left-1]);
                }
            }
            left++;
        }
        if(isPrint==true&&right!=len-1) {
            printf(" %s",wei[(len-1-right)/4+2]);
        }
        right+=4;
    }
    return 0;
}
