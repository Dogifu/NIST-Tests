#include <vector>
#include <istream>
#include <fstream>
#include "Block.cpp"
#include "Frequency Test.cpp"
#include "RunsTest.cpp"
#include "LongestRunofOnesTest.cpp"
#include "SpectralTest.cpp"
#include "Mauers.cpp"
#include "LinearTest.cpp"
#include "SerialTest.cpp"
#include "ApproximateEntropyTest.cpp"
#include "cusum.cpp"
#include "RandomExcursionTest.cpp"
#include "RandomVariantTest.cpp"
#include "Overlap_Test.cpp"

using namespace std;


int main() {

    long size;
    string str;

    string file_name;


  /*  if (argc == 1)
    {
        cout << "NIST TESTS " << endl;
        cout << "File_path indicate in argv[1]" << endl;
        cout << "There are 13 tests " << endl <<
        "1: Frequency (Monobits) Test" << endl << "2: Test For Frequency Within A Block"
        << endl << "3: Runs Test" << endl << "4: Test For The Longest Run Of Ones In A Block"
        << endl << "5: Random Binary Matrix Rank Test" << endl << "6: Discrete Fourier Transform (Spectral) Test"
        << endl << "7: Non-Overlapping (Aperiodic) Template Matching Test" << endl <<
        "8: Overlapping (Periodic) Template Matching Test" << endl << "9: Maurer's Universal Statistical Test"
        << endl << "10: Linear Complexity Test" << endl << "11: Serial Test"
        << endl << "12: Approximate Entropy Test" << endl << "13: Cumulative Sum (Cusum) Test"
        << endl << "14: Random Excursions Test" << endl << "15: Random Excursions Variant Test" << endl;
    }

     if(argc > 1)

    {

        file_name = argv[1];

    } */


    ifstream file (file_name, ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        size = file.tellg();
        char * contensts = new char[size];
        file.seekg(0,ios::beg);
        file.read(contensts, size);
        file.close();

        for(int i = 0; i < size; i++)
        {
           str +=  bitset<8>(contensts[i]).to_string();

        }
        delete [] contensts;
    }


    /* // 1 TEST //
     cout << "/////////////////////////////////" << endl;
     cout << "Frequency (Monobits) Test" << endl;
    // Block(str);
     cout << "/////////////////////////////////" << endl;
     cout << endl;
     // 1 TEST //

    // 2 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Test For Frequency Within A Block" << endl;
  //  Frequency(str, 100);
    cout << "/////////////////////////////////" << endl;
    cout << endl;
    // 2 TEST //

    // 3 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Runs Test" << endl;
  //  Runs(str);
    cout << "/////////////////////////////////" << endl;
    cout << endl;
    // 3 TEST //

    //4 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Test For The Longest Run Of Ones In A Block" << endl;
  //  LongestRunOfOne(str);
    cout << "/////////////////////////////////" << endl;
    // 4 TEST //


     // 5 TEST //

     // 5 TEST //

    // 6 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Discrete Fourier Transform (Spectral) Test" << endl;
  //  DiscreteFourierTransform(str);
    cout << "/////////////////////////////////" << endl;
    // 6 TEST //


     // 7 TEST //

     // 7 TEST //

     // 8 TEST //
     cout << "/////////////////////////////////" << endl;
     cout << "Overlapping Template Matching Test" << endl;
    // OverlappingTemplateMatchings("11111",str);
     cout << "/////////////////////////////////" << endl;
     // 8 TEST //

    // 9 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Maurer's Universal Statistical Test" << endl;
  //  Universal(str);
    cout << "/////////////////////////////////" << endl;
    // 9 TEST //

    // 10 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Linear Complexity Test" << endl;
   // LinearComplexity(550,str);
    cout << "/////////////////////////////////" << endl;
    // 10 TEST //


    // 11 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Serial Test" << endl;
   // Serial(2,str);
    cout << "/////////////////////////////////" << endl;
    // 11 TEST //



    // 12 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Approximate Entropy Test" << endl;
   // ApproximateEntropy(1,str);
    cout << "/////////////////////////////////" << endl;
    // 12 TEST //



    // 13 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Cumulative Sum (Cusum) Test" << endl;
   // CumulativeSums(str);
    cout << "/////////////////////////////////" << endl;
    // 13 TEST //




    // 14 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Random Excursions Test" << endl;
  //  RandomExcursions(str);
    cout << "/////////////////////////////////" << endl;
    // 14 TEST //



    // 15 TEST //
    cout << "/////////////////////////////////" << endl;
    cout << "Random Excursions Variant Test" << endl;
  //  RandomExcursionsVariant(str);
    cout << "/////////////////////////////////" << endl;
    // 15 TEST // */

}
