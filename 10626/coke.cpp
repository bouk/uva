#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int C;
int start_n1;
int start_n5;
int start_n10;

int states[151][151][51];
int starttotal;

int calcn1(int bought, int n5, int n10)
{
    return starttotal - 8*bought - 5*n5 - 10*n10;
}

int mincoins(int coke_left, int n1, int n5, int n10)
{
    if(coke_left == 0)
    {
        return 0;
    }

    if(states[coke_left][n5][n10] != -1)
    {
        return states[coke_left][n5][n10];
    }
    else
    {
        states[coke_left][n5][n10] = 1e9;
    }

    // Throw in 10, two ones change
    if(n10 >= 1)
    {
        states[coke_left][n5][n10] = min(states[coke_left][n5][n10], 1 + mincoins(coke_left-1, n1+2, n5, n10-1));
    }

    // Throw in 5 and 3 ones
    if(n5 >= 1 && n1 >= 3)
    {
        states[coke_left][n5][n10] = min(states[coke_left][n5][n10], 4 + mincoins(coke_left-1, n1-3, n5-1, n10));
    }

    // Throw in 2 fives, two ones change
    if(n5 >= 2)
    {
        states[coke_left][n5][n10] = min(states[coke_left][n5][n10], 2 + mincoins(coke_left-1, n1+2, n5-2, n10));
    }

    // Throw in 8 ones
    if(n1 >= 8)
    {
        states[coke_left][n5][n10] = min(states[coke_left][n5][n10], 8 + mincoins(coke_left-1, n1-8, n5, n10));
    }

    // Throw in 10 + 3 ones
    if(n10 >= 1 && n1 >= 3)
    {
        states[coke_left][n5][n10] = min(states[coke_left][n5][n10], 4 + mincoins(coke_left-1, n1-3, n5+1, n10-1));
    }

    return states[coke_left][n5][n10];
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        memset(states, -1, 151*151*51*sizeof(int));

        scanf("%d %d %d %d", &C, &start_n1, &start_n5, &start_n10);
        starttotal = start_n1 + start_n5*5 + start_n10*10;
        int best = mincoins(C, start_n1, start_n5, start_n10);
        printf("%d\n", best);
    }
}