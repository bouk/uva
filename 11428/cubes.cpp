#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N;

int main()
{
    while(scanf("%d", &N) != EOF && N)
    {
        for(int y = 0; y <= 200; y++)
        {
            int lowx = 0;
            int highx = 200;
            int testn;
            while(lowx < highx -1)
            {
                int x = (lowx+highx)/2;
                testn = x*x*x - y*y*y;
                if(testn == N)
                {
                    printf("%d %d\n", x, y);
                    goto nextcase;
                }
                else if(testn < N)
                {
                    lowx = x;
                }
                else
                {
                    highx = x;
                }
                // printf("%d %d %d %d %d\n", x, y, testn, lowx, highx);
            }
            testn = lowx*lowx*lowx - y*y*y;
            if(testn == N)
            {
                printf("%d %d\n", lowx, y);
                goto nextcase;
            }
            // printf("\n");
        }
        printf("No solution\n");
        nextcase:
        continue;
    }
}