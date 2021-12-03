#include <iostream>
#include <queue>
using namespace std;

int t, m, n, k;

// max pq위한 comp구조체
struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		// 거리가 같으면 x좌표가 작은 것이 더 가까운 위치
		if ((a.first * a.first + a.second * a.second) == (b.first * b.first + b.second * b.second)) {
			if (a.first == b.first) {
				if (a.second < b.second) {
					return true;
				}
			}
			else if (a.first < b.first) {
				return true;
			}
		}
		else if ((a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second)) {
			return true;
		}
		return false;
	}
};

// max pq

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

		cin >> m >> n >> k;

		// 기존에 존재하는 햄버거 집
		for (int i = 0; i < m + n; i++) {
			int x, y;
			cin >> x >> y;

			// pq의 사이즈가 k보다 작으면 일단 삽입
			if (pq.size() < k) {
				pq.push(make_pair(x, y));
			}
			// pq의 사이즈와 k가 같으면
			else if (pq.size() == k) {
				pair<int, int> top = pq.top();			// top
				pair<int, int> point = make_pair(x, y);	// 넣을 좌표

				// 새로 넣는 좌표와 pq의 top과 비교해서 top보다 작으면 top을 삭제하고 pq에 삽입한다.
				if ((top.first * top.first + top.second * top.second) == (point.first * point.first + point.second * point.second)) {
					if (top.first == point.first) {
						if (top.second > point.second) {
							pq.pop();
							pq.push(point);
						}
					}
					else if (top.first > point.first) {
						pq.pop();
						pq.push(point);
					}
				}
				else if ((top.first * top.first + top.second * top.second) > (point.first * point.first + point.second * point.second)) {
					pq.pop();
					pq.push(point);
				}
			}

			if (i >= m) {
				cout << pq.top().first << ' ' << pq.top().second << '\n';

			}
		}
	}

	return 0;
}