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


bool ReadInFile(const string& sFile, int& johnStart, int& johnEnd, int& cowStart, int& cowEnd)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    in >> johnStart >> johnEnd;
    in >> cowStart >> cowEnd;

    return true;
}

void Print(const int johnStart, const int johnEnd, const int cowStart, const int cowEnd)
{
    cout << johnStart << " " << johnEnd << endl;
    cout << cowStart << " " << cowEnd << endl;
}

bool WriteOut(const string& sFile, const int areaPainted)
{
    cout << areaPainted << endl;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << areaPainted << endl;

    out_file.close();

    return true;
}

int main()
{
    int johnStart, johnEnd, cowStart, cowEnd;

    bool bOk = ReadInFile("paint.in", johnStart, johnEnd, cowStart, cowEnd);
    //Print(johnStart, johnEnd, cowStart, cowEnd);

    vector<string> ans;

    int johnLen = johnEnd - johnStart;
    int cowLen = cowEnd - cowStart;
    int areaPainted = 0;

    if (cowStart >= johnStart && cowEnd <= johnEnd)
    {
        areaPainted = johnLen;
    }

    else if (cowStart <= johnStart && cowEnd >= johnEnd)
    {
        areaPainted = cowLen;
    }

    else if (johnStart < cowEnd && johnStart > cowStart)
    {
        areaPainted = cowLen + (johnEnd - cowEnd);
    }

    else if (cowStart < johnEnd && cowStart > johnStart)
    {
        areaPainted = johnLen + (cowEnd - johnEnd);
    }
    else
    {
        areaPainted += cowLen + johnLen;
    }

    WriteOut("paint.out", areaPainted);
}