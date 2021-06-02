#include <iostream>
#include <vector>


using namespace std;
/*
Below the arr must be passed by reference as array decay to pointer so template argument deduction cant' occur
passing an array by reference , array decaying to pointer doesn't occur
*/

template<typename T, unsigned int N>
void rotLeft(T (&arr)[N], int d)  // void rotLeft(T arr[N], int d) not allowed 
{
	int v = d % N;
	while (v != 0)
	{
		T first = arr[0];
		for (int i{ 1 }; i < N; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[N - 1] = first;
		v--;
	}

}

using arr_type = char[5];
void Bar(arr_type& code)
{
	for (char c : code)
	{
		cout << c << ' '; 
	}
}

template<typename _Ret, typename _Coll>
_Ret Sum(const _Coll& c)
{
	_Ret sum = 0;
	for (auto& v : c)
	{
		sum += v;
	}
	return sum;
}


template <std::size_t N>
struct type_of_size
{
	typedef char type[N]; // type is alias for char[N]
};

template <typename T, std::size_t Size>
typename type_of_size<Size>::type& sizeof_array_helper(T(&)[Size]); //dependentname, typename indicates  a type
#define sizeof_array(pArray) sizeof(sizeof_array_helper(pArray)) //size of char = 1; 


int main()
{
	int arr[] = { 1,2,3,4,5 };
	vector<int> v = { 1,2,3,4,5 };
	rotLeft(arr, 3);

	cout << Sum<int>(arr) << endl; // template parameter deducing;
	cout << Sum<int, vector<int>>(v) << endl;

	cout << sizeof_array(arr) << ' '; 

	return 0;
}

//https://www.nextptr.com/question/a6212599/passing-cplusplus-arrays-to-function-by-reference
//https://stackoverflow.com/questions/30185582/c-could-not-deduce-template-argument
//https://stackoverflow.com/questions/3368883/how-does-this-size-of-array-template-function-work