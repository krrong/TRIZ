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

		// x,y�� / x, y ����
		vector<pair<int, pair<int, int>>> v;
		int inha_value = 0;
		int drake_value = 0;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;

			v.push_back(make_pair(x + y, make_pair(x, y)));
		}

		// �� ũ�� ������ ����
		sort(v.begin(), v.end(), comp);

		// ū ������� ���� -> ��� ������ ��������
		// i % 2�� 0�̸� ����
		// i % 2�� 1�̸� ���
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