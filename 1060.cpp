#include <stdio.h>
#include <string.h>
#define MAX 110
struct result{
    char d[MAX]; // 0.xxx部分
    int k; // 10的k次方
};

result getResult(char *a, int n){
    result r;
    int firstPos = -1;
    int pointPos = -1;
    int index = 0;
    int i;
    for (i = 0; a[i]; i++){
        if (a[i] == '.'){
            pointPos = i;
            continue;
        }
        else if (a[i] == '0' && firstPos == -1) // 不能以0开头，否则忽略
            continue;
        else{
            if (firstPos == -1)
                firstPos = i; // 第一个非0数字的位置
            if (index < n)
            {
                if (index < strlen(a))
                    r.d[index++] = a[i]; // 对于特定的精度，有数字则填入相应数字，没有则补0
                else
                    r.d[index++] = '0';
            }
        }
    }
    r.d[index] = 0; // 在数字结尾加\0，防止越界
    if (pointPos == -1)
        pointPos = i; // 如果没有找到小数点，则小数点在最后，这是个纯整数
    if (pointPos - firstPos < 0) // 判断小数点与第一个非0数字的位置关系，计算10的几次方
        r.k = - (firstPos - pointPos - 1); // 负次方，例如0.015，pointPos = 1, firstPos = 3, 3 - 1 - 1 = 1, -1是因为多算了小数点进去,0.15*10^-1
    else
        r.k = pointPos - firstPos; // 正次方，例如21.25，pointPos = 2，firstPos = 0，2-0=2，0.2125*10^2
    if (index == 0){ // 如果index = 0，代表值为0，则每一位都写0，再加\0
        int i;
        for (i = 0; i != n; i++)
            r.d[i] = '0';
        r.d[i] = 0;
        r.k = 0;
    }
    return r;
}

int main(){
    int n;
    char a[MAX], b[MAX];
    scanf("%d%s%s", &n, a, b);
    result r1 = getResult(a, n);
    result r2 = getResult(b, n);
    if (strcmp(r1.d, r2.d) == 0 && r1.k == r2.k)
        printf("YES 0.%s*10^%d\n", r1.d, r1.k);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", r1.d, r1.k, r2.d, r2.k);
    return 0;
}
