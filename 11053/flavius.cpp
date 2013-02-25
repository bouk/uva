#include <cstdio>

using namespace std;
typedef unsigned long long ull;

int N;
int a;
int b;

inline ull f(ull x)
{
    return (((((a * x) % N) * x) % N) + b) % N;
}

ull testcase()
{
    ull tortoise = f(0);
    ull hare = f(tortoise);
    while(tortoise != hare)
    {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    ull length = 1;
    hare = f(tortoise);
    while(tortoise != hare)
    {
        hare = f(hare);
        length++;
    }
    return N - length;
}

int main()
{
    while(scanf("%d", &N) != EOF && N)
    {
        scanf("%d %d", &a, &b);
        printf("%lld\n", testcase());
    }
    return 0;
}
