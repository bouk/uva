#include <iostream>
#include <list>

using namespace std;

struct intersection
{
    list<int> streets;
    bool been;
};

int N;
int M;

intersection intersections[2000];

int count_reachable(int i)
{
    int count = 1;
    intersections[i].been = true;
    for(list<int>::iterator iter = intersections[i].streets.begin(); iter != intersections[i].streets.end(); iter++)
    {
        if(!intersections[*iter].been)
        {
            count += count_reachable(*iter);
        }
    }
    return count;
}

int main()
{
    while(cin >> N && cin >> M && N && M)
    {
        int V;
        int W;
        int P;
        for(int i = 0; i < 2000; i++)
        {
            intersections[i].streets.clear();
        }

        while(M--)
        {
            cin >> V;
            cin >> W;
            cin >> P;
            intersections[V-1].streets.push_back(W-1);
            if(P==2)
            {
                intersections[W-1].streets.push_back(V-1);
            }
        }

        for(int i = 0; i < N; i++)
        {
            for(int ii = 0; ii < 2000; ii++)
            {
                intersections[ii].been = false;
            }
            int count = count_reachable(i);
            if(count != N)
            {
                cout << 0 << endl;
                goto nextcase;
            }
        }
        cout << 1 << endl;
nextcase:
        continue;
    }
}
