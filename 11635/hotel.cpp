#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> adjList;
int n;
int h;
int c[100];
int m;
int a;
int b;
int t;

bitset<10000> isHotel;
short best[10000];

priority_queue<ii> * current = new priority_queue<ii>;
priority_queue<ii> * next = new priority_queue<ii>;

int main()
{
    while(scanf("%d", &n) != EOF && n)
    {
        adjList.assign(n, vii());
        isHotel.reset();
        memset(best, 0, sizeof(best));
        best[0] = 600;

        scanf("%d", &h);
        for(int i = 0; i < h; i++)
        {
            scanf("%d", &c[i]);
            isHotel.set(c[i]-1);
        }

        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &t);
            adjList[a-1].push_back(ii(b-1, t));
        }
        while(!current->empty())
        {
            current->pop();
        }
        while(!next->empty())
        {
            next->pop();
        }
        int day = 0;
        // ii(timeleft, pos)
        current->push(ii(600, 0));
        while(!current->empty())
        {
            day++;
            while(!current->empty())
            {
                ii p = current->top();
                current->pop();


            }
        }
    }
}
