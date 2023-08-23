#include <iostream>

using namespace std;

double	Pr(int u, double eta);

void OverlappingTemplateMatchings(string str1, string str)
{
    int m = str1.size();
    int n = str.size();
    int				i, k, match;
    double			W_obs, eta, sum, chi2, p_value, lambda;
    int				M, N, j, K = 5;
    unsigned int	nu[6] = { 0, 0, 0, 0, 0, 0 };
    double			pi[6] = { 0.364091, 0.185659, 0.139381, 0.100571, 0.0704323, 0.139865 };

    M = 1032;
    N = n/M;

    cout << "N = "  << N << endl;


        for ( i=0; i<m; i++ )
            str[i] = 1;

    lambda = (double)(M-m+1)/pow(2,m);
    eta = lambda/2.0;
    sum = 0.0;
    for ( i=0; i<K; i++ ) {			/* Compute Probabilities */
        pi[i] = Pr(i, eta);
        sum += pi[i];
    }
    pi[K] = 1 - sum;

    for ( i=0; i<N; i++ ) {
        W_obs = 0;
        for ( j=0; j<M-m+1; j++ ) {
            match = 1;
            for ( k=0; k<m; k++ ) {
                if ( str1[k] != str[i*M+j+k] )
                    match = 0;
            }
            if ( match == 1 )
                W_obs++;
        }
        if ( W_obs <= 4 )
            nu[(int)W_obs]++;
        else
            nu[K]++;
    }
    sum = 0;
    chi2 = 0.0;                                   /* Compute Chi Square */
    for ( i=0; i<K+1; i++ ) {
        chi2 += pow((double)nu[i] - (double)N*pi[i], 2)/((double)N*pi[i]);
        sum += nu[i];
    }

    cout << "chi2 = " << chi2 << endl;
    cout << "K = " << K << endl;
    p_value = cephes_igamc(K/2.0, chi2/2.0);
    cout << "P_VALUE = " <<  p_value;
}

double
Pr(int u, double eta)
{
    int		l;
    double	sum, p;

    if ( u == 0 )
        p = exp(-eta);
    else {
        sum = 0.0;
        for ( l=1; l<=u; l++ )
            sum += exp(-eta-u*log(2)+l*log(eta)-cephes_lgam(l+1)+cephes_lgam(u)-cephes_lgam(l)-cephes_lgam(u-l+1));
        p = sum;
    }
    return p;
}

