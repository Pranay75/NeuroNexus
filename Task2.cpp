#include <bits/stdc++.h>
using namespace std;

void calc()
{
    float a, b;
    char c;
    cout << "Enter numbers:";
    cin >> a >> b;

    while (1)
    {
        cout << "Enter operation\n\'+\' - Addition\n\'-\' - Subtraction\n\'*\' - Multiplication\n\'/\' - Divison\n"; // Based on the operator we give the respective result to user
        cin >> c;

        if (c == '+')
        {
            cout << "Result:";
            cout << a + b;
            return;
        }

        else if (c == '-')
        {
            cout << "Result:";
            cout << a - b;
            return;
        }
        
        else if (c == '*')
        {
            cout << "Result:";
            cout << a * b;
            return;
        }
        else if (c == '/')
        {
            cout << "Result:";
            cout << a / b;
            return;
        }
        else
        {
            cout << "Invalid operator" << endl;
            continue;
        }
    }
}

int main()
{
    calc();
    return 0;
}