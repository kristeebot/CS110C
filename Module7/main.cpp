// CS110C PROF MAX LUTTREL
// KRISTINA HELWING
// 101522

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

/*For this assignment, implement a simple stack calculator which can compute an infix expression.
It should take in a string containing an infix expression, compute the result, and print it out.  It should handle operators +, -, *, / and parenthesis.

Your program must have two main steps -- first convert the infix expression to postfix, and then compute the result using the algorithms discussed in videos/pdfs and textbook.
These algorithms require that you use a stack.  You must implement your own stack, you may not use a library that implements a stack.
No credit will be given if you don't implement your own stack.

Although your textbook contains implementations of a stack, I encourage you to try and implement your own stack, using the textbook as a reference only if you need it.
You can keep your stack simple -- e.g. it doesn’t need to be templated, it can just hold a simple data type like char.
Additionally, it doesn’t need to handle error conditions because we are guaranteed a string containing a syntactically correct infix expression.
You may implement either an array-based stack or a link-based stack.

Assumptions
To keep things simple, you may make the following assumptions:

there are no spaces or other whitespace in the string
all the operands are single digits
the result of every operation is a single digit.  For example, 2+3 is allowed because the result is 5.
5*3 is not allowed because the result is 15, which is two digits.
 5+3+4 is not allowed because even though the first operation is 8, a single digit, the result of the second operation is 12, two digits.
 5+3-4 is allowed because the result of the first operation is 8, and the result of the second operation is 4
any string entered contains a valid, syntactically correct infix expression.  If there are parenthesis in the expression, they are balanced.
Conversion between int and char
The expression contains both char and int data, because each operator is a char and each operand is a digit.
The easiest way to handle this is to implement a stack which supports char data.
 Since we know all our operands are single digits, we can simply push the character representing the digit onto the stack.
 Note this character will be the ASCII value of the character, not the integer value!
  As an example, the character '7' is ASCII value 55, '8' is 56, etc.  If you need the actual integer value of the character, in this case 7, there is a convenient way to determine it.
  You can subtract the ASCII value of zero, '0' from the character.  For example, the following code will store 7 in i:

  char c = '7';
  int i = c - '0';
To get the character back, you can add '0' to an integer.

Extra Credit
For up to 10% extra credit, improve your program to remove the assumption that the string contains a valid, syntactically correct infix expression.
It should compute the result if the string is valid, and gracefully handle an invalid string, for example by outputting an error message.
*/

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
        cout << "pushing value: " << value << endl;
        stack[top++] = value;
    }
    char peek()
    {
        return stack[top];
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

string infixToPostfix(string input)
{
    return " ";
}
int performOperator(int valueOne, int valueTwo, char oP)
{
    if (oP == '+')
    {
        return valueOne + valueTwo;
    }
    if (oP == "-")
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
            // write a function that does the math
        }
        else
        {
            myStack.push(charToInt(token));
        }
    }
    return result;
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
    return 0;
}
