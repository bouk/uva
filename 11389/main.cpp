#include <iostream>
#include <cstdlib>

using namespace std;

int morning_routes[100];
int evening_routes[100];

int n;
int d;
int r;

int sortints(const void * a, const void * b)
{
    return (*(int*)a) - (*(int*)b);
}

int main()
{
    while(true){
    cin >> n;
    cin >> d;
    cin >> r;
    if(!n || !d || !r)
    {
        break;
    }
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> morning_routes[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        cin >> evening_routes[i];
    }
    qsort(morning_routes, n, sizeof(int), sortints);
    qsort(evening_routes, n, sizeof(int), sortints);
    
    for(int i = 0; i < n; i++)
    {
        int t = morning_routes[i] + evening_routes[n - i - 1];
        if(t > d)
        {
            total += (t - d) * r;
        }
    }
    cout << total << endl;
    }
    return 0;
}
