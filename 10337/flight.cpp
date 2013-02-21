#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int wind[10][1001];
int best[10][1001];
int N;
int X;
bool first = true;
int main()
{
    scanf("%d", &N);
    for(int cas = 0; cas < N; cas++)
    {
        scanf("%d", &X);
        X /= 100;
        for(int i = 9; i >= 0; i--)
        {
            for(int j = 0; j < X; j++)
            {
                scanf("%d", &wind[i][j]);
            }
        }
        best[0][0] = 0;
        best[1][1] = best[0][0] + 60 - wind[0][0];
        for(int x = 2; x < X; x++)
        {
            for(int y = 1; y < min(10, x+1); y++)
            {
                best[y][x] = 9999999;
                if(y > 1)
                {
                    best[y][x] = min(best[y][x], best[y-1][x-1] + 60 - wind[y-1][x-1]);
                }
                if(y < x)
                {
                    best[y][x] = min(best[y][x], best[y][x-1] + 30 - wind[y][x-1]);
                }
                if(y < x-1)
                {
                    best[y][x] = min(best[y][x], best[y+1][x-1] + 20 - wind[y+1][x-1]);
                }
            }
        }
        /*for(int i = 9; i >= 0; i--)
        {
            for(int j = 0; j < X; j++)
            {
                printf("%4d", best[i][j]);
            }
            printf("\n");
        }
        */
        printf("%d\n\n", best[1][X-1] + 20 - wind[1][X-1]);
    }
    return 0;
}
