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
//		int fir = k * 2 - 1;	// ���� ���� ��
//		int sec = 1;			// ���� ���� ��
//
//		int cur = 0;			// ���� �� ��ġ
//
//		// �� �� ��ŭ �ݺ�
//		int a = k;
//		while (a--) {
//			int tmp = cur;	// ���� ��ġ�� �����ϴ� �ӽú���
//
//			while (tmp <= size) {
//				cout << str[tmp];
//
//				tmp = tmp + fir;
//				// ���ڰ� ������ whileŻ��
//				if (tmp >= size) {
//					break;
//				}
//				cout << str[tmp];
//
//				tmp = tmp + sec;
//				// ���ڰ� ������ whileŻ��
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