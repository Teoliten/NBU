#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> genVec(int numb)
{
    vector<int> result;
    result.resize(numb);//filling vector with random numbers
    for(int i = 0; i < numb; i++)
    {
        result[i] = rand() % 11; // 0 - 10;

    }
    
    return result;
}//genVec

void readVec(vector<int> vec)
{
    for(int i = 0; i < vec.size(); i++)//print vec.
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}//readVec

int minPos(vector<int> &vec, int i)//finding the smallest int, returning its position
{
    int min = i;
    for(i; i < vec.size(); i++) // vector = i x x x x x x x, 2nd time running = x i x x x x x x etc
    {
        if(vec[i] <= vec[min])
        {
            min = i;//updating the min as it searches through all the elements in vector.
        }
    }
    
    return min;
}

void swap(int &vec, int &vec2)//simple swap function
{
    int tmp = vec;
    vec = vec2;
    vec2 = tmp;
}

void sortVec(vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        int min_pos = minPos(vec, i);//find the position of the integer(that is the smallest) to be swapped with the current integer in pos i;
        if(min_pos != i)//checking if the smallest is itself
        {
            swap(vec[i], vec[min_pos]);// swapping the right two integers
            readVec(vec);//optional, just to see each swap in action.
        }
    }
}//sortVec

int main()
{
    srand(time(NULL));
    cout << "Numbers to be sorted: " << endl << ">";
    int numb;
    cin >> numb;

    vector<int> vec;
    vec = genVec(numb); //generate random numbers 0-10 for n integers
    readVec(vec); // print vector

    sortVec(vec); // sort vector smallest -> biggest
    //sortVec(vec);
    //readVec(vec);
    return 0;
}//main