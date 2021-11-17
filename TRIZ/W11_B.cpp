#include <iostream>
#define BLUE 0
#define RED  1
using namespace std;

int n;
int red, blue, redSum, blueSum;
bool board[1025][1025];

void check(int r, int c, int n) {
	// 1 x 1 크기의 종이면 종료
	if (n == 1) {
		if (board[r][c] == BLUE) {
			blue++;
			blueSum++;
		}
		else {
			red++;
			redSum++;
		}
		return;
	}

	int bluecheck = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[r + i][c + j] == BLUE) {
				bluecheck++;
			}
		}
	}

	if (bluecheck == n * n) {
		blue++;
		blueSum = blueSum + bluecheck;
		return;
	}
	else if (bluecheck == 0) {
		red++;
		redSum = redSum + n * n;
		return;
	}
	else {
		check(r, c, n / 2);
		check(r + n / 2, c, n / 2);
		check(r, c + n / 2, n / 2);
		check(r + n / 2, c + n / 2, n / 2);
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void reset() {
	red = 0;
	blue = 0;
	redSum = 0;
	blueSum = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char x;
				cin >> x;
				if (x == 'R') {
					board[i][j] = RED;
				}
				else {
					board[i][j] = BLUE;
				}
			}
		}

		check(0, 0, n);

		cout << red << ' ' << redSum << ' ' << blue << ' ' << blueSum << '\n';
		reset();
	}


	return 0;
}