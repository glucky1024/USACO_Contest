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

bool ReadInFile(const string& sFile, vector<string>& lists)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int n;
    in >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        in >> s;
        lists.push_back(s);
    }

    return true;
}

void Print(const vector<string> lists)
{
    cout << lists.size() << endl;

    for (int i = 0; i < lists.size(); i++)
    {
        cout << lists[i] << endl;
    }
}

bool ReadInCout(vector<string>& lists)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        lists.push_back(s);
    }


    return true;
}


bool WriteOut(const string& sFile, const vector<int> ans)
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

int calc(string& stringI)
{
    if (stringI.size() < 3)
    {
        return -1;
    }

    //check for moo
    for (int i = 0; i < stringI.length() - 2; i++)
    {
        if (stringI.substr(i, 3) == "MOO")
        {
            return stringI.length() - 3;
        }

        else
        {
            continue;
        }
    }

    for (int i = 0; i < stringI.length() - 2; i++)
    {
        if (stringI.substr(i, 3) == "MOM")
        {
            return stringI.length() - 2;
        }

        else if (stringI.substr(i, 3) == "OOO")
        {
            return stringI.length() - 2;
        }

        else
        {
            continue;
        }
    }

    for (int i = 0; i < stringI.length() - 2; i++)
    {
        if (stringI.substr(i, 3) == "OOM")
        {
            return stringI.length() - 1;
        }
    }

    return -1;

}

int main()
{
    vector<string> lists;

    //bool bOk = ReadInFile("../prob3_bronze_jan23/5.in", lists);
    ReadInCout(lists);
    //Print(lists);

    vector<int> ans;

    for (int i = 0; i < lists.size(); i++)
    {
        int n = calc(lists[i]);
        ans.push_back(n);
    }


    WriteOut("marathon.out", ans);
}