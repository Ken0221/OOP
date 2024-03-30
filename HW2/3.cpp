#include <iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

typedef unsigned short ushort;

class Time{
    ushort hour;
    ushort min;
    ushort sec;
    unsigned int toSeconds() const;
    Time(int);

public:
    void setHour(ushort);
    void setMin(ushort);
    void setSec(ushort);
    Time(ushort = 0, ushort = 0, ushort = 0);
    void setTime(ushort, ushort, ushort);
    ushort getHour();
    ushort getMin();
    ushort getSec();
    void getTime(ushort&, ushort&, ushort&);
    void printUniversal() const;
    void printStandard() const;
    void addHourbyOne();
    void addMinbyOne();
    void addSecbyOne();
    Time operator + (const Time&) const;
    Time operator - (const Time&) const;
    bool operator == (const Time&) const;
    friend istream & operator >> (istream &, Time &);
    friend ostream & operator << (ostream &onst, const Time &t); 
};  

int main()
{
  Time myTime; 
  Time yourTime;
  Time dif, sum;
  ushort h, m, s;
  myTime.setTime(5, 4, 32);
  myTime.printUniversal();
  myTime.printStandard();
  cout << myTime;
  yourTime.setTime(3, 2, 29);
  cout << yourTime;
  dif = yourTime - myTime;
  cout << "The difference of the two time:" << endl;
  cout << dif;
  sum = myTime + yourTime;
  cout << "The summation of the two time:" << endl;
  cout << sum;
  if(myTime == yourTime) 
    cout << "The two Times is Equal\n";
  else
    cout << "The two Times is NOT Equal\n\n";
  yourTime.addHourbyOne();
  cout << yourTime;
  yourTime.addMinbyOne();
  cout << yourTime;
  yourTime.addSecbyOne();
  cout << yourTime;
  yourTime.getTime(h,m,s);
  cout << "The Hour is " << h << " The Min is " << m << " The sec is " << s << endl;
  Time t;
  while(cin >> t)
    cout << t;

  return 0;
}

unsigned int Time::toSeconds() const{
    int s = 0;
    s += sec;
    s += min * 60;
    s += hour * 60 * 60;
    return s;

}  // return time in seconds

Time::Time(int s){
    setHour(s / (60 * 60));
    setMin((s % (60 * 60)) / 60);
    setSec(s % 60);
}         //private constructor:convert seconds to Time object

Time::Time(ushort h, ushort m, ushort s)
{
    setHour(h);
    setMin(m);
    setSec(s);
}

void Time::setHour(ushort h){
    hour = (23 >= h && h >= 0)? h : 0;
}     //set hour after validation

void Time::setMin(ushort m){
    min = (59 >= m && m >= 0) ? m : 0;
}      //set min after validation

void Time::setSec(ushort s){
    sec = (59 >= s && s >= 0) ? s : 0;
}      //set secr after validation

void Time::setTime(ushort h, ushort m, ushort s){
    setHour(h);
    setMin(m);
    setSec(s);
}//set hour, min, sec

ushort Time::getHour(){
    return hour;
}                   // return hour

ushort Time::getMin(){
    return min;
}                    // return min

ushort Time::getSec(){
    return sec;
}                    // return sec

void Time::getTime(ushort &h, ushort &m, ushort &s){
    h = hour;
    m = min;
    s = sec;
}  // return hour, min, sec 

void Time::printUniversal() const{
    cout << "The universal format:";
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec << endl;
} // HH:MM:SS

void Time::printStandard() const{
    cout << "The standard format:";
    cout << ((hour == 0 || hour == 12)? 12 : hour % 12) << ":" << setfill('0') << setw(2) << min << ":" << setw(2) << sec << ((hour < 12)? " AM" : " PM") << endl;

}// HH:MM:SS AM or HH:MM:SS PM

void Time::addHourbyOne(){
    setHour(hour + 1);
}

void Time::addMinbyOne(){
    setMin(min + 1);
    if(min == 0)
        addMinbyOne();
}

void Time::addSecbyOne(){
    setSec(sec + 1);
    if(sec == 0)
        addMinbyOne();
}

Time Time::operator + (const Time &t) const{
    int s = toSeconds() + t.toSeconds();
    Time Sum(s);
    return Sum;
} //return the summation of Time object.
    /*1.all the two Times call toSeconds() first 
	  2.calculate the sum of seconds 
	  3.then return the private constructor of the summation.*/

Time Time::operator - (const Time &t) const{
    int d = toSeconds() - t.toSeconds();
    Time Diff(abs(d));
    return Diff;
} //return the difference(positive) of Time object.
    /*1.all the two Times call toSeconds() first 
	  2.calculate the difference of seconds(make sure positive!!!) 
	  3.then return the private constructor of the difference.*/
    
bool Time::operator == (const Time &t) const{
    return (toSeconds() == t.toSeconds())? true : false;
}

istream & operator >> (istream &inst, Time &t){
    cout << "\nPlease Enter hour, min, sec:";
    inst >> t.hour >> t.min >> t.sec;
    t.setHour(t.hour);
    t.setMin(t.min);
    t.setSec(t.sec);
    return inst;
}

ostream & operator << (ostream &onst, const Time &t){
    onst << "The universal format:" << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.min << ":" << setw(2) << t.sec;
    onst << "  The standard format:" << setfill('0') << ((t.hour == 0 || t.hour == 12)? 12 : t.hour % 12) << ":" << setw(2) << t.min << ":" << setw(2) << t.sec << ((t.hour < 12)? " AM" : " PM") << endl << endl;
    return onst;
}
