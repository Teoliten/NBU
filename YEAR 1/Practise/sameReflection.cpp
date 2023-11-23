#include <iostream>

using namespace std;

const int len = 20;

bool isSame(char name1[len], int size1, char name2[len], int size2)
{
    bool result = true;
    
    for(int i = 0; i < size1; i++)
    {
        if(name1[i] != name2[i])
        {
            result = false;
        }
    }
    return result;
}//isSame

void rotate(char name[len], int size)
{
    char tmp = '\0';
    tmp = name[0];
    for(int i = 0; i < len; i++)
    {
        name[i] = name[i + 1];
    }
    name[size - 1] = tmp;
}//rotate

int isSameReflection(char name1[len], int size1, char name2[len], int size2)
{
    bool isf = false;

    if(size1 != size2)
    {   
        cout << "Not same len." << endl;
        return -1; 
    }

    for(int i = 0; i < size1; i++)
    {
        rotate(name1, size1);
        isf = isSame(name1, size1, name2, size2);
        if(isf == true)
        {
            break;
        }
    }

    if(isf)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}//isSameReflection

int main()
{
    char name1[len];
    char name2[len];

    for(int i = 0; i < 20; i++)
    {
        name1[i] = '\0';
    }

    for(int i = 0; i < 20; i++)
    {
        name2[i] = '\0';
    }

    cin >> name1;
    cin >> name2;

    int size1 = 0;
    int size2 = 0;

    for(int i = 0; i < 20; i++)
    {
        if(name1[i] != '\0')
        {
            size1++;
        }
    }

    for(int i = 0; i < 20; i++)
    {
        if(name2[i] != '\0')
        {
            size2++;
        }
    }

    //cout << size1 << " " << size2 << endl;

    cout << isSameReflection(name1, size1, name2, size2) << endl;

    return 0;
}//main