#include <cstdio>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<uint, int> ui;
#define MAX_R 10

struct state
{
    uint on;
    int pos;
    int steps;
    int hist;
};

struct prev
{
    char type;
    int room;
    int previous;
};

int r;
int d;
int s;

// rooms on, position
int states[1 << MAX_R][MAX_R];
vector<vi> switches;
vector<vi> adjList;
vector<prev> history;

void printresult(int i)
{
    if(history[i].type != 2)
    {
        printresult(history[i].previous);
    }
    switch(history[i].type)
    {
        case 0:
            printf("- Move to room %d.\n", history[i].room + 1);
            break;
        case 1:
            printf("- Switch on light in room %d.\n", history[i].room + 1);
            break;
        case 3:
            printf("- Switch off light in room %d.\n", history[i].room + 1);
            break;
    }
}

int main()
{
    int iteration = 1;
    while(scanf("%d %d %d", &r, &d, &s) != EOF && (r != 0 || d != 0 || s != 0))
    {
        printf("Villa #%d\n", iteration++);
        queue<state> q;
        switches.assign(r, vi());
        adjList.assign(r, vi());
        history.clear();
        for(int i = 0; i < (1 << MAX_R); i++)
        {
            for(int j = 0; j < MAX_R; j++)
            {
                states[i][j] = -1;
            }
        }
        states[1][0] = 0;
        state temp;
        prev tempprev;
        temp.on = 1;
        temp.pos = 0;
        temp.steps = 0;
        temp.hist = 0;
        tempprev.type = 2;
        history.push_back(tempprev);
        q.push(temp);
        for(int n = 0; n < d; n++)
        {
            int i;
            int j;
            scanf("%d %d", &i, &j);
            adjList[i - 1].push_back(j - 1);
            adjList[j - 1].push_back(i - 1);
        }
        for(int n = 0; n < s; n++)
        {
            int k;
            int l;
            scanf("%d %d", &k, &l);
            if(k != l)
            {
                switches[k - 1].push_back(l - 1);
            }
        }
        while(!q.empty())
        {
            state f = q.front();
            q.pop();
            uint on = f.on;
            int pos = f.pos;
            int steps = f.steps;
            int hist = f.hist;
            // printf("%u %d %d\n", on, pos, steps);
            if(pos == r - 1 && on == (1 << (r-1)))
            {
                printf("The problem can be solved in %d steps:\n", steps);
                printresult(hist);
                goto next;
                break;
            }
            tempprev.previous = hist;
            tempprev.type = 0;
            for(size_t i = 0; i < adjList[pos].size(); i++)
            {
                int other = adjList[pos][i];
                tempprev.room = other;
                if((1 << other) & on && states[on][other] == -1)
                {
                    temp.on = on;
                    temp.pos = other;
                    temp.steps = steps + 1;
                    history.push_back(tempprev);
                    temp.hist = history.size() - 1;

                    states[on][other] = steps + 1;
                    q.push(temp);
                }
            }
            for(size_t i = 0; i < switches[pos].size(); i++)
            {
                int other = switches[pos][i];
                // printf("%d %d\n", pos, other);
                uint new_on = on ^ (1 << other);
                tempprev.room = other;
                tempprev.type = new_on & (1 << other) ? 1 : 3;
                if(states[new_on][pos] == -1)
                {
                    temp.on = new_on;
                    temp.pos = pos;
                    temp.steps = steps + 1;
                    history.push_back(tempprev);
                    temp.hist = history.size() - 1;
                    states[new_on][pos] = steps + 1;
                    q.push(temp);
                }
            }
        }
        printf("The problem cannot be solved.\n");
next:
        printf("\n");
        continue;
    }
}
