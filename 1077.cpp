//
//  1077.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/26.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<cstring>
using namespace std;
int n, minLen=256,ans=0;
char s[100][256];

int main() {
    scanf("%d",&n);
    getchar();
    int i,j,len;
    for(i=0;i<n;i++) {
        gets(s[i]);
        len = strlen(s[i]);
        if(len<minLen) {
            minLen = len;
        }
        for(j=0;j<len/2;j++) {
            char temp = s[i][j];
            s[i][j] = s[i][len-j-1];
            s[i][len-j-1] = temp;
        }
    }
    bool same = true;
    for(i=0;i<minLen;i++) {
        char c = s[0][i];
        for(j=1;j<n;j++) {
            if(s[j][i]!=c) {
                same = false;
                break;
            }
        }
        if(same) {
            ans++;
        }else {
            break;
        }
    }
    if(ans) {
        for(i=ans-1;i>=0;i--) {
            printf("%c",s[0][i]);
        }
    } else {
        printf("nai");
    }
    return 0;
}
