//
//  1022.cpp
//  算法
//
//  Created by 王怡凡 on 2017/8/20.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include <stdio.h>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1010;

int main() {
    map<string,vector<int>> titles,authors,keywords,pubs,years;
    map<int,map<string,vector<int>>> keys;
    int i,n;
    string title,author,keyword,pub,year;
    int id;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        cin >> id;
        getchar();
        getline(cin,title);
        getline(cin,author);
        while(cin>>keyword) {
            keywords[keyword].push_back(id);
            char c;
            c = getchar();
            if(c=='\n') break;
        }
        getline(cin,pub);
        getline(cin,year);
//        cin >> id >> title >> author >> keyword >> pub >> year;
//        cout << id <<endl;
        titles[title].push_back(id);
        authors[author].push_back(id);
        pubs[pub].push_back(id);
        years[year].push_back(id);
    }
    keys[1] = titles;
    keys[2] = authors;
    keys[3] = keywords;
    keys[4] = pubs;
    keys[5] = years;
    int k;
    scanf("%d",&k);
    getchar();
    string query;
    map<string,vector<int>> strings;
    for(i=0;i<k;i++) {
        getline(cin,query);
        cout << query << endl;
        int index = query[0] - 48;
        query.erase(0,3);
        strings = keys[index];
        if(strings[query].size()==0) {
            cout << "Not Found" << endl;
        } else {
            sort(strings[query].begin(),strings[query].end());
            cout << strings[query][0] << endl;
            for(int j=1;j<strings[query].size();j++) {
                if(strings[query][j]!=strings[query][j-1]) {
                    printf("%07d\n",strings[query][j]);
                }
            }
        }
    }
    return 0;
}
