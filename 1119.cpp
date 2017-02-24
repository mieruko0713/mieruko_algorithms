//
//  1119.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 40;
int pre[maxn], post[maxn], n, flag=1;
vector<int> ans;


int find_index(int x, int l, int r) {
    int i;
    for(i=l;i<=r;i++) {
        if(pre[i] == x) {
            return i;
        }
    }
    return -1;
}

void setIn(int prel, int prer, int postl, int postr) {
    if(prel==prer) {
        ans.push_back(pre[prer]);
        return;
    }
    int x = find_index(post[postr-1], prel+1, prer);
    if(x-prel>1) {
        setIn(prel+1, x-1, postl, postl+x-prel-2);
        ans.push_back(pre[prel]);
        setIn(x,prer,postl+x-prel-1,postr-1);
    } else {
        flag = 0;
        ans.push_back(pre[prel]);
        setIn(x, prer, postl+x-prel-1, postr-1);
    }
 }

int main() {
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d", &pre[i]);
    }
    for(i=0;i<n;i++) {
        scanf("%d", &post[i]);
    }
    setIn(0, n-1, 0, n-1);
    if(flag==1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for(int i=0;i<n;i++) {
        printf("%d", ans[i]);
        if(i!=n-1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    return 0;
}
//#include <cstdio>
//#include <vector>
//using namespace std;
//vector<int> ans;
//int *pre, *post, unique = 1;
//
//int findFromPre (int x, int l, int r) {
//    for (int i = l; i <= r; i++) {
//        if (x == pre[i]) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//void setIn (int prel, int prer, int postl, int postr) {
//    if (prel == prer) {
//        ans.push_back(pre[prel]);
//        return;
//    }
//    if (pre[prel] == post[postr]) {
//        int x = findFromPre(post[postr - 1], prel + 1, prer);
//        if (x - prel > 1) {
//            setIn(prel + 1, x - 1, postl, postl + x - prel - 2);
//            ans.push_back(post[postr]);
//            setIn(x, prer, postl + x - prel - 2 + 1, postr - 1);
//        } else {
//            unique = 0;
//            ans.push_back(post[postr]);
//            setIn(x, prer, postl + x - prel - 2 + 1, postr - 1);
//        }
//    }
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    pre = new int [n];
//    post = new int [n];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &pre[i]);
//    }
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &post[i]);
//    }
//    setIn(0, n - 1, 0, n - 1);
//    printf("%s\n", unique ? "Yes" : "No");
//    printf("%d", ans[0]);
//    for (int i = 1; i < ans.size(); i++) {
//        printf(" %d", ans[i]);
//    }
//    printf("\n");
//    return 0;
//}
