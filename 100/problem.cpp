#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

map<unsigned int, unsigned int> dp;

unsigned int alg(unsigned int n)
{
    map<unsigned int, unsigned int>::iterator i = dp.find(n);
    if(i != dp.end())
    {
        return i->second;
    }
    return dp[n] = alg(n % 2 == 0 ? n / 2 : 3 * n + 1) + 1;
}

int main()
{
    dp[1] = 1;
    unsigned int i;
    unsigned int j;
    while(scanf("%d %d", &i, &j) != EOF && i && j)
    {
        printf("%d %d", i, j);
        unsigned int best = 0;
        unsigned int top = max(i, j);
        for(unsigned int p = min(i, j); p <= top; p++)
        {
            best = max(best, alg(p));
        }
        printf(" %d\n", best);
    }
}
