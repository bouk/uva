#include <cstdio>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
#define MAX_N 100
typedef vector<int> vi;
vector<vi> adjList;
int T;
int N;
bool dominates[MAX_N][MAX_N];

void tablerow()
{
    putchar('+');
    for(int i = 0; i < N * 2 - 1; i++)
    {
        putchar('-');
    }
    printf("+\n");
}

void testcase()
{
    scanf("%d", &N);
    adjList.assign(N, vi());
    for(int from = 0; from < N; from++)
    {
        for(int to = 0; to < N; to++)
        {
            int n;
            scanf("%d", &n);
            if(n)
            {
                adjList[from].push_back(to);
            }
            dominates[from][to] = to != 0 || from == 0;
        }
    }
    {
        queue<int> q;
        vector<bool> accessed(N, false);
        q.push(0);
        accessed[0] = true;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            for(size_t i = 0; i < adjList[n].size(); i++)
            {
                int o = adjList[n][i];
                if(!accessed[o])
                {
                    accessed[o] = true;
                    q.push(o);
                }
            }
        }
        for(int i = 1; i < N; i++)
        {
            if(!accessed[i])
            {
                for(int from = 0; from < N; from++)
                {
                    dominates[from][i] = false;
                }
            }
        }
    }
    // Determine which are aren't accessible if I disable node i
    for(int from = 1; from < N; from++)
    {
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            for(size_t i = 0; i < adjList[n].size(); i++)
            {
                int o = adjList[n][i];
                if(o != from && dominates[from][o])
                {
                    dominates[from][o] = false;
                    q.push(o);
                }
            }
        }
    }
    tablerow();
    for(int from = 0; from < N; from++)
    {
        putchar('|');
        for(int to = 0; to < N; to++)
        {
            putchar(dominates[from][to] ? 'Y' : 'N');
            putchar('|');
        }
        putchar('\n');
        tablerow();
    }
}

int main()
{
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case %d:\n", i);
        testcase();
    }
}
