#include <iostream>
#include <cmath>
#include "file.cpp"

using namespace std;




double

DiscreteFourierTransform(string str)
{

    int n = str.size();

    double	p_value, upperBound, percentile, N_l, N_o, d, *m = nullptr, *X = nullptr, *wsave = nullptr;
    int		i, count, ifac[15];

    if ( ((X = (double*) calloc(n,sizeof(double))) == nullptr) ||
         ((wsave = (double *)calloc(2*n,sizeof(double))) == nullptr) ||
         ((m = (double*)calloc(n/2+1, sizeof(double))) == nullptr) ) {
        if( X != nullptr )
            free(X);
        if( wsave != nullptr )
            free(wsave);
        if( m != nullptr )
            free(m);
        return 0;
    }
    for ( i=0; i<n; i++ )

        X[i] = int(2*str[i]) - 1;

     __ogg_fdrffti(n, wsave, ifac);		/* INITIALIZE WORK ARRAYS */
     __ogg_fdrfftf(n, X, wsave, ifac);	/* APPLY FORWARD FFT */

    m[0] = sqrt(X[0]*X[0]);	    /* COMPUTE MAGNITUDE */

    for ( i=0; i<n/2; i++ )
        m[i+1] = sqrt(pow(X[2*i+1],2)+pow(X[2*i+2],2));
    count = 0;				       /* CONFIDENCE INTERVAL */
    upperBound = sqrt(2.995732274*n);
    for ( i=0; i<n/2; i++ )
        if ( m[i] < upperBound )
            count++;
    percentile = (double)count/(n/2)*100;
    N_l = (double) count;       /* number of peaks less than h = sqrt(3*n) */
    N_o = (double) 0.95*n/2.0;
    d = (N_l - N_o)/sqrt(n/4.0*0.95*0.05);
    p_value = erfc(fabs(d)/sqrt(2.0));


   // cout << percentile << endl;
    if (p_value > 0.01) {
        cout << "Test passed P_value: " << p_value << endl;
    }

    else
    {
        cout << "Test failed, P_value is less than 0.01" << endl;
    }
    return p_value;

    free(X);
    free(wsave);
    free(m);
}
