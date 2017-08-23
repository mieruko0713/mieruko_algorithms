//
//  1047.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxc = 2510;
const int maxs = 40010;
char stus[maxs][5];
vector<int> course[maxc];
int n,k;

bool cmp(int a,int b) {
    return strcmp(stus[a],stus[b]) < 0;
}

int main() {
    scanf("%d %d",&n,&k);
    int i;
    for(i=0;i<n;i++) {
        scanf("%s",stus[i]);
        int c,id;
        scanf("%d",&c);
        for(int j=0;j<c;j++) {
            scanf("%d",&id);
            course[id].push_back(i);
        }
    }
    for(i=1;i<=k;i++) {
        int len = int(course[i].size());
        printf("%d %d\n",i,len);
        sort(course[i].begin(),course[i].end(),cmp);
        for(int j=0;j<len;j++) {
            printf("%s\n",stus[course[i][j]]);
        }
    }
   return 0;
}
