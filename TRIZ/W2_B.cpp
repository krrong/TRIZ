#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first > b.first) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		int n;

		cin >> n;

		// x,y합 / x, y 저장
		vector<pair<int, pair<int, int>>> v;
		int inha_value = 0;
		int drake_value = 0;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;

			v.push_back(make_pair(x + y, make_pair(x, y)));
		}

		// 합 크기 순으로 정렬
		sort(v.begin(), v.end(), comp);

		// 큰 순서대로 인하 -> 비룡 순으로 나눠가짐
		// i % 2가 0이면 인하
		// i % 2가 1이면 비룡
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				inha_value = inha_value + v[i].second.first;
			}
			else {
				drake_value = drake_value + v[i].second.second;
			}
		}


		cout << inha_value - drake_value << '\n';
	}

	return 0;
 }