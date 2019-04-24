#include <iostream>
#include <string>
#include "interface.h"
using namespace std;


int main(){
    int access=-1;
    access=interface_login();
    interface_welpage(access);
    //up to now the user have successfully logged in and is seeing the welcoming page

    string command="";
    cin>>command;
    while (command != "quit"){
        //1. read child info
        if (command=="1"){
            child.showall();
            interface_showall();
            string cmd1="";
            cin>>cmd1;
            if (cmd=="quit") continue;
        }
        //2. add/shipment
        else if(command == "2") continue;
        //3. import test score
        else if(command == "3") continue;
        //4. ranking and notifications
        else if(command == "4") continue;

        //back to the welcome page and input new command
        interface_welpage();
        cin>>command;
    }

    //user have choose to exit the program
    interface_quit();
}
