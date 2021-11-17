#include <iostream>
#include <vector>
using namespace std;

vector<int> home;

// m명이 dis거리만큼 떨어져 살 수 있는지 체크
bool check(int dis, int m) {
	int size = home.size();

	int cur = home[0];	// 처음 선택하는 집
	m--;

	for (int i = 0; i < size; i++) {
		// 집에서 떨어진 거리보다 집이 멀리 있으면 살 수 있다.
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

	int left = home[0];					// 거리가 가장 짧을 경우
	int right = home[n - 1] - home[0];	// 거리가 가장 길 경우

	// 이분 탐색
	while (left <= right) {
		int mid = (left + right) / 2;		// 떨어뜨려 놓을 거리

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

// 반례
// 7 3
// 1 2 3 4 9 10 16
// output : 3
// answer : 7