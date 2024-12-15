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

using namespace std;   

long long ceilDiv(long long a, long long b)
{
    return (a + b - 1) / b;
}


bool ReadInFile(const string& sFile)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int t = 0;
    in >> t;

    for (int i = 0; i < t; i++)
    {
        int n = 0;
        in >> n;

        vector<int> initials;
        vector<int> grows;
        vector<int> t;

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            in >> x;
            initials.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            in >> x;
            grows.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            in >> x;
            t.push_back(x);
        }

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            p[t[i]] = i;
        }

        long long day = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int smallIdx = p[i + 1], bigIdx = p[i];
            long long diff = (initials[smallIdx] + grows[smallIdx] * day) - (initials[bigIdx] + grows[bigIdx] * day);
            if (diff >= 0)
            {
                long long rateDiff = grows[bigIdx] - grows[smallIdx];
                if (rateDiff <= 0)
                {
                    day = -1;
                    break;
                }
                day += ceilDiv(diff + 1, rateDiff);
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            long long bigDay = initials[p[i]] + grows[p[i]] * day;
            long long smallDay = initials[p[i + 1]] + grows[p[i + 1]] * day;
            if (smallDay >= bigDay)
            {
                day = -1;
                break;
            }
        }

        cout << day << endl;
    }
   
}

bool ReadInCout()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n = 0;
        cin >> n;

        vector<int> initials;
        vector<int> grows;
        vector<int> t;

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            initials.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            grows.push_back(x);
        }

        for (int i = 0; i < n; i++)
        {
            int x = 0;
            cin >> x;
            t.push_back(x);
        }

        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            p[t[i]] = i;
        }

        long long day = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int smallIdx = p[i + 1], bigIdx = p[i];
            long long diff = (initials[smallIdx] + grows[smallIdx] * day) - (initials[bigIdx] + grows[bigIdx] * day);
            if (diff >= 0)
            {
                long long rateDiff = grows[bigIdx] - grows[smallIdx];
                if (rateDiff <= 0)
                {
                    day = -1;
                    break;
                }
                day += ceilDiv(diff + 1, rateDiff);
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            long long bigDay = initials[p[i]] + grows[p[i]] * day;
            long long smallDay = initials[p[i + 1]] + grows[p[i + 1]] * day;
            if (smallDay >= bigDay)
            {
                day = -1;
                break;
            }
        }

        cout << day << endl;
    }

    return true;
}

void Print(const vector<bool>& infects)
{

}

void WriteOut(const string& sFile, int)
{
    //cout <<  << endl;

    //ofstream out_file;
    //out_file.open(sFile);
    //out_file << a << " " << d << endl;

    //out_file.close();
}

int main()
{
    //ReadInFile("1.in");
    //Print(infects);

    ReadInCout();


    //return 1;
}