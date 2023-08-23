#include<iostream>
#include<algorithm>
#include<stack> //스택 사용
using namespace std;

int n;
stack<int> my_stack;
int answer[1000001];
int n_list[1000001];

int main()
{
	cin >> n;
	// 입력받기
	for (int i = 0; i < n; i++){
		cin >> n_list[i];
	}
	
    // 스택이 비었을 때 예외 처리 / 새로 들어오는 값(오른쪽에 있는값)이 해당 값보다 크면 해당값의 오큰수가 될 수 있음.
	for (int i = 0; i < n; i++){
		while (!my_stack.empty() && n_list[my_stack.top()] < n_list[i]){
			answer[my_stack.top()] = n_list[i];
			my_stack.pop();
        	}   
		my_stack.push(i);
	}
	
	// 스택에 남아있던 애는 오큰수가 될 수 있는 수가 없었던 것이므로 -1 저장
	while(!my_stack.empty()) {
		answer[my_stack.top()] = -1;
	        my_stack.pop();
	}
	// 결과
	for (int i = 0; i < n; i++){
		cout << answer[i] << " ";
	}
}
