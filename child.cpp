#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "child.h"
using namespace std;

void child_info(){
    string line;
    ifstream info("storage/studentinfo.txt");
    cout<<endl;
    cout<<setw(15)<<setfill(' ')<<left<<"NAME"<<setw(10)<<"CODE"<<setw(5)<<"AGE"<<setw(7)<<"GENDER"<<setw(7)<<"AVERAGE"<<endl;
    while (getline(info,line)){
        istringstream iss(line);
        string name, code, gender;
        double ave, age;
        iss>>name>>code>>age>>gender>>ave;
        cout<<setw(15)<<left<<name<<setw(10)<<code<<setw(5)<<int(age)<<setw(7)<<gender<<setw(7)<<ave<<endl;
    }
    info.close();
}

void child_detail(string name){
    string txtname = "storage/"+name+"_score.txt";
    ifstream detail(txtname);
    double ave=0;
    if (detail.fail()){
        cout<<"\nCannot find this child, try again please."<<endl;
    }
    else{
        cout<<"\nThe test result of child "<<name<<" :"<<endl;
        string line;
        int total=0,times=0;
        while (getline(detail,line)){
            istringstream iss(line);
            int score;
            string testtime;
            iss>>testtime>>score;
            total += score;
            times+=1;
            cout<<setw(10)<<right<<testtime<<setw(10)<<score<<endl;
        }
        detail.close();
        cout<<"Total test attended: "<<times<<endl;
        if (times!=0) ave=total/times*1.0;
        cout<<"Average score: "<<ave<<endl;
    }
}

void child_add(){
    string name, code, gender;
    double age=1;
    cout<<"Please type in the name of this new child: ";
    cin>>name;
    while (name == "back"){
        cout<<"Conflict with system command, you cannot use this name. Try again.";
        cin>>name;
    }
    cout<<"Please type in the code of this new child: ";
    cin>>code;
    cout<<"Please type in the gender of this new child(M/F): ";
    cin>>gender;
    int ave=0;
    ofstream stuinfo("storage/studentinfo.txt",ios::app);
    stuinfo<<name<<"\t"<<code<<"\t"<<age<<"\t"<<gender<<"\t"<<ave<<endl;
    stuinfo.close();
    ofstream personal("storage/"+name+"_score.txt");
    personal.close();
    cout<<"The new child have been added to the system, welcome to grace field house."<<endl;
}

void child_ship(){
    string name, infoname;
    cout<<"Please type in the name of the child to be shipped: ";
    cin>>name;
    ifstream origin("storage/studentinfo.txt");
    ofstream replaced("storage/temp.txt");
    string line;
    bool found=false;
    while (!found){
        while (getline(origin,line)){
            istringstream iss(line);
            iss>>infoname;
            if (name!=infoname)     replaced<<line<<'\n';
            else found=true;
        }
        if (found){
            origin.close();
            replaced.close();
            remove("studentinfo.txt");
            rename("temp.txt","studentinfo.txt");
            string txtname = name+"_score.txt";
            remove((txtname).c_str());
            cout<<"Shipment procedure complete, thank you for your work."<<endl;
        }
        else{
            cout<<"Child not found, try again or \"back\""<<endl;
            cout<<"Please type in the name of the child to be shipped: ";
            cin>>name;
        }
        remove("temp.txt");
        if (name=="back") break;
    }
}
