#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// minheap�� ���� ���Լ�
struct comp {
	bool operator()(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
		if (a.second.first > b.second.first) {
			return true;
		}
		// �ð��� ���ٸ�
		else if (a.second.first == b.second.first) {
			// ��ȣ�� ���� ���� �켱����
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
	int* result = new int[n + 1];	// index�� ���뿡�� ����� �ݾ� ������ �迭

	// minheap ����, n�� ��ŭ ���� ����
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;
		pq.push(make_pair(i, make_pair(t, p)));
	}

	// m-n���� Guest�� ���ʴ�� ����
	for (int i = 0; i < m - n; i++) {
		int t, p;
		cin >> t >> p;
		Guest.push(make_pair(t, p));
	}

	// minheap �� top�� delete�ؼ� �ӽ� ������ ����
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