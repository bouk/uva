#include <iostream>

using namespace std;
long long ways[101][101];

int main()
{
    int N;
    int K;
    for(int n = 1; n <= 100; n++)
    {
        ways[n][0] = 0;
    }
    for(int k = 0; k <= 100; k++)
    {
        ways[0][k] = 1;
    }
    for(int n = 1; n <= 100; n++)
    {
        for(int k = 1; k <= 100; k++)
        {
            ways[n][k] = (ways[n-1][k] + ways[n][k-1]) % 1000000;
        }
    }
    while(cin >> N && cin >> K && N && K)
    {
        cout << ways[N][K] << endl;
    }
    return 0;
}
