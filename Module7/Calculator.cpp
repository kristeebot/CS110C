// CS110C PROF MAX LUTTRELL
// KRISTINA HELWING
// 101722

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAX_STACK = 100;

class Stack
{
private:
    char stack[MAX_STACK];
    int top;

public:
    Stack()
    {
        top = 0;
    }
    void push(char value)
    {
        // cout << "pushing value: " << value << endl;
        stack[top++] = value;
    }
    char peek()
    {
        if (isEmpty())
        {
            cerr << "cannot peek into an empty stack" << endl;
            exit(-1);
        }
        return stack[top - 1];
    }
    bool isEmpty()
    {
        return top == 0;
    }
    bool pop()
    {
        if (isEmpty())
        {
            return false;
        }
        top--;
        return true;
    }
};

bool isOp(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int charToInt(char c)
{
    return c - '0';
}

int getPrecedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}
bool isLeftParen(char c)
{
    return c == '(';
}
bool isRightParen(char c)
{
    return c == ')';
}
bool isOperand(char c)
{
    return !isOp(c) && !isLeftParen(c) && !isRightParen(c);
}
string infixToPostfix(string input)
{
    Stack myStack;
    string output;
    for (int i = 0; i < input.size(); i++)
    {
        char token = input[i];
        // 1. if you encounter an operand, append it to the output string
        if (isOperand(token))
        {
            output.push_back(token);
        }
        // 2. if you encounter a "(", push it onto the stack
        if (isLeftParen(token))
        {
            myStack.push(token);
        }
        // 3. if you encounter an operator:

        if (isOp(token))
        {
            // 1. if the stack is empty, push it onto the stack
            if (myStack.isEmpty())
            {
                myStack.push(token);
            }
            // 2. else, peek at the stack. if it is an operator of greater or
            // equal precedence, pop it from the stack and append it to
            // postfixExp. keep peeking/popping until you encounter
            // either a "(" or an operator of lower precedence, or the
            // stack becomes empty. then, push the operator onto the stack
            else
            {
                char c = myStack.peek();
                while (!isLeftParen(c) && getPrecedence(c) >= getPrecedence(token) && !myStack.isEmpty())
                {
                    output.push_back(c);
                    myStack.pop();
                    if (!myStack.isEmpty())
                    {
                        c = myStack.peek();
                    }
                }
                myStack.push(token);
            }
        }
        // 4. if you encounter a ")", pop operators off the stack and append
        // them to postfixExp until you encounter the "(". pop off the "("
        if (isRightParen(token))
        {
            char c = myStack.peek();
            do
            {
                output.push_back(c);
                myStack.pop();
                if (!myStack.isEmpty())
                {
                    c = myStack.peek();
                }
            } while (!isLeftParen(c) && !myStack.isEmpty());
            if (isLeftParen(c))
            {
                myStack.pop();
            }
            else
            {
                cerr << "No matching left paren " << endl;
                exit(-1);
            }
        }
    }

    // 5. if you encounter the end of the string, pop off remaining stack
    // operators and append them to postfixExp
    while (!myStack.isEmpty())
    {
        char c = myStack.peek();
        if (isLeftParen(c) || isRightParen(c))
        {
            cerr<<"mismatched parens" <<endl;
            exit (-1);
        }
        output.push_back(c);
        myStack.pop();
    }
    return output;
}
// do the math
int performOperator(int valueOne, int valueTwo, char oP)
{
    if (oP == '+')
    {
        return valueOne + valueTwo;
    }
    if (oP == '-')
    {
        return valueOne - valueTwo;
    }
    if (oP == '/')
    {
        return valueOne / valueTwo;
    }
    if (oP == '*')
    {
        return valueOne * valueTwo;
    }
    cerr << "unkown operator: " << oP;
    exit(-1);
}

int calculatePostfix(string input)
{
    Stack myStack;
    int result = 0;
    for (int i = 0; i < input.size(); i++)
    {
        char token = input[i];
        if (isOp(token))
        {
            int valueTwo = myStack.peek();
            myStack.pop();
            int valueOne = myStack.peek();
            myStack.pop();
            // call a function that does the math
            myStack.push(performOperator(valueOne, valueTwo, token));
        }
        else
        {
            myStack.push(charToInt(token));
        }
    }
    return myStack.peek();
}

int calculateInfix(string input)
{
    return calculatePostfix(infixToPostfix(input));
}

int main()
{
    string input = "1+2*3";
    cout << "infix to post fix: " << infixToPostfix(input) << endl;
    cout << "calculate post fix: " << calculatePostfix("34+") << endl;
    int inputOneValue = calculateInfix(input);
    string inputTwo = "(1+2)*3";
    int inputTwoValue = calculateInfix(inputTwo);
    cout << "Calcuate: " << input << " = " << inputOneValue << " should be 7" << endl;
    cout << "Calculate: " << inputTwo << " = " << inputTwoValue << " should be 9" << endl;
    // Extra Credit
    // For up to 10% extra credit, improve your program to remove the assumption that the string contains a valid, syntactically correct infix expression.
    // It should compute the result if the string is valid, and gracefully handle an invalid string, for example by outputting an error message.
    // Here is some bad input handling:
    cout << "infix to post fix: " << infixToPostfix("123") << endl;    // no operators
    //cout << "infix to post fix: " << infixToPostfix("(1+2*3") << endl; // mismatched paren commented out to test other error case
    cout << "infix to post fix: " << infixToPostfix("1+2*3)") << endl; // mismatched paren

    return 0;
}
/*SAMPLE OUTPUT
1 arguments:
argv[0] = '/Users/kristinahelwing/CS110C/Module7/main'
infix to post fix: 123*+
calculate post fix: 7
Calcuate: 1+2*3 = 7 should be 7
Calculate: (1+2)*3 = 9 should be 9
infix to post fix: 123
infix to post fix: No matching left paren 
Process exited with status 255
logout
*/