#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

string board[5];
char number[10][5][3] = {
	//0
	{
		{'*','*','*'},
		{'*',' ','*'},
		{'*',' ','*'},
		{'*',' ','*'},
		{'*','*','*'}
	},
	//1
	{
		{' ',' ','*'},
		{' ',' ','*'},
		{' ',' ','*'},
		{' ',' ','*'},
		{' ',' ','*'}
	},
	//2
	{
		{'*','*','*'},
		{' ',' ','*'},
		{'*','*','*'},
		{'*',' ',' '},
		{'*','*','*'}
	},
	//3
	{
		{'*','*','*'},
		{' ',' ','*'},
		{'*','*','*'},
		{' ',' ','*'},
		{'*','*','*'}
	},
	//4
	{
		{'*',' ','*'},
		{'*',' ','*'},
		{'*','*','*'},
		{' ',' ','*'},
		{' ',' ','*'}
	},
	//5
	{
		{'*','*','*'},
		{'*',' ',' '},
		{'*','*','*'},
		{' ',' ','*'},
		{'*','*','*'}
	},
	//6
	{
		{'*','*','*'},
		{'*',' ',' '},
		{'*','*','*'},
		{'*',' ','*'},
		{'*','*','*'}
	},
	//7
	{
		{'*','*','*'},
		{' ',' ','*'},
		{' ',' ','*'},
		{' ',' ','*'},
		{' ',' ','*'}
	},
	//8
	{
		{'*','*','*'},
		{'*',' ','*'},
		{'*','*','*'},
		{'*',' ','*'},
		{'*','*','*'}
	},
	//9
	{
		{'*','*','*'},
		{'*',' ','*'},
		{'*','*','*'},
		{' ',' ','*'},
		{'*','*','*'}
	},
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 5; ++i)
        getline(cin, board[i]);

    bool flag = false;
    int ans = 0;
    for(int i = 0; i < board[0].size(); i += 4){
        int nn = 0;
        while(nn < 10){
            bool flag = true;
			int cnt = 0;
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 3; y++) {
					if (board[x][i + y] == '*') cnt++;
					if (board[x][i + y] != number[nn][x][y]) {
						flag = false;
					}
				}
			}
			if (cnt == 0) {
				break;
			}
			if (flag) {
				ans = ans * 10 + nn;
				break;
			}
            nn++;
        }
        if(nn == 10){
            flag = true;
            break;
        }
    }
    if(ans % 6 != 0 || flag)
        cout << "BOOM!!" << endl;
    else   
        cout << "BEER!!" << endl;
    return 0;
}