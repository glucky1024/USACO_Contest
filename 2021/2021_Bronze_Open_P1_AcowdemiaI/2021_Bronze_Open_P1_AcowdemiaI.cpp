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

bool ReadInFile(const string& sFile, int& L, vector<int>& papers)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nPapers;
    in >> nPapers >> L;

    for (int i = 0; i < nPapers; i++)
    {
        int temp1;
        in >> temp1;
        papers.push_back(temp1);
    }

    return true;
}

void Print(const int L, const vector<int> papers)
{
    cout << papers.size() << " " << L << endl;

    for (int i = 0; i < papers.size(); i++)
    {
        cout << papers[i] << " ";
    }

    cout << endl;
}

bool ReadInCout(int& L, vector<int>& papers)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nPapers;
    cin >> nPapers >> L;

    for (int i = 0; i < nPapers; i++)
    {
        int temp1;
        cin >> temp1;
        papers.push_back(temp1);
    }

    return true;
}


bool WriteOut(const string& sFile, const int& ans)
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
    vector<int> c;
    int L;

    //bool bOk = ReadInFile("../prob1_bronze_open21/4.in", L, c);
    ReadInCout(L, c);
    //Print(L, papers);

    int h = 0;
    sort(c.begin(), c.end(), greater<int>());
    //bool found = false;
    //while (!found)
    //{
    //    h++;
    //    if (c[h - 1] >= h)
    //    {
    //        continue;
    //    }
    //    else
    //    {    
    //        h--;
    //        found = true;
    //        break;
    //    }
    //}

    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] > i) {
            h = i + 1;
        }
        else {
            break;
        }
    }



    int cnt = 0;
    for (int i = h; i < c.size(); i++)
    {
        if (cnt >= L)
        {
            break;
        }

        if (c[i] + 1 > i)
        {
            h = i + 1;
            cnt++;
        }
        else
        {
            break;
        }
    }


    cout << h << endl;

    //WriteOut("marathon.out", ans);
}