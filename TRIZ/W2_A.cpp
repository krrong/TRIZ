#include <iostream>
#include <vector>
using namespace std;

int n, m, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<string> ans;
		vector<string> words[21];

		// 문장을 구성하는 단어
		for (int i = 0; i < m; i++) {
			string str;
			cin >> str;
			ans.push_back(str);
		}

		// words[i][j]는 i+1번째 학생이 j번쨰로 들은 단어
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			for (int j = 0; j < num; j++) {
				string str;
				cin >> str;
				words[i].push_back(str);
			}
		}

		// 확인
		bool possible = true;
		while (true) {
			string tmp = ans[0];

			// 각 학생의 첫 번째 문자열과 같으면 첫째 문자열 삭제
			for (int i = 0; i < n; i++) {
				if (words[i][0] == tmp) {
					words[i].erase(words[i].begin());
					ans.erase(ans.begin());
					break;
				}
			}


			// 문장을 구성하는 단어를 모두 삭제하면 종료
			if (ans.size() == 0) {
				break;
			}

			// 문장을 구성하는 단어의 첫째 단어를 삭제하지 못해도 종료
			if (tmp == ans[0]) {
				possible = false;
				break;
			}
		}

		cout << possible << '\n';
	}

	return 0;
}