//
//  1039.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/22.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<algorithm>
const int maxn = 26 * 26 * 26 * 10 + 10;
using namespace std;
vector<int> stu[maxn];
int n,k;

int getid(char a[]) {
    int num = 0,i;
    for(i=0;i<3;i++) {
        num = num* 26 + (a[i] - 'A');
    }
    num = num*10+ (a[i] - '0');
    return num;
}

int main() {
    int i,id,ni;
    char name[5];
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++) {
        scanf("%d %d",&id,&ni);
        for(int j=0;j<ni;j++) {
            scanf("%s",name);
//            getchar();
//            printf("id:%d\n",id);
//            printf("%s\n",name);
            stu[getid(name)].push_back(id);
        }
    }
    for(i=0;i<n;i++) {
        scanf("%s",name);
        int id = getid(name),len = int(stu[id].size());
        printf("%s %d",name,len);
        sort(stu[id].begin(),stu[id].end());
        for(int j=0;j<len;j++) {
            printf(" %d",stu[id][j]);
        }
        printf("\n");
    }
    return 0;
}
