#include <iostream>

using namespace std;



void RandomExcursionsVariant(string str) {
    int n = str.size();
    int i, p,  x,  count, *S_k;
    double constraint;
    double J;
    int stateX[18] = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double p_value;

    if ((S_k = (int *) calloc(n, sizeof(int))) == nullptr) {
        return;
    }
    J = 0;

    S_k[0] = 2 * int(str[0]) - 1;
    for (i = 1; i < n; i++) {
        n = str[i] - '0';
        S_k[i] = S_k[i - 1] + 2 * int(str[i]) - 1;
        if (S_k[i] == 0)
            J++;
    }

    if (S_k[n - 1] != 0)
        J++;

  //  cout << "J = " << J << endl;



    double a1, a2;
    a1 = 0.005 * pow(n, 0.5);
    a2 = 500;

    if (a1 > a2)
    {
        constraint  = a1;
    }
    else
    {
        constraint = a2;
    }

   // cout << "const = " << constraint << endl;


     if (J > constraint)
     {
         for (i = 0; i < 18; i++)
            cout << 0 << endl;
     }
     else {
        for (p = 0; p <= 17; p++) {
            x = stateX[p];
            count = 0;
            for (i = 0; i < n; i++)
                if (S_k[i] == x)
                    count++;
            p_value = erfc(fabs(count - J) / (sqrt(2.0 * J * (4.0 * fabs(x) - 2))));
            if (p_value > 0.01) {
                cout << "Test passed P_value № " << p + 1 << ": " << p_value  << endl;
            }

            else
            {
                cout << "Test failed, P_value is less than 0.01" << endl;
            }

        }


    }

}
