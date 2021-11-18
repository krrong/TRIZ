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

// ��Ʈ��ŷ
void backtrack(int index, int cnt[26], int sum) {
	// M�� ������
	if (index == M) {
		answer = max(sum, answer);
		return;
	}

	backtrack(index + 1, cnt, sum);

	bool ok = true;
	for (int i = 0; i < words[index].size(); i++) {
		// ��� ���ĺ� ���ҽ�Ŵ
		cnt[words[index][i] - 'a']--;
		
		// ������ �Ǹ� �ܾ ���� �� ����
		if (cnt[words[index][i] - 'a'] < 0) {
			ok = false;
		}
	}

	// �ܾ ���� �� �ִ� ���
	if (ok == true) {
		backtrack(index + 1, cnt, sum + score[index]);
	}
	for (int i = 0; i < words[index].size(); i++) {
		// ��� ���ĺ� ����ġ
		cnt[words[index][i] - 'a']++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// �Է�
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