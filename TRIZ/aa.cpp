#include <iostream>
#include <vector>
using namespace std;

string board[3002];
int F[3002];
int n, m;
vector<string> words;
string s;

void getFailure(string p) {
	F[0] = 0;
	int i = 1;
	int j = 0;

	while (i < p.size()) {
		if (p[i] == p[j]) {
			F[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			j = F[j - 1];
		}
		else {
			F[i] = 0;
			i++;

		}
	}
}

bool kmp(string s, string p) {
	int s_size = s.size();
	int p_size = p.size();
	int i = 0;
	int j = 0;

	while (i < s_size) {
		if (s[i] == p[j]) {
			if (j == (p_size - 1)) {
				return true;
			}
			i++;
			j++;
		}
		else if (j > 0) {
			j = F[j - 1];
		}
		else {
			i++;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		words.push_back(s);
	}

	for (int t = 0; t < m; t++) {
		bool ok = false;
		getFailure(words[t]);
		
		// ���� Ȯ��
		for (int i = 0; i < n; i++) {
			string s = board[i];

			if (kmp(s, words[t]) == true) {
				cout << 1 << '\n';
				ok = true;
				break;
			}
		}

		// ���� �� ������ ���� �ܾ� Ȯ��
		if (ok == true) {
			continue;
		}

		// ���� Ȯ��
		for (int i = 0; i < n; i++) {
			string s = "";

			for (int j = 0; j < n; j++) {
				s = s + board[j][i];
			}

			if (kmp(s, words[t]) == true) {
				cout << 1 << '\n';
				ok = true;
				break;
			}
		}

		// ���� �� ������ ���� �ܾ� Ȯ��
		if (ok == true) {
			continue;
		}

		// A -> B -> M -> R ... -> C �밢�� Ȯ��
		for (int i = 0; i < n; i++) {
			string s = "";
			for (int j = 0; i + j < n; j++) {
				s = s + board[j][i + j];
			}

			// �ؽ�Ʈ�� ���Ϻ��� �� ���� kmp����
			if (s.size() >= words[t].size()) {
				if (kmp(s, words[t]) == true) {
					cout << 1 << '\n';
					ok = true;
					break;
				}
			}
		}

		// ���� �� ������ ���� �ܾ� Ȯ��
		if (ok == true) {
			continue;
		}

		// A -> P -> P -> L ... -> F �밢�� Ȯ��
		for (int i = 0; i < n; i++) {
			string s = "";
			for (int j = 0; i + j < n; j++) {
				s = s + board[i + j][j];
			}

			// �ؽ�Ʈ�� ���Ϻ��� �� ���� kmp����
			if (s.size() >= words[t].size()) {
				if (kmp(s, words[t]) == true) {
					cout << 1 << '\n';
					ok = true;
					break;
				}
			}
		}

		if (ok == false) {
			cout << 0 << '\n';
		}
	}

	return 0;
}
