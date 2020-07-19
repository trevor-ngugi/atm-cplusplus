#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;

void home();
void adminLogin();
void adminPage();
void adminReset();
void registerClient();
void userLogin();
void homePage();
void userReset();
void userBalance();


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
        userLogin();
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
        registerClient();
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
 void registerClient(){
     ofstream user("usersDB.txt");
     string clientname,clientpassword;
     int clientcash;
     cout<<"enter clients name";
     cin>>clientname;
     cout<<"enter client password";
     cin>>clientpassword;
     cout<<"enter amount registered";
     cin>>clientcash;

    
    user<<clientname<<"\n";
    user<<clientpassword<<"\n";
    user<<clientcash<<"\n";
    
    cin.clear();
    cout<<"succesfully added a user \n\n\n";
    user.close();
    adminPage(); 

 }

 string clientname,clientpassword,filename,filepassword;
 void userLogin(){
    ifstream credential;
    // look if path is correct
    credential.open("usersDB.txt");
    
    cout<<" welcome to client login page \n";
    cout<<" enter username : ";
    cin>>clientname;
    cout<<" enter password : ";
    cin>>clientpassword;

//    workiing login 
    getline(credential,filename);
    getline(credential,filepassword);
    if( clientname==filename && clientpassword==filepassword){
        homePage();
        
    }
    else{
        cout<<"nooo \n";
    }

    credential.close();
 }

 void homePage(){
     int choice;
     cout<<"welcome "<<clientname<< "\n";
     cout<<" 1. withdraw cash \n";
     cout<<" 2.check balamce \n";
     cout<<" 3.reset password \n";
     cout<<" enter option to continue \n";
     cin>>choice;

     if(choice==1){
         cout<<"you have chosen to withdraw cash \n";

     }
     else if(choice==2){
         userBalance();
     }
     else if(choice==3){
         userReset();
     }
     else{
         cout<<"wrong option choose again \n";
         homePage();
     }

 }

 void userReset(){
     // outputs code in another file not want i wanted
    ofstream outfile("userReset.txt");
    ifstream readfile("usersDB.txt");
    string oldpassword,newpassword,filepassword;

    cout<<"enter old password";
    cin>>oldpassword;

    while(getline(readfile,filepassword)){
        if(filepassword==oldpassword){
            cout<<"enter new password \n";
            cin>>newpassword;
            outfile<< "\n"<<newpassword<<"\n";
            cout<<"succesfully changed password \n";
        }
        else{
            outfile<<filepassword;
        }  
    }
 }

 void userBalance(){
    string name,secret;
    string cash;
    ifstream credential;
    // look if path is correct
    credential.open("usersDB.txt");
    
    

//    workiing login 
    getline(credential,name);
    getline(credential,secret);
    getline(credential,cash);
    cout<<cash<<"\n";

    credential.close();

 }



