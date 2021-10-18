// Include libraries
#include <bits/stdc++.h>

// Macros
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define read(type) readInt<type>()

// Constants
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);

// member/method macros
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

// Shorten typenames
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef map<int,int> mii;

// Solution
void solve()
{
	// Code Here
}

// Main function
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
