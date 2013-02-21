#include <iostream>
#include <cstdlib.h>

int total;
int coins_count;
int coins[100];

int sortcoins(const void * a, const void * b)
{
    return (*(*int)a) - (*(*int)b);
}

int main()
{
    int testcases;
    cin >> testcases;
    for(int testcase = 0; testcase < testcases; testcase++)
    {
        cin >> total;
        cin >> coins_count;
        for(int coin = 0; coin < coins_count; coin++)
        {
            cin >> coins[i];
        }
        qsort(coins, coins_count, sizeof(int), sortcoins);
    }
    
    
    return 0;
}
