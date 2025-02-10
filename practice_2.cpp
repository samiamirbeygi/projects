//برنامه ای که عددی از ورودی دریافت بکند و فاکتوریل آن را حساب کند 
#include<iostream>
using namespace std ;
int main() {
int number ;
long int fact= 1 ;
cout<<"please inter your number "<<endl ;
cout<<"number = " ;
while(true){
cin>>number ;
if(cin.fail()){
cout<<"the input is invalid " <<endl ;
cin.clear() ;
cin.ignore(1000 ,'\n') ;

}
else {

break;

}

}
for(int i = number ; i>1 ; i-- ){

fact *= i ;
}

cout<<"fact is "<<fact ;

}