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

bool ReadInFile(const string& sFile, int& start, vector<int>& types, vector<int>& powers)
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

void Print(const vector<int> slept)
{
    cout << slept.size() << endl;

    for (int i = 0; i < slept.size(); i++)
    {
        cout << slept[i] << " ";
    }

    cout << endl;
}

bool ReadInCout(long long& start, vector<int>& types, vector<int>& powers)
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

int main()
{
    //string sFile = "../prob1_bronze_feb22/1.in";

    //fstream in;
    //in.open(sFile, ios::in);
    //if (!in.is_open())
    //{
    //    cout << "Error: cannot open input file." << endl;
    //    return false;
    //}

    vector<int> slept;
    int sum = 0;

    int t;
    //in >> t;
    cin >> t;
    for (int p = 0; p < t; p++)
    {
        sum = 0;
        slept.clear();
        int n;
        //in >> n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int temp1;
            //in >> temp1;
            cin >> temp1;

            slept.push_back(temp1);
            sum += temp1;
        }

        // r is the ending amt of numbers there will be
        for (int r = n; r >= 1; r--)
        {
            if (sum % r == 0)
            {
                int section = sum / r;

                int curSum = 0;
                bool equals = true;

                for (int i = 0; i < n; i++)
                {
                    curSum += slept[i];

                    if(curSum > section)
                    {
                        equals = false;
                        break;
                    }

                    if (curSum == section)
                    {
                        curSum = 0;
                    }
                }

                if (equals)
                {
                    cout << n - r << endl;
                    break;
                }
            }
        }

    }

}