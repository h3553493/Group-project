#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
//#include "interface.h"
using namespace std;

int interface_login(){
    cout<<setw(60)<<setfill('-')<<""<<endl;
    cout<<'|'<<setw(58)<<setfill(' ')<<""<<'|'<<endl;
    cout<<'|'<<setw(4)<<""<<"Welcome to the Grace Field House management system"<<setw(4)<<""<<'|'<<endl;
    cout<<'|'<<setw(58)<<""<<'|'<<endl;
    cout<<setw(60)<<setfill('-')<<""<<endl;
    while (true){
        cout<<"Please log in with your username and password"<<endl;
        string username, password;
        cout<<"Username: ";
        cin>>username;
        cout<<"Password: ";
        cin>>password;
        ifstream in("login.txt");
        string line;
        if (in.fail()){
            cout<<"Failed to access the database, please try again later"<<endl;
            exit(1);
        }
        while (getline(in, line)){
            istringstream iss(line);
            string cname, cpassword, access;
            iss>>cname>>cpassword>>access;
            if (username==cname && password==cpassword){
                cout<<"Log in success.\n"<<endl;
                cout<<"Welcome, "<<username<<".\t"<<"Current access level: "<<access<<".\n";
                in.close();
                if (access == "mama") return 1;
                if (access == "sister") return 0;
            }
        }
        cout<<"Username or password inccorect, please try again\n\n";
    }
}

void interface_welpage(int access){
    cout<<"\n1. read children details"<<endl;
    if (access==1){
        cout<<"2. child intake or shipment"<<endl;
        cout<<"3. import test score"<<endl;
    }
    else if (access==0){
        cout<<"2. child intake or shipment\t(mama only)"<<endl;
        cout<<"3. import test score\t\t(mama only)"<<endl;
    }
    cout<<"4. shipment notifications and ranking"<<endl;
    cout<<"What would you like to do? (1-4): ";
}

void  interface_info(){
    cout<<"Type in a name to see full score detail of a child; \"back\" to main page."<<endl;
}

void interface_addship(){
    cout<<"Input \"add\" to add a new child; \"ship\" to ship an existing child; \"back\" to main page."<<endl;
}

void interface_scoreimport(){
    cout<<"Input the full name of the file to be imported: ";
}

void  interface_rank(){
    cout<<"Input \"all\" to see the ranking of all children; \"back\" to main page."<<endl;
}

void interface_exit(){
    cout<<"You have successfully logged out, thanks for using Grace Field management system!"<<endl;
}
