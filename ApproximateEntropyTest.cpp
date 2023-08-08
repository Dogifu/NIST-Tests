#include <iostream>

using namespace std;

void ApproximateEntropy(int m, string str)
{
    int n = str.size();
    int				i, j, k, r, blockSize, seqLength, powLen, index;
    double			sum, numOfBlocks, ApEn[2], apen, chi_squared, p_value;
    unsigned int	*P;



    seqLength = n;
    r = 0;

    for ( blockSize=m; blockSize<=m+1; blockSize++ ) {
        if ( blockSize == 0 ) {
            ApEn[0] = 0.00;
            r++;
        }
        else {
            numOfBlocks = (double)seqLength;
            powLen = (int)pow(2, blockSize+1)-1;
            if ( (P = (unsigned int*)calloc(powLen,sizeof(unsigned int)))== nullptr ) {

                return;
            }
            for ( i=1; i<powLen-1; i++ )
                P[i] = 0;
            for ( i=0; i<numOfBlocks; i++ ) {
                k = 1;
                for ( j=0; j<blockSize; j++ ) {
                    k <<= 1;

                    if ( int(str[(i+j) % seqLength]) == '1' )
                        k++;
                }
                P[k-1]++;
            }

            sum = 0.0;
            index = (int)pow(2, blockSize)-1;
            for ( i=0; i<(int)pow(2, blockSize); i++ ) {
                if ( P[index] > 0 )
                    sum += P[index]*log(P[index]/numOfBlocks);
                index++;
            }
            sum /= numOfBlocks;
            ApEn[r] = sum;
            r++;
            free(P);
        }
    }
    apen = ApEn[0] - ApEn[1];

    chi_squared = 2.0*seqLength*(log(2) - apen);
    p_value = cephes_igamc(pow(2, m-1), chi_squared/2.0);

    if (p_value > 0.01) {
        cout << "Test passed P_value: " << p_value;
    }

    else
    {
        cout << "Test failed, P_value is less than 0.01" << endl;
    }



    }



