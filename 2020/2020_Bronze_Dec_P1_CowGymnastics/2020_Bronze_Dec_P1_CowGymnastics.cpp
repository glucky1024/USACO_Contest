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

//bool ReadInFile(const string& sFile, int& nCows, int& data[])
//{
//    fstream in;
//    in.open(sFile, ios::in);
//    if (!in.is_open())
//    {
//        cout << "Error: cannot open input file." << endl;
//        return false;
//    }
//
//    int sessions;
//
//    cin >> sessions >> nCows;
//
//
//      
//
//    return true;
//}
//
//bool ReadInCout(vector<int>& petalOrder)
//{
//    ios::sync_with_stdio(0); cin.tie(0);
//
//    return true;
//
//}
//
//void Print(const vector<int> petalOrder)
//{
//
//}

int nCows = 0; int sessions = 0;
int bonk[10][20];

bool ahead(int cowa, int cowb, int sessionNum)
{
    int posa = 0; int posb = 0;
    for (int i = 0; i < nCows; i++)
    {
        if (bonk[sessionNum][i] == cowa)
        {
            posa = i;
        }

        if (bonk[sessionNum][i] == cowb)
        {
            posb = i;
        }
    }

    if (posa > posb)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int total(int cowa, int cowb)
{
    int count = 0; 

    for (int i = 0; i < sessions; i++)
    {
        if (ahead(cowa, cowb, i) == true)
        {
            count++;
        }
    }

    return count;
}

bool WriteOut(const string& sFile, int maxN)
{
    cout << maxN << endl;

    //
    ofstream out_file;
    out_file.open(sFile);
    out_file << maxN << endl;


    out_file.close();

    return true;
}

int main()
{
    fstream in;
    in.open("gymnastics.in", ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int ans = 0;

    in >> sessions >> nCows;

    for (int i = 0; i < sessions; i++)
    {
        for (int j = 0; j < nCows; j++)
        {
            in >> bonk[i][j];
        }
    }

    for (int i = 1; i <= nCows; i++)
    {
        for (int j = 1; j <= nCows; j++)
        {
            if (total(i, j) == sessions)
            {
                ans++;
            }
        }
    }

    WriteOut("gymnastics.out", ans);
}