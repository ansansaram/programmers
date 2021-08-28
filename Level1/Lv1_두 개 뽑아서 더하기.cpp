#include <string>
#include <vector>

using namespace std;

bool isSum[201];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    fill_n(isSum,201,false);

    for (int i = 0; i < numbers.size()-1; i++)
    {
        for (int j = i+1; j < numbers.size(); j++)
        {
            isSum[numbers[i]+numbers[j]] = true;
        }
    }
    
    for (int i = 0; i < 201; i++)
    {
        if (isSum[i])
        {
            answer.push_back(i);
        }
        
    }
    

    return answer;
}