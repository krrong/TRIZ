//#include <iostream>
//#include <vector>
//using namespace std;
//
//int n;
//int dp[501];
//int answer;
//
//void reset() {
//	for (int i = 0; i < n; i++) {
//		dp[i] = 0;
//	}
//	answer = 0;
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
//		cin >> n;
//		vector<int> v;
//		for (int i = 0; i < n; i++) {
//			int x;
//			cin >> x;
//			v.push_back(x);
//		}
//
//		dp[0] = 1;
//		for (int i = 1; i < n; i++) {
//			dp[i] = 1;
//			for (int j = i; j >= 0; j--) {
//				if (v[i] > v[j]) {
//					dp[i] = max(dp[i], dp[j] + 1);
//				}
//			}
//		}
//
//		for (int i = 0; i < n; i++) {
//			if (dp[i] > answer) {
//				answer = dp[i];
//			}
//		}
//
//		cout << answer << '\n';
//
//		reset();
//	}
//
//
//
//	return 0;
//}