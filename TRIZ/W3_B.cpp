//#include <iostream>
//#include <vector>
//using namespace std;
//
// // dfs�� �ι� ����Ͽ� ������ Ǯ���� �� �ִ�.
//int v, u, d, t;
//int node, answer;
//vector<vector<pair<int, int>>> tree;	// �׷��� (���ǹ�ȣ, (���� ��ȣ, �Ÿ�)) ����
//vector<bool> visited;					// �湮���� ����
//
//// ����� dfs, answer�� node�� ȣ�⸶�� ����
//void dfs(int s, int dist) {
//	// �Ÿ��� ���ؼ� ����
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
//// Ʈ��, �湮 �׷��� �ʱ�ȭ
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
//		// input�� �׷����� ��ȯ
//		for (int i = 1; i < n; i++) {
//			cin >> u >> v >> d;
//			tree[u].push_back(make_pair(v, d));
//			tree[v].push_back(make_pair(u, d));
//		}
//
//		// ������ ��忡�� �����ؼ� ���� �� ��� Ž��
//		visited[1] = true;
//		dfs(1, 0);
//
//		// �湮 ���� �ʱ�ȭ
//		for (int i = 1; i <= n; i++) {
//			visited[i] = false;
//		}
//
//		// ã�� ��忡�� ���� �� ��� Ž��
//		visited[node] = true;
//		dfs(node, 0);
//		cout << answer << '\n';
//
//		reset();
//	}
//	return 0;
//}