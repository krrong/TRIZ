//#include <iostream>
//#include <vector>
//using namespace std;
//
//int t;
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> t;
//	while (t--) {
//		int n;
//		cin >> n;
//		vector<int> v(n);
//		for (int i = 0; i < n; i++) {
//			cin >> v[i];
//		}
//
//		bool possible = true;	// ������ ��Ÿ���� flag
//		for (int i = 1; i < n; i++) {
//			possible = true;	
//			for (int j = 0; i + j < n; j++) {
//				// �ϳ��� �ٸ��� �Ұ���, �ٽ� ó������ Ȯ��
//				if (v[j] != v[i + j]) {
//					possible = false;
//					break;
//				}
//			}
//			// �����ϸ� ��� �� �ش� step ����
//			if (possible == true) {
//				for (int j = 0; j < i; j++) {
//					cout << v[j] << ' ';
//				}
//				cout << '\n';
//				break;
//			}
//		}
//		
//		// �Ұ����ϸ� ��ü ��� �� ����
//		if (possible == false) {
//			for (int i = 0; i < n; i++) {
//				cout << v[i] << ' ';
//			}
//			cout << '\n';
//		}
//	}
//}
//
//// test case
//// 1
//// 2
//// 2
//
//// 8
//// 1 2 3 4 5 6 7 1
//// 1 2 3 4 5 6 7
//
//// 9
//// 1 2 3 4 5 6 7 8 2
//// 1 2 3 4 5 6 7 8 2
//
//// 3
//// 1 1 1
//// 1
//
//// �ݷ�1
//// 3
//// 1 1 2
//// output : 1
//// answer : 1 1 2
//
//// �ݷ�2
//// 4
//// 1 1 9 1
//// output : 1
//// answer : 1 1 9
//
//// 4
//// 1 9 1 1
//// 1 9 1
//
//// �ݷ�3
//// 5
//// 1 2 1 2 2
//// output : 1 2
//// answer : 1 2 1 2 2
//
//// 5
//// 1 2 1 2 1
//// 1 2
//
//// 6
//// 1 2 3 1 2 4
//// 1 2 3 1 2 4
//
//// 5
//// 1 3 1 2 1
//// 1 3 1 2
//
//// �ݷ�
//// 20
//// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 1 1 1 1 1
//// output : 1
//// answer : 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 
//
//// �ݷ�
//// 20
//// 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
//// output : 1
//// answer : 1 1 1 1 2 1 1 1 1 1 1 1 1 1 1 1