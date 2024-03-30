#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

template<class T1, class T2>
class Pair{
	private:
		T1 first;
		T2 second;

	public:
		Pair(const T1 f, const T2 s)
		{
			first = f;
			second = s;
		}

		T1 getFirst()
		{
			return first;
		}

		void setFirst(T1 f)
		{
			first = f;
		}

		T2 getSecond()
		{
			return second;
		}

		void setSecond(T2 s)
		{
			second = s;
		}

		void print()
		{
			cout << "(first, second)= " << "(" << first << ", " << second << ")";
		}
};

Pair<int, int> minmax(vector<int> &v)
{
	int min = v[0];
	int max = v[0];

	for(int i = 1;i < v.size(); i++)
	{
		if(v[i] < min)
		{
			min = v[i];
		}
		if(v[i] > max)
		{
			max = v[i];
		}
	}
	return Pair<int, int>(min, max);
}

int main()
{
	Pair<string, int> rating[4] = {
    	Pair<string, int>("The Old Man and the Sea", 5),
	    Pair<string, int>("Oscar Wilde's fairy tale world", 6),
	    Pair<string, int>("The Little Prince", 7),
	    Pair<string, int>("Dork Diaries", 10)
	};

	//step 2
	for(int i = 0; i < 4; i++)
	{
		cout << rating[i].getFirst() << ":" << rating[i].getSecond() << endl;
	}

	//step 3
	for(int i = 0; i < 4; i++)
	{
		rating[i].print();
		cout << endl;
	}
	cout << endl;

	//step 4
	cout << "rating[3] revised:" << endl;
	rating[3].setSecond(8);
	rating[3].print();
	cout << endl;

	//step 5
	int score[] = {92, 71, 82, 88, 52, 66, 72, 97};
	vector<int> mv(score, score + 8);

	//step 6
	Pair<int, int> p = minmax(mv);
	cout << "\nmin=" << p.getFirst() << ", max=" << p.getSecond() << endl;

	return 0;
}

