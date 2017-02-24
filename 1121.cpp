//
//  1121.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100100;
int Hash[maxn];
bool comes[maxn] = {false};
vector<int> ans,temp;



int main() {
    fill(Hash,Hash+maxn,-1);
    int couples,couple1,couple2,n,people,i;
    scanf("%d", &couples);
    for(i=0;i<couples;i++) {
        scanf("%d %d", &couple1, &couple2);
        Hash[couple1] = couple2;
        Hash[couple2] = couple1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d", &people);
        comes[people] = true;
        temp.push_back(people);
    }
    for(i=0;i<temp.size();i++) {
        if(Hash[temp[i]]==-1) {
            ans.push_back(temp[i]);
        } else if(!comes[Hash[temp[i]]]) {
            ans.push_back(temp[i]);
//            printf("id: %d couple: %d comes: %d",temp[i],Hash[temp[i]],comes[Hash[temp[i]]]);
        }
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for(i=0;i<ans.size();i++) {
        printf("%05d",ans[i]);
        if(i!=ans.size()-1) {
            printf(" ");
        }
    }
}
