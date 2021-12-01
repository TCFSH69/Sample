#include <stdio.h>
#define MODULUS 10007
int getSecret(int n);
int gcd(int a, int b);

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", getSecret(n));
    return 0;
}

int getSecret(int n){
    int len = 0, k = n, deno = 1, upper, lower;
    for (;k != 0; k /= 10, len++);
    len = (len % 2 == 0) ? len / 2 : len / 2 + 1;
    for (int i = 0; i < len; i++, deno *= 10);
    if (n < 10) return n;
    upper = n / deno;
    lower = n % deno;
    return (n % MODULUS + getSecret(gcd(upper, lower))) % MODULUS;
}

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}
