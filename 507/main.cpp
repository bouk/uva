#include <iostream>

using namespace std;


int main()
{
    int b;
    cin >> b;
    for(int t = 1; t <= b; t++)
    {
        int s;
        cin >> s;
        int bstart = -1;
        int bend;
        int best = 0;
        int cur = 0;
        int curstart = 1;
        int i;
        for(int pos = 1; pos < s; pos++)
        {
            cin >> i;
            //cout << pos << ':' << i;
            cur += i;
            //cout << ':' << cur << ':' << (bend - bstart) << ':' << (curstart - pos + 1) << endl;
            if(cur >= 0)
            {
                if(cur > best || (cur == best && (bend - bstart < pos + 1 - curstart)))
                {
                    best = cur;
                    bstart = curstart;
                    bend = pos + 1;
                }
            }
            else
            {
                cur = 0;
                curstart = pos + 1;
            }
        }
        if(bstart == -1)
        {
            cout << "Route " << t << " has no nice parts" << endl;
        }
        else
        {
            cout << "The nicest part of route " << t << " is between stops " << bstart << " and " << bend << endl;
        }
    }
    return 0;
}
