#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef pair<int, int> p;

char solve(char c){
    if('a' <= c && c <= 'z'){
        int diff = (int)c - 'a';
        if(diff + 13 <= 25)
            return (int)'a' + diff + 13;
        else 
            return (int)'a' + (diff + 13) % 26;

    }else if('A' <= c && c <= 'Z'){
        int diff = (int)c - 'A';
        if(diff + 13 <= 25)
            return (int)'A' + diff + 13;
        else 
            return (int)'A' + (diff + 13) % 26;
    }
    return c;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

    string S; 
    getline(cin, S);
    for(int i = 0; i < S.size(); ++i)
        cout << (char)solve(S[i]);
	return 0;
}