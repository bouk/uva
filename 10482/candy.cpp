#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned char byte;

int n;
int cases;
byte candies[32];

int main()
{
    scanf("%d", &cases);
    for(int c = 0; c < cases; c++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &candies[i]);
        }
    }
}