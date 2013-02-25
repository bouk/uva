#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

int N;
int M;

char a[256];

int cti(char c)
{
    return c - 'A';
}

int activated_parts;
vector<int> adjList[26];
int parts[26];
int start[3];
void testcase()
{
    scanf("%d", &M);
    scanf("%s", a);
    activated_parts = 3;
    // printf("%s\n", a);
    for(int i = 0; i < 26; i++)
    {
        parts[i] = 0;
        adjList[i].clear();
    }
    start[0] = cti(a[0]);
    start[1] = cti(a[1]);
    start[2] = cti(a[2]);
    parts[start[0]] = parts[start[1]] = parts[start[2]] = 3;

    int years = 0;
    for(int i = 0; i < M; i++)
    {
        int from;
        int to;
        scanf("%s", a);
        from = cti(a[0]);
        to = cti(a[1]);
        adjList[from].push_back(to);
        adjList[to].push_back(from);
        // printf("%s\n", a);
    }
    if(N == 3)
    {
        printf("WAKE UP IN, 0, YEARS\n");
        return;
    }
    queue<int> * next = new queue<int>;
    queue<int> * current = new queue<int>;
    for(int i = 0; i < 3; i++)
    {
        current->push(start[i]);
    }

    while(!current->empty())
    {
        years++;
        while(!current->empty())
        {
            int p = current->front();
            current->pop();
            for(int i = 0; i < (int)adjList[p].size(); i++)
            {
                int o = adjList[p][i];

                if(++parts[o] == 3)
                {
                    // This part just got 3 connections
                    next->push(o);
                    if(++activated_parts == N)
                    {
                        printf("WAKE UP IN, %d, YEARS\n", years);
                        return;
                    }
                }
            }
        }
        queue<int> * temp = next;
        next = current;
        current = temp;
    }
    printf("THIS BRAIN NEVER WAKES UP\n");
}

int main()
{
    while(scanf("%d", &N) != EOF && N)
    {
        testcase();
    }
}
