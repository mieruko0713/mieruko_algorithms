//
//  1058.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/27.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
using namespace std;

int main() {
    int a1,a2,a3,b1,b2,b3,ans1,ans2,ans3;
    scanf("%d.%d.%d",&a1,&a2,&a3);
    scanf("%d.%d.%d",&b1,&b2,&b3);
    ans1 = a1+b1;
    ans2 = a2+b2;
    ans3 = a3+b3;
    if(ans3>=29) {
        ans2 = ans2 + ans3/29;
    }
    ans3 = ans3 % 29;
    if(ans2>=17) {
        ans1 = ans2/17+ans1;
    }
    ans2 %= 17;
    printf("%d.%d.%d",ans1,ans2,ans3);
    return 0;
}
