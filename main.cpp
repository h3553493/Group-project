#include <iostream>
#include <string>
#include "interface.h"
#include "child.h"
#include "score.h"
#include "rank.h"
using namespace std;

//bookmarks are the functions to be implemented

int main(){
    int access=-1;
    //access: -1 initialize, 0 for sister, 1 for mama
    access=interface_login();
    interface_welpage(access);
    //up to now the user have successfully logged in and is seeing the welcoming page

    string command="";
    cin>>command;
    while (command != "exit"){

        switch (command){

            //1. read child info
            case '1':
                //show the basic info of all child
                child_info();

                //show options in the read child info page and prompt the user to input a child name or back
                interface_info();
                string cmd1="";
                cin>>cmd1;
                while (cmd1 != "back"){
                    //type in a name to see full details, this would implicitly call a function in score.h!!!!
                    child_detail(cmd1);
                    interface_info();
                    cin>>cmd1;
                }

                break;


            //2. add/shipment
            case '2':
                if (access){
                    //give three options: add or shipment or back
                    interface_addship();
                    string cmd2="";
                    cin>>cmd2;
                    while (cmd2 != "back"){
                        //ask the user of the name, age, code, sex of the child to be added and alter the allchild.txt, crate childname.txt
                        if (cmd2 == "add")      child_add();

                        //ask the user name of the child to be shipped, another yes/no to double check
                        else if (cmd == "shipment")     child_ship();

                        else:   cout<<"Sorry, wrong command."<<endl;

                        interface_addship();
                        cin>>cmd2;
                    }
                }
                else cout<<"Sorry, no access."<<endl;

                break;


            //3. import test score
            case '3':
                if (access){
                    //ask the use to input the name of the file storing the score to be import
                    interface_import();
                    string cmd3="";
                    cin>>cmd3;
                    while (cmd3 != "back"){
                        //could first assume the files are of legal format, can later alter the program to create intermediate files while importing, show a error alert when error detected in the file and return to the state before importing
                        //remember to auto upgrade the age!
                        score_import();
                        cin>>cmd3;
                    }
                }
                else cout<<"Sorry, no access."<<endl;

                break;


            //4. ranking and notifications
            case '4':
                //show notification: the child needs to be shipped immediately
                rank_notif();

                //ask the user to input "all" or "back"
                interface_rank();
                string cmd4="";
                cin>>cmd4;
                while (cmd4 != "back"){
                    //show all child sorted by ranking
                    if (cmd4 == "all")      ank_all();

                    else:       cout<<"Sorry, wrong command."<<endl;

                    interface_rank();
                    cin>>cmd4;
                }
                break;


            //wrong command
            default:
                cout<<"Sorry wrong command."<<endl;
        }

        //back to the welcome page and input new command
        interface_welpage(access);
        cin>>command;
    }

    //user have choose to exit the program
    interface_exit();
}
