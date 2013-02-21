#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>

using namespace std;

struct place
{
    list<int> connections;
};

int N;

place places[100];
bool been[100];
string line;

int count_reachable(int p, int ignore)
{
    int count = 1;
    been[p] = true;
    for(list<int>::iterator iter = places[p].connections.begin(); iter != places[p].connections.end(); iter++)
    {
        if(!been[*iter] && (*iter) != ignore)
        {
            count += count_reachable(*iter, ignore);
        }
    }
    return count;
}

int main()
{
    while(getline(cin, line))
    {
        istringstream iss(line);
        iss >> N;
        if(N == 0)
        {
            break;
        }
        //cout << 'n' << N << endl;
        for(int p = 0; p < 100; p++)
        {
            places[p].connections.clear();
        }
         
        while(true)
        {
            getline(cin, line);
            istringstream is(line);
            istream_iterator<int> iter = istream_iterator<int>(is);
            int pp = (*iter);
            //cout << 'p' << pp << endl;
            if(pp == 0)
            {
                break;
            }
            iter++;
            for(; iter != istream_iterator<int>(); iter++)
            {
                //cout << pp << ':' << *iter << endl;
                places[pp-1].connections.push_back((*iter)-1);
                places[(*iter)-1].connections.push_back(pp-1);
            }
        }
        int critical_places = 0;
        for(int p = 0; p < N; p++)
        {
            for(int i = 0; i < N; i++)
            {
                been[i] = false;
            }
            int count = count_reachable((p + 1) % N, p);
            if(count < N - 1)
            {
                // cout << "Critical place: " << p+1 << endl;
                critical_places++;
            }
        }
        cout << critical_places << endl;
    }
}
