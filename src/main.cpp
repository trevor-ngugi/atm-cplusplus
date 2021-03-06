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
    cout<<" 1. Normal user login \n";
    cout<<" 2. Administrator login \n \n";
    cout<<" Choose an option to proceed : "; 
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
    cout<<"\n";
    cout<<"-------------------------------------------------- \n";
    cout<<" Welcome to Registration and Deposit page \n";
    cout<<" Enter administrator  username and password. \n";
    cout<<" Enter username : ";
    cin>>username;
    cout<<" Enter password : ";
    cin>>password;

//    workiing login 
    getline(credentials,adminName);
    getline(credentials,login);
    if( username == adminName && password==login){
        adminPage();
        
    }
    else{
        cout<<" Wrong username or password \n";
        adminLogin();
    }

    credentials.close();
}

void adminPage(){
    int choice;
    cout<<"\n";
    cout<<"-------------------------------------------------- \n";
    cout<<" Welcome "<<adminName<<"\n";
    cout<<" 1. Deposit money for client \n ";
    cout<<"2. Register new client \n";
    cout<<" 3. Reset password \n";
    cout<<" 4. Logout \n\n";
    cout<<" Enter option to proceed :";

    cin>>choice;
    if(choice==1){
        // function deposit money for client
        cout<<"deposit cash function \n";
        adminPage();

    }
    else if(choice==2){
        registerClient();
    }
    else if(choice==3){
        adminReset();
    }
    else if(choice==4){
        home();
    }
    else{
        cout<<" Wrong input please try again \n";
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

    cout<<" Enter old password : ";
    cin>>oldpassword;

    while(getline(readfile,filepassword)){
        if(filepassword==oldpassword){
            cout<<" Enter new password : ";
            cin>>newpassword;
            outfile<< "\n"<<newpassword;
            cout<<" succesfully changed password \n";
        }
        else{
            outfile<<filepassword;
        }  
    }
    outfile.close();
    readfile.close();
    adminPage();
}

 void registerClient(){
     ofstream user("usersDB.txt");
     string clientname,clientpassword;
     int clientcash;

    cout<<"\n";
    cout<<"-------------------------------------------------- \n";
    cout<<" Enter clients name : ";
    cin>>clientname;
    cout<<" Enter client password : ";
    cin>>clientpassword;
    cout<<" Enter amount registered : ";
    cin>>clientcash;

    
    user<<clientname<<"\n";
    user<<clientpassword<<"\n";
    user<<clientcash<<"\n";
    
    cin.clear();
    cout<<" Succesfully added a user !!! \n\n\n";
    user.close();
    adminPage(); 

 }

 string clientname,clientpassword,filename,filepassword;
 void userLogin(){
    ifstream credential;
    // look if path is correct
    credential.open("usersDB.txt");
    cout<<"\n";
    cout<<"------------------------------------- \n";
    cout<<" Welcome to client login page : \n\n";
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
        cout<<" Wrong username or password input please try again \n";
        userLogin();
    }

    credential.close();
 }

 void homePage(){
     int choice;
     cout<<"\n";
     cout<<"------------------------------------- \n";
     cout<<" Welcome "<<clientname<< "\n";
     cout<<" 1. Withdraw cash \n";
     cout<<" 2. Check balance \n";
     cout<<" 3. Reset password \n ";
     cout<<"4. Logout \n\n";
     cout<<" enter option to continue : ";
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
     else if(choice==4){
         home();
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

    cout<<"\n";
    cout<<" enter old password : ";
    cin>>oldpassword;

    while(getline(readfile,filepassword)){
        if(filepassword==oldpassword){
            cout<<" enter new password : ";
            cin>>newpassword;
            outfile<< "\n"<<newpassword<<"\n";
            cout<<" succesfully changed password \n \n\n\n";
        }
        else{
            // validation imekataa
            outfile<<filepassword;
            // cout<<"wrong pasword \n";
            // homePage();
            // outfile.close();
            // readfile.close();
        }  
    }
    outfile.close();
    readfile.close();
    homePage();
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
    cout<<" your amount in the account : "<<cash<<"\n";
    homePage();

    credential.close();

 }



