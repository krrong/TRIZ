//#include <iostream>
//using namespace std;
//
//int t, k;
//string str;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> t;
//
//	while (t--) {
//		cin >> str >> k;
//		
//		int size = str.size();
//
//		// 행만큼 반복
//		for (int i = 0; i < k; i++) {
//			for (int j = 0; j < size; j = j + 2 * k) {
//				// 문자열의 길이를 넘어가면 break
//				if (j + i >= size) {
//					break;
//				}
//				cout << str[j + i];
//
//				// 문자열의 길이를 넘어가면 break
//				if (j + 2 * k - i - 1 >= size) {
//					break;
//				}
//				cout << str[j + 2 * k - i - 1];
//			}
//		}
//		cout << '\n';
//	}
//}