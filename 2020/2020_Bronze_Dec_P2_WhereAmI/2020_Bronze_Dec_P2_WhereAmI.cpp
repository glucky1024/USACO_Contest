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

bool ReadInFile(const string& sFile, string& colors)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nMailboxes = 0;

    in >> nMailboxes;
    in >> colors;

    return true;
}

//bool ReadInCout(vector<int>& petalOrder)
//{
//    ios::sync_with_stdio(0); cin.tie(0);
//
//    return true;
//
//}

void Print(const string colors)
{
    cout << colors.size() << endl;

    for (int i = 0; i < colors.size(); i++)
    {
        cout << colors[i];
    }

    cout << endl;
}


bool WriteOut(const string& sFile, int ans)
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
    string colors;

    bool bOk = ReadInFile("whereami.in", colors);
    //Print(colors);

    int nMailbxs = colors.size();
    int ans = 0;

    for (int k = 1; k <= nMailbxs; k++)
    {
        bool bFound = false;
        for (int pos = 0; pos + k <= nMailbxs; pos++)  // this one this the orginal like substring AB
        {
            for (int i = 0; i < pos; i++)
            {
                if (colors.substr(pos, k) == colors.substr(i, k))
                {
                    bFound = true;
                    break;
                }
            }

            if (bFound)
                break;
        }

        if (!bFound)
        {
            ans = k;
            cout << k << endl;
            break;
        }
    }

    WriteOut("whereami.out", ans);

}