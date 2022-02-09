#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 51
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;

const double PI = acos(-1); // PI 값을 지정해 놓음
typedef complex<double> cpx;
void FFT(vector<cpx>& f, cpx w) {
	int n = f.size();
	if (n == 1) return; //base case
	vector<cpx> even(n >> 1), odd(n >> 1);
	for (int i = 0; i < n; i++) {
		if (i & 1) odd[i >> 1] = f[i];
		else even[i >> 1] = f[i];
	}
	FFT(even, w * w); FFT(odd, w * w);
	cpx wp(1, 0);
	for (int i = 0; i < n / 2; i++) {
		f[i] = even[i] + wp * odd[i];
		f[i + n / 2] = even[i] - wp * odd[i];
		wp *= w;
	}
}
/*
input : a => A's Coefficient, b => B's Coefficient
output : A * B
*/
vector<cpx> mul(vector<cpx> a, vector<cpx> b) {
	int n = 1;
	while (n <= a.size() || n <= b.size()) n <<= 1;
	n <<= 1;
	a.resize(n); b.resize(n); vector<cpx> c(n);
	cpx w(cos(2 * PI / n), sin(2 * PI / n));
	FFT(a, w); FFT(b, w);
	for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
	FFT(c, cpx(1, 0) / w);
	for (int i = 0; i < n; i++) {
		c[i] /= cpx(n, 0);
		c[i] = cpx(round(c[i].real()), round(c[i].imag())); //result is integer
	}
	return c;
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> A(n + n), B(n);
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = n - 1; i >= 0; i--) cin >> B[i];
	for (int i = 0; i < n; i++) A[i + n] = A[i];
	vector<cpx> a, b;
	for (auto i : A) a.push_back(cpx(i, 0));
	for (auto i : B) b.push_back(cpx(i, 0));
	vector<cpx> c = mul(a, b);
	long long ans = 0;
	for (int i = 0; i < c.size(); i++) {
		cout << round(c[i].real()) << " ";
	}
	return 0;
}