/*
    set 자료구조는 중복된 key값을 허용하지 않는다.
    따라서 서로 다른 폰켓몬 종류 수를 구하는데 사용한다.
*/
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    set<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        s.insert(nums[i]); // 키 값 중복시엔 삽입 X
    }
    
    int max = nums.size()/2; // 최대 N/2마리

    set<int> ::iterator iter; 
    for (iter = s.begin(); iter != s.end() ; iter++)
    {
        if (answer<max) 
        {
            answer++;
        }
        else break; // 폰켓몬 종류의 수가 max보다 크거나 같더라도 가져갈수 있는 최대 수는 max마리 이다.
    }
    return answer;
}