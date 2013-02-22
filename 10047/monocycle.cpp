#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;
#define MAX_M 25
#define MAX_N 25
#define FACES  4
#define COLORS 5
#define TURN_LEFT(s) s.facing = (s.facing + (FACES - 1)) % FACES
#define TURN_RIGHT(s) s.facing = (s.facing + 1) % FACES
#define CYCLE_COLOR(s) s.color = (s.color + 1) % COLORS
#define EXISTS(s) (dp[s.x][s.y][s.facing][s.color] != -1)
#define SETDP(s) dp[s.x][s.y][s.facing][s.color] = s.time
struct state
{
    short x;
    short y;
    short facing;
    short color;
    int time;
};

int dp[MAX_M][MAX_N][FACES][COLORS];
int M;
int N;
short start_x;
short start_y;
short target_x;
short target_y;

char board[MAX_M][MAX_N];
queue<state> q;

void testcase()
{
    while(!q.empty())
    {
        q.pop();
    }
    memset(dp, -1, sizeof(dp));
    target_x = start_x = target_y = start_y = -1;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%c", &board[j][i]);
            if(board[j][i] == 'S')
            {
                start_x = j;
                start_y = i;
                board[j][i] = '.';
            }
            else if(board[j][i] == 'T')
            {
                target_x = j;
                target_y = i;
                board[j][i] = '.';
            }
            // printf("%c", board[j][i]);
        }
        scanf("\n");
        // printf("\n");
    }
    if(start_x == -1 || start_y == -1 || target_x == -1 || target_y == -1)
    {
        printf("destination not reachable\n");
        return;
    }
    state tmp;
    tmp.x = start_x;
    tmp.y = start_y;
    tmp.facing = 0;
    tmp.color = 0;
    tmp.time = 0;
    q.push(tmp);
    while(!q.empty())
    {
        state f = q.front();
        // printf("S x%d y%d f%d c%d t%d\n", f.x, f.y, f.facing, f.color, f.time);
        q.pop();
        f.time++;

        // turn left
        TURN_LEFT(f);
        if(!EXISTS(f))
        {
            SETDP(f);
            q.push(f);
        }
        // turn right
        TURN_RIGHT(f);
        TURN_RIGHT(f);
        if(!EXISTS(f))
        {
            SETDP(f);
            q.push(f);
        }
        TURN_LEFT(f);
        // move fwd
        switch(f.facing)
        {
            // N
            case 0:
                f.y--;
                break;
            // E
            case 1:
                f.x++;
                break;
            // S
            case 2:
                f.y++;
                break;
            // W
            case 3:
                f.x--;
                break;
        }
        CYCLE_COLOR(f);
        // check if we can move fwd
        if(f.x >= 0 && f.x < N && f.y >= 0 && f.y < M && board[f.x][f.y] != '#')
        {
            if(f.x == target_x && f.y == target_y && f.color == 0)
            {
                // printf("S x%d y%d f%d c%d t%d\n", f.x, f.y, f.facing, f.color, f.time);
                printf("minimum time = %d sec\n", f.time);
                return;
            }
            if(!EXISTS(f))
            {
                SETDP(f);
                q.push(f);
            }
        }
    }
    printf("destination not reachable\n");
}

int main()
{
    int test = 1;
    while(true)
    {
        if(scanf("%d %d\n", &M, &N) && M && N)
        {
            if(test != 1)
            {
                printf("\n");
            }
            printf("Case #%d\n", test++);
            testcase();
        }
        else
        {
            return 0;
        }
    }
}
