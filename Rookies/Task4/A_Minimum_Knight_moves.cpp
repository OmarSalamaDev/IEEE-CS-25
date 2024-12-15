#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;


void BFS(vector<vector<ll>> &v, ll x1, ll y1, ll x2, ll y2);


int main() {

	ll t;
  cin >> t;
  vector<ll> ans;
	while (t--) {

    string a, b;
    cin >> a >> b;
    ll x1 = a[0] - 'a';
    ll y1 = a[1] - '1';

    ll x2 = b[0] - 'a';
    ll y2 = b[1] - '1';

    vector<vector<ll>> c(8, vector<ll>(8, 0));

    BFS(c, x1, y1, x2, y2);

    ans.push_back(c[x2][y2] - 1);

	}

  for (auto i : ans) cout << i << endl;

}


void BFS(vector<vector<ll>> &v, ll x1, ll y1, ll x2, ll y2) {
	ll x[] = { -2,-1,+1,+2,+2,+1,-1,-2 };

	ll y[] = { +1,+2,+2,+1,-1,-2,-2,-1 };
	queue<pair<ll, ll>> q;
	v[x1][y1] = 1;
	q.push({ x1,y1 });
	while (!q.empty()) {
		auto it = q.front();
		q.pop();
		ll i = it.first;
		ll j = it.second;
		for (ll k = 0; k < 8; k++)
		{
			ll dx = i + x[k];
			ll dy = j + y[k];

			if (dx >= 0 && dx < 8 && dy >=0 && dy<8 && v[dx][dy]==0) {
				v[dx][dy] = v[i][j] + 1;
				q.push({ dx,dy });
			}

		}
	}

}