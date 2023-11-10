#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9 + 1;

/**
 * 서로 다른 위치에서 시작해서 서로를 향해 가까워지는 투 포인터
 * 두 용액의 합이 가장 0에 가까운 용액의 쌍 리턴
*/
ci findLiquid(int left, int right, vector<int> &liquid) {
    // 초기화
    ci ans = {0, 0};  // 합이 가장 0에 가까운 용액의 쌍
    int value = INF;  // 현재 가장 0에 가까운 값

    // left는 항상 right 보다 작아야 함 (두 포인터가 같은 용액을 가리키면 종료)
    while (left < right) { 
        // 두 용액을 혼합
        int mix = liquid[left] + liquid[right]; 

        // 0이라면 바로 리턴 (이보다 더 0에 가까워질 수는 없기 때문)
        if (mix == 0) { 
            return {liquid[left], liquid[right]};
        }
        
        if (abs(mix) < value) { // 새로운 혼합 값이 현재 value보다 0에 가깝다면 답 갱신
            value = abs(mix);
            ans = {liquid[left], liquid[right]};
        }
        if (mix > 0) { // 0보다 크다면 더 작은 값을 만들어야 함 -> right 이동
            right--;
        } else { // 0보다 작다면 더 큰 값을 만들어야 함 -> left 이동
            left++;
        }
    }
    return ans;
}

int main() {
    int n;

    // 입력
    cin >> n;
    vector<int> liquid(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    // 연산
    sort(liquid.begin(), liquid.end());
    ci ans = findLiquid(0, n - 1, liquid);

    // 출력
    cout << ans.first << ' ' << ans.second;
    return 0;
}