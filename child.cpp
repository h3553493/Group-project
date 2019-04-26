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
    ifstream info("studentinfo.txt");
    cout<<setw(15)<<left<<"NAME"<<setw(10)<<"CODE"<<setw(5)<<"AGE"<<setw(5)<<"GENDER"<<endl;
    while (getline(info,line)){
        istringstream iss(line);
        string name, code, gender;
        double ave, age;
        iss>>name>>code>>age>>gender;
        cout<<setw(15)<<left<<name<<setw(10)<<code<<setw(5)<<age<<setw(5)<<gender<<endl;
    }
    info.close();
}

void child_detail(string name){
    string txtname =    name+"_score.txt";
    ifstream detail(txtname);
    if (detail.fail()){
        cout<<"Cannot find this child, try again please:";
        exit(1);
    }
}

void child_add(){
    string name, code, gender;
    double age=1;
    cout<<"Please type in the name of this new child: ";
    cin>>name;
    cout<<"Please type in the code of this new child: ";
    cin>>code;
    cout<<"Please type in the gender of this new child(M/F): ";
    cin>>gender;
    ofstream stuinfo("studentinfo.txt",ios::app);
    stuinfo<<name<<"\t"<<code<<"\t"<<age<<"\t"<<gender<<endl;
    stuinfo.close();
    ofstream personal(name+"_score.txt");
    personal.close();
    cout<<"The new child have been added to the system, welcome to grace field house."<<endl;
}

void child_ship(){
    string name, infoname;
    cout<<"Please type in the name of the child to be shipped: ";
    cin>>name;
    ifstream origin("studentinfo.txt");
    ofstream replaced("temp.txt");
    string line;
    bool found=false;
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
        string txtname = name+"score.txt";
        remove((txtname).c_str());
        cout<<"Shipment procedure complete, thank you for your work."<<endl;
    }
    else{
        cout<<"Child not found, try again."<<endl;
        remove("temp.txt");
        exit(1);
    }
}


int main(){
    cout<<"\nchild_info :"<<endl;
    child_info();
    cout<<"\n\nchild_detail: "<<endl;
    string name;
    cin>>name;
    child_detail(name);
    cout<<"\n\nchild add: "<<endl;
    child_add();
    cout<<"\n\nchild shipment: "<<endl;
    child_ship();
}
