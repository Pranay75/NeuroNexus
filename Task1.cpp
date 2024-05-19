#include <bits/stdc++.h>
using namespace std;

void guess()
{
    srand(time(0));      // seed the rand() such that it will not give same number again and again if we re-run
    int x = rand() % 10; // This will make sure random number is in [0,9]
    int g;
    while (1)
    {
        cout << "Guess the number:";
        cin >> g;

        if (g > x)
        {
            cout << "Guess is high" << endl; // feedback to user guessed number is high.
            continue;
        }

        else if (g < x)
        {
            cout << "Guess is low" << endl; // feedback to user guessed number is low.
            continue;
        }

        else
        {
            break; // user guessed the right number.
        }
    }

    return;
}

int main()
{
    guess();
    cout << "You guessed it right";
    return 0;
}