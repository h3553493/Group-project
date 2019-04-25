#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "child.h"
using namespace std;

void child_info(){
    string line;
    ifstream info("studentinfo.txt");
    cout<<setw(15)<<left<<"Name"<<setw(10)<<"Code"<<setw(5)<<"Age"<<endl;
    while (getline(info,line)){
        istringstream iss(line);
        string name, code, age, ave;
        iss>>name>>code>>age;
        cout<<setw(15)<<left<<name<<setw(10)<<code<<setw(5)<<age<<endl;
    }
    info.close();
}

void child_detail(string name){
    string txtname = "score_"+name+".txt";
    ifstream detail(txtname);
    if (detail.fail()){
        cout<<"Cannot find this child, try again please:";
        exit(1);
    }
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
        cout<<line<<endl;
    }
    detail.close();
    cout<<endl<<"Total test attended: "<<times<<endl;
    cout<<"Average score: "<<total/times*1.0<<endl;
}

void child_add(){

}

void child_ship();

int main(){
    child_info();
    child_detail("Emma");
}
