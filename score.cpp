#include<iostream>
//#include"score.h"
#include<sstream>
#include<fstream>
using namespace std;
void import(string scorefile_txt)
{
	string line,name,score,name_score;
	ifstream fin(scorefile_txt.c_str());
    if (fin.fail())
    {
      cout<<"Error in file opening!"<<endl;
      exit(1);
    }
    else
    {
      while (getline(fin,line))
      {
        istringstream line_in(line);
        line_in>>name>>score;
        name_score=name+"_score";
        ofstream fout(name_score.c_str(),ios::app);
        if (fout.fail())
        {
          cout<<"Error in fail opening"<<endl;
          exit(1);
        }
        else
        {
          fout<<score<<endl;
        }
        fout.close();
        fout.clear();
      }
    }
    fin.close();
}

