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
};
int main()
{
NUMBOX nb1(10, 20);
NUMBOX result = nb1 + 10;
nb1.ShowNumber();
result.ShowNumber();
}

