#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct junction
{
    list<int> streets;
    char c;
};

queue<int> process;
junction junctions[200];
int T;
int v;
int e;
int red_count;
int blue_count;
int total_count;
int processed_junctions;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> v;
        cin >> e;
        for(int i = 0; i < 200; i++)
        {
            junctions[i].c = 'w';
            junctions[i].streets.clear();
        }
        while(!process.empty())
            process.pop();
        total_count = 0;
        processed_junctions = 0;
        while(e--)
        {
            int f;
            int t;
            cin >> f;
            cin >> t;
            junctions[f].streets.push_back(t);
            junctions[t].streets.push_back(f);
        }
        while(processed_junctions < v)
        {
            red_count = 0;
            blue_count = 0;
            for(int i = 0; i < v; i++)
            {
                if(junctions[i].c == 'w')
                {
                    //cout << "Found unused: " << i << endl;
                    process.push(i);
                    junctions[i].c = 'r';
                    red_count++;
                    break;
                }
            }
            while(!process.empty())
            {
                int j = process.front();
                process.pop();
                processed_junctions++;
                for(list<int>::iterator iter = junctions[j].streets.begin(); iter != junctions[j].streets.end(); iter++)
                {
                    if(junctions[*iter].c == 'w')
                    {
                        //cout << j << ':' << *iter << endl;
                        if(junctions[j].c == 'r')
                        {
                           junctions[*iter].c = 'b';
                           blue_count++;
                        }
                        else
                        {
                           junctions[*iter].c = 'r';
                           red_count++;
                        }
                        process.push(*iter);
                    }
                    else
                    {
                        if(junctions[*iter].c == junctions[j].c)
                        {
                            cout << -1 << endl;
                            goto nextcase;
                        }
                    }
                }
            }
            //cout << "r: " << red_count << " b: " << blue_count << endl;
            total_count += max(1, min(red_count, blue_count));
        }
        cout << total_count << endl;
        nextcase:
            continue;
    }

    return 0;
}
