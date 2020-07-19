#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;

void home();
void adminLogin();
void adminPage();
void adminReset();


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
// global variable for admin name and admin login
string username ,password,adminName,login;
void adminLogin(){
   // string username ,password,name,login;
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
    getline(credentials,adminName);
    getline(credentials,login);
    if( username == adminName && password==login){
        adminPage();
        
    }
    else{
        cout<<"nooo \n";
    }

    credentials.close();
}

void adminPage(){
    int choice;
    cout<<" Welcome "<<adminName<<"\n";
    cout<<" 1. deposit money for client \n ";
    cout<<" 2. register new client \n";
    cout<<" 3. reset password \n\n";
    cout<<" enter option to proceed \n";

    cin>>choice;
    if(choice==1){
        // function deposit money for client
        cout<<"deposit cash function \n";
        adminPage();

    }
    else if(choice==2){
        cout<<"register client function \n";
        adminPage();
    }
    else if(choice==3){
        adminReset();
    }
    else{
        cout<<"wrong choice \n";
        adminPage();
    }
    
}

void adminReset(){

    //  works but doesnt overwirite the main file
    // ostringstream text;
    // ifstream readfile("admin.txt");
    // text<<readfile.rdbuf();
    // string str=text.str();
    // string str_found="admin123";
    // string str_replace="changed password";
    // size_t pos=str.find(str_found);
    // str.replace(pos, string(str_found).length(), str_replace);
    // readfile.close();

    // ofstream out_file("text.txt");
    // out_file << str; 




   // outputs code in another file not want i wanted
    ofstream outfile("temp.txt");
    ifstream readfile("admin.txt");
    string oldpassword,newpassword,filepassword;

    cout<<"enter old password";
    cin>>oldpassword;

    while(getline(readfile,filepassword)){
        if(filepassword==oldpassword){
            //outfile<<filepassword<<"\n";
            

            cout<<"enter new password \n";
            cin>>newpassword;
            outfile<< "\n"<<newpassword;
            cout<<"succesfully changed password \n";
            //adminPage();
        }
        else{
            outfile<<filepassword;
        }  
    }
}




