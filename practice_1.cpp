#include<iostream>
//را محاسبه ونمایش دهد nرا در یافت کند و مجموع اعداد 1 تا n برنامه ای بنویسید که عدد 
using namespace std ;
int main() {
int n ;
int sum = 0 ;
cout<<"please inter your number "<<endl ;
cout<<"number = " ;
cin>>n ;
for(int i = 1 ; i<=n ; i++ ){
sum+=i ;
}
cout<<"sum is "<<sum ;

}