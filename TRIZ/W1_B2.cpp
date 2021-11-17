//#include <iostream>
//#include <stack>
//using namespace std;
//
//int t, n, q, num;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> t;
//
//	while (t--) {
//		cin >> n;
//		
//		stack<int> minNum;
//		stack<int> maxNum;
//
//		for (int i = 0; i < n; i++) {
//			cin >> q;
//
//			if (q == 1) {
//				cin >> num;
//
//				// 최소값을 담은 스택
//				if (minNum.empty()) {
//					minNum.push(num);
//				}
//				else {
//					minNum.push(min(minNum.top(), num));
//				}
//
//				// 최대값을 담은 스택
//				if (maxNum.empty()) {
//					maxNum.push(num);
//				}
//				else{
//					maxNum.push(max(maxNum.top(), num));
//				}
//
//				cout << minNum.top() << " " << maxNum.top() << '\n';
//
//			}
//
//			else {
//				if (!minNum.empty()) {
//					minNum.pop();
//				}
//				if (!maxNum.empty()) {
//					maxNum.pop();
//				}
//			}
//		}
//	}
//}