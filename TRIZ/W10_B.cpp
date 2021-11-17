//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int length[501];
//int arr[501];
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int t;
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//
//		int answer = 0;
//		for (int k = 0; k < n; k++) {
//			length[k] = 1;
//			for (int i = 0; i < k; i++) {
//				if (arr[i] < arr[k]) {
//					length[k] = max(length[k], length[i] + 1);
//				}
//			}
//			if (length[k] > answer) {
//				answer = length[k];
//			}
//		}
//
//		cout << answer << '\n';
//	}
//
//
//	return 0;
//}