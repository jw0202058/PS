#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {

	int K;
	int N;
	list<int> circle;
	list<int>::iterator iter;
	list<int>::iterator end;

	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++) {
		circle.push_back(i);		// 원에 하나하나 추가
	}

	iter = circle.begin();			// 현재 가리키고 있는 곳은 리스트의 맨 처음


	cout << "<";

	for (int i = 0; i < N; i++)			// 모든 사람이 지워질 때까지
	{
		end = circle.end();
		end--;

		for (int i = 0; i < K - 1; i++) {
			if (iter == end)							// 현재 가리키고 있는 곳이 리스트의 맨 마지막이라면, 맨 처음으로 돌아가서 다시 가리킬 것
			{
				iter = circle.begin();
			}
			else
				iter++;
		}

		if (i != N-1)
			cout << *iter << ", ";
		else
			cout << *iter << ">";

		if (iter == end) {
			circle.erase(iter);
			iter = circle.begin();
		}
		else {
			iter = circle.erase(iter);
		}
	}

	return 0;

}