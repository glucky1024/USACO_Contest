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

bool ReadInFile(const string& sFile, vector<string>& order, vector<int>& range)
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

    string s;
    in >> s;

    for (int j = 0; j < s.length(); j++)
    {
        order.push_back(s.substr(j, 1));
    }


    for (int i = 0; i < nCows; i++)
    {
        int temp;
        in >> temp;
        range.push_back(temp);
    }
    return true;
}

void Print(const vector<string> order, const vector<int> range)
{
    cout << order.size() << endl;

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < range.size(); i++)
    {
        cout << range[i] << " ";
    }
    cout << endl;

}

bool ReadInCout(vector<string>& order, vector<int>& range)
{
    ios::sync_with_stdio(0); cin.tie(0);

    order.clear();
    range.clear();

    int nCows = 0;
    cin >> nCows;

    string s;
    cin >> s;

    for (int j = 0; j < s.length(); j++)
    {
        order.push_back(s.substr(j, 1));
    }


    for (int i = 0; i < nCows; i++)
    {
        int temp;
        cin >> temp;
        range.push_back(temp);
    }
    return true;
}


bool WriteOut(const string& sFile, const int ans)
{
    cout << ans << endl;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << ans << endl;

    out_file.close();

    return true;
}

int foundLeaderG(int cowI, vector<int> range, int& leaderG)
{
    for (int i = cowI; i <= range[cowI] - 1; i++)
    {
        if (i == leaderG)
        {
            return cowI;
        }
    }

    return 0;
}

int foundLeaderH(int cowI, vector<int> range, int& leaderH)
{               
    for (int i = cowI; i <= range[cowI]-1; i++)
    {
        if (i == leaderH)
        {
            return cowI;
        }
    }

    return 0;
}

int main()
{
    vector<string> order;
    vector<int> range;
    int cnt = 0, cnt1 =0;

    bool bOk = ReadInFile("../prob1_bronze_jan23/5.in", order, range);
    //ReadInCout(order, range);
    //Print(order, range);

    int ans = 0, totalG = 0, totalH = 0;
    int leaderH = -1, leaderG = -1; //is whatever i of GHHG it falls on

    for (int i = 0; i < range.size(); i++)
    {
        if (order[i] == "G")
        {
            totalG++;
        }

        else
        {
            totalH++;
        }
    }

    //holsteins first
    for (int i = 0; i < order.size(); i++)
    {
        if (order[i] == "G")
        {
            int temp = 0;
            for (int j = i; j < range[i]; j++)
            {
                if (order[j] == "G")
                {
                    temp++;
                }
            }

            if (temp == totalG)
            {
                leaderG = i;
                cnt1++;
            }
            break;
        }
    }

    for (int i = 0; i < order.size(); i++)
    {
        if (order[i] == "H")
        {
            int temp = 0;
            for (int j = i; j < range[i]; j++)
            {
                if (order[j] == "H")
                {
                    temp++;
                }
            }
            if (temp = totalH)
            {
                leaderH = i;
                cnt++;
            }
            break;
        }
    }

    int newLeaderG = 0;

    //now if holstein has gurnsey leader
    for (int i = 0; i < leaderH; i++)
    {
        if (order[i] == "G" && range[i] >= leaderH)
        {
            newLeaderG++;
        }

        else if (i == leaderG)
        {
            newLeaderG++;
        }
    }

    int newLeaderH = 0;
    for (int i = 0; i < leaderG; i++)
    {
        if (order[i] == "H" && range[i] >= leaderG)
        {
            newLeaderH++;
        }

        else if (i == leaderH)
        {
            newLeaderH++;
        }
    }

    ans = newLeaderH+newLeaderG;

    cout << ans << endl;
}