#include <iostream>


double MAX(double x, double y)
{
    if (x > y)
    {
        return x;
    }

    else
    {
        return y;
    }
}

using namespace std;

void RandomExcursions(string str)
{

    int n = str.size();
    int		b, i, j, k, J, x;
    int		cycleStart, cycleStop, *cycle = nullptr, *S_k = nullptr;
    int		stateX[8] = { -4, -3, -2, -1, 1, 2, 3, 4 };
    int		counter[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
    double	p_value, sum, constraint, nu[6][8];
    double	pi[5][6] = { {0.0000000000, 0.00000000000, 0.00000000000, 0.00000000000, 0.00000000000, 0.0000000000},
                           {0.5000000000, 0.25000000000, 0.12500000000, 0.06250000000, 0.03125000000, 0.0312500000},
                           {0.7500000000, 0.06250000000, 0.04687500000, 0.03515625000, 0.02636718750, 0.0791015625},
                           {0.8333333333, 0.02777777778, 0.02314814815, 0.01929012346, 0.01607510288, 0.0803755143},
                           {0.8750000000, 0.01562500000, 0.01367187500, 0.01196289063, 0.01046752930, 0.0732727051} };

    if ( ((S_k = (int *)calloc(n, sizeof(int))) == nullptr) ||
         ((cycle = (int *)calloc(MAX(1000, n/100), sizeof(int))) == nullptr) ) {
        if ( S_k != nullptr )
            free(S_k);
        if ( cycle != nullptr )
            free(cycle);
        return;
    }

    J = 0;
    S_k[0] = 2* int(str[0]) - 1;
    for( i=1; i<n; i++ ) {

        S_k[i] = S_k[i-1] + 2* int(str[i]) - 1;
        if ( S_k[i] == 0 ) {
            J++;
            if ( J > MAX(1000, n/100) ) {
                free(S_k);
                free(cycle);
                return;
            }
            cycle[J] = i;
        }
    }
    if ( S_k[n-1] != 0 )
        J++;
    cycle[J] = n;



        constraint = MAX(0.005*pow(n, 0.5), 500);

        cycleStart = 0;
        cycleStop  = cycle[1];
        for ( k=0; k<6; k++ )
            for ( i=0; i<8; i++ )
                nu[k][i] = 0.;
        for ( j=1; j<=J; j++ ) {
            for ( i=0; i<8; i++ )
                counter[i] = 0;
            for ( i=cycleStart; i<cycleStop; i++ ) {
                if ( (S_k[i] >= 1 && S_k[i] <= 4) || (S_k[i] >= -4 && S_k[i] <= -1) ) {
                    if ( S_k[i] < 0 )
                        b = 4;
                    else
                        b = 3;
                    counter[S_k[i]+b]++;
                }
            }
            cycleStart = cycle[j]+1;
            if ( j < J )
                cycleStop = cycle[j+1];

            for ( i=0; i<8; i++ ) {
                if ( (counter[i] >= 0) && (counter[i] <= 4) )
                    nu[counter[i]][i]++;
                else if ( counter[i] >= 5 )
                    nu[5][i]++;
            }
        }

        for ( i=0; i<8; i++ )
        {
            x = stateX[i];
            sum = 0.;
            for ( k=0; k<6; k++ )
                sum += pow(nu[k][i] - J*pi[(int)fabs(x)][k], 2) / (J*pi[(int)fabs(x)][k]);
            p_value = cephes_igamc(2.5, sum/2.0);

            if (p_value > 0.01) {
                cout << "Test passed P_value № " << i + 1 << ": " << p_value  << endl;
            }

            else
            {
                cout << "Test failed, P_value is less than 0.01" << endl;
            }

        }
    }

