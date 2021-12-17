#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
bool lights[101];			// ������ ���� ����
vector<int> switchs[10];	// ����ġ�� ����� ���� ����
bool answer;				// answer flag

// ��� ������ �������� Ȯ��
bool check() {
	for (int i = 1; i <= m; i++) {
		if (lights[i] == true) {
			return false;
		}
	}
	return true;
}

// ��Ʈ��ŷ
void back(int index) {
	// ����ġ ������ ������ return
	if (index == n) {
		return;
	}

	back(index + 1);

	int size = switchs[index].size();

	// ����ġ�� ����� ������ on, off change
	for (int i = 0; i < size; i++) {
		if (lights[switchs[index][i]] == true) {
			lights[switchs[index][i]] = false;
		}
		else {
			lights[switchs[index][i]] = true;
		}
	}

	// ����ġ ���� �� ��� ���������� return
	if (check() == true) {
		answer = true;
		return;
	}

	// ���� ����ġ ���� �� ���� ����ġ Ȯ��
	back(index + 1);

	// ����ġ�� ����� ������ on, off change(�տ��� �״��� ���� �ڵ�)
	for (int i = 0; i < size; i++) {
		if (lights[switchs[index][i]] == true) {
			lights[switchs[index][i]] = false;
		}
		else {
			lights[switchs[index][i]] = true;
		}
	}
}

// �ʱ�ȭ
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