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


bool ReadInFile(const string& sFile, vector<pair<string, string>>& boards)
{
    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nBoards;

    in >> nBoards;

    for (int i = 0; i < nBoards; i++)
    {
        string temp1, temp2;
        in >> temp1 >> temp2;

        boards.push_back(std::make_pair(temp1, temp2));
    }

    return true;
}

void Print(const vector<pair<string, string>> boards)
{
    cout << boards.size() << endl;

    for (int i = 0; i < boards.size(); i++)
    {
        cout << boards[i].first << " " << boards[i].second << endl;
    }
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

int main()
{
    vector<pair<string, string>> boards;

    bool bOk = ReadInFile("blocks.in", boards);
    //Print(boards);

    vector<int> ans;
    int totalA =0, totalB = 0, totalC = 0, totalD = 0, totalE = 0, totalF = 0, totalG = 0, totalH = 0, totalI = 0, totalJ = 0, totalK = 0, totalL = 0, totalM = 0;
    int totalN =0, totalO = 0, totalP = 0, totalQ = 0, totalR = 0, totalS = 0, totalT = 0, totalU = 0, totalV = 0, totalW = 0, totalX = 0, totalY = 0, totalZ = 0;

    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0; 

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "a")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "a")
            {
                cnt2++;
            }
        }

        totalA += max(cnt1, cnt2);
    }

    ans.push_back(totalA);

    //b

    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "b")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "b")
            {
                cnt2++;
            }
        }

        totalB += max(cnt1, cnt2);
    }
    ans.push_back(totalB);

    //c
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "c")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "c")
            {
                cnt2++;
            }
        }

        totalC += max(cnt1, cnt2);
    }
    ans.push_back(totalC);

    //d
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "d")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "d")
            {
                cnt2++;
            }
        }

        totalD += max(cnt1, cnt2);
    }
    ans.push_back(totalD);

    //e
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "e")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "e")
            {
                cnt2++;
            }
        }

        totalE += max(cnt1, cnt2);
    }
    ans.push_back(totalE);

    //f
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "f")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "f")
            {
                cnt2++;
            }
        }

        totalF += max(cnt1, cnt2);
    }
    ans.push_back(totalF);

    //g
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "g")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "g")
            {
                cnt2++;
            }
        }

        totalG += max(cnt1, cnt2);
    }
    ans.push_back(totalG);

    //h
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "h")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "h")
            {
                cnt2++;
            }
        }

        totalH += max(cnt1, cnt2);
    }
    ans.push_back(totalH);

    //i
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "i")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "i")
            {
                cnt2++;
            }
        }

        totalI += max(cnt1, cnt2);
    }
    ans.push_back(totalI);

    //j
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "j")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "j")
            {
                cnt2++;
            }
        }

        totalJ += max(cnt1, cnt2);
    }
    ans.push_back(totalJ);      

    //k
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "k")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "k")
            {
                cnt2++;
            }
        }

        totalK += max(cnt1, cnt2);
    }
    ans.push_back(totalK);

    //l
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "l")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "l")
            {
                cnt2++;
            }
        }

        totalL += max(cnt1, cnt2);
    }
    ans.push_back(totalL);

    //m
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "m")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "m")
            {
                cnt2++;
            }
        }

        totalM += max(cnt1, cnt2);
    }
    ans.push_back(totalM);

    //n
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "n")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "n")
            {
                cnt2++;
            }
        }

        totalN += max(cnt1, cnt2);
    }
    ans.push_back(totalN);

    //o
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "o")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "o")
            {
                cnt2++;
            }
        }

        totalO += max(cnt1, cnt2);
    }
    ans.push_back(totalO);

    //p
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "p")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "p")
            {
                cnt2++;
            }
        }

        totalP += max(cnt1, cnt2);
    }
    ans.push_back(totalP);

    //Q
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "q")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "q")
            {
                cnt2++;
            }
        }

        totalQ += max(cnt1, cnt2);
    }
    ans.push_back(totalQ);

    //R
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "r")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "r")
            {
                cnt2++;
            }
        }

        totalR += max(cnt1, cnt2);
    }
    ans.push_back(totalR);

    //S
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "s")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "s")
            {
                cnt2++;
            }
        }

        totalS += max(cnt1, cnt2);
    }
    ans.push_back(totalS);

    //T
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "t")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "t")
            {
                cnt2++;
            }
        }

        totalT += max(cnt1, cnt2);
    }
    ans.push_back(totalT);

    //U
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "u")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "u")
            {
                cnt2++;
            }
        }

        totalU += max(cnt1, cnt2);
    }
    ans.push_back(totalU);

    //V
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "v")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "v")
            {
                cnt2++;
            }
        }

        totalV += max(cnt1, cnt2);
    }
    ans.push_back(totalV);

    //W
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "w")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "w")
            {
                cnt2++;
            }
        }

        totalW += max(cnt1, cnt2);
    }
    ans.push_back(totalW);

    //X
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "x")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "x")
            {
                cnt2++;
            }
        }

        totalX += max(cnt1, cnt2);
    }
    ans.push_back(totalX);

    //Y
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "y")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "y")
            {
                cnt2++;
            }
        }

        totalY += max(cnt1, cnt2);
    }
    ans.push_back(totalY);


    //Z
    for (int j = 0; j < boards.size(); j++)
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < boards[j].first.size(); i++)
        {
            if (boards[j].first.substr(i, 1) == "z")
            {
                cnt1++;
            }
        }

        for (int i = 0; i < boards[j].second.size(); i++)
        {
            if (boards[j].second.substr(i, 1) == "z")
            {
                cnt2++;
            }
        }

        totalZ += max(cnt1, cnt2);
    }
    ans.push_back(totalZ);

    WriteOut("blocks.out", ans);
}