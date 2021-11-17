#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> directory;
vector<int> word;
vector<bool> visit;
vector<int> dis;
int t, a, b;
string str;

void bfs(int start, int size) {
	queue<int> q;
	q.push(start);
	int len = size;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		int s = directory[tmp].size();
		for (int i = 0; i < s; i++) {
			int cur = directory[tmp][i];
			if (visit[cur] == false) {
				visit[cur] = true;
				q.push(cur);
				dis[cur] = dis[tmp] + 1 + word[cur];
			}
		}
	}
	return;
}

// �湮����, ���丮, �ܾ�, ���� �ʱ�ȭ
void resetAll() {
	visit.clear();
	directory.clear();
	word.clear();
	//dis.clear(); -> ��� ���� �ȴ�.
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i <= n; i++) {
			vector<int> tmp;
			directory.push_back(tmp);

			visit.push_back(false);
			dis.push_back(0);
		}

		for (int i = 1; i < n; i++) {
			cin >> a >> b;

			// ���� ����
			directory[a].push_back(b);
			//directory[b].push_back(a);
		}

		word.push_back(0);
		// �ܾ� �Է� -> ���̷� �ٲ㼭 ����
		for (int i = 1; i <= n; i++) {
			cin >> str;
			word.push_back(str.size());
		}

		dis[1] = 4;	// 1->1 ������ �Ÿ��� 4�� ���� (�׻� root �̱� ������)
		bfs(1, 4);
		for (int i = 1; i <= n; i++) {
			cout << dis[i] << '\n';
		}

		resetAll();
	}

	return 0;
}