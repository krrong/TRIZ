#include <iostream>
#define BLACK 2
#define WHITE 1
using namespace std;

int n, q, turn;
int board[21][21];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

// 판 범위를 벗어났는지 체크하는 함수
bool valid(int r, int c) {
	return !(r<1 || r>n || c<1 || c>n);
}

// 주어진 위치에 놓을 수 있는지 체크하는 함수
bool isPoss(int t, int r, int c, int w, int u) {
	int nr = r + dx[w];
	int nc = c + dy[w];
	if (valid(nr, nc) && board[nr][nc] == 3 - t) {
		while (valid(nr, nc) && board[nr][nc] == 3 - t) {
			nr = nr + dx[w];
			nc = nc + dy[w];
		}
		if (valid(nr, nc) && board[nr][nc] == u) {
			return 1;
		}
	}
	return 0;
}

// 놓을 수 있는 위치가 있는지 체크하는 함수
bool nowhere(int t) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == t) {
				for (int w = 0; w < 8; w++) {
					if (isPoss(t, i, j, w, 0)) return 0;	// 놓을 수 있는 위치 존재
				}
			}
		}
	}
	return 1;												// 놓을 수 있는 위치 없음
}

void reset() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board[i][j] = 0;
		}
	}
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> q;	
		board[n / 2][n / 2] = board[n / 2 + 1][n / 2 + 1] = BLACK;
		board[n / 2][n / 2 + 1] = board[n / 2 + 1][n / 2] = WHITE;

		turn = BLACK;
		while (q--) {
			//print();
			// 놓을 자리가 없다면 턴 교체
			if (nowhere(turn)) turn = 3 - turn;

			int r, c;
			cin >> r >> c;

			// 범위를 벗어났거나 이미 돌이 놓여있다면 무시
			if (!valid(r, c) || board[r][c] != 0) continue;

			for (int w = 0; w < 8; w++) {
				// 현재 위치에 놓을 돌과 반대쪽 끝에 놓인 돌이 같은 색이면 놓을 수 있다.
				if (isPoss(turn, r, c, w, turn)) {
					board[r][c] = turn;
					int nr = r + dx[w];
					int nc = c + dy[w];

					// 돌 뒤집기
					while (valid(nr, nc) && board[nr][nc] == 3 - turn) {
						board[nr][nc] = turn;
						nr = nr + dx[w];
						nc = nc + dy[w];
					}

				}
			}
			if (board[r][c] == turn)turn = 3 - turn;
		}

		int black = 0, white = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] == WHITE) {
					white++;
				}
				else if (board[i][j] == BLACK) {
					black++;
				}
			}
		}

		if (white > black) {
			cout << WHITE << '\n';
		}
		else if (white < black) {
			cout << BLACK << '\n';
		}
		else {
			cout << 0 << '\n';
		}
		reset();
	}

	return 0;
}