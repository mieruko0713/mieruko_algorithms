//
//  1098.cpp
//  算法
//
//  Created by 王怡凡 on 2017/3/23.
//  Copyright © 2017年 王怡凡. All rights reserved.
//

#include<cstdio>
#include<algorithm>
using namespace std;
const int N=111;
int origin[N],tempOri[N],changed[N];
int n;

bool isSame(int A[], int B[]) {
    int i;
    for(i=1;i<=n;i++) {
        if(A[i]!=B[i]) {
            return false;
        }
    }
    return true;
}

void showArray(int A[]) {
    int i;
    for(i=1;i<=n;i++) {
        printf("%d",A[i]);
        if(i<n) printf(" ");
    }
    printf("\n");
}

bool insertSort() {
    bool flag = false;
    int i;
    for(i=1;i<n;i++) {
        if(isSame(tempOri,changed)) {
            flag = true;
        }
        int temp = tempOri[i],j=i;
        while(j>0&&tempOri[j-1]>temp) {
            tempOri[j] = tempOri[j-1];
            j--;
        }
        tempOri[j] = temp;
        if(flag==true) {
            return true;
        }
    }
    return false;
}

void downAdjust(int low, int high) {
    int i=low, j=i*2;
    while(j<=high) {
        if(j+1<=high&&tempOri[j+1]>tempOri[j]) {
            j=j+1;
        }
        if(tempOri[j]>tempOri[i]) {
            swap(tempOri[i],tempOri[j]);
            i=j;
            j=i*2;
        } else {
            break;
        }
    }
}

void heapSort() {
    bool flag = false;
    int i;
    for(i=n/2;i>=1;i--) {
        downAdjust(i,n);
    }
    for(i=n;i>1;i--) {
        if(isSame(tempOri,changed)) {
            flag = true;
        }
        swap(tempOri[i],tempOri[1]);
        downAdjust(1,i-1);
        if(flag==true) {
            showArray(tempOri);
            return;
        }
    }
}

int main() {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) {
        scanf("%d",&origin[i]);
        tempOri[i] = origin[i];
    }
    for(i=1;i<=n;i++) {
        scanf("%d",&changed[i]);
    }
    if(insertSort()) {
        printf("Insertion Sort\n");
        showArray(tempOri);
    } else {
        printf("Heap Sort\n");
        for(i=1;i<=n;i++) {
            tempOri[i] = origin[i];
        }
        heapSort();
    }
    return 0;
}
