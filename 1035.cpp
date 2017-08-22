//
//  1035.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/22.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<cstring>
using namespace std;
const int maxn = 1010;
char name[12],word[12];
int n;

struct node{
    char name[12],word[12];
    bool flag=false;
} nodes[maxn];

int main() {
    scanf("%d",&n);
    int i,num=0;
    for(i=0;i<n;i++) {
        scanf("%s %s",nodes[i].name,nodes[i].word);
//        printf("%s %s\n",name,word);
        strcpy(word,nodes[i].word);
        for(int j=0;j<strlen(word);j++) {
            if(word[j]=='1'||word[j]=='0'||word[j]=='l'||word[j]=='O') {
                nodes[i].flag = true;
            }
            if(word[j]=='1') {
                word[j] = '@';
            } else if(word[j]=='0') {
                word[j] = '%';
            } else if(word[j]=='l') {
                word[j] = 'L';
            } else if(word[j]=='O') {
                word[j] = 'o';
            }
        }
        strcpy(nodes[i].word,word);
        if(nodes[i].flag) {
            num++;
        }
    }
    if(num!=0) {
        printf("%d\n",num);
        for(i=0;i<n;i++) {
            if(nodes[i].flag) {
                printf("%s %s\n",nodes[i].name,nodes[i].word);
            }
        }
    } else {
        if(n==1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified",n);
        }
        
    }
}
