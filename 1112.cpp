//
//  1112.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int k;
const int maxn = 1010;
map<char,int> hashes;
map<char,int> hashes2;
map<char,bool> isnot;

int main() {
    scanf("%d",&k);
    string str;
    cin >> str;
    int i,len=int(str.length());
//    printf("len:%d\n",len);
    for(i=0;i<=len-k;i++) {
        int j=1;
        bool flag = true;
        while(j<k) {
            if(str[i]!=str[i+j]) {
                flag = false;
                isnot[str[i]] = true;
                //                printf("%c %c\n",str[i],str[i+j]);
            }
            j++;
        }
        if(!flag) {
            continue;
        } else {
            hashes[str[i]] += flag;
            i+=k-1;
        }
    }
    char pre = str[len-k];
    int j=1;
    while(j<k) {
        if(str[len-k+j]!=pre) {
            isnot[str[len-k+j]] = true;
        }
        j++;
    }
    for(i=0;i<=len-k;i++) {
        if(hashes[str[i]]>1&&hashes2[str[i]]==0&&isnot[str[i]]==false) {
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
