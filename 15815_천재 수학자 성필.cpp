#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX_V 500 + 1
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    stack<int> numbers;
    loop(i, s.size()) {
        if (0 <= (s[i] - '0') && (s[i] - '0') <= 9)
            numbers.push(s[i] - '0');
        else {
            int a, b;
            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();
            if (s[i] == '+')
                numbers.push(a + b);
            else if (s[i] == '-')
                numbers.push(b - a);
            else if (s[i] == '*')
                numbers.push(a * b);
            else if (s[i] == '/')
                numbers.push(b / a);
        }
    }

    cout << numbers.top() << endl;
    return 0;
}