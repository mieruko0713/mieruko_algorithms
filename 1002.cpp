//
//  1002.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/12.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;


int main() {
    int k1,k2,e,max=-1,num=0;
    float c;
    float hash[1010]={0};
    int i;
    scanf("%d",&k1);
    for(i=0;i<k1;i++) {
        scanf("%d %f",&e,&c);
        hash[e]+=c;
        if(e>max) {
            max = e;
        }
    }
    scanf("%d",&k2);
    for(i=0;i<k2;i++) {
        scanf("%d %f",&e,&c);
        hash[e]+=c;
        if(e>max) {
            max = e;
        }
    }
    for(i=max;i>=0;i--) {
        if(hash[i]) {
            num++;
        }
    }
    printf("%d",num);
    for(i=max;i>=0;i--) {
        if(hash[i]!=0){
            printf(" %d %.1f",i,hash[i]);
        }
        
    }
    return 0;
}
