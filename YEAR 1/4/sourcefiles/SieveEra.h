#ifndef SIEVEERA_H
#define SIEVEERA_H

#include <string>
#include <fstream>

using namespace std;

class SieveEra
{
    public:
        SieveEra(const string &out_filename);
        ~SieveEra();
        void generate(int n);

    private:
        ofstream out_strm;       
};

#endif
