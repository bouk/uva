#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <list>

using namespace std;
typedef vector<int> vi;

int n;
int l;
int a;
int b;

vector<vi> adjList;
vi parent;
list<int> la;
list<int> lb;

void g(int u, int v)
{
    printf("The fleas jump forever between ");
    if(u < v)
    {
        printf("%d and %d", u+1, v+1);
    }
    else
    {
        printf("%d and %d", v+1, u+1);
    }
    printf(".\n");
}

void query()
{
    la.clear();
    lb.clear();
    int pos = a;
    while(pos != -1)
    {
        la.push_front(pos);
        pos = parent[pos];
    }
    pos = b;
    while(pos != -1)
    {
        lb.push_front(pos);
        pos = parent[pos];
    }
    list<int>::iterator itera = la.begin();
    list<int>::iterator iterb = lb.begin();
    int lfromroot = 0;
    while(*(itera) == *(iterb))
    {
        itera++;
        iterb++;
        lfromroot++;
    }
    itera--;
    iterb--;
    lfromroot--;
    // printf("%d %d %d\n", *(itera)+1, *(iterb)+1, lfromroot);
    int pathlength = la.size() + lb.size() - lfromroot*2 - 2;
    // printf("%d\n", pathlength);
    int lca = *itera;
    if(pathlength % 2 == 1)
    {
        // keep jumping
        if(la.size()-1 == lb.size())
        {
            g(lca, *(++itera));
        }
        else if(la.size() == lb.size()-1)
        {
            g(lca, *(++iterb));
        }
        else
        {
            if(la.size() > lb.size())
            {
                for(int i = 0; i <= (int)(la.size() - lb.size()); i++)
                {
                    itera++;
                }
                itera++;
                itera++;
                int x = *itera;
                itera++;
                int y = *itera;
                g(x, y);
            }
            else
            {
                for(int i = 0; i <= (int)(lb.size() - la.size()); i++)
                {
                    iterb++;
                }
                iterb++;
                printf("%d\n", (int)(la.size() - lb.size()));
                iterb++;
                int x = *iterb;
                iterb++;
                int y = *iterb;
                g(x, y);
            }
        }
    }
    else
    {
        printf("The fleas meet at ");
        // end on same place
        if(la.size() == lb.size())
        {
            printf("%d", (*itera)+1);
        }
        else
        {

            /*for(list<int>::iterator iter = la.begin(); iter != la.end(); iter++)
            {
                printf("%d ", *iter);
            }
            printf("\n");
            for(list<int>::iterator iter = lb.begin(); iter != lb.end(); iter++)
            {
                printf("%d ", *iter);
            }
            printf("\n");
            */
            if(la.size() > lb.size())
            {
                for(int i = 0; i < (int)(la.size()-lb.size())/2; i++)
                {
                    itera++;
                }
                printf("%d", (*itera)+1);
            }
            else
            {
                for(int i = 0; i < (int)(lb.size()-la.size())/2; i++)
                {
                    iterb++;
                }
                printf("%d", (*iterb)+1);
            }
        }
        printf(".\n");
    }
}


int main()
{
    while(scanf("%d", &n) != EOF && n)
    {
        adjList.assign(n, vi());
        parent.assign(n, -1);
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            adjList[a].push_back(b);
            parent[b] = a;
        }
        scanf("%d", &l);
        for(int i = 0; i < l; i++)
        {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            query();
        }
    }

    return 0;
}
