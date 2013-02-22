#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef unsigned short us;
#define MAX_BEEPERS 10
#define MAX_HEIGHT  21
#define MAX_WIDTH   21

struct beeper
{
    int x;
    int y;
};

int T;
int grid_width;
int grid_height;
int start_x;
int start_y;
int beeper_count;
beeper beepers[MAX_BEEPERS];
int dp[1 << MAX_BEEPERS][MAX_BEEPERS];

int dist(int fromx, int fromy, int tox, int toy)
{
    return abs(fromx - tox) + abs(fromy - toy);
}

int dist(int fromb, int tob)
{
    return dist(beepers[fromb].x, beepers[fromb].y, beepers[tob].x, beepers[tob].y);
}

int go(us beepers_left, int current_beeper)
{
    if(dp[beepers_left][current_beeper] != -1)
    {
        return dp[beepers_left][current_beeper];
    }

    // Return to starting position
    if(beepers_left == 0)
    {
        return dp[beepers_left][current_beeper] = dist(beepers[current_beeper].x, beepers[current_beeper].y, start_x, start_y);
    }

    int best = 1 << 25;
    for(int i = 0; i < beeper_count; i++)
    {
        if(beepers_left & (1 << i))
        {
            best = min(best, go(beepers_left & ~(1 << i), i) + dist(current_beeper, i));
        }
    }
    return dp[beepers_left][current_beeper] = best;
}

void testcase()
{
    scanf("%d %d", &grid_width, &grid_height);
    scanf("%d %d", &start_x, &start_y);
    scanf("%d", &beeper_count);
    memset(dp, -1, sizeof(dp));


    for(int i = 0; i < beeper_count; i++)
    {
        scanf("%d %d", &beepers[i].x, &beepers[i].y);
    }
    us start_mask = 0;
    for(int i = 0; i < beeper_count; i++)
    {
        start_mask <<= 1;
        start_mask |= 1;
    }
    int best = 1 << 25;
    for(int i = 0; i < beeper_count; i++)
    {
        us current_mask = start_mask & ~(1 << i);
        int traveled = go(current_mask, i) + dist(start_x, start_y, beepers[i].x, beepers[i].y);
        best = min(best, traveled);
    }
    printf("The shortest path has length %d\n", best);
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        testcase();
    }
}
