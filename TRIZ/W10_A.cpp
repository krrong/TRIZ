#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int number;
bool visit[10000];
int dist[10000];

// 뒤집어 주는 함수
int reverse(int n) {
	int a = 0;
	if (n / 10 == 0) {
		a = n * 1000;
	}
	else if (n / 10 == 1) {
		a = a + (n % 10) * 1000;
		a = a + (n / 10) * 100;
	}
	else if (n / 100 == 1) {
		a = a + (n % 10) * 1000;
		a = a + (n / 10 - 10) * 100;
		a = a + (n / 100) * 10;
	}
	else {
		a = a + (n % 10) * 1000;
		a = a + (n / 10 - (n / 100) * 10) * 100;
		a = a + (n / 100 - (n / 1000) * 10) * 10;
		a = a + (n / 1000);
	}
	return a;
}

// +1, -1, 뒤집은 수 리턴
vector<int> check(int n) {
	vector<int> ret;
	
	if (n == 9999) {
		ret.push_back(9998);
	}
	else if (n == 0) {
		ret.push_back(1);
	}
	else {
		ret.push_back(n + 1);
		ret.push_back(n - 1);
		ret.push_back(reverse(n));
	}

	return ret;
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visit[s] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == number) {
			cout << dist[cur] << '\n';
		}

		vector<int> v = check(cur);
		int size = v.size();

		for (int i = 0; i < size; i++) {
			if (visit[v[i]] == false) {
				visit[v[i]] = true;
				q.push(v[i]);
				dist[v[i]] = dist[cur] + 1;
				}
			}
		}
	}


void reset() {
	for (int i = 0; i < 10000; i++) {
		visit[i] = false;
		dist[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int start;
		cin >> start;
		cin >> number;
		bfs(start);

		reset();
	}

	return 0;
}