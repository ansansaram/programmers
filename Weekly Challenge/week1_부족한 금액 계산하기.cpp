#include<iostream>
using namespace std;

long long solution(int price, int money, int count)
{

    long long total = static_cast<long long>(price) * count * (count + 1) / 2;

    return total-money > 0 ? total - money : 0;
}
