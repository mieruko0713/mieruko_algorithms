#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

void to_array(int n, int num[]) {
    int i;
    for(i=0;i<4;i++) {
        num[i] = n%10;
        n /= 10;
    }
}

int to_number(int num[]) {
    int sum = 0,i;
    for(i=0;i<4;i++) {
        sum = sum*10 + num[i];
    }
    return sum;
}

int main() {
    int n,minD,maxD;
    scanf("%d",&n);
    int num[4];
    while(true) {
        to_array(n,num);
        sort(num,num+4);
        minD = to_number(num);
        sort(num,num+4,cmp);
        maxD = to_number(num);
        n = maxD-minD;
        printf("%04d - %04d = %04d\n",maxD,minD,n);
        if(n==0||n==6174) break;
    }
    return 0;
}