//
//  1077.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/24.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;
int n;

int main() {
    scanf("%d",&n);
    getchar();
    int i;
    string s1;
    getline(cin,s1);
//    printf("%c\n",s1[9]);
    string s2;
    for(i=1;i<n;i++) {
        getline(cin,s2);
        int len1 = int(s1.length()),len2 = int(s2.length());
        if(len2<len1) {
            string s3 = s1;
            int len3 = len1;
            s1 = s2;
            s2 =s3;
            len1 = len2;
            len2 =len3;
        }
//        cout<<len1<<endl;
//        cout<<len2 <<endl;
        if(len1==0) {
            break;
        }
        for(int j=0;j<len1;j++) {
            if(s1[len1-1-j]!=s2[len2-1-j]) {
//                printf("j:%d %c %c\n",j,s1[len1-1-j],s2[len2-1-j]);
//                cout << s1 <<endl;
//                cout << s2 <<endl;
//                continue;
                s1 = s1.substr(len1-j,len1);
                break;
            }
        }
    }
    if(s1.length()==0) {
        cout << "nai" <<endl;
    } else {
        cout << s1 << endl;
    }
    return 0;
}
