#include <cstdio>

using namespace std;

int Z;
int I;
int M;
int L;

inline int f(int l)
{
    return (Z * l + I) % M;
}

inline int testcase()
{
    int tortoise = f(L);
    int hare = f(tortoise);
    while(tortoise != hare)
    {
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    int length = 1;
    hare = f(hare);
    while(hare != tortoise)
    {
        hare = f(hare);
        length++;
    }
    return length;
}

int main()
{
    int t = 1;
    while(scanf("%d %d %d %d", &Z, &I, &M, &L) != EOF && Z && I && M && L)
    {
        printf("Case %d: %d\n", t++, testcase());
    }
}
