#include<iostream>
#include<vector>
using namespace std;

//step 1:
template <class t>
t larger(t a, t b)
{
	return (a > b)? a : b;
}

//step 2:
int* larger(int *a, int *b)
{
	return (*a > *b)? a : b;
}

//step 3:
template <class T>
T larger(const T a[], int size)
{
	T max = a[0];
	for(int i = 1;i < size; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

//step 4:
template <class T>
T larger(const vector<T> v)
{
	T max = v[0];
	for(int i = 1;i < v.size(); i++)
	{
		if(v[i] > max)
		{
			max = v[i];
		}
	}
	return max;
}

int main()
{
	cout << "larger=" << larger(10, 20) << endl;
	cout << "larger=" << larger(2.3, 4.5) << endl;
	cout << "larger=" << larger<int>(7.8, 5) << endl;
	cout << "larger=" << larger<double>(7.8, 5) << endl;

	int a = 5, b = 10;
	cout << "*larger=" << *larger(&a, &b) << endl;

	char text[] = "template type parameter";
	cout<< "larger=" << larger(text, 23) << endl;

	double d[] = {2.3, 4.5, -0.7, 9.6, 1.8, 0.2};
	vector<double> v = {1.2, 9.0, 11.2, 5.6, 19.7, 6.5, 18.3};
	cout << "Array largest=" << larger(d, 6) << endl;
	cout << "Vector largest=" << larger(v) << endl;

	return 0;
}

