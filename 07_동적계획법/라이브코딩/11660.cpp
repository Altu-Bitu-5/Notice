#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> calcPsum(int n, vector<vector<int>>& A) {
	//psum[i][j]: (1,1)부터 (i,j)까지의 합
	vector<vector<int>> psum(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + A[i][j];
		}
	}
	return psum;
}

int calcSum(int x1, int y1, int x2, int y2, vector<vector<int>>& psum) {
	return psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m;
	cin >> n >> m;

	vector<vector<int>> A(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}

	//연산
	vector<vector<int>> psum = calcPsum(n, A);

	while (m--) {
		int x1, y1, x2, y2;

		//입력
		cin >> x1 >> y1 >> x2 >> y2;

		//연산 & 출력
		cout << calcSum(x1, y1, x2, y2, psum) << "\n";
	}

	return 0;
}