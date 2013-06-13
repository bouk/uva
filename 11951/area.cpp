#include <cstdio>

using namespace std;
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define smax(a, b) (a = max(a, b))
#define smin(a, b) (a = min(a, b))
int N, M, K;
int grid[100][100];
int sum[100][100];

int testcase()
{
    scanf("%d %d %d", &N, &M, &K);

    for(int y = 0; y < N; y++)
        for(int x = 0; x < M; x++)
            scanf("%d", &grid[x][y]);
    for(int x = 0; x < M; x++)
        sum[x][0] = grid[x][0];

    for(int y = 1; y < N; y++)
        for(int x = 0; x < M; x++)
            sum[x][y] = sum[x][y - 1] + grid[x][y];

    int best_sum = 0;
    int best_area = 0;

    for(int starty = -1; starty < N; starty++)
    {
        for(int endy = starty + 1; endy < N; endy++)
        {
            int running_sum = 0;
            int startx = -1;
            for(int x = 0; x < M; x++)
            {
                int matrix_sum = sum[x][endy] - (starty == -1 ? 0 : sum[x][starty]);
                running_sum += matrix_sum;
                while(running_sum > K)
                {
                    startx++;
                    running_sum -= sum[startx][endy] - (starty == -1 ? 0 : sum[startx][starty]);
                }

                int area = (endy - starty) * (x - startx);
                if(area > best_area)
                {
                    best_sum = running_sum;
                    best_area = area;
                }
                else if(area == best_area)
                {
                    smin(best_sum, running_sum);
                }
            }
        }
    }
    printf("%d %d\n", best_area, best_sum);
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
        testcase();
    }
}
