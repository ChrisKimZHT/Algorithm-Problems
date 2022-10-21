#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    bool have_upper = false, have_lower = false, is_distict = true;
    bool upper_char[26]{}, lower_char[26]{};
    for (int i = 0; i < S.size(); i++)
    {
        if (isupper(S[i]))
        {
            have_upper = true;
            if (!upper_char[S[i] - 'A'])
                upper_char[S[i] - 'A'] = true;
            else
                is_distict = false;
        }
        if (islower(S[i]))
        {
            have_lower = true;
            if (!lower_char[S[i] - 'a'])
                lower_char[S[i] - 'a'] = true;
            else
                is_distict = false;
        }
    }
    if (have_upper && have_lower && is_distict)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}