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

		// ������ �����ϴ� �ܾ�
		for (int i = 0; i < m; i++) {
			string str;
			cin >> str;
			ans.push_back(str);
		}

		// words[i][j]�� i+1��° �л��� j������ ���� �ܾ�
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			for (int j = 0; j < num; j++) {
				string str;
				cin >> str;
				words[i].push_back(str);
			}
		}

		// Ȯ��
		bool possible = true;
		while (true) {
			string tmp = ans[0];

			// �� �л��� ù ��° ���ڿ��� ������ ù° ���ڿ� ����
			for (int i = 0; i < n; i++) {
				if (words[i][0] == tmp) {
					words[i].erase(words[i].begin());
					ans.erase(ans.begin());
					break;
				}
			}


			// ������ �����ϴ� �ܾ ��� �����ϸ� ����
			if (ans.size() == 0) {
				break;
			}

			// ������ �����ϴ� �ܾ��� ù° �ܾ �������� ���ص� ����
			if (tmp == ans[0]) {
				possible = false;
				break;
			}
		}

		cout << possible << '\n';
	}

	return 0;
}