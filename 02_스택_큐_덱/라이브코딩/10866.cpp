#include <iostream>
#include <deque> //덱 라이브러리

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    string cmd;
    deque<int> dq; //덱 dp 선언

    cin >> n;
    while(n--) {
        cin >> cmd;
        if(cmd == "push_front") {
            cin >> x;
            dq.push_front(x); //덱의 앞의 원소 front를 삭제한다
        }
        else if(cmd == "push_back") {
            cin >> x;
            dq.push_back(x);//덱의 뒤의 원소 back을 삭제한다
        }
        else if(cmd == "pop_front") {
            if(dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back") {
            if(dq.empty()) { // 덱이 비어 있을 시 1 리턴
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n';
                dq.pop_back(); 
            }
        }
        else if(cmd == "size") {
            cout << dq.size() << '\n'; //덱의 크기(구성요소수) 리턴
        }
        else if(cmd == "empty") {
            cout << dq.empty() << '\n';
        }
        else if(cmd == "front") {
            if(dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.front() << '\n';
            }
        }
        else if(cmd == "back") {
            if(dq.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << dq.back() << '\n'; //덱의 백 요소 리턴 (삭제 없음)
            }
        }
    }
    return 0;
}
