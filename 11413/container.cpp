#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int m;

int vessels[1001];

bool possible(int cap)
{
    int left = m - 1;
    int c = 0;
    for(int i = 0; i < n; i++)
    {
        if(vessels[i] + c > cap)
        {
            c = 0;
            left--;
            if(left < 0)
            {
                return false;
            }
        }
        c += vessels[i];
    }
    return true;
}

int main()
{
    while(scanf("%d %d", &n, &m) != EOF && n && m)
    {
        int low = 1;
        int high = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &vessels[i]);
            high += vessels[i];
            low = max(low, vessels[i]);
        }
        while(true)
        {
            int test = (low+high)/2;
            if(possible(test))
            {
                if(high == test)
                {
                    break;
                }
                high = test;
            }
            else
            {
                if(low == test)
                {
                    break;
                }
                low = test;
            }
        }
        printf("%d\n", high);
    }
}
