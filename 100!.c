#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int cifre(long long x, int a[])
{
    int cnt = 0;
    while(x)
    {
        a[cnt++] = x % 10;
        x /= 10;
    }

    return cnt;
}

int mul(int na, int a[], int nb, int b[], int c[])
{
    int NR;
    for(int i=0; i<na; i++)
    {
        for(int t=0; t<nb; t++)
        {
            NR = a[i] * b[t];
            c[t + i] += NR;

            c[t + i + 1] += c[t + i] / 10;
            c[t + i] %= 10;
        }
    }

    int cnt = MAX;
    while(!c[--cnt]);

    return cnt + 1;
}

int computeFactorial(int n, int digits[MAX])
{

    for(int i=0; i<MAX; i++)
        digits[i]=0;

    int lastNum[MAX];

    for(int i=0; i<MAX; i++)
        lastNum[i]=0;


    int lastNumLength = 1;
    lastNum[0] = 1;

    int digitsLen = 0;

    for(int i=2; i<=n; i++)
    {

        for(int i=0; i<MAX; i++)
            digits[i]=0;
        int thisNum[MAX];
        int thisLen = cifre(i, thisNum);
        digitsLen = mul(lastNumLength, lastNum, thisLen, thisNum, digits);



        for(int t=0; t<digitsLen; t++)
        {
            lastNum[t] = digits[t];
        }
        lastNumLength = digitsLen;
    }

    return lastNumLength;
}

int main()
{

    int a[2];
    int b[] = {1, 3, 8};

    int c[MAX];

    for(int i=0; i<MAX; i++)
        c[i] = 0;
    cifre(19, a);

    int cnt = mul(2, a, 3, b, c);

//    for(int i=0; i<cnt; i++)
//        printf("%d ", c[i]);
//
//    printf("\n");

    int digits[MAX];

    for(int i=0; i<MAX; i++)
        digits[i]=0;
    int len = computeFactorial(100, digits);

    printf("lungime 100! = %d cifre\n", len);
    for(int i=len-1; i>=0; i--)
        printf("%d ", digits[i]);

    return 0;
}
