//
//  1011.cpp
//  算法
//
//  Created by 王怡凡 on 2017/5/17.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;
char res[3] = {'W','T','L'};

int main() {
    float num[3],odd,max,product=1;
    char cho[3];
    int i,j,choice;
    for(i=0;i<3;i++) {
        max = 0;
        for(j=0;j<3;j++) {
            scanf("%f",&odd);
            if(odd>max) {
                max = odd;
                choice = j;
            }
        }
        num[i] = max;
        cho[i] = choice;
    }
    for(i=0;i<3;i++) {
        product *= num[i];
        printf("%c ",res[cho[i]]);
    }
    printf("%.2f",(product*0.65-1)*2);
    return 0;
}
