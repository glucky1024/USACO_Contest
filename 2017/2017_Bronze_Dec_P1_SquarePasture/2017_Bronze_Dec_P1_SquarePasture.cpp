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


bool ReadInFile(const string& sFile, vector<int>& rect1, vector<int>& rect2)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    for (int i = 0; i < 4; i++)
    {
        int temp1;
        in >> temp1;

        rect1.push_back(temp1);
    }

    for (int i = 0; i < 4; i++)
    {
        int temp1;
        in >> temp1;

        rect2.push_back(temp1);
    }

    return true;
}

void Print(const vector<int> rect1, const vector<int> rect2)
{
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


int main()
{
    vector<int> rect1;
    vector<int> rect2;

    bool bOk = ReadInFile("square.in", rect1, rect2);
    //Print(rect1, rect2);

    int rect1L = rect1[2] - rect1[0];
    int rect2L = rect2[2] - rect2[0];

    int length = 0, height = 0;

    int miniX = 10, maxiX = 0, miniY = 10, maxiY = 0;

    if (rect1[0] >= rect2[0] && rect1[2] <= rect2[2])
    {
        length = rect2L;
    }

    else if (rect1[0] <= rect2[0] && rect1[2] >= rect2[2])
    {
        length = rect1L;
    }

    else if (rect1[2] > rect2[2] && rect1[0] > rect2[0])
    {
        //rectangle 1 is longer than 2
        length = rect2L + (rect1[2] - rect2[2]);
    }

    else if (rect1[2] < rect2[2] && rect1[0] < rect2[0])
    {
        //rectangle 2 is longer than 1
        length = rect1L + (rect2[2] - rect1[2]);
    }
    else
    {
        int maxiL = max(rect1[1], rect2[1]);
        int miniL = min(rect1[3], rect2[3]);
        length = abs(maxiL - miniL) + rect1L + rect2L;
    }

    int rect1H = rect1[3] - rect1[1];
    int rect2H = rect2[3] - rect2[1];

    if (rect1[1] >= rect2[1] && rect1[3] <= rect2[3])
    {
        height = rect2H;
    }

    else if (rect1[1] <= rect2[1] && rect1[3] >= rect2[3])
    {
        height = rect1H;
    }

    else if (rect1[3] > rect2[3] && rect1[1] > rect2[1])
    {
        //rectangle 1 is higher than 2
        height = rect2H + (rect1[3] - rect2[3]);
    }

    else if (rect1[3] < rect2[3] && rect1[1] < rect2[1])
    {
        //rectangle 2 is higher than 1
        height = rect1H + (rect2[3] - rect1[3]);
    }
    else
    {
        int maxiH = max(rect1[1], rect2[1]);
        int miniH = min(rect1[3], rect2[3]);
        height = abs(maxiH - miniH) + rect1H + rect2H;
    }

    int maxFR = max(length, height);
    int area = maxFR * maxFR;

    WriteOut("square.out", area);
}