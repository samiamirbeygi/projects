//برنامه‌ای بنویسید که با استفاده از مفهوم ساختار، اطلاعات چند  دانشجو را از ورودی دریافت کند و همان اطلاعات را در خروجی چاپ کند.
#include<iostream>
using namespace std ;
int main() {
struct date{ int year ; int month ; int day ;} ;
struct student{int age ; int number ; string name ; date birthday;};
student mosh ;
cout<<"please inter your age :" ;
cin>>mosh.age ;
cout<<"please inter your birthday :" ;
cout<<"day =" ;
cin>>mosh.birthday.day ;
cout<<"month = " ;
cin>>mosh.birthday.month ;
cout<<"year = " ;
cin>>mosh.birthday.year ;
cout<<"please inter your name :" ;
cin>>mosh.name ;
cout<<"please inter your number :" ;
cin>>mosh.number ;
cout<<"age is " <<mosh.age <<endl;
cout<<"***********************" <<endl;
cout<<"number is "<<mosh.number <<endl;
cout<<"***********************"<<endl ;
cout<<"name is "<<mosh.name<<endl ;
cout<<"***********************"<<endl ;
cout<<"your birthday :"<<" "<<mosh.birthday.year<<" "<<'/'<<" "<<mosh.birthday.month<<" "<<'/'<<" "<<mosh.birthday.day ;

}