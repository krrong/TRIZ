#include <iostream>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first * b.second + b.first * c.second + c.first * a.second;
    op -= (a.second * b.first + b.second * c.first + c.second * a.first);
    if (op > 0)return 1;        // �ݽð� ����
    else if (op == 0)return 0;  // ����
    else return -1;             // �ð� ����
}

int isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c) * ccw(a, b, d);   // ab���п� ���� �� c, d�� ccw ��
    int cd = ccw(c, d, a) * ccw(c, d, b);   // cd���п� ���� �� a, b�� ccw ��

    if (ab <= 0) {
        if (ab == 0 && cd == 0) {
            if (a > b) swap(a, b);
            if (c > d) swap(c, d);

            // �� ������ ������ ���
            if (a == d || b == c) {
                return 2;
            }
            // ������ �ʴ� ���
            else if (a > d || b < c) {
                return 1;
            }
            // ���ԵǴ� ���
            else if ((a <= c && d <= b) || (c <= a && b <= d)) {
                return 4;
            }
            // �������� �Ϻΰ� ��ġ�� ���
            else {
                return 3;
            }
        }
        // ������ �ʴ� ���
        else if (cd > 0) {
            return 1;
        }
        // �������� ��� �� ������ ����
        else {
            return 2;
        }
    }
    else {
        return 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x1, x2, y1, y2, x3, x4, y3, y4;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        pair<pair<int, int>, pair<int, int>> x;
        pair<pair<int, int>, pair<int, int>> y;

        x.first = make_pair(x1, y1);
        x.second = make_pair(x2, y2);
        y.first = make_pair(x3, y3);
        y.second = make_pair(x4, y4);

        cout << isIntersect(x, y) << '\n';
    }

    return 0;
}