//#include <iostream>
//#define WHITE 1
//#define BLACK 2
//using namespace std;
//
//int T, n, q, r, c, turn;
//int board[21][21];
//int dx[8] = { -1,-1,-1,0,0,1,1,1 };
//int dy[8] = { -1,0,1,-1,1,-1,0,1 };
//
//void turnChange() {
//	if (turn == BLACK) {
//		turn = WHITE;
//	}
//	else {
//		turn = BLACK;
//	}
//}
//
//void sol(int r, int c) {
//	// 해당 자리에 돌이 이미 있을 때
//	if (board[r][c] != 0)
//		return;
//
//	bool check1 = false;	// 놓을 수 없는 위치일 경우를 무시하기 위한 flag
//
//	// 흑돌 차례
//	if (turn == BLACK) {
//		board[r][c] = BLACK;
//
//		for (int i = 0; i < 8; i++) {
//			int change = 0;		// 바꾸는 돌의 수
//			for (int j = 1; j <= n; j++) {
//				if (r + dx[i] * j > 0 && r + dx[i] * j <= n && c + dy[i] * j > 0 && c + dy[i] * j <= n) {
//					// 흑돌 중간에 아무것도 안놓여 있다면 stop
//					if (board[r + dx[i] * j][c + dy[i] * j] == 0) {
//						break;
//					}
//					// 백돌이라면 지나침
//					else if (board[r + dx[i] * j][c + dy[i] * j] == WHITE) {
//						change++;
//						continue;
//					}
//					// 흑돌이라면 지나친 백돌을 모두 뒤집음
//					else if (board[r + dx[i] * j][c + dy[i] * j] == BLACK) {
//						// 지나친 백돌이 하나라도 있다면 flag를 true로
//						if (change > 0) {
//							check1 = true;
//						}
//						for (int a = 1; a <= j; a++) {
//							board[r + dx[i] * a][c + dy[i] * a] = BLACK;
//						}
//					}
//				}
//			}
//		}
//	}
//	// 백돌 차례
//	else {
//		board[r][c] = WHITE;
//
//		for (int i = 0; i < 8; i++) {
//			int change = 0;
//			for (int j = 1; j <= n; j++) {
//				if (r + dx[i] * j > 0 && r + dx[i] * j <= n && c + dy[i] * j > 0 && c + dy[i] * j <= n) {
//					// 백돌 중간에 아무것도 안놓여 있다면 stop
//					if (board[r + dx[i] * j][c + dy[i] * j] == 0) {
//						break;
//					}
//					// 흑돌이라면 지나침
//					else if (board[r + dx[i] * j][c + dy[i] * j] == BLACK) {
//						change++;
//						continue;
//					}
//					// 백돌이라면 지나친 흑돌을 모두 뒤집음
//					else if (board[r + dx[i] * j][c + dy[i] * j] == WHITE) {
//						// 지나친 흑돌이 하나라도 있다면 flag를 true로
//						if (change > 0) {
//							check1 = true;
//						}
//						for (int a = 1; a <= j; a++) {
//							board[r + dx[i] * a][c + dy[i] * a] = WHITE;
//						}
//					}
//				}
//			}
//		}
//	}
//
//	// 놓을 수 없는 위치였다면 다시 차례를 바꿔줌
//	if (check1 == false) {
//		board[r][c] = 0;
//		turnChange();
//	}
//}
//
//void check() {
//	int black_sum = 0;
//	int white_sum = 0;
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (board[i][j] == BLACK) {
//				black_sum++;
//			}
//			else if (board[i][j] == WHITE) {
//				white_sum++;
//			}
//		}
//	}
//
//	if (black_sum > white_sum) {
//		cout << 2 << '\n';
//	}
//	else if (white_sum > black_sum) {
//		cout << 1 << '\n';
//	}
//	else {
//		cout << 0 << '\n';
//	}
//}
//
//void setting() {
//	for (int i = 1; i <= 20; i++) {
//		for (int j = 1; j <= 20; j++) {
//			board[i][j] = 0;
//		}
//	}
//
//	int s = n / 2;
//	board[s][s] = BLACK;
//	board[s + 1][s + 1] = BLACK;
//	board[s + 1][s] = WHITE;
//	board[s][s + 1] = WHITE;
//}
//
//void print() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << board[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> T;
//	while (T--) {
//		turn = WHITE;
//		cin >> n >> q;
//		setting();
//		//print();
//		for (int i = 0; i < q; i++) {
//			cin >> r >> c;
//
//			// 순서 바꾸기
//			turnChange();
//
//			sol(r, c);
//			//print();
//		}
//		check();
//		setting();
//	}
//
//	return 0;
//}