#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tri[3];
	while (true) {
		cin >> tri[0] >> tri[1] >> tri[2];
		sort(tri, tri + 3);
		if (!tri[0] && !tri[1] && !tri[2]) break;
		if (tri[2] >= tri[1] + tri[0]) cout << "Invalid" << endl;
		else if (tri[0] == tri[1] && tri[1] == tri[2]) cout << "Equilateral" << endl;
		else if (tri[0] == tri[1] || tri[1] == tri[2] || tri[0] == tri[2]) cout << "Isosceles" << endl;
		else cout << "Scalene" << endl;
	}

	return 0;
}
