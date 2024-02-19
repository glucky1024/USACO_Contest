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


using namespace std;

void Print(const vector<string> words, const vector<string> types, const int commas, const int periods)
{
    cout << words.size() << " " << commas << " " << periods << endl;

    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i] << " " << types[i] << endl;
    }

}

int main()
{
    string sFile = "../prob2_bronze_open23/1.in";

    fstream in;
    in.open(sFile, ios::in);
    if (!in.is_open())
    {
        cout << "Error: cannot open input file." << endl;
        return false;
    }

    int nT=0;
    in >> nT;
    //cin >> t;

    for (int test = 0; test < nT; test++)
    {
        unsigned int nWords = 0, nCommas = 0, nPeriods = 0;
        in >> nWords >> nCommas >> nPeriods;
        //cin >> nWords >> commas >> periods;

        vector<string> wordsNoun, wordsVi, wordsVt, wordsConj;
        for (unsigned int i = 0; i < nWords; i++) 
        {
            string w, sType;
            in >> w >> sType;
            //cin >> w >> sType;

            if (sType == "intransitive-verb")
            {
                wordsVi.push_back(w);
            }
            else if (sType == "transitive-verb")
            {
                wordsVt.push_back(w);
            }
            else if (sType == "noun")
            {
                wordsNoun.push_back(w);
            }
            else if (sType == "conjunction")
            {
                wordsConj.push_back(w);
            }
            else {
                assert(0);
            }
        }

        unsigned int ans = 0;
        for (unsigned int iVt = 0; iVt < wordsVt.size(); ++iVt) 
        {
            unsigned int iVi = min(wordsVi.size(), wordsNoun.size() - 2 * iVt); // 
            unsigned int J = 0;
            while (iVi >= 0) {
                J = min((unsigned int)wordsConj.size(), (iVt + iVi) / 2); // J=min(# of conjunctions,T/2)
                if (iVt + iVi - J <= nPeriods) //  T-J<=P
                    break;
                iVi--;
            }
            if (iVi < 0)
                continue;
            
            unsigned int M = min(nCommas, (unsigned int)wordsNoun.size() - (iVi + 2* iVt)); // M = min(n - (t1 + 2*t2), C)
            if (iVt == 0)
                M = 0;

            unsigned int W = 2 *iVi + 3*iVt + J + M; // W = 2*t1 +3*t2 + J + M
            ans = max(ans, W);
        }

        cout << ans << endl;
    }
}