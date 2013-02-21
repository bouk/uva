#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define MAX_N 100

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

int N;
int E;

int S;
int T;

int minTemp[MAX_N];
int dist[MAX_N];
int back[MAX_N];

viii adjList[MAX_N];
priority_queue<ii, vector<ii>, greater<ii> > dijkq;

// position (temp in mintemp)
queue<int> bfsq;

void printRoute(int p)
{
    if(back[p] != p)
    {
        printRoute(back[p]);
    }
    printf("%d", p+1);
    if(p != T)
    {
        printf(" ");
    }
}

int main()
{
    while(scanf("%d %d", &N, &E) != EOF && N && E)
    {
        scanf("%d %d", &S, &T);
        S--;
        T--;
        int X;
        int Y;
        int R; // TEMPERATURE
        int R2;
        int D; // dist
        int D2;

        for(int i = 0; i < N; i++)
        {
            minTemp[i] = 1000;
            dist[i] = -1;
            back[i] = -1;
            adjList[i].clear();
        }

        for(int i = 0; i < E; i++)
        {
            scanf("%d %d %d.%d %d.%d", &X, &Y, &R, &R2, &D, &D2);
            // printf("%d %d %d.%d %d.%d\n", X, Y, R, R2, D, D2);
            X--;
            Y--;
            adjList[X].push_back(iii(D*10+D2, ii(R*10+R2, Y)));
            adjList[Y].push_back(iii(D*10+D2, ii(R*10+R2, X)));
        }

        minTemp[S] = 0;
        bfsq.push(S);

        while(!bfsq.empty())
        {
            int f = bfsq.front();
            bfsq.pop();
            // printf("PROCESS %d: %d\n", f, adjList[f].size());
            for(int i = 0; i < (int)adjList[f].size(); i++)
            {
                iii o = adjList[f][i];
                if(minTemp[o.second.second] > max(minTemp[f], o.second.first))
                {
                    minTemp[o.second.second] = max(minTemp[f], o.second.first);

                    bfsq.push(o.second.second);
                }
            }
        }

        dijkq.push(ii(0, S));
        dist[S] = 0;
        while(!dijkq.empty())
        {
            ii f = dijkq.top();
            dijkq.pop();
            if(dist[f.second] != f.first)
            {
                continue;
            }
            for(int i = 0; i < (int)adjList[f.second].size(); i++)
            {
                iii o = adjList[f.second][i];
                if(o.second.first <= minTemp[T] && (dist[o.second.second] == -1 || dist[o.second.second] > dist[f.second] + o.first))
                {
                    dist[o.second.second] = dist[f.second] + o.first;
                    dijkq.push(ii(dist[o.second.second], o.second.second));
                    back[o.second.second] = f.second;
                }
            }
        }
        back[S] = S;
        printRoute(T);
        printf("\n");
        printf("%d.%d %d.%d\n", dist[T]/10, dist[T]%10, minTemp[T]/10, minTemp[T]%10);
    }

    return 0;
}