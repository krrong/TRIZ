#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
bool lights[101];			// 전구의 상태 저장
vector<int> switchs[10];	// 스위치와 연결된 전구 저장
bool answer;				// answer flag

// 모든 전구가 꺼졌는지 확인
bool check() {
	for (int i = 1; i <= m; i++) {
		if (lights[i] == true) {
			return false;
		}
	}
	return true;
}

// 백트래킹
void back(int index) {
	// 스위치 개수와 같으면 return
	if (index == n) {
		return;
	}

	back(index + 1);

	int size = switchs[index].size();

	// 스위치와 연결된 전구의 on, off change
	for (int i = 0; i < size; i++) {
		if (lights[switchs[index][i]] == true) {
			lights[switchs[index][i]] = false;
		}
		else {
			lights[switchs[index][i]] = true;
		}
	}

	// 스위치 조작 후 모두 꺼져있으면 return
	if (check() == true) {
		answer = true;
		return;
	}

	// 현재 스위치 조작 후 다음 스위치 확인
	back(index + 1);

	// 스위치와 연결된 전구의 on, off change(앞에서 켰던거 끄는 코드)
	for (int i = 0; i < size; i++) {
		if (lights[switchs[index][i]] == true) {
			lights[switchs[index][i]] = false;
		}
		else {
			lights[switchs[index][i]] = true;
		}
	}
}

// 초기화
void reset() {
	for (int i = 0; i < 10; i++) {
		switchs[i].clear();
	}

	for (int i = 0; i < 101; i++) {
		lights[i] = false;
	}

	answer = 0;
}

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < switchs[i].size(); j++) {
			cout << switchs[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		// input
		for (int i = 1; i <= m; i++) {
			cin >> lights[i];
		}

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			for (int j = 0; j < a; j++) {
				int b;
				cin >> b;
				switchs[i].push_back(b);
			}
		}

		back(0);
		cout << answer << '\n';
		reset();
	}

	return 0;
}