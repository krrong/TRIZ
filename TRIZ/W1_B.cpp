#include <iostream>
#include <deque>
using namespace std;

int t, n, qus, num, maxNum, minNum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		deque<int> d;
		maxNum = 0;
		minNum = 0;
		for (int i = 0; i < n; i++) {
			cin >> qus;

			if (qus == 1) {
				cin >> num;

				d.push_back(num);
				// 처음 넣는다면 최대, 최소 값 초기화
				if (d.size() == 1) {
					minNum = num;
					maxNum = num;
				}
				else {
					if (d.back() > maxNum) {
						maxNum = d.back();
					}
					if (d.back() < minNum) {
						minNum = d.back();
					}
				}
				cout << minNum << ' ' << maxNum << '\n';
			}
			else {
				// 블록 탑이 비어있을 경우 무시
				if (d.empty()) {
					continue;
				}
				int tmp = d.back();
				d.pop_back();

				// pop한 원소가 최대인 경우 재탐색
				if (maxNum == tmp) {
					maxNum = 0;
					for (auto e : d) {
						if (maxNum < e) {
							maxNum = e;
						}
					}
				}

				// pop한 원소가 최소인 경우 재탐색
				if (minNum == tmp) {
					minNum = 1000;
					for (auto e : d) {
						if (minNum > e) {
							minNum = e;
						}
					}
				}
			}
		}
	}

}