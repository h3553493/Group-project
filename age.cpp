#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdio.h>
#include"age.h"
using namespace std;
void upgrade()
{
	string line,name,gender;
	double average,age;
	int code;
	ifstream fin("storage/studentinfo.txt");
    if (fin.fail())
    {
      cout<<"Error in opening file"<<endl;
      exit(1);
    }
    else
    {
      while(getline(fin,line))
      {
        istringstream iss(line);
        iss>>name>>code>>age>>gender>>average;
        age+=0.5;
        ofstream fout("storage/studentinfo1.txt",ios::app);
        if (fout.fail())
        {
        	cout<<"Error in file opening!"<<endl;
        	exit(1);
		}
		else
		{
			fout<<name<<"\t"<<code<<"\t"<<age<<"\t"<<gender<<"\t"<<average<<endl;
		}
		fout.close();
		fout.clear();
      }
    }
    fin.close();
    remove("storage/studentinfo.txt");
    rename("storage/studentinfo1.txt","storage/studentinfo.txt");
}


