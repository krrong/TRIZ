#include <iostream>
#include <queue>
using namespace std;

struct comp {
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		if (a.first > b.first) {
			return true;
		}
		else if (a.first == b.first) {
			if (a.second.first == b.second.first) {
				return a.second.second > b.second.second;
			}
			return a.second.first > b.second.first;
		}
		else {
			return false;
		}
	}
};

int n, m, k, t, x, y;

// 거리는 x^2 + y^2으로 저장
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;	// (거리, (x, y)) 순으로 저장
		queue <pair<int, pair<int, int>>> q;

		cin >> m >> n >> k;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			int dis = x * x + y * y;
			pq.push(make_pair(dis, make_pair(x, y)));
		}

		// 가까운 k개만 남기기
		for (int i = 0; i < k; i++) {
			q.push(pq.top());
			pq.pop();
		}

		// pq 비우기
		while (!pq.empty()) {
			pq.pop();
		}

		// pq 다시 채우기
		for (int i = 0; i < k; i++) {
			pq.push(q.front());
			q.pop();
		}

		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			int dis = x * x + y * y;
			pair<int, pair<int, int>> tmp = make_pair(dis, make_pair(x, y));
			pq.push(tmp);

			int a = k - 1;
			while (a--) {
				q.push(pq.top());
				pq.pop();
			}
			cout << pq.top().second.first << " " << pq.top().second.second << '\n';

			while (!q.empty()) {
				pq.push(q.front());
				q.pop();
			}
		}
	}

	return 0;
}
