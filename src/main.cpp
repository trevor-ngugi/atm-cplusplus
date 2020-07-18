#include<iostream>
#include <fstream>
using namespace std;

void home();
void adminLogin();
void adminPage();

int main(){

    home();

    return 0;
}

void home(){
    int choice;

    cout<<"**** WELCOME TO BBIT2020 E-CASH SERVICES ****\n";
    cout<<" 1. normal user login \n";
    cout<<" 2. administrator login \n \n";
    cout<<" choose an option to proceed : "; 
    cin >> choice;

    if (choice==1){
        // normal user login
        cout<<"user login \n";
    }
    else if(choice==2){
        adminLogin();
    }
    else{
        cout<<" wrong option choose 1 or 2 \n";
        home();
    }
}

void adminLogin(){
    string username ,password,name,login;
    // to read from files
    ifstream credentials;
    // look if path is correct
    credentials.open("admin.txt");
    
    cout<<" welcome to registration and deposit page \n";
    cout<<" enter administrator  username and password \n";
    cout<<" enter username : ";
    cin>>username;
    cout<<" enter password : ";
    cin>>password;

//    workiing login 
    getline(credentials,name);
    getline(credentials,login);
    if( username == name && password==login){
        cout<<"yess \n";
    }
    else{
        cout<<"nooo \n";
    }

    credentials.close();
}

