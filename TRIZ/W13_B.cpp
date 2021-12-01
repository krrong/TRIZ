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
		
		// 0번 index 채우기 위함
		message.push_back(0);
		answer.push_back(0);

		// 메시지 입력
		for (int i = 0; i < m; i++) {
			cin >> a;
			message.push_back(a);
			answer.push_back(0);
		}

		// 거꾸로 돌면서
		for (int i = m; i >= 0; i--) {
			// 자신 추가 -> 만약 자신이 이미 들어가있다면 set이라 들어가지 않음
			read_people.insert(message[i]);
			answer[i] = read_people.size();
		}

		// 전체 사람 수에서 현재 읽은 사람의 수를 빼고 출력
		for (int i = 1; i <= m; i++) {
			cout << n - answer[i] << '\n';
		}
	}

	return 0;
}