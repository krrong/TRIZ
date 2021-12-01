#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		vector<int> message;
		vector<int> answer;
		set<int> read_people;

		cin >> n >> m;
		
		// 0�� index ä��� ����
		message.push_back(0);
		answer.push_back(0);

		// �޽��� �Է�
		for (int i = 0; i < m; i++) {
			cin >> a;
			message.push_back(a);
			answer.push_back(0);
		}

		// �Ųٷ� ���鼭
		for (int i = m; i >= 0; i--) {
			// �ڽ� �߰� -> ���� �ڽ��� �̹� ���ִٸ� set�̶� ���� ����
			read_people.insert(message[i]);
			answer[i] = read_people.size();
		}

		// ��ü ��� ������ ���� ���� ����� ���� ���� ���
		for (int i = 1; i <= m; i++) {
			cout << n - answer[i] << '\n';
		}
	}

	return 0;
}