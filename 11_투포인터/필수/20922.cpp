#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX_NUM = 100001;

/**
 * 같은 정수를 k개 이하로 포함한 최장 연속 부분 수열의 길이를 구한다.
*/
int calcMaxLength(vector<int> seq, int k, int n) {
    // 초기화
    int ans = 1;             // 최대 수열 길이
    int left = 0, right = 1; // 부분 수열의 왼쪽, 오른쪽 포인터
    vector<int> count(MAX_NUM, 0); // 수열 내 각 숫자의 개수
    count[seq[left]]++;

    while (right < n) {
        // right를 오른쪽으로 옮겨가면서 right번째 숫자를 수열에 추가할 수 있을 지 판단
        if (count[seq[right]] >= k) { // right에 있는 숫자의 개수가 k가 넘으면 -> 추가 불가
            count[seq[left]]--;       // left 숫자 삭제
            left++;
        } else {                      // right에 있는 숫자의 개수가 k보다 작으면 -> 추가 가능
            count[seq[right]]++;      // right 숫자 추가
            right++;
            ans = max(ans, right - left); // 최대 수열 길이 갱신
        }
    }
    return ans;
}

int main() {
    int n, k;

    // 입력
    cin >> n >> k;
    vector<int> seq(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    // 연산 및 출력
    cout << calcMaxLength(seq, k, n);
    return 0;
}