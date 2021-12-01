#include <iostream>
#include <vector>
using namespace std;

string board[3005];
int failure[3005];
int n, m;

void getFailure(string p) {
	failure[0] = 0;
	int i = 1;
	int j = 0;
	int p_size = p.size();

	while (i < p_size) {
		if (p[i] == p[j]) {
			failure[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0) {
			j = failure[j - 1];
		}
		else {
			failure[i] = 0;
			i++;
		}
	}
}

bool kmp(string s, string p) {
	int i = 0;
	int j = 0;
	int s_size = s.size();
	int p_size = p.size();

	while (i < s_size) {
		if (s[i] == p[j]) {
			if (j == (p_size - 1)) {
				return true;
			}
			
			i++;
			j++;
		}
		else if (j > 0) {
			j = failure[j - 1];
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

	string str;	// 문자열
	string word;

	for (int i = 0; i < n; i++) {
		str = str + board[i];					// 가로 문자열
		str = str + "$";						// 구분자
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			str = str + board[j][i];			// 세로 문자열
		}
		str = str + "$";						// 구분자
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; i + j < n; j++) {
			str = str + board[j][i + j];		// 행방향 대각선 문자열
		}
		str = str + "$";						// 구분자
	}


	for (int i = 1; i < n; i++) {
		for (int j = 0; i + j < n; j++) {
			str = str + board[i + j][j];		// 열방향 대각선 문자열
		}
		str = str + "$";						// 구분자
	}

	while (m--) {
		cin >> word;
		getFailure(word);
		if (kmp(str, word) == true) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}
