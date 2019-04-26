#include <iostream>
#include <string>
#include "interface.h"
#include "child.h"
#include "score.h"
#include "rank.h"
#include "age.h"
using namespace std;


int main(){
    int access=-1;
    //access: -1 initialize, 0 for sister, 1 for mama
    access=interface_login();
    interface_welpage(access);
    //up to now the user have successfully logged in and is seeing the welcoming page

    string command="";
    cin>>command;
    while (command != "5"){

        //1. read child info
        if (command=="1"){
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
        }


        //2. add/shipment
        else if (command == "2"){
            if (access){
                //give three options: add or shipment or back
                interface_addship();
                string cmd2="";
                cin>>cmd2;
                while (cmd2 != "back"){
                    //ask the user of the name, age, code, sex of the child to be added and alter the allchild.txt, crate childname.txt
                    if (cmd2 == "add")      child_add();

                    //ask the user name of the child to be shipped, another yes/no to double check
                    else if (cmd2 == "ship")     child_ship();

                    else   cout<<"Sorry, wrong command."<<endl;

                    interface_addship();
                    cin>>cmd2;
                }
            }
            else cout<<"Sorry, no access."<<endl;
        }


        //3. import test score
        else if (command == "3"){
            if (access){
                //ask the user to input the name of the file storing the score to be import
                //could first assume the files are of legal format, can later alter the program to create intermediate files while importing, show a error alert when error detected in the file and return to the state before importing
                //remember to auto upgrade the age!
                interface_scoreimport();
                string scorefile_txt;
                cin>>scorefile_txt;
                import(scorefile_txt);
                getaverage();
                upgrade();
            }
            else cout<<"Sorry, no access."<<endl;
        }


        //4. ranking and notifications
        else if (command == "4"){
            //show notification: the child needs to be shipped immediately
            int n;
            getn(n);
            notif(n);

            //ask the user to input "all" or "back"
            interface_rank();
            string cmd4="";
            cin>>cmd4;
            while (cmd4 != "back"){
                //show all child sorted by ranking
                if (cmd4 == "all")      showrank();

                else       cout<<"Sorry, wrong command."<<endl;

                interface_rank();
                cin>>cmd4;
            }
        }


        //wrong command
        else    cout<<"Sorry wrong command."<<endl;

        //back to the welcome page and input new command
        interface_welpage(access);
        cin>>command;
    }

    //user have choose to exit the program
    interface_exit();
}
