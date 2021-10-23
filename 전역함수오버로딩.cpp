#include <iostream>
using namespace std;
class NUMBOX
{
private:
int num1, num2;
public:
NUMBOX(int num1, int num2) : num1(num1), num2(num2) { }
void ShowNumber()
{
cout << "num1: " << num1 << ", num2: " << num2 << endl;
}
NUMBOX operator+(int num)
{
return NUMBOX(num1+num, num2+num);
}
friend NUMBOX operator+(int num, NUMBOX ref);
};
NUMBOX operator+(int num, NUMBOX ref)
{
ref.num1 += num;
ref.num2 += num;
return ref;
}
int main()
{
NUMBOX nb1(10, 20);
NUMBOX result = 10 + nb1 + 40;
nb1.ShowNumber();
result.ShowNumber();
}

/*
코드를 먼저 살펴보시면, 19행에 operator+ 함수가 선언되었습니다.
friend 키워드가 붙은 이유는, 이 함수가 클래스의 멤버 함수가 아니기 때문에 멤버 변수에 접근할 수 없으므로 붙여준 것입니다.
그리고 22~27행을 보시면 전역 함수로 operator+ 함수가 추가로 정의되었습니다. 33행은 22~27행의 operator+ 함수를 통해 operator+(10, nb1)으로 인식됩니다.
이어서 main 함수 내의 33행을 다시한번 보시면 10과 nb1을 더하고 그 결과에서 40을 더해 result에 대입하고 있습니다.
36행을 통해 결과를 확인해보면 정상적으로 덧셈 연산이 이루어졌음을 확인할 수 있습니다.

*/
