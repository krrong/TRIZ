#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 점수, 거리 저장
int N, A, B;

bool comp(pair<int, int> a, pair<int, int> b) {
	// 거리 오름차순 정렬
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
		int score;			// 현재 최대 평점
		int answer = 1;		// 후보군 개수, 정렬 후 첫번째 원소는 무조건 선택
		vector<pair<int, int>> candidate;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			candidate.push_back(make_pair(A, B));
		}

		// 거리를 기준으로 오름차순 정렬
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