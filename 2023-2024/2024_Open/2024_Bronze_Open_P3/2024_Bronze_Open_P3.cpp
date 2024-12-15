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
#include <stack>

#define RUN_SERVER 1

using namespace std;

bool ReadInFile(const string& sFile, vector<int>& )
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }


    return true;
}

bool ReadInCout(vector<int>& )
{
    ios::sync_with_stdio(0); cin.tie(0);

    return true;
}

void Print(vector<int>& )
{

}

void WriteOut(vector<bool>& ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i])
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    //ReadInFile("../P3.in");
    //Print();
    //ReadInCout();

    string sFile = "../P3.in";
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int T =0;
#ifdef RUN_SERVER  
    cin >> T;
#else
    string sFile = "../P2.in";
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }
    in >> T;
#endif
    for (int t = 0; t < T; t++)
    {
        int N = 0;
#ifdef RUN_SERVER
            cin >> N;
#else
            in >> N;
#endif   
        vector<int> H;
        for (int j = 0; j < N; j++)
        {
            int te;
#ifdef RUN_SERVER
            cin >> te;
#else
            in >> te;
#endif 
            H.push_back(te);
        }


    }

    //WriteOut(ans);
}