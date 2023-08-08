#include <iostream>
#include "Cephes.cpp"

using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
double Frequency( string& st, int M)

{


     int n = st.size(), N, i, j;
     double p_value, blockSum, pi, v, chi_squared, sum = 0 ;
     N = n/M;


    for ( i=0; i<N; i++ ) {
        blockSum = 0;
        for ( j=0; j<M; j++ )
            if (st[j+ i*M] == '1')
            blockSum ++;
        pi = (double)blockSum/(double)M;
        v = pi - 0.5;
        sum += v*v;
    }
      chi_squared = 4.0 * M * sum;
      p_value = cephes_igamc(N/2.0, chi_squared/2.0);
      cout << endl;

      cout << "The Lenght of blocks is: " << M << endl;

      if (p_value > 0.01) {
          cout << "Test passed P_value: " << p_value;
      }

      else
      {
          cout << "Test failed, P_value is less than 0.01" << endl;
      }
      return p_value;

}
#pragma clang diagnostic pop