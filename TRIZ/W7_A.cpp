//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int t, N, M, A, B;
//vector<int> v[101];
//bool visit[101];
//
//void bfs(int start) {
//	int res = 0;
//	queue<int> q;
//	q.push(start);
//	visit[start] = true;
//	
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//
//		for (int i = 0; i < v[cur].size(); i++) {
//			if (visit[v[cur][i]] == false) {
//				visit[v[cur][i]] = true;
//				q.push(v[cur][i]);
//				res++;
//			}
//		}
//	}
//
//	cout << res << ' ';
//}
//
//void resetVisit() {
//	for (int i = 1; i <= N; i++) {
//		visit[i] = false;
//	}
//}
//
//void reset() {
//	for (int i = 1; i <= N; i++) {
//		visit[i] = false;
//		v[i].clear();
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> t;
//	while (t--) {
//		cin >> N >> M;
//		for (int i = 0; i < M; i++) {
//			cin >> A >> B;
//			v[A].push_back(B);
//		}
//
//		for (int i = 1; i <= N; i++) {
//			bfs(i);
//			resetVisit();
//		}
//		cout << '\n';
//		reset();
//	}
//
//
//
//	return 0;
//}
