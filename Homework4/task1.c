#include<stdio.h>

//Рекурсивный метод O(2^n)
unsigned long long pasc(int n, int k){
    if (n ==0 || k == n)
        return 1;
    return pasc(n-1, k-1) + pasc(n-1, k);
}
//Метод через массив O(n^2)
unsigned long long binom(int n, int k){
    unsigned long long arr[1000] = {0};
       arr[0] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = j; i >=1; i--){
            arr[i] = arr[i - 1] + arr[i];
            printf("%llu\n", arr[i]);
        }
    return arr[k];
}

int main(int argc, char const *argv[])
{
    int k, n;
    scanf("%d %d", &n, &k);
    printf("res = %llu", binom(n, k));
    return 0;
}