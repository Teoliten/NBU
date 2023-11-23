#include <iostream>
#include <string>
#include <fstream>

using namespace std;

double readvrd(const string &in_file_name)
{
    double result = 0.0;
    double sum = 0.0;
    int numb = 0;

    //open file stream
    ifstream in_strm(in_file_name.c_str());

    if(!in_strm.fail())
    {
        double curr;
        in_strm >> curr;
        do
        {
            sum += curr;
            numb++;
            in_strm >> curr;
        }
        while(!in_strm.eof());
        result = sum / numb;

        in_strm.close();
        
    }
    else
    {
        cerr << "Cannot open input file: " << in_file_name << endl;
    }

    return result;
}

int main()
{
    cout << "Input file name: ";
    string in_file_name;
    cin >> in_file_name;

    double result = readvrd(in_file_name); 

    cout << "Mean value: " << result << endl; 
    return 0;
}