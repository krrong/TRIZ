#include <iostream>
#include <vector>
using namespace std;

vector<int> home;

// m���� dis�Ÿ���ŭ ������ �� �� �ִ��� üũ
bool check(int dis, int m) {
	int size = home.size();

	int cur = home[0];	// ó�� �����ϴ� ��
	m--;

	for (int i = 0; i < size; i++) {
		// ������ ������ �Ÿ����� ���� �ָ� ������ �� �� �ִ�.
		if (cur + dis < home[i]) {
			cur = home[i];
			m--;
		}
		if (m == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		home.push_back(x);
	}

	int left = home[0];					// �Ÿ��� ���� ª�� ���
	int right = home[n - 1] - home[0];	// �Ÿ��� ���� �� ���

	// �̺� Ž��
	while (left <= right) {
		int mid = (left + right) / 2;		// ����߷� ���� �Ÿ�

		if (check(mid, m) == true) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left;

	return 0;
}

// test case

// 5 4
// 1 2 4 8 9
// 1

// �ݷ�
// 7 3
// 1 2 3 4 9 10 16
// output : 3
// answer : 7