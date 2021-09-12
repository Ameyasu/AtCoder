/*
 * https://atcoder.jp/contests/past202012-open/tasks/past202012_e
 * E - �n���R
 * 
 * �e�g���X�̏Փ˔���Ɏ��Ă��肪������
 * �v�Z�ʂɂ͖��ʂ��������ǁA�g���ϐ����Ȃ�ׂ����Ȃ����Ă݂�
 */

#include <iostream>

#define rep(i, b, e) for (int i = b; i < e; ++i)

int main(void) {
	int h, w; std::cin >> h >> w;
	char s[10][10] = {}, t[10][10] = {};
	rep(i, 0, h) std::cin >> s[i];
	rep(i, 0, h) std::cin >> t[i];

	rep(r, 0, 4) {
		rep(i, -9, 10) rep(j, -9, 10) {
			rep(k, 0, 10) rep(l, 0, 10) {
				int m = i + k, n = j + l;
				if (0 <= m && m < h && 0 <= n && n < w) {
					if (s[m][n] == '#' && t[k][l] == '#') goto NEXT;
				} else {
					if (t[k][l] == '#') goto NEXT;
				}
			}
			std::cout << "Yes";
			return 0;
		NEXT:;
		}
		char u[10][10]; memcpy(u, t, sizeof(u));
		rep(i, 0, 10) rep(j, 0, 10) t[i][j] = u[j][9 - i];
	}
	std::cout << "No";
	return 0;
}