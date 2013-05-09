#include <cstdio>
#include <vector>

using namespace std;

int coins[] = {1, 5, 10, 25, 50};
#define MAX_N 30001
unsigned long long ways[MAX_N];

int main()
{
    ways[0] = 1;
    for(int c = 0; c < 5; c++)
    {
        for(int i = coins[c]; i < 30001; i++)
        {
                ways[i] += ways[i - coins[c]];
        }
    }
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(ways[n] == 1)
        {
            printf("There is only 1 way to produce %d cents change.\n", n);
        }
        else
        {
            printf("There are %llu ways to produce %d cents change.\n", ways[n], n);
        }
    }
}
