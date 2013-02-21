#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int T;
int N;
int R;
int u;
int v;
int s;
int d;

// vector<vi> adjList;
int matrix[101][101];

int main()
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &N);
        // adjList.assign(N, vi());
        scanf("%d", &R);

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                matrix[i][j] = 1e9;
            }
            matrix[i][i] = 0;
        }

        for(int i = 0; i < R; i++)
        {
            scanf("%d %d", &u, &v);
            matrix[u][v] = matrix[v][u] = 1;
            // adjList[u].push_back(v);
        }

        scanf("%d %d", &s, &d);

        for(int k = 0; k < N; k++)
        {
            for(int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        int m = 0;
        for(int i = 0; i < N; i++)
        {
            m = max(m, matrix[s][i] + matrix[i][d]);
        }
        printf("Case %d: %d\n", cas, m);
    }
    return 0;
}