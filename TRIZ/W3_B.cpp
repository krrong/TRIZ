//#include <iostream>
//#include <vector>
//using namespace std;
//
// // dfs를 두번 사용하여 문제를 풀이할 수 있다.
//int v, u, d, t;
//int node, answer;
//vector<vector<pair<int, int>>> tree;	// 그래프 (집의번호, (집의 번호, 거리)) 저장
//vector<bool> visited;					// 방문여부 저장
//
//// 재귀적 dfs, answer과 node를 호출마다 갱신
//void dfs(int s, int dist) {
//	// 거리를 비교해서 갱신
//	if (dist > answer) {
//		answer = dist;
//		node = s;
//	}
//
//	for (int i = 0; i < tree[s].size(); i++) {
//		pair<int, int> cur = tree[s][i];
//		if (visited[cur.first] == true)continue;
//		visited[cur.first] = true;
//		dfs(cur.first, dist + cur.second);
//	}
//}
//
//// 트리, 방문 그래프 초기화
//void reset() {
//	answer = 0;
//	node = 0;
//
//	int size = tree.size();
//	for (int i = 0; i < size; i++) {
//		tree.erase(tree.begin());
//	}
//
//	size = visited.size();
//	for (int i = 0; i < size; i++) {
//		visited.erase(visited.begin());
//	}
//
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//
//		for (int i = 0; i <= n; i++) {
//			vector<pair<int, int>> node;
//			tree.push_back(node);
//			visited.push_back(false);
//		}
//
//		// input을 그래프로 변환
//		for (int i = 1; i < n; i++) {
//			cin >> u >> v >> d;
//			tree[u].push_back(make_pair(v, d));
//			tree[v].push_back(make_pair(u, d));
//		}
//
//		// 임의의 노드에서 시작해서 가장 먼 노드 탐색
//		visited[1] = true;
//		dfs(1, 0);
//
//		// 방문 여부 초기화
//		for (int i = 1; i <= n; i++) {
//			visited[i] = false;
//		}
//
//		// 찾은 노드에서 가장 먼 노드 탐색
//		visited[node] = true;
//		dfs(node, 0);
//		cout << answer << '\n';
//
//		reset();
//	}
//	return 0;
//}