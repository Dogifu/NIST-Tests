#include <iostream>

using namespace std;


void CumulativeSums(string str)
{
    int n = str.size();
    int		S, sup, inf, z, zrev, k;
    double	sum1, sum2, p_value;

    S = 0;
    sup = 0;
    inf = 0;
    for ( k=0; k < n; k++ ) {
        if (str[k] == '1')
        S++;
        else
            S--;
        if ( S > sup )
            sup++;
        if ( S < inf )
            inf--;
        z = (sup > -inf) ? sup : -inf;
        zrev = (sup-S > S-inf) ? sup-S : S-inf;
    }

    // forward
    sum1 = 0.0;
    for ( k=(-n/z+1)/4; k<=(n/z-1)/4; k++ ) {
        sum1 += cephes_normal(((4*k+1)*z)/sqrt(n));
        sum1 -= cephes_normal(((4*k-1)*z)/sqrt(n));
    }
    sum2 = 0.0;
    for ( k=(-n/z-3)/4; k<=(n/z-1)/4; k++ ) {
        sum2 += cephes_normal(((4*k+3)*z)/sqrt(n));
        sum2 -= cephes_normal(((4*k+1)*z)/sqrt(n));
    }


     p_value = 1 - sum1 + sum2;
    if (p_value > 0.01) {
        cout << "Test passed P_value: " << p_value << endl;
    }

    else
    {
        cout << "Test failed, P_value is less than 0.01" << endl;
    }



    // backwards
    sum1 = 0.0;
    for ( k = (-n/zrev+1)/4; k<=(n/zrev-1)/4; k++ ) {
        sum1 += cephes_normal(((4*k+1)*zrev)/sqrt(n));
        sum1 -= cephes_normal(((4*k-1)*zrev)/sqrt(n));
    }
    sum2 = 0.0;
    for ( k = (-n/zrev-3)/4; k<=(n/zrev-1)/4; k++ ) {
        sum2 += cephes_normal(((4*k+3)*zrev)/sqrt(n));
        sum2 -= cephes_normal(((4*k+1)*zrev)/sqrt(n));
    }
    p_value = 1 - sum1 + sum2;
    if (p_value > 0.01) {
        cout << "Test passed P_value: " << p_value << endl;
    }

    else
    {
        cout << "Test failed, P_value is less than 0.01 " << p_value << endl;
    }
}
