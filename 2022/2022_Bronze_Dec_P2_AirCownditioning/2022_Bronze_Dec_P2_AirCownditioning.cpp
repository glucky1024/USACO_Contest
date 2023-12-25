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

bool ReadInFile(const string& sFile, vector<int>& tempsWant, vector<int>& tempsNow)
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
        int t;
        in >> t;
        tempsWant.push_back(t);
    }

    for (int i = 0; i < nCows; i++)
    {
        int t;
        in >> t;
        tempsNow.push_back(t);
    }

    return true;
}

bool ReadInCout(vector<int>& tempsWant, vector<int>& tempsNow)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nCows;
    cin >> nCows;

    for (int i = 0; i < nCows; i++)
    {
        cin >> tempsWant[i];
    }

    for (int i = 0; i < nCows; i++)
    {
        cin >> tempsNow[i];
    }


    return true;
}

void Print(const vector<int> tempsWant, const vector<int> tempsNow)
{
    cout << tempsNow.size() << endl;
    for (int i = 0; i < tempsNow.size(); i++)
    {
        cout << tempsWant[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < tempsNow.size(); i++)
    {
        cout << tempsNow[i] << " ";
    }
}

int PosOrNeg(int num)
{
    if (num > 0)
    {
        return -1;
    }

    else if(num <0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int UpOrDown(int x)
{
    if (x > 0)
    {
        return 1;
    }

    else if (x < 0)
    {
        return -1;
    }

    else
    {
        return 0;
    }
}


int main()
{
    vector<int> tempsWant;
    vector<int> tempsNow;
    //bool bOk = ReadInFile("../prob2_bronze_dec21/1.in", tempsWant, tempsNow);
    //Print(tempsWant, tempsNow);

    bool bOk = ReadInCout(tempsWant, tempsNow);
    if (!bOk) { return 0; }

    //code!

    int nCows = tempsWant.size();
    vector<int> tempsDiff;
    int cnt = 0;

    for (int i = 0; i < nCows; i++)
    {
        int t;
        t = tempsWant[i] - tempsNow[i];
        tempsDiff.push_back(t);
    }

    while (true)
    {
        int nonzero = 0;
        while (nonzero < nCows && tempsDiff[nonzero] == 0)
        {
            nonzero++;
        }

        //check if the nonzero needs to increment or decrement

        int range = nonzero;

        while ((UpOrDown(tempsDiff[range]) == UpOrDown(tempsDiff[nonzero])) && range+1 <nCows)
        {
            range++;
        }

        for (int i = nonzero; i < range; i++)
        {
            if (tempsDiff[i] > 0)
            {
                tempsDiff[i]++;
            }

            else
            {
                tempsDiff[i]--;
            }
        }

        cnt++;
    }

    cout << cnt << endl;
}