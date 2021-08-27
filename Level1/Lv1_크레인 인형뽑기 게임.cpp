/*
    stack의 top을 비교하기 전에 비어있지 않은지 먼저 확인 해야한다.
    확인하지 않고 empty stack의 top을 비교하면 segmentation fault 발생.
*/
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    int answer = 0;
    stack<int> S;

    for (int i = 0; i < moves.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[j][moves[i]-1]!=0)
            {
                if(!S.empty() && S.top() == board[j][moves[i]-1]){ S.pop(); answer+=2;}
                else S.push(board[j][moves[i]-1]);
                
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    return answer;
}
