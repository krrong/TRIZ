#include <iostream>
#include <queue>
using namespace std;

int t, m, n, k;

// max pq���� comp����ü
struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		// �Ÿ��� ������ x��ǥ�� ���� ���� �� ����� ��ġ
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

		// ������ �����ϴ� �ܹ��� ��
		for (int i = 0; i < m + n; i++) {
			int x, y;
			cin >> x >> y;

			// pq�� ����� k���� ������ �ϴ� ����
			if (pq.size() < k) {
				pq.push(make_pair(x, y));
			}
			// pq�� ������� k�� ������
			else if (pq.size() == k) {
				pair<int, int> top = pq.top();			// top
				pair<int, int> point = make_pair(x, y);	// ���� ��ǥ

				// ���� �ִ� ��ǥ�� pq�� top�� ���ؼ� top���� ������ top�� �����ϰ� pq�� �����Ѵ�.
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