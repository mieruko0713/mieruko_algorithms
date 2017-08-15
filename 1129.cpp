//
//  1129.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/15.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include<set>
using namespace std;
int n,k;
const int maxn = 50010;
int hashes[maxn];

struct item {
    int index,times;
    item(int a, int b): index(a),times(b){}
    bool operator < (const item &a) const {
        return (times!=a.times)?times>a.times:index<a.index;
    }
};
set<item> items;

int main() {
    scanf("%d%d",&n,&k);
    int num;
    int i,index;
    for(i=0;i<n;i++) {
        scanf("%d",&index);
        if(i!=0) {
            set<item>::iterator it;
            num=0;
            printf("%d:",index);
            for(it=items.begin();it!=items.end();it++) {
                printf(" %d",it->index);
                num++;
                if(num==k) {
                    break;
                }
            }
            printf("\n");
        }
        auto it = items.find(item(index,hashes[index]));
        if(it!=items.end()){
            items.erase(it);
        }
        hashes[index]++;
        items.insert(item(index,hashes[index]));
    }
    return 0;
}



