#include <iostream>
#include <vector>
using namespace std;

string board[3002];		// 격자판
int F[3002];			// 실패함수
int n, m;
vector<string> words;	// 찾을 단어 저장
vector<string> text;	// 만들 수 있는 단어 저장
string s;

// 실패함수
void getFailure(string p) {
	F[0] = 0;
	int i = 1;
	int j = 0;

	while (i < p.size()) {		// 문자열의 길이만큼
		if (p[i] == p[j]) {		// 두 문자가 같다면
			F[i] = j + 1;		// 접두사와 접미사의 최대 길이 저장
			i++;				// 다음 문자 확인을 위한 i++
			j++;				// 다음 문자 확인을 위한 j++
		}
		else if (j > 0) {		// 앞부분이 일치하다 중간에 불일치 하는 경우
			j = F[j - 1];		// 실패함수에 저장된 값 이용
		}
		else {					// 처음부터 실패한 경우
			F[i] = 0;			// 공통부분의 최대 길이는 0
			i++;				// 오른쪽으로 한칸 옮김

		}
	}
}

// kmp
bool kmp(string s, string p) {
	int s_size = s.size();
	int p_size = p.size();
	int i = 0;
	int j = 0;

	while (i < s_size) {				// 텍스트 전체 길이에 대해
		if (s[i] == p[j]) {				// 문자가 같다면
			if (j == (p_size - 1)) {	// 끝까지 확인했는지 판단 -> 탐색 성공
				return true;
			}
			i++;						// 다음 문자 확인을 위한 i++
			j++;						// 다음 문자 확인을 위한 j++
		}
		else if (j > 0) {				// 앞부분이 일치하다 중간에 불일치 하는 경우
			j = F[j - 1];				// 실패함수에 저장된 값 이용
		}
		else {							// 처음부터 실패한 경우
			i++;						// 오른쪽으로 한칸 옮김
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

	// 가로 문자 추가
	for (int i = 0; i < n; i++) {
		string s = board[i];
		text.push_back(s);
	}

	// 세로 문자 추가
	for (int i = 0; i < n; i++) {
		string s = "";

		for (int j = 0; j < n; j++) {
			s = s + board[j][i];
		}
		text.push_back(s);
	}

	// A -> B -> M -> R ... -> C 대각선 추가(열방향)
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; i + j < n; j++) {
			s = s + board[j][i + j];
		}
		text.push_back(s);
	}

	// A -> P -> P -> L ... -> F 대각선 추가(행방향)
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; i + j < n; j++) {
			s = s + board[i + j][j];
		}
		text.push_back(s);
	}

	int size = text.size();			// 확인할 수 있는 텍스트의 개수

													// 확인할 패턴에 대해
	for (int i = 0; i < m; i++) {		
		getFailure(words[i]);						// 실패함수 구하고
		bool ok = false;							// 성공을 저장할 flag
		for (int j = 0; j < size; j++) {			// 확인가능한 텍스트에 대해
			if (kmp(text[j], words[i]) == true) {	// 패턴이 있다면
				cout << 1 << '\n';					// 1출력
				ok = true;							// flag에 저장
				break;
			}
		}
		if (ok == false) {							// 찾지 못했다면 0출력
			cout << 0 << '\n';
		}
	}

	return 0;
}
