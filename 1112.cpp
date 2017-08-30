//
//  1112.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
#include<map>
using namespace std;
int k;
const int maxn = 1010;
map<char,int> hashes;
map<char,int> hashes2;
char str[maxn];

int main() {
    scanf("%d",&k);
    getchar();
    gets(str);
    int i,len=int(strlen(str));
    for(i=0;i<=len-k;i++) {
        int j=1;
        bool flag = true;
        while(j<k) {
            if(str[i]!=str[i+j]) {
                flag = false;
//                printf("%c %c\n",str[i],str[i+j]);
            }
            j++;
        }
        hashes[str[i]] += flag;
        if(flag) {
            i+=k-1;
        }
    }
    for(i=0;i<=len-k;i++) {
        if(hashes[str[i]]>1&&hashes2[str[i]]==0) {
            hashes2[str[i]] = 1;
            printf("%c",str[i]);
        }
    }
    printf("\n");
    for(i=0;i<len;i++) {
        printf("%c",str[i]);
        if(hashes2[str[i]]) {
            i += k-1;
        }
    }
    printf("\n");
    return 0;
}
