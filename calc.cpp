#include<iostream>
using namespace std;
int main(){
   
    cout<<"|-----------SIMPLE CALCULATOR-----------|"<<endl<<endl<<endl;
    
    char op;
    float num1;
    float num2;
    cout<<"Enter the first number :"<<endl;
    cin>>num1;
    cout<<"Enter the operation you wnat to perform :"<<endl;
    cin>>op;
    cout<<"Enter the second number :"<<endl;
    cin>>num2;
    float result;
    switch (op)
    {
    case '+':
        result=num1+num2;
        cout<<"SUM IS :"<<result<<endl;
        break;
    case '-':
        result=num1-num2;
          cout<<"DIFFERANCE IS :"<<result<<endl;
        break;
    case '*':
        result=num1*num2;
         cout<<"PRODUCT IS :"<<result<<endl;
        break;
    case '/':
    if(num1==0 || num2==0){
        cout<<"Zero is not allowed,we can't any number by zero !"<<endl;
        return -1;
    }
    else{
        result=num1/num2;
         cout<<"DIVISION IS :"<<result<<endl;
        break;
    }
    case '%':
        result=int(num1)%int(num2);
          cout<<"REMAINDER IS :"<<result<<endl;
        break;
    
    default:
    cout<<"Invalid !"<<endl;
        break;
    }
    cout<<"THANK YOU !!!";
    return 0;
}