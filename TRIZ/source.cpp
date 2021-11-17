//#include <iostream>
//#define WHITE 1
//#define BLACK 2
//using namespace std;
//
//int board[21][21];
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };
//int n, q, r, c, turn;
//
//// 범위안에 들어가는지 판단
//bool valid(int r, int c) {
//	return !(r < 1 || r > n || c < 1 || c > n);
//}
//
//// 돌을 놓을 수 있는지 리턴
//bool isposs(int t, int r, int c, int w, int u) {
//	int nr = r + dx[w];
//	int nc = c + dy[w];
//
//	if (valid(nr, nc) && board[nr][nc] == 3 - t) {
//		while (valid(nr, nc) && board[nr][nc] == 3 - t) {
//			nr = nr + dx[w];
//			nc = nc + dy[w];
//		}
//		if (valid(nr, nc) && board[nr][nc] == u) {
//			return true;
//		}
//	}
//	return false;
//}
//
//// 놓을 수 있는 자리가 있는지 리턴
//bool can(int t) {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (board[i][j] == t) {
//				for (int w = 0; w < 8; w++) {
//					if (isposs(t, i, j, w, 0)) {
//						return false;
//					}
//				}
//			}
//		}
//	}
//	return true;
//}
//
//void reset() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			board[i][j] = 0;
//		}
//	}
//
//	board[n / 2][n / 2] = BLACK;
//	board[n / 2 + 1][n / 2 + 1] = BLACK;
//	board[n / 2 + 1][n / 2] = WHITE;
//	board[n / 2][n / 2 + 1] = WHITE;
//}
//
//void print() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << board[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int t;
//	cin >> t;
//	while (t--) {
//		turn = BLACK;
//		cin >> n >> q;
//		reset();
//		//print();
//		while (q--) {
//			// 놓을 수 있는 자리가 없다면 턴 교체
//			if (can(turn)) turn = 3 - turn;
//
//			// 입력
//			cin >> r >> c;
//
//			// 판을 벗어나거나 이미 돌이 있다면 무시
//			if (!valid(r, c) || board[r][c] != 0) {
//				continue;
//			}
//
//			for (int w = 0; w < 8; w++) {
//				if (isposs(turn, r, c, w, turn)) {
//					board[r][c] = turn;
//					int nr = r + dx[w];
//					int nc = c + dy[w];
//
//					while (valid(nr, nc) && board[nr][nc] == 3 - turn) {
//						board[nr][nc] = turn;
//						nr = nr + dx[w];
//						nc = nc + dy[w];
//					}
//				}
//			}
//
//			// 돌을 놓았으면 턴 교체
//			if (board[r][c] == turn)turn = 3 - turn;
//		}
//
//		int black = 0, white = 0;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (board[i][j] == BLACK) {
//					black++;
//				}
//				else if (board[i][j] == WHITE) {
//					white++;
//				}
//			}
//		}
//
//		if (black > white) {
//			cout << BLACK << '\n';
//		}
//		else if (black < white) {
//			cout << WHITE << '\n';
//		}
//		else {
//			cout << 0 << '\n';
//		}
//	}
//
//
//
//	return 0;
//}