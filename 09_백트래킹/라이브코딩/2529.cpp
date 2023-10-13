// 2529번 부등호: https://www.acmicpc.net/problem/2529
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> check(10, false);
vector<int> choose;
string max_num = "0123456789";
string min_num = "9876543210";

/**
 * 선택한 숫자 목록(choose)을 문자열로 변환한다.
*/
string chooseToString() {
    string num = "";
    for (int i = 0; i < choose.size(); i++)
        num += to_string(choose[i]);
    return num;
}

/**
 * 최댓값, 최솟값을 갱신한다.
*/
void updateAnswer() {
    string num = chooseToString();  // 현재 선택한 숫자 목록
    max_num = max(max_num, num);
    min_num = min(min_num, num);
}

/**
 * 부등호 방향에 맞게 k + 1개의 수를 뽑는다.
 * 
 * brackets: 부등호가 담긴 벡터
 * cnt: 현재 뽑은 수의 개수
*/
void findMinMax(vector<char> brackets, int cnt)
{
    // 재귀 호출 종료 조건: 숫자(k + 1 개)를 다 뽑은 경우
    if (cnt > brackets.size())
    {
        // 최댓값, 최솟값 갱신
        updateAnswer();
        return;
    }
    // 0~9의 숫자 중 하나를 선택
    for (int i = 0; i < 10; i++)
    {
        // 아직 선택하지 않은 숫자인 경우만
        if (!check[i])
        {
            // 숫자 선택
            check[i] = true;
            choose.push_back(i);

            if (cnt == 0) {     // 처음 숫자를 뽑는 경우
                findMinMax(brackets, cnt + 1);
            } else if (brackets[cnt - 1] == '<' && choose[choose.size() - 2] < i) {    // (이전 숫자 < 현재 숫자)의 경우
                findMinMax(brackets, cnt + 1);
            } else if (brackets[cnt - 1] == '>' && choose[choose.size() - 2] > i) {     // (이전 숫자 > 현재 숫자)의 경우
                findMinMax(brackets, cnt + 1);
            }

            // 선택한 숫자 회수
            check[i] = false;
            choose.pop_back();
        }
    }
}

int main()
{
    int k;

    // 입력
    cin >> k;
    vector<char> brackets(k, '<');
    for (int i = 0; i < k; i++) {
        cin >> brackets[i];
    }

    // 연산
    min_num = min_num.substr(0, k + 1);
    max_num = max_num.substr(0, k + 1);
    findMinMax(brackets, 0);

    // 출력
    cout << max_num << '\n'
         << min_num;

    return 0;
}