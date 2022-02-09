#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
#define MAX 4002
using namespace std;
typedef pair<int, double> p;

bool solve(string s, string t)
{
    int idx = 0;
    for(int i = 0; i <t.size(); ++i){
        if(idx == s.size())
            return true;
        if(t[i] == s[idx])
            idx++;
    }        
    if(idx == s.size())
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    while (cin >> s>>t)
    {
        if (solve(s, t))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}