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

bool ReadInFile(const string& sFile, vector<int>& movesTo, vector<string>& ids)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int n;
    movesTo.clear();
    ids.clear();

    in >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        in >> temp;
        movesTo.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        string temp;
        in >> temp;
        ids.push_back(temp);
    }

    return true;
}

void Print(const vector<int> movesTo, vector<string> ids)
{
    cout << movesTo.size() << endl;

    for (int i = 0; i < movesTo.size(); i++)
    {
        cout << movesTo[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < movesTo.size(); i++)
    {
        cout << ids[i] << " ";
    }

    cout << endl;
}

bool WriteOut(const string& sFile, const vector<string> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    //
    ofstream out_file;
    out_file.open(sFile);

    for (int i = 0; i < ans.size(); i++)
    {
        out_file << ans[i] << endl;
    }


    out_file.close();

    return true;
}

int main()
{
    vector<int> movesTo;
    vector<string> ids;

    bool bOk = ReadInFile("shuffle.in", movesTo, ids);
    Print(movesTo, ids);

    int nCows = movesTo.size();

    for (int k = 0; k < 3; k++)
    {
        std::vector<std::string> old_pos(nCows);
        for (int i = 0; i < nCows; i++)
        {
            old_pos[i] = ids[movesTo[i] - 1];
        }
        ids = old_pos;
    }

    WriteOut("shuffle.out", ids);
}