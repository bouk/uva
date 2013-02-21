#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_M 101
#define MAX_VALUE 501 * MAX_M

int dp[MAX_M][MAX_VALUE];
int coins[MAX_M];

int n;
int m;

int go(int cur_coin, int space)
{
    if(dp[cur_coin][space] != -1)
    {
        return dp[cur_coin][space];
    }
    if(cur_coin == m)
    {
        return dp[cur_coin][space] = 0;
    }

    // perfect solution
    if(space - coins[cur_coin] == 0)
    {
        return dp[cur_coin][space] = space;
    }
    // still space left
    else if(space - coins[cur_coin] > 0)
    {
        // maybe take the coin
        return dp[cur_coin][space] = max(go(cur_coin + 1, space - coins[cur_coin]) + coins[cur_coin], go(cur_coin + 1, space));
    }
    return dp[cur_coin][space] = go(cur_coin + 1, space);
}

void testcase()
{
    scanf("%d\n", &m);
    int total = 0;
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &coins[i]);
        total += coins[i];
    }
    int best_score = go(0, total / 2);
    int result = total - best_score * 2;
    // int result = total - ((total / 2) * 2) + space_left;

    printf("%d\n", result);
}

int main()
{
    scanf("%d\n", &n);
    while(n--)
    {
        for(int i = 0; i < MAX_M; i++)
        {
            for(int j = 0; j < MAX_VALUE; j++)
            {
                dp[i][j] = -1;
            }
        }
        testcase();
    }
    return 0;
}
