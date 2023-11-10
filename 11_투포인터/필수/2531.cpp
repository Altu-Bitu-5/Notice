#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * 먹을 수 있는 초밥 가짓수의 최댓값을 계산한다.
 * n: 회전 초밥 벨트에 놓인 접시의 수
 * d: 초밥의 가짓수
 * k: 연속해서 먹는 접시의 수
 * c: 쿠폰 번호
*/
int calcMaxSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0); // 종류별 먹은 초밥의 개수

    // 쿠폰으로 초밥 먹기
    int section_sushi = 1;
    sushi[c]++;

    // 처음부터 연속으로 k개의 초밥 먹기
    for (int i = 0; i < k; i++) {
        if (!sushi[belt[i]]) {
            section_sushi++;
        }
        sushi[belt[i]]++;
    }

    int ans = section_sushi;
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        // 맨 처음 먹은 초밥을 먹은 목록에서 제거
        sushi[belt[i - k]]--;
        if (!sushi[belt[i - k]]) {  // 해당 초밥을 0개 먹었다면
            section_sushi--;    // 먹은 초밥 가짓수 감소
        }
        // 다음 초밥 먹기
        if (!sushi[belt[i % n]]) {  // 새로운 종류의 초밥이라면
            section_sushi++;    // 먹은 초밥 가짓수 증가
        }
        sushi[belt[i % n]]++;
        // 답 갱신
        ans = max(ans, section_sushi);
    }
    return ans;
}

int main() {
    int n, d, k, c;

    // 입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    // 연산 및 출력
    cout << calcMaxSushi(belt, n, d, k, c);
    return 0;
}