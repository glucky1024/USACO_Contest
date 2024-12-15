#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <set>
#include <map>

using namespace std;

bool ReadInFile(const string& sFile)
{
    return true;
}

void Print()
{


    cout << endl;
}

bool ReadInCout()
{
    ios::sync_with_stdio(0); cin.tie(0);



    return true;
}


bool WriteOut(const string& sFile, const vector<int> ans)
{

    return true;
}


int main()
{
    //fstream in;
    //in.open("1.in", ios::in);
    //if (!in.is_open())
    //{
    //    cout << "Error: cannot open input file." << endl;
    //    return false;
    //}

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n = 0;
        cin >> n;

        vector<int> cows;
        set<int> ans;

        for (int j = 0; j < n; j++)
        {
            int x = 0;
            cin >> x;
            cows.push_back(x);
        }

        for (int j = 0; j < n; j++)
        {
            if (j + 1 < n && cows[j] == cows[j + 1])
            {
                ans.insert(cows[j]);
            }

            if (j + 2 < n && cows[j] == cows[j + 2])
            {
                ans.insert(cows[j]);
            }
        }

        set<int>::iterator a;

        if (ans.size() == 0)
        {
            cout << -1 << endl;
        }

        else
        {
            for (a = ans.begin(); a != ans.end(); a++)
            {
                cout << *a;
                if (next(a) != ans.end())
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}
