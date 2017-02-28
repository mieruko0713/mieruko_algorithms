//
//  1034.cpp
//  算法
//
//  Created by 王怡凡 on 17/2/28.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<iostream>
#include<map>
#include<string>
using namespace std;
const int maxn = 2010;
int G[maxn][maxn]={0},weight[maxn]={0};
int n,k,numPerson = 0;
bool vis[maxn] = {false};
map<int,string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;

int change(string str) {
    if(stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];
    } else {
        stringToInt[str] = numPerson;
        intToString[numPerson] = str;
        return numPerson++;
    }
}

void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
    int i;
    numMember++;
    vis[nowVisit] =true;
    if(weight[nowVisit]>weight[head]) {
        head = nowVisit;
    }
    for(i=0;i<numPerson;i++) {
        if(G[nowVisit][i]>0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i]==false) {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}

void DFSTrave() {
    int i;
    for(i=0;i<numPerson;i++) {
        if(vis[i] == false) {
            int head = i,numMember=0,totalValue=0;
            DFS(i,head,numMember,totalValue);
            if(numMember>2&&totalValue>k) {
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int main() {
    string str1, str2;
    int w;
    int i;
    cin >> n >> k;
    for(i=0;i<n;i++) {
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    cout << Gang.size() << endl;
    map<string,int>::iterator it;
    for(it=Gang.begin();it!=Gang.end();it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}
