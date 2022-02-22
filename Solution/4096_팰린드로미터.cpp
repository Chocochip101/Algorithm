#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
	
bool isPld(string str){
    for(int i=0;i<str.size()/2;i++){
        if(str[i]!=str[str.size()-1-i]){
            return false;
        }
    }
    return true;
}
	
string itos(string str,int n){
    string temp = to_string(n);
    while(temp.size()<str.size()){
        temp= "0" + temp;
    }
    return temp;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    string t;
    while(1){
        cin >> t;
        if(t == "0")
            break;
        int cnt = 0;

        while(!isPld(t)){
            cnt++;
            int temp = stoi(t);
            temp++;
            t = itos(t, temp);
        }
        cout << cnt << endl;
    }
	return 0;
}

