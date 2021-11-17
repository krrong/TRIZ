//#include <iostream>
//#include <vector>
//#include <queue>
//#define NONE	0	// �̵� ������ ��ġ
//#define SAFE	1	// ��ǥ ��ġ
//#define DANGER	2	// ���ݹ���
//#define WORRIOR 3	// �˻� ��ġ
//#define GUNMAN	4	// ���Ѽ� ��ġ
//#define CUR		5	// ���� ��ġ
//using namespace std;
//
//int n, m, T;
//int a1, a2, b1, b2, c1, c2, d1, d2;
//int board[1001][1001];		// ������
//bool visit[1001][1001];		// �湮üũ
//int dist[1001][1001];		// ���������κ��� �Ÿ� ����
//int d[3] = { -1,0,1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };		// x�̵�
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };		// y�̵�
//
//// bfs ����
//void solve(int x, int y) {
//	queue<pair<int, int>> q;
//	q.push(make_pair(x, y));
//	visit[x][y] = true;
//	dist[x][y] = 0;
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//		// ���� ���� ��ġ�� ��ǥ �����̶�� ��� �� ����
//		if (board[cur.first][cur.second] == SAFE) {
//			cout << dist[cur.first][cur.second] << '\n';
//			return;
//		}
//		for (int i = 0; i < 8; i++) {
//			// �̵� ������ ��ġ�� ��(�̵� ������ ��ġ, ��ǥ ��ġ)
//			if (board[cur.first + dx[i]][cur.second + dy[i]] == 0 || board[cur.first+dx[i]][cur.second+dy[i]] == 1){
//				// �湮���� �ʾҰ� ���� �ȿ� �ִ� ��
//				if (visit[cur.first + dx[i]][cur.second + dy[i]] == false && cur.first + dx[i] > 0 && cur.first + dx[i] <= n && cur.second + dy[i] > 0 && cur.second + dy[i] <= n) {
//					visit[cur.first + dx[i]][cur.second + dy[i]] = true;
//					q.push(make_pair(cur.first + dx[i], cur.second + dy[i]));
//					dist[cur.first + dx[i]][cur.second + dy[i]] = dist[cur.first][cur.second] + 1;
//				}
//			}
//		}
//	}
//	// ��ǥ������ �������� ���ߴٸ� 0��� �� ����
//	cout << 0 << '\n';
//}
//
//void setting() {
//	board[a1][a2] = CUR;
//	board[b1][b2] = SAFE;
//	board[c1][c2] = WORRIOR;	// �˻�
//	board[d1][d2] = GUNMAN;		// ���Ѽ�
//
//	// �˻� ���ݹ��� ����
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (board[c1 + d[i]][c2 + d[j]] == GUNMAN || board[c1 + d[i]][c2 + d[j]] == WORRIOR) {
//				continue;
//			}
//			board[c1 + d[i]][c2 + d[j]] = DANGER;
//		}
//	}
//
//	// ���Ѽ� ���ݹ��� ����
//	int tmp = d1 - 1;
//	// ��
//	while (tmp > 0) {
//		if (board[tmp][d2] == WORRIOR) {
//			break;
//		}
//		board[tmp][d2] = DANGER;
//		tmp--;
//	}
//	// ��
//	tmp = d1 + 1;
//	while (tmp <= n) {
//		if (board[tmp][d2] == WORRIOR) {
//			break;
//		}
//		board[tmp][d2] = DANGER;
//		tmp++;
//	}
//	// ��
//	tmp = d2 - 1;
//	while (tmp > 0) {
//		if (board[d1][tmp] == WORRIOR) {
//			break;
//		}
//		board[d1][tmp] = DANGER;
//		tmp--;
//	}
//	// ��
//	tmp = d2 + 1;
//	while (tmp <= n) {
//		if (board[d1][tmp] == WORRIOR) {
//			break;
//		}
//		board[d1][tmp] = DANGER;
//		tmp++;
//	}
//	// ����
//	int x = d1 + 1;
//	int y = d2 + 1;
//	while (x <= n && y <= n) {
//		if (board[x][y] == WORRIOR) {
//			break;
//		}
//		board[x][y] = DANGER;
//		x++;
//		y++;
//	}
//	// ���
//	x = d1 - 1;
//	y = d2 + 1;
//	while (x > 0 && y <= n) {
//		if (board[x][y] == WORRIOR) {
//			break;
//		}
//		board[x][y] = DANGER;
//		x--;
//		y++;
//	}
//	// ����
//	x = d1 + 1;
//	y = d2 - 1;
//	while (x <= n && y > 0) {
//		if (board[x][y] == WORRIOR) {
//			break;
//		}
//		board[x][y] = DANGER;
//		x++;
//		y--;
//	}
//	// �»�
//	x = d1 - 1;
//	y = d2 - 1;
//	while (x > 0 && y > 0) {
//		if (board[x][y] == WORRIOR) {
//			break;
//		}
//		board[x][y] = DANGER;
//		x--;
//		y--;
//	}
//}
//
//// ������ ����
//void reset() {
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= n; j++) {
//			board[i][j] = NONE;
//			visit[i][j] = NONE;
//			dist[i][j] = NONE;
//		}
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> T;
//	while (T--) {
//		cin >> n;
//		cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
//		setting();
//		solve(a1, a2);
//		reset();
//	}
//}