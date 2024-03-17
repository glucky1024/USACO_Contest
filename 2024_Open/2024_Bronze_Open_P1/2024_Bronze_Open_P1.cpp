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

bool ReadInFile(const string& sFile, vector<int>&)
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

bool ReadInCout(vector<int>&)
{
    ios::sync_with_stdio(0); cin.tie(0);

    return true;
}

void Print(vector<int>&)
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

bool isEven(int j)
{
    return j % 2 == 0;
}

void clean_empty(vector<string>& Bs)
{
    vector<string> BsLocal = Bs;
    Bs.clear();
    for (const string& b : BsLocal) {
        if (b.empty())
            continue;
        Bs.push_back(b);
    }
}
void clean_empty(vector<int>& Bs)
{
    vector<int> BsLocal = Bs;
    Bs.clear();
    for (const int& val : BsLocal) {
        if (val == -1)
            continue;
        Bs.push_back(val);
    }
}

int main()
{
    // vector<int>;
    //ReadInFile("../P1.in", );
    //Print();
    //ReadInCout();

    long N = 0, Q = 0;
    vector<int> vecBs_OG; // 0- false, 1-true, 2- and, 3- or
    vector<string> ans;

#ifdef RUN_SERVER  
    cin >> N >> Q;
#else
    string sFile = "../P1_2.in";
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }
    in >> N >> Q;
#endif

    for (long i = 0; i < N; i++)
    {
        string s1;
#ifdef RUN_SERVER  
        cin >> s1;
#else
        in >> s1;
#endif
        int iVal = -1;
        if (s1 == "false") {
            iVal = 0;
        }
        else if(s1 == "true") {
            iVal = 1;
        }
        else if (s1 == "and") {
            iVal = 2;
        }
        else if (s1 == "or") {
            iVal = 3;
        }
        vecBs_OG.push_back(iVal);
    }

    for (long i = 0; i < Q; i++)
    {
        long start = 0, end = 0;
        string target;
#ifdef RUN_SERVER  
        cin >> start >> end >> target;
#else
        in >> start >> end >> target;
#endif
        bool bTarget = target == "true" ? true: false;

        // true
        vector<int> BsLocal = vecBs_OG;
        BsLocal.erase(BsLocal.begin() + start - 1, BsLocal.begin() + end - 1);
        BsLocal[start - 1] = 1;

        // and
        for (long j = 1; j < BsLocal.size(); j += 2)
        {
            if (BsLocal[j] == 2)
            {
                if (BsLocal[j - 1] == 0 || BsLocal[j + 1] == 0)
                {
                    BsLocal[j + 1] = 0;
                }
                else
                {
                    BsLocal[j + 1] = 1;
                }
                BsLocal[j - 1] = -1;
                BsLocal[j] = -1;
            }
        }
        clean_empty(BsLocal);

        // or
        for (long j = 1; j < BsLocal.size(); j += 2)
        {
            if (BsLocal[j] == 3)
            {
                if (BsLocal[j - 1] == 1 || BsLocal[j + 1] == 1)
                {
                    BsLocal[j + 1] = 1;
                }
                else
                {
                    BsLocal[j + 1] = 0;
                }
                BsLocal[j - 1] = -1;
                BsLocal[j] = -1;
            }
        }
        clean_empty(BsLocal);
        assert(BsLocal.size() == 1);
        if (BsLocal[0] == bTarget)
        {
            ans.push_back("Y");
            continue;
        }


        //false
        BsLocal = vecBs_OG;
        BsLocal.erase(BsLocal.begin() + start - 1, BsLocal.begin() + end - 1);
        BsLocal[start - 1] = 0;

        // and
        for (long j = 1; j < BsLocal.size(); j += 2)
        {
            if (BsLocal[j] == 2)
            {
                if (BsLocal[j - 1] == 0 || BsLocal[j + 1] == 0)
                {
                    BsLocal[j + 1] = 0;
                }
                else
                {
                    BsLocal[j + 1] = 1;
                }
                BsLocal[j - 1] = -1;
                BsLocal[j] = -1;
            }
        }
        clean_empty(BsLocal);

        // or
        for (long j = 1; j < BsLocal.size(); j += 2)
        {
            if (BsLocal[j] == 3)
            {
                if (BsLocal[j - 1] == 1 || BsLocal[j + 1] == 1)
                {
                    BsLocal[j + 1] = 1;
                }
                else
                {
                    BsLocal[j + 1] = 0;
                }
                BsLocal[j - 1] = -1;
                BsLocal[j] = -1;
            }
        }
        clean_empty(BsLocal);



        assert(BsLocal.size() == 1);
        if (BsLocal[0] == bTarget)
        {
            ans.push_back("Y");
            continue;
        }

        ans.push_back("N");
    }

    for (const string& s : ans)
    {
        cout << s;
    }
    cout << endl;

    //WriteOut(ans);
}