#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// minheap을 위한 비교함수
struct comp {
	bool operator()(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
		if (a.second.first > b.second.first) {
			return true;
		}
		// 시간이 같다면
		else if (a.second.first == b.second.first) {
			// 번호가 낮은 곳이 우선순위
			return a.first > b.first;
		}
		else {
			return false;
		}
	}
};

int n, m, T, maxTime;

// minHeap	(number, (time, price))
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;

// Guest (time, price)
queue <pair<int, int>> Guest;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n >> m;
	int* result = new int[n + 1];	// index번 계산대에서 계산한 금액 저장할 배열

	// minheap 생성, n명 만큼 계산대 입장
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;
		pq.push(make_pair(i, make_pair(t, p)));
	}

	// m-n명은 Guest에 차례대로 입장
	for (int i = 0; i < m - n; i++) {
		int t, p;
		cin >> t >> p;
		Guest.push(make_pair(t, p));
	}

	// minheap 중 top을 delete해서 임시 저장할 변수
	while (!Guest.empty()) {
		pair<int, pair<int, int>> tmp = pq.top();
		pq.pop();

		pair<int, int> guest = Guest.front();
		Guest.pop();

		tmp.second.first = tmp.second.first + guest.first;
		tmp.second.second = tmp.second.second + guest.second;

		pq.push(tmp);   
	}


	while (!pq.empty()) {
		result[pq.top().first] = pq.top().second.second;
		
		if (pq.top().second.first > maxTime) {
			maxTime = pq.top().second.first;
		}
		pq.pop();
	}

	cout << maxTime << '\n';
	for (int i = 1; i <= n; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}