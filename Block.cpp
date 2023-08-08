#include <iostream>
#include <cmath>

using namespace std;

double Block(const string& st)
{

    int n;

    double counter = 0, p_value, S_obs, S_obs1;

    for (char i : st)

    {
       n = i - '0';

       if (i == '0')
       {
           n = -1;
       }

       counter += n;

    }

    S_obs = abs(counter)/(sqrt(st.size()));

    S_obs1 = S_obs/ sqrt(2);

     p_value = erfc(S_obs1);


    if (p_value < 0.01)
    {
        cout << "Test failed, P_value is less than 0.01" << endl;
    }

    else {
        cout << "Test passed P_value = " << p_value << endl;
    }


    return p_value;

}