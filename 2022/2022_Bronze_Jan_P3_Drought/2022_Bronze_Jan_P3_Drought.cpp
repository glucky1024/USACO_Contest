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

bool ReadInFile(const string& sFile, vector<int>& patches)
{


    return true;
}

void Print(const vector<int> patches)
{

}

bool ReadInCout(vector<int>& patches)
{
    ios::sync_with_stdio(0); cin.tie(0);


    return true;
}


int main()
{
    vector<int> patches;

    //bool bOk = ReadInFile("test2.in", patches);
    ReadInCout(patches);
    Print(patches);

    string s = "../prob3_bronze_jan22/1.in";
    fstream in;
    in.open(s, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nTests;
    in >> nTests;
    //cin >> nTests;
    vector<int> hungers;

    for (int p = 0; p < nTests; p++)
    {
        int nCows;
        in >> nCows;
        //cin >> nCows;
        hungers.clear();

        for (int i = 0; i < nCows; i++)
        {
            int temp1;
            in >> temp1;
            //cin >> temp1;
            hungers.push_back(temp1);
        }



        
    }








    cout << patches.size() << endl;

    return 0;
}