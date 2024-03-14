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

#define RUN_SERVER 1


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

    return true;
}

void Print(const int L, const vector<int> papers)
{

}

bool ReadInCout(int& L, vector<int>& papers)
{
    ios::sync_with_stdio(0); cin.tie(0);



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

bool isAlph(const string& s1, const string& s2)
{
    int mini = min(s1.size(), s2.size());
    for (int i = 0; i < mini; i++)
    {
        if (s1[i] == s2[i])
        {
            continue;
        }
        else if (s1[i] < s2[i])
        {
            return true;
        } 
        else
        {
            return false;
        }
    }

    assert(0);
    return false;
}

int main()
{
    int K = 0, N = 0;
#ifdef RUN_SERVER  
    cin >> K >> N;
#else
    string sFile = "../prob2_bronze_open21/2.in";
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }
    in >> K >> N;
#endif

    vector<string> members;
    map<string, int> scores;
    for (int i = 0; i < N; i++)
    {
        string temp1;
#ifdef RUN_SERVER  
        cin >> temp1;
#else
        in >> temp1;
#endif
        members.push_back(temp1);
        scores[temp1] = 0;
    }

    for (int i = 0; i < K; i++)
    {
        bool bAlph = true;
        vector<string> order;
        for (int j = 0; j < N; j++)
        {
            string temp1;
#ifdef RUN_SERVER  
            cin >> temp1;
#else
            in >> temp1;
#endif
            order.push_back(temp1);
        }

        int s = 0;
        for (int j = 0; j < N - 1; j++)
        {
            string name_1 = order[j+1];
            if (isAlph(order[j], order[j + 1]))
            {
                scores[name_1] += s;
                continue;
            }
            else
            {
                s++;
                scores[name_1] += s;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        int s_i = scores[members[i]];
        for (int j = 0; j < N; j++)
        {
            if (i == j) {
                cout << "B";
                continue;
            }
            int s_j = scores[members[j]];
            if (s_i > s_j) {
                cout << 1;
            }
            else if (s_i == s_j)
            {
                cout << "?";
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }

    //WriteOut("marathon.out", ans);
}