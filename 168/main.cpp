#include <iostream>
#include <list>
#include <cassert>

using namespace std;

struct cavern
{
    bool hascandle;
    list<int> connections;
};

cavern caverns[26];

int cti(char c)
{
    return c - 'A';
}

char itc(int i)
{
    return i + 'A';
}

int theseus_pos;
int minotaur_pos;
int k;
int current_k;

int decide_route()
{
    for(list<int>::iterator iter = caverns[minotaur_pos].connections.begin(); iter != caverns[minotaur_pos].connections.end(); iter++)
    {
        if(!caverns[*iter].hascandle && (*iter != theseus_pos))
        {
            return (*iter);
        }
    }
    return -1;
}

int main()
{
    bool first = true;
    while(true)
    {
        char c;
        cin >> c;
        //cout << c;
        if(c == '#')
        {
            break;
        }
        for(int i = 0; i < 26; i++)
        {
            caverns[i].hascandle = false;
            caverns[i].connections.clear();
        }
        current_k = 0;
        while(true)
        {
            int cave = cti(c);
            cin >> c;
            //cout << c;
            assert(c == ':');
            cin >> c;
            //cout << c;
            while(cti(c) >= 0 && cti(c) < 26)
            {
                caverns[cave].connections.push_back(cti(c));
                cin >> c;
                //cout << c;
            }
            if(c == '.')
            {
                break;
            }
            else if(c == ';')
            {
                cin >> c;
                //cout << c;
            }
        }
        cin >> c;
        minotaur_pos = cti(c);
        cin >> c;
        theseus_pos = cti(c);
        cin >> k;
        /*
        cout << endl;
        for(list<int>::iterator iter = caverns[0].connections.begin(); iter != caverns[0].connections.end(); iter++)
        {
            cout << itc(*iter) << endl;
        }
        */
        caverns[theseus_pos].hascandle = true;
        int old_minotaur_pos;
        while(true)
        {
            current_k++;
            old_minotaur_pos = minotaur_pos;
            minotaur_pos = decide_route();
            if(minotaur_pos == -1)
            {
                if(!first)
                {
                    cout << endl;
                }
                first = false;
                cout << '/' << itc(old_minotaur_pos);
                break;
            }
            theseus_pos = old_minotaur_pos;
            if(current_k == k || k == 0)
            {
                current_k = 0;
                caverns[theseus_pos].hascandle = true;
                cout << itc(theseus_pos) << ' ';
            }
        }
    }
    return 0;
}
