#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template<typename T>

T sum_all ( vector<T> &v)
{
    T result= v[0];
    for(int i= 1; i<v.size();i++)
    {
        result+=v[i];
    }
   return result;
}

template<typename T>

T sum_all (const T &t)    
{  
    return t;    
}

string sum_all ( vector<char> &v)
{
    stringstream res;
    for(auto i:v)
    {
        res<<i;
       
    }
    return res.str();
}

int main()
{
    vector<int> v1= {1, 2, 3};
    vector<double> v2= {1, 2, 3};
    vector<string> v3= {"a", "bc", "def"};
    vector<char> v4= {'a', 'b', 'c'};
    
    cout << sum_all(5) << endl;
    cout << sum_all(3.0) << endl;
    cout << sum_all(v1) << endl;
    cout << sum_all(v2) << endl;
    cout << sum_all(v3) << endl;
    cout << sum_all(v4) << endl;
    
    return 0;
}
