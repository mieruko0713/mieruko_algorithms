//
//  1050.cpp
//  算法
//
//  Created by 王怡凡 on 17/3/1.
//  Copyright © 2017年 王怡凡. All rights reserved.
//1050. String Subtraction (20)

//
//Given two strings S1 and S2, S = S1 - S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1 - S2 for any given strings. However, it might not be that simple to do it fast.
//
//Input Specification:
//
//Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 104. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.
//
//Output Specification:
//
//For each test case, print S1 - S2 in one line.
//Sample Input:
//
//They are students.
//aeiou
//
//Sample Output:
//
//Thy r stdnts.



#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 10010;
int n;
char s1[maxn],s2[maxn];
bool Hash[256] = {false};

int main() {
    int i;
    cin.getline(s1,maxn);
    cin.getline(s2,maxn);
//    printf("%s\n",s1);
//    printf("%s\n",s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(i=0;i<len2;i++) {
        Hash[s2[i]] = true;
    }
    for(i=0;i<len1;i++) {
        if(!Hash[s1[i]]) {
            printf("%c",s1[i]);
        }
    }
    return 0;
}
