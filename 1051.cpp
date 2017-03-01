//
//  1051.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<stack>
#include<vector>
using namespace std;

int main() {
    int i,m,n,k,j;
    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<k;i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n);
        for(j=0;j<n;j++) {
            scanf("%d",&v[j]);
        }
        int current = 0;
        for(j=1;j<=n;j++) {
            s.push(j);
            if(s.size()>m) {
                break;
            }
            while(!s.empty()&&s.top()==v[current]) {
                s.pop();
                current++;
            }
        }
        if(current == n) flag = true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}