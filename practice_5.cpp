
//برنامه ای که از ورودی اطلاعات ده دانشجو را دریافت میکند 
//اطلاعات دانشجویی که بیشترین معدل را دارد چاپ میکند
//به مسن ترین دانشجوی کلاس یک نمره اضافه میکند
#include<iostream>
using namespace std ;
struct student{float avg ; double number ; string name ; int age; } ;
int main() {
student array[10] ;
for(int i=0 ; i<10 ; i++){
cout<<"please inter student name"<<i+1<<" : " ;
cin>>array[i].name ;
cout<<"please inter student avg" <<i+1<<" : " ;
cin>>array[i].avg ;
cout<<"please inter student  number "<<i+1<<" : " ;
cin>>array[i].number ;
cout<<"please inter student  age "<<i+1<<" : " ;
cin>>array[i].age ;
}
int stu ;
int max = array[0].avg ;
for(int i =1 ; i<10 ; i++){
if (array[i].avg > max ){
    max=array[i].avg ;
    stu=i ;
}

}
int big_age = array[0].age ;
int astu ;
for(int i =1 ; i<10 ; i++){
    if (array[i].age > big_age ){
        big_age =array[i].age ;
       astu = i  ;
    }
    
    }
    

cout<<"information about the student with the highest GPA :" <<endl;
cout<<"************************" <<endl;
cout<<"student name :";
cout<<array[stu].name<<endl;
cout<<"************************"<<endl ;
cout<<"student number :" ;
cout<<array[stu].number<<endl ;
cout<<"************************"<<endl ;
cout<<"student avg :" ;
cout<<array[stu].avg<<endl ;
cout<<"************************"<<endl ;
cout<<"student age :" ;
cout<<array[stu].age<<endl ;



cout<<"#######################################################################"<<endl ;
cout<<"we add one grade to the grade point average of the oldest student :"<<endl ;

cout<<"information about the student with the highest age :" <<endl;
cout<<"************************" <<endl;
cout<<"student name :";
cout<<array[astu].name<<endl;
cout<<"************************"<<endl ;
cout<<"student number :" ;
cout<<array[astu].number<<endl ;
cout<<"************************"<<endl ;
cout<<"student avg :" ;
cout<<array[astu].avg + 1<<endl ;
cout<<"************************"<<endl ;
cout<<"student age :" ;
cout<<array[astu].age<<endl ;


}
