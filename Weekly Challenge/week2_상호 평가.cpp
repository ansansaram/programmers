#include <string>
#include <vector>
#include <iostream>
using namespace std;

char getGrade(int score){
    
    if (score>=90) return 'A';
    else if(score>=80) return 'B';
    else if(score>=70) return 'C';
    else if(score>=50) return 'D';
    else return 'F';
}

string solution(vector<vector<int> > scores) {
    string answer = "";

    float size = scores.size();

    for (int i = 0; i < size; i++)
    {
        int min = 100;
        int max = 0;
        int sum = 0;
        int own = scores[i][i];
        for (int j = 0; j < size; j++)
        {
            sum+=scores[j][i];
            if (scores[j][i]<=min)
            {
                min = scores[j][i];
            }
            if(scores[j][i] >= max)
            {
                max = scores[j][i];
            }
        }
        if (own == min || own == max)
        {
            int cnt = 0;
            for (int k = 0; k < size; k++)
            {
                if (k == i)
                {
                    ;
                }
                else if(scores[k][i]==own) cnt++;
            }
            if (cnt==0) // 자기 자신을 평가한 점수가 유일한 최고점 또는 유일한 최저점인 경우
            {
                answer += getGrade((sum-own)/(size-1.0));
            }
            else answer+= getGrade(sum/size);
        }
        else answer+=getGrade(sum/size);

    }
    

    return answer;
}


