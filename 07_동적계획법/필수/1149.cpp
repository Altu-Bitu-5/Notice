#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R = 0, G = 1, B = 2;

int paint(int n, vector<vector<int>>& houses) {
	// dp[i][j]: i번째 집을 j색으로 칠할 때, 1~i번 집까지 칠하는 최소 비용
	vector<vector<int>> dp(n + 1, vector<int>(3, 0));

	for (int i = 1; i <= n; i++) {
		//i번 집은 (i-1)번 집과 다른 색상으로 칠해야 함
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + houses[i][R];
		dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + houses[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + houses[i][B];
	}
	return min({ dp[n][R], dp[n][G], dp[n][B] });
}

/*
1번집 부터 차례로 색칠합니다.
만약 i번 집을 빨간색으로 칠한다면, (i-1)번 집을 초록색이나 파란색으로 칠했어야 합니다.
초록색과 파란색 중 더 비용이 적게 드는 색을 선택하면 됩니다.
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	vector<vector<int>> houses(n + 1, vector<int>(3, 0));
	for (int i = 1; i <= n; i++) {
		cin >> houses[i][R] >> houses[i][G] >> houses[i][B];
	}

	//연산 & 출력
	cout << paint(n, houses);

	return 0;
}