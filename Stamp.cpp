/*
 * https://atcoder.jp/contests/past202012-open/tasks/past202012_e
 * E - ハンコ
 * 
 * テトリスの衝突判定に似てる問題があった
 * 計算量には無駄が多いけど、行数をなるべく少なくしてみた
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
				if (((m < 0 || h <= m || n < 0 || w <= n) || (s[m][n] == '#')) && (t[k][l] == '#')) goto NEXT;
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
