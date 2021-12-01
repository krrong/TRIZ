#include <iostream>
#include <vector>
using namespace std;

string board[3002];		// ������
int F[3002];			// �����Լ�
int n, m;
vector<string> words;	// ã�� �ܾ� ����
vector<string> text;	// ���� �� �ִ� �ܾ� ����
string s;

// �����Լ�
void getFailure(string p) {
	F[0] = 0;
	int i = 1;
	int j = 0;

	while (i < p.size()) {		// ���ڿ��� ���̸�ŭ
		if (p[i] == p[j]) {		// �� ���ڰ� ���ٸ�
			F[i] = j + 1;		// ���λ�� ���̻��� �ִ� ���� ����
			i++;				// ���� ���� Ȯ���� ���� i++
			j++;				// ���� ���� Ȯ���� ���� j++
		}
		else if (j > 0) {		// �պκ��� ��ġ�ϴ� �߰��� ����ġ �ϴ� ���
			j = F[j - 1];		// �����Լ��� ����� �� �̿�
		}
		else {					// ó������ ������ ���
			F[i] = 0;			// ����κ��� �ִ� ���̴� 0
			i++;				// ���������� ��ĭ �ű�

		}
	}
}

// kmp
bool kmp(string s, string p) {
	int s_size = s.size();
	int p_size = p.size();
	int i = 0;
	int j = 0;

	while (i < s_size) {				// �ؽ�Ʈ ��ü ���̿� ����
		if (s[i] == p[j]) {				// ���ڰ� ���ٸ�
			if (j == (p_size - 1)) {	// ������ Ȯ���ߴ��� �Ǵ� -> Ž�� ����
				return true;
			}
			i++;						// ���� ���� Ȯ���� ���� i++
			j++;						// ���� ���� Ȯ���� ���� j++
		}
		else if (j > 0) {				// �պκ��� ��ġ�ϴ� �߰��� ����ġ �ϴ� ���
			j = F[j - 1];				// �����Լ��� ����� �� �̿�
		}
		else {							// ó������ ������ ���
			i++;						// ���������� ��ĭ �ű�
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		words.push_back(s);
	}

	// ���� ���� �߰�
	for (int i = 0; i < n; i++) {
		string s = board[i];
		text.push_back(s);
	}

	// ���� ���� �߰�
	for (int i = 0; i < n; i++) {
		string s = "";

		for (int j = 0; j < n; j++) {
			s = s + board[j][i];
		}
		text.push_back(s);
	}

	// A -> B -> M -> R ... -> C �밢�� �߰�(������)
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; i + j < n; j++) {
			s = s + board[j][i + j];
		}
		text.push_back(s);
	}

	// A -> P -> P -> L ... -> F �밢�� �߰�(�����)
	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; i + j < n; j++) {
			s = s + board[i + j][j];
		}
		text.push_back(s);
	}

	int size = text.size();			// Ȯ���� �� �ִ� �ؽ�Ʈ�� ����

													// Ȯ���� ���Ͽ� ����
	for (int i = 0; i < m; i++) {		
		getFailure(words[i]);						// �����Լ� ���ϰ�
		bool ok = false;							// ������ ������ flag
		for (int j = 0; j < size; j++) {			// Ȯ�ΰ����� �ؽ�Ʈ�� ����
			if (kmp(text[j], words[i]) == true) {	// ������ �ִٸ�
				cout << 1 << '\n';					// 1���
				ok = true;							// flag�� ����
				break;
			}
		}
		if (ok == false) {							// ã�� ���ߴٸ� 0���
			cout << 0 << '\n';
		}
	}

	return 0;
}
