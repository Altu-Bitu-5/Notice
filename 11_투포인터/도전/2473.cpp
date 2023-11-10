#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 3 * 1e9 + 1;

ll min_diff = INF;

/**
 * 세 용액 중 하나(fixed)는 고정하고 나머지 두 용액을 투포인터로 탐색
 *  -> 다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
*/
pair<ll, ll> findLiquid(vector<ll> &liquid, ll fixed, int left, int right) {
    pair<ll, ll> ans = {INF, INF};

    // left는 항상 right 보다 작아야 함 (두 포인터가 같은 용액을 가리키면 종료)
    while (left < right) {
        // 세 용액 혼합
        ll mix = fixed + liquid[left] + liquid[right];  

        // 0이라면 바로 리턴 (이보다 더 0에 가까워질 수는 없기 때문)
        if (mix == 0) {
            return {liquid[left], liquid[right]};
        }

        // 새로운 혼합 값이 현재 min_diff보다 0에 가깝다면 답 갱신
        if (abs(mix) < min_diff) { 
            min_diff = abs(mix);
            ans = {liquid[left], liquid[right]};
        }

        // 투 포인터 이동
        if (mix > 0) { // 0보다 크다면 더 작은 값을 만들어야 함 -> right 이동
            right--;
        } else { // 0보다 작다면 더 큰 값을 만들어야 함 -> left 이동
            left++;
        }
    }
    return ans;
}

/**
 * [세 용액]
 * 1. 하나의 용액을 반드시 사용한다고 가정 -> 용액 하나 고정
 * 2. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n;

    // 입력
    cin >> n;
    vector<ll> liquid(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> liquid[i];
    }

    // 연산
    sort(liquid.begin(), liquid.end());
    tuple<ll, ll, ll> ans;  // tuple: 3개의 값 저장
    for (int i = 0; i < n - 2; i++) {
        pair<ll, ll> p = findLiquid(liquid, liquid[i], i + 1, n - 1); // liquid[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { // 최솟값이 갱신된 경우
            ans = {liquid[i], p.first, p.second};
        }
    }

    // 출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0;
}