#include <iostream>

using namespace std;

double psi2(int m, string str);

void Serial(int m, const string& str)
{

    double	p_value1, p_value2, psim0, psim1, psim2, del1, del2;

    psim0 = psi2(m, str);
    // cout << psim0 << endl;

    psim1 = psi2(m-1, str);
    psim2 = psi2(m-2, str);
   // cout << psim1 << endl;
   // cout << psim2 << endl;
    del1 = psim0 - psim1;
   // cout << del1 << endl;
    del2 = psim0 - 2*psim1 + psim2;
   // cout << del2 << endl;
    p_value1 = cephes_igamc(pow(2, m-2), del1/2);
    p_value2 = cephes_igamc(pow(2, m-3), del2/2);



    cout << "P_value_1: " << p_value1 << endl;
    cout << "P_value_2: " << p_value2 << endl;

    if ((p_value1 || p_value2) > 0.01)
    {
        cout << "Test passed";
    }
    else
    {
        cout << "Test Failed";
    }
}

double
psi2(int m, string str)
{
    int n = str.size();
    int				i, j, k, powLen;
    double			sum, numOfBlocks;
    unsigned int	*P;

    if ( (m == 0) || (m == -1) )
        return 0;
    numOfBlocks = n;
    powLen = int(pow(2, m+1))-1;
    if ( (P = (unsigned int*)calloc(powLen,sizeof(unsigned int)))== nullptr ) {

        return 0;
    }
    for ( i=1; i < (powLen-1); i++ )
        P[i] = 0;
    for ( i=0; i<numOfBlocks; i++ ) {
        k = 1;
        for ( j=0; j<m; j++ ) {


            if ( str[(i+j)%n] == '0' ) {
                k *= 2;
            }
            else if ( str[(i+j)%n] == '1' ) {
                k = 2 * k + 1;
            }
        }
        P[k-1]++;
    }
    sum = 0.0;
    for ( i=(int)pow(2, m)-1; i<(int)pow(2, m+1)-1; i++ )
        sum += pow(P[i], 2);
    sum = (sum * pow(2, m)/(double)n) - (double)n;
    free(P);

    return sum;
}

