// 15665번 N과 M(11): https://www.acmicpc.net/problem/15665
#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<int> numbers;     // 입력 받은 수
vector<int> sequence; // 출력할 수열

/**
 * 입력 받은 수에서 중복수열을 만든다.
 * 
 * m: 수열의 길이
 * cnt: 현재 뽑은 수의 개수
*/
void backtracking(int m, int cnt) {
    // 재귀 호출 종료 조건: m개의 수를 모두 뽑음
    if (cnt == m) {
        // 수열 출력
        for (int i = 0; i < m; i++)
            cout << sequence[i] << ' ';
        cout << '\n';
        return;
    }
    // 중복을 허용해서 하나씩 수를 뽑아 수열에 저장
    for (auto num: numbers) {
        sequence[cnt] = num;
        backtracking(m, cnt + 1);
    }
}

int main() {
    // 입력
    int n, m;
    cin >> n >> m;
    while (n--) {
        int num;
        cin >> num;
        numbers.insert(num);
    }
    // 초기화
    sequence.assign(m, 0);
    // 연산
    backtracking(m, 0);
    return 0;
}