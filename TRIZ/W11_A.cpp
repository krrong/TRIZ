#include <iostream>
#include <vector>
using namespace std;

int m;
int dp[23];
vector<vector<int>> v;
vector<pair<string, int>> words;

bool check(string str, vector<int> v) {
	int size = str.size();
	vector<int> tmp = v;
	for (int i = 0; i < size; i++) {
		// 알파벳을 만들 수 없으면 flag교체
		if (tmp[str[i] - 'a'] != 0) {
			tmp[str[i] - 'a']--;
		}
		else if (tmp[str[i] - 'a'] == 0) {
			return false;
		}
	}
	return true;
}

void renew(string str, vector<int> &v) {
	int size = str.size();
	for (int i = 0; i < size; i++) {
		// 단어를 만들 수 있으면 알파벳 감소
		if (v[str[i] - 'a'] != 0) {
			v[str[i] - 'a']--;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> alpa;
	for (int i = 0; i < 26; i++) {
		int a;
		cin >> a;
		alpa.push_back(a);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		v.push_back(alpa);
		string s;
		int a;
		cin >> s >> a;
		words.push_back(make_pair(s, a));
	}

	// 첫 항
	if (check(words[0].first, v[0]) == true) {
		renew(words[0].first, v[0]);
		dp[0] = words[0].second;
	}

	// 나머지
	for (int i = 1; i < m; i++) {
		if (check(words[i].first, v[i]) == true) {
			dp[i] = words[i].second;
			renew(words[i].first, v[i]);
		}
		vector<int> tmp;
		for (int j = 0; j < i; j++) {
			tmp.push_back(0);
			if (check(words[i].first, v[j]) == true) {
				if (dp[i] < dp[j] + dp[i]) {
					v[i] = v[j];
					renew(words[i].first, v[i]);
					tmp[j] = dp[j] + dp[i];
				}
			}
		}
		for (int j = 0; j < i; j++) {
			if (tmp[j] > dp[i]) {
				dp[i] = tmp[j];
			}
		}
	}

	int max = 0;
	for (int i = 0; i < m; i++) {
		if (dp[i] > max) {
			max = dp[i];
		}
	}
	cout << max;

	return 0;
}