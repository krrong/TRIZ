#include <iostream>
#include <vector>
using namespace std;

// answer의 초기값이 100000000이어야 correct가 나온다.
int N;
int Triangle[103][103];
int Answer[103][103];
int answer = 100000000;

void print() {
	for (int i = 1; i <= N+1; i++) {
		for (int j = 1; j <= i; j++) {
			cout << Answer[i][j] << ' ';
		}
		cout << endl;
	}
}

void reset() {
	for (int i = 1; i <= N + 1; i++) {
		for (int j = 1; j <= i; j++) {
			Triangle[i][j] = 0;
			Answer[i][j] = 100000000;
		}
	}
	answer = 100000000;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		reset();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> Triangle[i][j];
			}
		}

		Answer[1][1] = Triangle[1][1];
		// 현재 위치에서 갈 수 있는 길은 두 가지 : 바로 아래, 우측 아래
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				// 바로 아래 값 갱신
				Answer[i + 1][j] = min(Answer[i + 1][j], Answer[i][j] + Triangle[i + 1][j]);

				// 우측 아래 값 갱신
				Answer[i + 1][j + 1] = min(Answer[i + 1][j + 1], Answer[i][j] + Triangle[i + 1][j + 1]);
			}
		}

		// 정답은 가장 마지막 줄의 최소값
		for (int j = 1; j <= N; j++) {
			answer = min(answer, Answer[N][j]);
		}
		cout << answer << "\n";
	}

	return 0;
}