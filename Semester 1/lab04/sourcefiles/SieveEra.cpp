#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

#include "SieveEra.h"

SieveEra::SieveEra(const string &out_filename)
{
    out_strm.open(out_filename.c_str());
    if (out_strm.fail())
    {
        cerr << "Error in class SieveEra: cannot open file." << endl;
    }    
}//SieveEra

SieveEra::~SieveEra()
{
    if (!out_strm.fail())
    {
        out_strm.close();
    }
}//~SieveEra

void SieveEra::generate(int n)
{
    assert(n > 0);

    vector<bool> sieve(n, true);
	sieve[0] = sieve[1] = false;
	int sroot = int(sqrt(n)) + 1;

	for (int i = 2; i < sroot; i++)
	{
		if (sieve[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				sieve[j] = false;
			}
		}
	}	

	for (int i = 2; i <= n; i++)
	{
		if (sieve[i])
		{
			out_strm << i << " ";
		}
	}
}//generate
