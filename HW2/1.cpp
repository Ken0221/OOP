#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

class Fraction{
	int numer;
	int denom;
	int find_gcd(int,int);
  public:
	Fraction(){}
	Fraction(int n){numer = n, denom = 1;}
	Fraction(int n,int d){numer = n, denom = d;}
	void setNum(int);
	void setDen(int);
	int getNum();
	int getDen();
	Fraction operator + (const Fraction &fr);
	Fraction operator * (const Fraction &fr);
	Fraction operator - (const Fraction &fr);
	Fraction operator / (const Fraction &fr);
	void reduce_fraction(int*, int*);
	void print_fraction();
	void operator -= (const Fraction &fr);
	Fraction operator / (int n);
	friend Fraction operator * (int n, const Fraction &fr);
	friend istream& operator>>(istream &ist, Fraction &fr);
	friend ostream& operator<<(ostream &ost, Fraction &fr);
};

int main(){
	Fraction f1,f2(2),f3(3,4);
	f1.setNum(5);
	f1.setDen(6);
	printf("numer of f1: %d, denom of f1: %d\n",f1.getNum(),f1.getDen());

	printf("1st fraction: ");
	f1.print_fraction();
	printf("\n");

	printf("2nd fraction: ");
	f2.print_fraction();
	printf("\n");

	printf("3rd fraction: ");
	f3.print_fraction();
	printf("\n\n");

	// add
	printf("=== add ===\n");
	f1.print_fraction();
	printf(" + ");
	f2.print_fraction();
	f3 = f1+f2;
	printf(" = ");
	f3.print_fraction();
	printf("\n\n");

	// subtract
	printf("=== subtract ===\n");
	f1.print_fraction();
	printf(" - ");
	f2.print_fraction();
	f3 = f1-f2;
	printf(" = ");
	f3.print_fraction();
	printf("\n\n");

	// multiply
	printf("=== multiply ===\n");
	f1.print_fraction();
	printf(" * ");
	f2.print_fraction();
	f3 = f1*f2;
	printf(" = ");
	f3.print_fraction();
	printf("\n\n");

	// divide
	printf("=== divide ===\n");
	f1.print_fraction();
	printf(" / ");
	f2.print_fraction();
	f3 = f1/f2;
	printf(" = ");
	f3.print_fraction();
	printf("\n");
	printf("\n===============================\n");

	Fraction a1, a2, a3;
	int b, c;
	while(cout<<"input the num and den of a1,a2 and a3 by cin:"<<endl, cin>>a1>>a2>>a3){

		if((a1.getDen()==0) || (a2.getDen()==0) || (a3.getDen()==0)){
			cout << "error input" << endl << endl;
            continue;
        }
		cout << "==========" << endl;
		cout << "a1 = " << a1 << endl;
		cout << "a2 = " << a2 << endl;
		cout << "a3 = " << a3 << endl;

		cout << endl << "a3 -= a1 " << endl;
		a3 -= a1;
		cout << "a3 = " << a3 << endl;

		int b,c;
		cout << endl << "input two integers: ";
		cin>>b>>c;

		cout<< endl  << "a2 = a3 / b " << endl;
		a2 = a3/b;
		cout << a2 << " = " << a3 << " / " << b << endl;
		cout << endl << "a1 = c * a2" << endl;
		a1 = c*a2;
		cout << a1 << " = " << c << " * " << a2 << endl<<endl<<endl;

	}
	return 0;
}

void Fraction::setNum(int n){
    numer = n;
}

void Fraction::setDen(int d){
    denom = d;
}

int Fraction::getNum(){
    return numer;
}

int Fraction::getDen(){
    return denom;
}

Fraction Fraction::operator + (const Fraction &fr){
    int numer_t;
    int denom_t;
    int temp_d = denom;
    numer_t = numer * fr.denom + fr.numer * temp_d;
    denom_t = denom * fr.denom;   
    Fraction ans(numer_t, denom_t);
    ans.reduce_fraction(&ans.numer, &ans.denom);
    return ans;
}

Fraction Fraction::operator * (const Fraction &fr){
    Fraction ans(numer * fr.numer, denom * fr.denom);
    ans.reduce_fraction(&ans.numer, &ans.denom);
    return ans;
}

Fraction Fraction::operator - (const Fraction &fr){
    int numer_t;
    int denom_t;
    int temp_d = denom;
    numer_t = numer * fr.denom - fr.numer * temp_d;
    denom_t = denom * fr.denom;
    Fraction ans(numer_t, denom_t);
    ans.reduce_fraction(&ans.numer, &ans.denom);
    return ans;

}

Fraction Fraction::operator / (const Fraction &fr){
    Fraction ans(numer * fr.denom, denom * fr.numer);
    ans.reduce_fraction(&ans.numer, &ans.denom);
    return ans;

}
void Fraction::reduce_fraction(int* numer, int* denom){
    int b = *denom;
    int a = *numer;
    while(b != 0){
       int t = b;
       b = a % b;
       a = t;
    }
    *numer /= abs(a);
    *denom /= abs(a);
}

void Fraction::print_fraction(){
    if(denom == 1)
        cout << "(" << numer << ")";
    else
        cout << "(" << numer << "/" << denom << ")";
}

void Fraction::operator -= (const Fraction &fr){
    Fraction a = operator - (fr);
    numer = a.numer;
    denom = a.denom;
}

Fraction Fraction::operator / (int n){
    Fraction a(n);
    Fraction b;
    b = operator / (a);
    return b;
}

Fraction operator * (int n, const Fraction &fr){
    Fraction a(n);
    a = a * fr;
    return a;
}

istream& operator>>(istream &ist, Fraction &fr){
   ist >> fr.numer;
   ist >> fr.denom;
   return ist;
}
ostream& operator<<(ostream &ost, Fraction &fr){
    if(fr.denom == 1)
        ost << "(" << fr.numer << ")";
    else
        cout << "(" << fr.numer << "/" << fr.denom << ")";
    return ost;
}

