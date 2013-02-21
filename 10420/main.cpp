#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map <string, int> countries;

int main()
{
    cin >> n;
    
    string input;
    while(n-- > 0)
    {
        cin >> input;
        char c;
        while(cin.get(c))
        {
            if(c == '\n')
            {
                break;
            }
        }
        countries[input]++;
    }
    
    for(map<string, int>::iterator iter = countries.begin(); iter != countries.end(); iter++)
    {
        cout << iter->first << ' ' << iter->second << endl;
    }
    
    return 0;
}
