#include <list>
#include <vector>
#include <iostream>

#include <algorithm>
#include <utility>
#include <queue>
#include <stack>

using namespace std;
typedef pair<long long, long long> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

int T;
int S;
int N;

vii tasks;
list<iii> q;
stack<int> result;
void testcase()
{
    cin >> N;

    tasks.resize(N);
    long long total_time = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> tasks[i].first >> tasks[i].second;
        q.push_back(iii(ii(tasks[i].first, tasks[i].second), i + 1));
        total_time += tasks[i].first;
    }
    for(int i = 0; i < N; i++)
    {
        list<iii>::iterator B = q.begin();
        list<iii>::iterator pos = q.begin();
        long long best = 000000000000;
        while(pos != q.end())
        {
            long long t = (total_time - (*pos).first.first) * (*pos).first.second;
            if(t >= best)
            {
                best = t;
                B = pos;
            }
            pos++;
        }
        result.push((*B).second);
        total_time -= (*B).first.first;
        q.erase(B);
    }
    bool first = true;
    while(!result.empty())
    {
        int i = result.top();
        result.pop();
        if(!first)
        {
            cout << ' ';
        }
        cout << i;
        first = false;
    }
    cout << endl;
}

int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        testcase();
    }
    return 0;
}
