#include <iostream>

using namespace std;

void
Universal(string str)
{
    int n = str.size();
    int		i, j, p, L, Q, K;
    double	arg, sqrt2, sigma, phi, sum, p_value, c;
    long	*T, decRep;
    double	expected_value[17] = { 0, 0, 0, 0, 0, 0, 5.2177052, 6.1962507, 7.1836656,
                                     8.1764248, 9.1723243, 10.170032, 11.168765,
                                     12.168070, 13.167693, 14.167488, 15.167379 };
    double   variance[17] = { 0, 0, 0, 0, 0, 0, 2.954, 3.125, 3.238, 3.311, 3.356, 3.384,
                              3.401, 3.410, 3.416, 3.419, 3.421 };
    L = 5;
    if ( n >= 387840 )     L = 6;
    if ( n >= 904960 )     L = 7;
    if ( n >= 2068480 )    L = 8;
    if ( n >= 4654080 )    L = 9;
    if ( n >= 10342400 )   L = 10;
    if ( n >= 22753280 )   L = 11;
    if ( n >= 49643520 )   L = 12;
    if ( n >= 107560960 )  L = 13;
    if ( n >= 231669760 )  L = 14;
    if ( n >= 496435200 )  L = 15;
    if ( n >= 1059061760 ) L = 16;

    Q = 10*int(pow(2, L));
    K = int ((floor(n/L)) - double(Q));

    p = int(pow(2, L));
    if ( (L < 6) || (L > 16) || (double(Q) < 10*pow(2, L)) ||
         ((T = (long *)calloc(p, sizeof(long))) == nullptr) ) {

        return;
    }

    c = 0.7 - 0.8/double(L) + (4 + 32/double(L))*pow(K, -3/double(L))/15;
    sigma = c * sqrt(variance[L]/double(K));
    sqrt2 = sqrt(2);
    sum = 0.0;
    for ( i=0; i<p; i++ )
        T[i] = 0;
    for ( i=1; i<=Q; i++ ) {
        decRep = 0;
        for ( j=0; j<L; j++ )
            decRep += str[(i-1)*L+j] * long(pow(2, L-1-j));
        T[decRep] = i;
    }
    for ( i=Q+1; i<=Q+K; i++ ) {
        decRep = 0;
        for ( j=0; j<L; j++ )
            decRep += str[(i-1)*L+j] * long(pow(2, L-1-j));
        sum += log(i - T[decRep])/log(2);
        T[decRep] = i;
    }
    phi = double((sum/double(K)));

    arg = fabs(phi-expected_value[L])/(sqrt2 * sigma);
    p_value = erfc(arg);
    if (p_value > 0.01) {
        cout << "Test passed P_value: " << p_value << endl;
    }

    else
    {
        cout << "Test failed, P_value is less than 0.01" << endl;
    }
    free(T);
}
