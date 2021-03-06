//
//  1108.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/30.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<string>
#include<iostream>
using namespace std;
int n;

double trans(string s) {
    double res=0,res1=0.1;
    
    bool flag = false,fu=false;
    if(s[0]=='-') {
        fu=true;
        s.erase(0,1);
    }
    int len = int(s.length());
    for(int i=0;i<len;i++){
        if(!flag&&s[i]!='.') {
            res =  res*10+(s[i]-'0');
        } else if(s[i]=='.') {
            flag = true;
        } else if(flag){
            res += (s[i]-'0')*res1;
            res1 *= 0.1;
        }
    }
    if(fu) {
        res *= -1;
    }
    return res;
}

bool isLegal(string s) {
    if(s[0]<'0'||s[0]>'9') {
        if(s[0]!='-')
        return false;
    }
    int len = int(s.length());
    for(int i=0;i<len;i++) {
        if(s[i]=='.') {
            int num = len-1-i;
            if(num>2) {
                return false;
            }
        }
    }
    double res = trans(s);
    if(res>1000||res<-1000) {
        return false;
    }
    return true;
}






int main() {
    string s;
    double sum=0;
    int num=0;
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++) {
       cin >> s;
        if(isLegal(s)) {
            num++;
            sum += trans(s);
        } else {
            cout << "ERROR: "+s+" is not a legal number"<<endl;
        }
    }
    if(num==0) {
        cout << "The average of 0 numbers is Undefined"<<endl;
    } else if(num==1) {
        printf("The average of 1 number is %.2lf\n",sum);
    }
      else {
        printf("The average of %d numbers is %.2lf\n",num,sum/num);

    }
    return 0;
}
