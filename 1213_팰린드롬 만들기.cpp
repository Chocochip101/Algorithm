#include<bits/stdc++.h>
#define ll long long
#define MAX 51
using namespace std; 
typedef pair<int, double> p;

string s;
int alphabets[26];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(alphabets, 0, sizeof(alphabets));
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
        alphabets[s[i] - 'A']++;

    int a = 0;
    char Odd_char;
    for(int i = 0; i <26; ++i)
        
        if (alphabets[i] % 2) {
            ++a;
            Odd_char = 'A' + i;
            if (a > 1) {
                cout << "I'm Sorry Hansoo";
                return 0;
            }
        }
    string res;
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < alphabets[i] / 2; ++j)
            res += i + 'A';
    cout << res;
    if(a == 1)
        cout << Odd_char;
    for (int i = res.size() - 1; i >= 0; --i)
        cout << res[i];
    return 0;
}