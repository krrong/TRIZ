#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ����, �Ÿ� ����
int N, A, B;

bool comp(pair<int, int> a, pair<int, int> b) {
	// �Ÿ� �������� ����
	if (a.second < b.second) {
		return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int score;			// ���� �ִ� ����
		int answer = 1;		// �ĺ��� ����, ���� �� ù��° ���Ҵ� ������ ����
		vector<pair<int, int>> candidate;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			candidate.push_back(make_pair(A, B));
		}

		// �Ÿ��� �������� �������� ����
		sort(candidate.begin(), candidate.end(), comp);
		score = candidate[0].first;

		for (int i = 0; i < candidate.size(); i++) {
			if (score < candidate[i].first) {
				answer++;
				score = candidate[i].first;
			}
		}
			
		cout << answer << '\n';
	}

	return 0;
}