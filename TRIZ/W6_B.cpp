//#include <iostream>
//#include <vector>
//#include <queue>
//#define NONE	0	// 이동 가능한 위치
//#define SAFE	1	// 목표 위치
//#define DANGER	2	// 공격범위
//#define WORRIOR 3	// 검사 위치
//#define GUNMAN	4	// 소총수 위치
//#define CUR		5	// 현재 위치
//using namespace std;
//
//int n, m, T;
//int a1, a2, b1, b2, c1, c2, d1, d2;
//int board[1001][1001];		// 보드판
//bool visit[1001][1001];		// 방문체크
//int dist[1001][1001];		// 시작점으로부터 거리 저장
//int d[3] = { -1,0,1 };
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };		// x이동
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };		// y이동
//
//// bfs 수행
//void solve(int x, int y) {
//	queue<pair<int, int>> q;
//	q.push(make_pair(x, y));
//	visit[x][y] = true;
//	dist[x][y] = 0;
//	while (!q.empty()) {
//		pair<int, int> cur = q.front();
//		q.pop();
//		// 만약 현재 위치가 목표 지점이라면 출력 후 종료
//		if (board[cur.first][cur.second] == SAFE) {
//			cout << dist[cur.first][cur.second] << '\n';
//			return;
//		}
//		for (int i = 0; i < 8; i++) {
//			// 이동 가능한 위치일 때(이동 가능한 위치, 목표 위치)
//			if (board[cur.first + dx[i]][cur.second + dy[i]] == 0 || board[cur.first+dx[i]][cur.second+dy[i]] == 1){
//				// 방문하지 않았고 범위 안에 있는 곳
//				if (visit[cur.first + dx[i]][cur.second + dy[i]] == false && cur.first + dx[i] > 0 && cur.first + dx[i] <= n && cur.second + dy[i] > 0 && cur.second + dy[i] <= n) {
//					visit[cur.first + dx[i]][cur.second + dy[i]] = true;
//					q.push(make_pair(cur.first + dx[i], cur.second + dy[i]));
//					dist[cur.first + dx[i]][cur.second + dy[i]] = dist[cur.first][cur.second] + 1;
//				}
//			}
//		}
//	}
//	// 목표지점에 도달하지 못했다면 0출력 후 종료
//	cout << 0 << '\n';
//}
//
//void setting() {
//	board[a1][a2] = CUR;
//	board[b1][b2] = SAFE;
//	board[c1][c2] = WORRIOR;	// 검사
//	board[d1][d2] = GUNMAN;		// 소총수
//
//	// 검사 공격범위 세팅
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (board[c1 + d[i]][c2 + d[j]] == GUNMAN || board[c1 + d[i]][c2 + d[j]] == WORRIOR) {
//				continue;
//			}
//			board[c1 + d[i]][c2 + d[j]] = DANGER;
//		}
//	}
//
//	// 소총수 공격범위 세팅
//	int tmp = d1 - 1;
//	// 상
//	while (tmp > 0) {
//		if (board[tmp][d2] == WORRIOR) {
//			break;
//		}
//		board[tmp][d2] = DANGER;
//		tmp--;
//	}
//	// 하
//	tmp = d1 + 1;
//	while (tmp <= n) {
//		if (board[tmp][d2] == WORRIOR) {
//			break;
//		}
//		board[tmp][d2] = DANGER;
//		tmp++;
//	}
//	// 좌
//	tmp = d2 - 1;
//	while (tmp > 0) {
//		if (board[d1][tmp] == WORRIOR) {
//			break;
//		}
//		board[d1][tmp] = DANGER;
//		tmp--;
//	}
//	// 우
//	tmp = d2 + 1;
//	while (tmp <= n) {
//		if (board[d1][tmp] == WORRIOR) {
//			break;
//		}
//		board[d1][tmp] = DANGER;
//		tmp++;
//	}
//	// 우하
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
//	// 우상
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
//	// 좌하
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
//	// 좌상
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
//// 게임판 리셋
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