//
//  1061.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/29.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
using namespace std;
char weeks[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main() {
    char strs[4][62],week[4];
    int len[4];
    int i,min=0,h=0;
    for(i=0;i<4;i++) {
        scanf("%s",strs[i]);
        len[i] = int(strlen(strs[i]));
    }
    int num=0;
    i=0;
    while(i<len[0]&&i<len[1]) {
        if(strs[0][i]==strs[1][i]) {
            if(num==0) {
                char com = strs[1][i];
                if(com>='A'&&com<='G') {
                    num++;
                    strcpy(week,weeks[com-'A']);
                }
            } else if(num==1) {
                char com = strs[1][i];
                if(com>='0'&&com<='9') {
                    h = com - '0';
                    break;
                } else if(com<='N'&&com>='A'){
                    h = com - 'A' + 10;
                    break;
                }
            }
        }
        i++;
    }
    i=0;
    while(i<len[2]&&i<len[3]) {
        if(strs[2][i]==strs[3][i]) {
            char com = strs[2][i];
            if((com>='a'&&com<='z')||(com>='A'&&com<='Z')) {
                min = i;
                break;
            }
            
        }
        i++;
    }
    printf("%s %02d:%02d",week,h,min);
}
