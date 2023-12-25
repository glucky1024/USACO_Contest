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

bool ReadInFile(const string& sFile, vector<int>& petalOrder)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nDaisy;
    in >> nDaisy;

    for (int i = 0; i < nDaisy; i++)
    {
        int temp;
        in >> temp;
        petalOrder.push_back(temp);
    }

    return true;
}

bool ReadInCout(vector<int>& petalOrder)
{
    ios::sync_with_stdio(0); cin.tie(0);

    int nDaisy;
    cin >> nDaisy;

    for (int i = 0; i < nDaisy; i++)
    {
        int temp;
        cin >> temp;
        petalOrder.push_back(temp);
    }

    return true;
}

void Print(const vector<int> petalOrder)
{
    cout << petalOrder.size() << endl;

    for (int i = 0; i < petalOrder.size(); i++)
    {
        cout << petalOrder[i] << " ";
    }

    cout << endl;
}

bool avgInRange(int start, int end, double avg, vector<int> petalOrder)
{
    for (int i = start; i <= end; i++)
    {
        double temp = petalOrder[i];
        if (avg == temp)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> petalOrder;

    //bool bOk = ReadInFile("../prob2_bronze_dec20/1.in", petalOrder);
    //Print(petalOrder);

    bool bOk = ReadInCout(petalOrder);
    if (!bOk) { return 0; }

    //code!

    int nDaisy = petalOrder.size();
    int totalPetals = 0;
    int flic = 0;


    for (int i = 0; i < nDaisy; i++)
    {
        totalPetals = 0;
        double avg = 0.0;   
        bool found = false;

        for (int j = i; j < nDaisy; j++)
        {
            totalPetals += petalOrder[j];
            double temp = (j - i) + 1;
            avg = 0.0;
            avg = totalPetals / temp;

            found = avgInRange(i, j, avg, petalOrder);
            if (found == true)
            {
                flic++;
            }
        }
    }

    cout << flic << endl;

}