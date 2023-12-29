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

bool ReadInFile(const string& sFile, vector<int>& sTimes, vector<int>& eTimes, vector<int>& buckets)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nCows;
    in >> nCows;

    for (int i = 0; i < nCows; i++)
    {
        int start; int end; int b;
        in >> start >> end >> b;

        sTimes.push_back(start);
        eTimes.push_back(end);
        buckets.push_back(b);
    }

    return true;
}

void Print(const vector<int> sTimes, const vector<int> eTimes, const vector<int> buckets)
{
    cout << buckets.size() << endl;

    for (int i = 0; i < buckets.size(); i++)
    {
        cout << sTimes[i] << " " << eTimes[i] << " " << buckets[i] << endl;
    }
}

bool WriteOut(const string& sFile, const int maxBuck)
{
    cout << maxBuck << endl;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << maxBuck<< endl;

    out_file.close();

    return true;
}

int main()
{
    vector<int> sTimes;
    vector<int> eTimes;
    vector<int> buckets;

    bool bOk = ReadInFile("blist.in", sTimes, eTimes, buckets);
    //Print(sTimes, eTimes, buckets);

    int maxBuck = 0;

    for (int time = 1; time <= 1000; time++)
    {
        int buck1sec = 0;
        for (int i = 0; i < buckets.size(); i++)
        {
            if (sTimes[i] <= time && eTimes[i] >= time)
            {
                buck1sec += buckets[i];
            }
        }

        maxBuck = max(maxBuck, buck1sec);
    }

    WriteOut("blist.out", maxBuck);
}