//
//  1061.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/6.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cstring>
using namespace std;

int ans[3];
char inp[4][70];
char week[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main() {
    scanf("%s%s%s%s",inp[0],inp[1],inp[2],inp[3]);
//    printf("%s\n",inp[1]);
    int i,num=0,min1,min2;
    min1 = strlen(inp[0])>strlen(inp[1])? strlen(inp[1]):strlen(inp[0]);
    min2 = strlen(inp[2])>strlen(inp[3])? strlen(inp[3]):strlen(inp[2]);
    for(i=0;i<min1;i++) {
            if(inp[0][i]==inp[1][i]) {
                if(num==0&&inp[0][i]>='A'&&inp[0][i]<='Z') {
                    ans[0] = inp[0][i] - 'A';
                    num++;
                } else if(num==1) {
                    if(inp[0][i]>='0'&&inp[0][i]<='9') {
                        ans[1] = inp[0][i] - '0';
                        break;
                    } else if(inp[0][i]>='A'&&inp[0][i]<='N') {
                        ans[1] = inp[0][i] - 'A'+10;;
                        break;
                    }
                }
            }
    }
    for(i=0;i<min2;i++) {
        if(inp[2][i]==inp[3][i]&&(inp[2][i]>='a'&&inp[2][i]<='z'||inp[2][i]>='A'&&inp[2][i]<='Z')) {
            ans[2] = i;
            break;
        }
    }
    printf("%s %02d:%02d",week[ans[0]],ans[1],ans[2]);
    return 0;
}
