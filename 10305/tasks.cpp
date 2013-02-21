#include <list>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

struct task
{
    int deps;
    bool done;
    vector<int> tasks;
};

int m;
int n;
bool first = true;

task tasks[100];
queue<int> ready;

int main()
{
    while(scanf("%d %d", &n, &m) != EOF && n)
    {
        first = true;
        while(!ready.empty())
        {
            ready.pop();
        }

        for(int t = 0; t < n; t++)
        {
            tasks[t].deps = 0;
            tasks[t].done = false;
            tasks[t].tasks.clear();
        }

        for(int t = 0; t < m; t++)
        {
            int i;
            int j;
            scanf("%d %d", &i, &j);
            tasks[i-1].tasks.push_back(j-1);
            tasks[j-1].deps++;
        }

        for(int t = 0; t < n; t++)
        {
            if(tasks[t].deps == 0)
            {
                ready.push(t);
            }
        }

        while(!ready.empty())
        {
            int t = ready.front();
            ready.pop();
            if(!first)
            {
                printf(" ");
            }
            first = false;
            printf("%d", t+1);
            for(int i  = 0; i < tasks[t].tasks.size(); i++)
            {
                int o = tasks[t].tasks[i];
                tasks[o].deps--;
                if(tasks[o].deps == 0)
                {
                    ready.push(o);
                }
            }
        }


        printf("\n");
    }
    return 0;
}
