#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> words;
int score[23];
int alpa[26];
int answer;
int M;
int sum;

// 백트래킹
void backtrack(int index, int cnt[26], int sum) {
	// M개 뽑으면
	if (index == M) {
		answer = max(sum, answer);
		return;
	}

	backtrack(index + 1, cnt, sum);

	bool ok = true;
	for (int i = 0; i < words[index].size(); i++) {
		// 사용 알파벳 감소시킴
		cnt[words[index][i] - 'a']--;
		
		// 음수가 되면 단어를 만들 수 없음
		if (cnt[words[index][i] - 'a'] < 0) {
			ok = false;
		}
	}

	// 단어를 만들 수 있는 경우
	if (ok == true) {
		backtrack(index + 1, cnt, sum + score[index]);
	}
	for (int i = 0; i < words[index].size(); i++) {
		// 사용 알파벳 원위치
		cnt[words[index][i] - 'a']++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	for (int i = 0; i < 26; i++) {
		cin >> alpa[i];
	}
	cin >> M;

	for (int i = 0; i < M; i++) {
		string str;
		int s;
		cin >> str >> s;
		words.push_back(str);
		score[i] = s;
	}

	backtrack(0, alpa, sum);
	cout << answer;

	return 0;
}