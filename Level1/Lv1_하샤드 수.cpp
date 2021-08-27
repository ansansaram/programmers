#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    
    int n = x;
    int sumOfDigits = 0;
    while (n)
    {
        sumOfDigits += (n%10);
        n /= 10;
    }
    


    return !(x/sumOfDigits);
}