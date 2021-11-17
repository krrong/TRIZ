//#include <iostream>
//#include <vector>
//#include <string>
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
//		int fir = k * 2 - 1;	// 앞의 증가 값
//		int sec = 1;			// 뒤의 증가 값
//
//		int cur = 0;			// 현재 행 위치
//
//		// 열 수 만큼 반복
//		int a = k;
//		while (a--) {
//			int tmp = cur;	// 현재 위치를 저장하는 임시변수
//
//			while (tmp <= size) {
//				cout << str[tmp];
//
//				tmp = tmp + fir;
//				// 문자가 없으면 while탈출
//				if (tmp >= size) {
//					break;
//				}
//				cout << str[tmp];
//
//				tmp = tmp + sec;
//				// 문자가 없으면 while탈출
//				if (tmp >= size) {
//					break;
//				}
//
//			}
//
//			fir = fir - 2;
//			sec = sec + 2;
//			cur++;
//		}
//		cout << '\n';
//	}
//}