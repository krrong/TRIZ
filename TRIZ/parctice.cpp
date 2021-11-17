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
//	// �ش� �ڸ��� ���� �̹� ���� ��
//	if (board[r][c] != 0)
//		return;
//
//	bool check1 = false;	// ���� �� ���� ��ġ�� ��츦 �����ϱ� ���� flag
//
//	// �浹 ����
//	if (turn == BLACK) {
//		board[r][c] = BLACK;
//
//		for (int i = 0; i < 8; i++) {
//			int change = 0;		// �ٲٴ� ���� ��
//			for (int j = 1; j <= n; j++) {
//				if (r + dx[i] * j > 0 && r + dx[i] * j <= n && c + dy[i] * j > 0 && c + dy[i] * j <= n) {
//					// �浹 �߰��� �ƹ��͵� �ȳ��� �ִٸ� stop
//					if (board[r + dx[i] * j][c + dy[i] * j] == 0) {
//						break;
//					}
//					// �鵹�̶�� ����ħ
//					else if (board[r + dx[i] * j][c + dy[i] * j] == WHITE) {
//						change++;
//						continue;
//					}
//					// �浹�̶�� ����ģ �鵹�� ��� ������
//					else if (board[r + dx[i] * j][c + dy[i] * j] == BLACK) {
//						// ����ģ �鵹�� �ϳ��� �ִٸ� flag�� true��
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
//	// �鵹 ����
//	else {
//		board[r][c] = WHITE;
//
//		for (int i = 0; i < 8; i++) {
//			int change = 0;
//			for (int j = 1; j <= n; j++) {
//				if (r + dx[i] * j > 0 && r + dx[i] * j <= n && c + dy[i] * j > 0 && c + dy[i] * j <= n) {
//					// �鵹 �߰��� �ƹ��͵� �ȳ��� �ִٸ� stop
//					if (board[r + dx[i] * j][c + dy[i] * j] == 0) {
//						break;
//					}
//					// �浹�̶�� ����ħ
//					else if (board[r + dx[i] * j][c + dy[i] * j] == BLACK) {
//						change++;
//						continue;
//					}
//					// �鵹�̶�� ����ģ �浹�� ��� ������
//					else if (board[r + dx[i] * j][c + dy[i] * j] == WHITE) {
//						// ����ģ �浹�� �ϳ��� �ִٸ� flag�� true��
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
//	// ���� �� ���� ��ġ���ٸ� �ٽ� ���ʸ� �ٲ���
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
//			// ���� �ٲٱ�
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