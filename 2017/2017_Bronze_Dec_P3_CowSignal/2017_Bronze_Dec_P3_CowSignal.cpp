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


bool ReadInFile(const string& sFile, vector<string>& lines, int& k)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nLines, sLen;
    in >> nLines >> sLen >> k;
    
    for (int i = 0; i < nLines; i++)
    {
        string s;
        in >> s;
        lines.push_back(s);
    }

    return true;
}

void Print(const vector<string> lines, const int k)
{
    cout << lines.size() <<" " << lines[0].length() << " " << k << endl;

    for (int i = 0; i < lines.size(); i++)
    {
        cout << lines[i] << endl;
    }
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

string lineAfterMult(vector<string> lines, int i, int k)
{
    string theLine;

    for (int j = 0; j < lines[i].length(); j++)
    {
        if (lines[i].substr(j, 1) == "X")
        {
            for (int p = 0; p < k; p++)
            {
                theLine += "X";
            }
        }

        else
        {
            for (int p = 0; p < k; p++)
            {
                theLine += ".";
            }
        }
    }

    return theLine;
}

int main()
{
    vector<string> lines;
    int k;

    bool bOk = ReadInFile("cowsignal.in", lines, k);
    //Print(lines, k);

    vector<string> ans;

    for(int i =0; i < lines.size(); i++)
    {
        string curLine = lineAfterMult(lines, i, k);

        for (int i = 0; i < k; i++)
        {
            ans.push_back(curLine);
        }
    }
    

    WriteOut("cowsignal.out", ans);
}