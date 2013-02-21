#include <iostream>
#include <stdlib.h>

using namespace std;

int N;

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        int speed;
        int maxspeed = 0;
        cin >> speed;
        maxspeed = max(speed, maxspeed);
        while(cin.peek() != '\n')
        {
            cin >> speed;
            maxspeed = max(speed, maxspeed);
        }
        cout << "Case " << i+1 << ": " << maxspeed << endl;
    }
    return 0;
}
