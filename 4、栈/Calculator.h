#include "Assistance.h"
#include "LinkStack.h"
int OperPrior(char op1, char op2)
//返回结果：0为消掉，1为op1<op2,2为op1>op2,-1不存在,3为#完成处理
{
    int prior;
    switch (op1)
    {
    case '+':
    case '-':
        if(op2 == '+' || op2 == '-' || op2 == ')'|| op2 == '#') 
            prior = 2;
        else 
            prior = 1;
        break;
    case '*':
    case '/':
    case '^':
        if(op2 == '(' || op2 == '^')
            prior = 1;
        else
            prior = 2;
        break;
    case '(':
        if(op2 == ')')
            prior = 0;
        else if(op2 == '#')
            prior = -1;
        else 
            prior = 1; 
        break;
    case ')':
        if(op2 == '(')
            prior = -1;
        else 
            prior = 2;
        break;
    case '#':
        if(op2 == '#')
        prior = 3;
        else
        prior = 1;
        break;
    default:
        break;
    }
    return prior;
}
bool IsOperator(char ch)
{
    if(ch == '#' || ch == '(' || ch == ')' || ch == '+' 
    || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    return true;
    return false;
}
// void InfixInToPostfix()
// {
//     LinkStack<double> opnd;
//     char ch;
//     double operand,first,second;
//     cout << "输入后缀表达式，以#号结束：" ;
//     ch = getchar();
//     while(ch!='#')
//     {
//         if(IsOperator(ch) || ch == '.')
//         {
//             if()
//         }
//     }
// }