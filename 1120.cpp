#include<cstdio>
#include<set>
using namespace std;

int getFriendNum(int num) {
    int sum = 0;
    while(num!=0) {
        sum += num%10;
        num /= 10;
    }
    return sum;
}

int main() {
    set<int> s;
    set<int>::iterator it;
    int n,num,i;
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        scanf("%d", &num);
        s.insert(getFriendNum(num));
    }
    printf("%d\n", s.size());
    for(it = s.begin();it != s.end(); it++) {
        if(it!=s.begin()) {
            printf(" %d",*it);
        } else {
            printf("%d", *it);
        }
    }
    return 0;
}