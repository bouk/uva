#include <iostream>
#include <list>
#include <queue>

using namespace std;

// BFS marking max sound at each point and redoing BFS from that point if it is lower
// read value of the endpoint at the end
typedef unsigned int uint;

struct connection
{
    uint to;
    int sound;
};

struct crossing
{
    list<connection> connections;
    uint from;
};

crossing crossings[100];
queue<uint> checking;

uint C;
uint S;
uint Q;

int maxsound[100];
int main()
{
    uint testcase = 1;
    bool first = true;
    while(cin >> C && cin >> S && cin >> Q && C && S && Q)
    {
        if(!first)
        {
            cout << endl;
        }
        first = false;
        cout << "Case #" << testcase << endl;
        testcase++;

        for(uint i = 0; i < C; i++)
        {
            crossings[i].connections.clear();
        }

        while(!checking.empty())
            checking.pop();

        while(S--)
        {
            uint c1;
            uint c2;

            connection con;
            cin >> c1;
            cin >> c2;
            cin >> con.sound;
            con.to = c2-1;
            crossings[c1-1].connections.push_back(con);
            con.to = c1-1;
            crossings[c2-1].connections.push_back(con);
        }

        while(Q--)
        {
            uint from;
            uint to;
            cin >> from;
            cin >> to;
            for(uint i = 0; i < C; i++)
            {
                maxsound[i] = -1;
                crossings[i].from = -1;
            }
            maxsound[from-1] = 0;
            checking.push(from-1);
            while(!checking.empty())
            {
                uint c = checking.front();
                checking.pop();
                for(list<connection>::iterator iter = crossings[c].connections.begin(); iter != crossings[c].connections.end(); iter++)
                {
                    if(maxsound[(*iter).to] == -1 || max(maxsound[c], (*iter).sound) < maxsound[(*iter).to])
                    {
                        maxsound[(*iter).to] = max(maxsound[c], (*iter).sound);
                        checking.push((*iter).to);
                        crossings[(*iter).to].from = c;
                    }
                }
            }
            if(maxsound[to-1] == -1)
            {
                cout << "no path" << endl;
            }
            else
            {
                cout << maxsound[to-1] << endl;
                uint dir = to-1;
                //while(dir != -1)
                //{
                //    cout << dir+1 << ' ';
                //    dir = crossings[dir].from;
                //}
                //cout << endl;
            }
        }
    }
}
