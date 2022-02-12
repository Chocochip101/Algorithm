#include <bits/stdc++.h>
#define endl "\n"
#define MAX 51
using namespace std;

int N;
char s[MAX];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
    
	cin >> N;
    int s_len;
    for(int i = 0; i <N; ++i){
        string temp; cin >> temp;
        if(i == 0){
            for(int j = 0; j < temp.size(); j++)
                s[j] = temp[j];
            s_len = temp.size();
        }
        else{
            for(int j = 0; j < temp.size(); j++)
                if(s[j] !=  temp[j])
                    s[j] = '?';
        }
    }
    for(int i = 0; i < s_len; ++i)
        cout << s[i];
	return 0;
}