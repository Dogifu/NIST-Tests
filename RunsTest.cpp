#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#include <iostream>

using namespace std;


double Runs(string st) {

    int S, k;
    int n = st.size();
    double pi, V, erfc_arg, p_value;

    S = 0;
    for ( k=0; k<n; k++ )
        if ( st[k] == '1' )
            S++;
    pi = (double)S / (double)n;

    if ( fabs(pi - 0.5) > (2.0 / sqrt(n)) ) {

        p_value = 0;
    }
    else {

        V = 1;
        for ( k=1; k<n; k++ )
            if ( st[k] != st[k-1] )
                V++;

        erfc_arg = fabs(V - 2.0 * n * pi * (1-pi)) / (2.0 * pi * (1-pi) * sqrt(2*n));
        p_value = erfc(erfc_arg);

    }

    if (p_value > 0.01) {
        cout << "Test passed P_value: " << p_value << endl;
    }

    else
    {
        cout << "Test failed, P_value is less than 0.01" << endl;
    }
    return p_value;
}

#pragma clang diagnostic pop