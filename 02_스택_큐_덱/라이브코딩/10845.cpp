#include <iostream>
#include <queue> // 큐 라이브러리

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    string cmd;
    queue<int> q;

    cin >> n;
    while(n--) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> x;
            q.push(x); //큐에 값 넣기
        }
        else if(cmd == "pop") {
            if(q.empty()) { //큐가 비어 있을 시 1 리턴
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n'; //큐의 front 값 삭제 없이 리턴
                q.pop(); // 큐의 front 삭제
            }
        }
        else if(cmd == "size") {
            cout << q.size() << '\n'; //큐의 사이즈 리턴(구성요수수)
        }
        else if(cmd == "empty") {
            cout << q.empty() << '\n';
        }
        else if(cmd == "front") {
            if(q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else if(cmd == "back") {
            if(q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}
