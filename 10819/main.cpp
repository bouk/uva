#include <iostream>

using namespace std;

struct item
{
    int p;
    int f;
};

item items[100];
int values[101][10001];
int m;
int n;

int main()
{
    while(!cin.eof())
    {
        for(int y = 0; y < 101; y++)
        {
            for(int x = 0; x < 10001; x++)
            {
                values[y][x] = 0;
            }
        }
        
        cin >> m;
        cin >> n;
        if(m == 0 || n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if(m > 2000)
        {
            m += 200;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> items[i].p;
            cin >> items[i].f;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int weight = 1; weight <= m; weight++)
            {
                if(items[i - 1].p <= weight)
                {
                    values[i][weight] = max(values[i - 1][weight], values[i - 1][weight - items[i - 1].p] + items[i - 1].f);
                }
                else
                {
                    values[i][weight] = values[i - 1][weight];
                }
                // cout << weight << ':' << values[i][weight] << ' ';
            }
            // cout << endl;
        }
        cout << values[n][m] << endl;
    }
    return 0;
}
