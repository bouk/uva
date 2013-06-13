#include <cstdio>

using namespace std;
#define max(a, b) (a > b ? a : b)
#define smax(a, b) (a = max(a, b))
int N;
int grid[100][100];
int sum[100][100];

int main()
{
    scanf("%d", &N);

    for(int y = 0; y < N; y++)
        for(int x = 0; x < N; x++)
            scanf("%d", &grid[x][y]);
    for(int x = 0; x < N; x++)
        sum[x][0] = grid[x][0];

    for(int y = 1; y < N; y++)
        for(int x = 0; x < N; x++)
            sum[x][y] = sum[x][y - 1] + grid[x][y];
    int best_sum = grid[0][0];
    for(int starty = -1; starty < N; starty++)
    {
        for(int endy = starty + 1; endy < N; endy++)
        {
            int running_sum = sum[0][endy] - (starty == -1 ? 0 : sum[0][starty]);
            for(int x = 1; x < N; x++)
            {
                int matrix_sum = sum[x][endy] - (starty == -1 ? 0 : sum[x][starty]);
                running_sum = max(running_sum + matrix_sum, matrix_sum);
                smax(best_sum, running_sum);
            }
        }
    }
    printf("%d\n", best_sum);
}
