/*
    2020 카카오 인턴십
*/
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// vector<pair<int,int> > position = {
//     {3,1}, // 키패드 0의 위치
//     {0,0}, {0,1}, {0,2},
//     {1,0}, {1,1}, {1,2},
//     {2,0}, {2,1}, {2,2},
//     {3,0},        {3,2} // 키패드 *, # 의 위치. * -> position[10], # -> position[11]
// };
int distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    vector<pair<int,int> > positions;
    positions.push_back(make_pair(3,1)); 
    positions.push_back(make_pair(0,0)); 
    positions.push_back(make_pair(0,1)); 
    positions.push_back(make_pair(0,2)); 
    positions.push_back(make_pair(1,0)); 
    positions.push_back(make_pair(1,1)); 
    positions.push_back(make_pair(1,2)); 
    positions.push_back(make_pair(2,0)); 
    positions.push_back(make_pair(2,1)); 
    positions.push_back(make_pair(2,2)); 
    positions.push_back(make_pair(3,0)); 
    positions.push_back(make_pair(3,2)); 
    int leftHand = 10, rightHand = 11; // 초기 손의 위치

    bool isLeftHandsMove ;
    for (int i = 0; i < numbers.size(); i++)
    {
        isLeftHandsMove = false;
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            isLeftHandsMove = true;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            ;
        }
        else // 2, 5, 8, 0
        {
            // 왼손의 거리
            // positions[leftHand] , positions[numbers[i]] 간의 거리 이다.
            if (distance(positions[leftHand], positions[numbers[i]]) < distance(positions[rightHand], positions[numbers[i]]))
            {
                // 왼손이 더 가까운 경우
                // answer += 'L';
                isLeftHandsMove = true;
            }
            else if (distance(positions[leftHand], positions[numbers[i]]) > distance(positions[rightHand], positions[numbers[i]]))
            {
                ;
            }
            else // 키패드까지의 거리가 같은 경우 주손이 이동
            {
                if (hand == "left")
                {
                    isLeftHandsMove = true;
                }
                else
                {
                    ;
                }
            }
        }
        if (isLeftHandsMove){
            answer += 'L';
            leftHand = numbers[i];
            }
        else {
            answer += 'R';
            rightHand = numbers[i];
            }
    }
    return answer;
}