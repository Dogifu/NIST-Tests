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


using namespace std;


int main() {

    long size;
    string str;

    ifstream file ("/Users/user/Desktop/Aktiv Rutoken ECP 0 2023-07-21_16-02-23.dump", ios::in|ios::binary|ios::ate);
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



    // FIRST TEST //

     // Block(str);

     // FIRST TEST //



     // SECOND TEST //

     // Frequency(str, 100);

     // SECOND TEST //



     // THIRD TEST //

     // Runs(str);

     // THIRD TEST //




     // FOURTH TEST //

     // LongestRunOfOne(str);

     // FOURTH TEST //


     // 5 TEST //



     // 5 TEST //





     // SIXTH TEST //


     // DiscreteFourierTransform(str);

     // SIXTH TEST //


     // 7 TEST //

     // 7 TEST //


     // 8 TEST //

     // 8 TEST //


     // NINTH TEST //


    // Universal(str);

     // NINTH TEST //


     // 10 TEST //

     // LinearComplexity(550,str);

    // 10 TEST //


    // 11 TEST //


    // Serial(2,str);


    // 11 TEST //



    // 12 TEST //

    // ApproximateEntropy(1,str);

    // 12 TEST //



    // 13 TEST //



    // CumulativeSums(str);

    // 13 TEST //




    // 14 TEST //


    // RandomExcursions(str);



    // 14 TEST //



    // 15 TEST //


    // RandomExcursionsVariant(str);

    // 15 TEST //





}
