#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> grid;
int T;
int N;

void paint(int x, int y)
{
    if(grid[y][x] != 'x' && grid[y][x] != '@')
    {
        return;
    }
    grid[y][x] = '.';
    if(x > 0)
    {
        paint(x - 1, y);
    }
    if(y > 0)
    {
        paint(x, y - 1);
    }
    if(x < N - 1)
    {
        paint(x + 1, y);
    }
    if(y < N - 1)
    {
        paint(x, y + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> N;
        grid.resize(N);
        for(int i = 0; i < N; i++)
        {
            cin >> grid[i];
        }
        int count = 0;
        for(int x = 0; x < N; x++)
        {
            for(int y = 0; y < N; y++)
            {
                if(grid[y][x] == 'x')
                {
                    paint(x, y);
                    count++;
                }
            }
        }
        cout << "Case " << t << ": " << count << endl;
    }
}
