#include <iostream>

using namespace std;

int T;
int N;
int D;

struct stone
{
    char type;
    int distance;
    bool used;
};

stone stones[100];

void testcase(int c)
{
    fin >> N;
    fin >> D;
    int longest_leap = 0;
    int pos = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> stones[i].type;
        cin >> stones[i].distance;
        stones[i].used = false;
    }
    
}

int main()
{
    fin >> T;
    for(int i = 0; i < T; i++)
    {
        testcase(i + 1);
    }
    return 0;
}
