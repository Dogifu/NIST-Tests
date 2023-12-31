#include <iostream>
using namespace std;

void LinearComplexity(int M, string str)
{
    int  n = str.size();
    int       i, ii, j, d, N, L, m, N_, parity, sign, K = 6;
    double    p_value, T_, mean, nu[7], chi2;
    double    pi[7] = { 0.01047, 0.03125, 0.12500, 0.50000, 0.25000, 0.06250, 0.020833 };
    char  *T = nullptr, *P = nullptr, *B_ = nullptr, *C = nullptr;

    N = (int)floor(n/M);
    if ( ((B_ = (char *) calloc(M, sizeof(char))) == nullptr) ||
         ((C  = (char *) calloc(M, sizeof(char))) == nullptr) ||
         ((P  = (char *) calloc(M, sizeof(char))) == nullptr) ||
         ((T  = (char *) calloc(M, sizeof(char))) == nullptr) ) {
        if ( B_ != nullptr )
            free(B_);
        if ( C != nullptr )
            free(C);
        if ( P != nullptr )
            free(P);
        if ( T != nullptr )
            free(T);
        return;
    }




    for ( i=0; i<K+1; i++ )
        nu[i] = 0.00;
    for ( ii=0; ii<N; ii++ ) {
        for ( i=0; i<M; i++ ) {
            B_[i] = 0;
            C[i] = 0;
            T[i] = 0;
            P[i] = 0;
        }
        L = 0;
        m = -1;
        d = 0;
        C[0] = 1;
        B_[0] = 1;

        /* DETERMINE LINEAR COMPLEXITY */
        N_ = 0;
        while ( N_ < M ) {
            d = int(str[ii*M+N_]);
            for ( i=1; i<=L; i++ )
                d += C[i] * str[ii*M+N_-i];
            d = d%2;
            if ( d == 1 ) {
                for ( i=0; i<M; i++ ) {
                    T[i] = C[i];
                    P[i] = 0;
                }
                for ( j=0; j<M; j++ )
                    if ( B_[j] == 1 )
                        P[j+N_-m] = 1;
                for ( i=0; i<M; i++ )
                    C[i] = (C[i] + P[i])%2;
                if ( L <= N_/2 ) {
                    L = N_ + 1 - L;
                    m = N_;
                    for ( i=0; i<M; i++ )
                        B_[i] = T[i];
                }
            }
            N_++;
        }
        if ( (parity = (M+1)%2) == 0 )
            sign = -1;
        else
            sign = 1;
        mean = M/2.0 + (9.0+sign)/36.0 - 1.0/pow(2, M) * (M/3.0 + 2.0/9.0);
        if ( (parity = M%2) == 0 )
            sign = 1;
        else
            sign = -1;
        T_ = sign * (L - mean) + 2.0/9.0;

        if ( T_ <= -2.5 )
            nu[0]++;
        else if ( T_ > -2.5 && T_ <= -1.5 )
            nu[1]++;
        else if ( T_ > -1.5 && T_ <= -0.5 )
            nu[2]++;
        else if ( T_ > -0.5 && T_ <= 0.5 )
            nu[3]++;
        else if ( T_ > 0.5 && T_ <= 1.5 )
            nu[4]++;
        else if ( T_ > 1.5 && T_ <= 2.5 )
            nu[5]++;
        else
            nu[6]++;
    }
    chi2 = 0.00;
    for ( i=0; i<K+1; i++ )
    for ( i=0; i<K+1; i++ )
        chi2 += pow(nu[i]-N*pi[i], 2) / (N*pi[i]);
     p_value = cephes_igamc(K/2.0, chi2/2.0);

    if (p_value > 0.01) {
        cout << "Test passed P_value: " << p_value << endl;
    }

    else
    {
        cout << "Test failed, P_value is less than 0.01" << endl;
    }

    free(B_);
    free(P);
    free(C);
    free(T);
}
