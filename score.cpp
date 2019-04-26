#include<iostream>
//#include"score.h"
#include<sstream>
#include<fstream>
using namespace std;
void import(string scorefile_txt)
{
	string line,name,name_score,testno;
	int score;
	cout<<"Please input test number:"<<endl;
	cin>>testno;
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
        name_score=name+"_score.txt";
        ofstream fout(name_score.c_str(),ios::app);
        if (fout.fail())
        {
          cout<<"Error in fail opening"<<endl;
          exit(1);
        }
        else
        {
          fout<<testno<<": "<<score<<endl;
        }
        fout.close();
        fout.clear();
      }
	}	
    fin.close();
}
void getaverage()
{
	string name,gender,name_score,line1,line,testno;
	double age,average,n=0,average1;
	int code,score,total=0;
	ifstream fin("studentinfo.txt");
	if (fin.fail())
	{
		cout<<"Error in file opening!"<<endl;
		exit(1);
	}
	else
	{
		while(getline(fin,line))
		{
			istringstream iss(line);
			iss>>name>>code>>age>>gender>>average;
			name_score=name+"_score.txt";
			ifstream file1(name_score.c_str());
			if (file1.fail())
			{
				cout<<"Error in file opening!"<<endl;
				exit(1);
			}
			else
			{
				total=0;
				n=0;
				while(getline(file1,line1))
				{
					istringstream is(line1);
					is>>testno>>score;
					total+=score;
					n++;
				}
			}
			file1.close();
			file1.clear();		
			average1=double (total)/double (n);
			ofstream file("studentinfo1.txt",ios::app);
			if (file.fail())
			{
				cout<<"Error in file opening!"<<endl;
				exit(1);
			}
			else
			{
				file<<name<<" "<<code<<" "<<age<<" "<<gender<<" "<<average1<<endl;
			}
			file.close();
			file.clear();
		}
	}
	fin.close();
	remove("studentinfo.txt");
	rename("studentinfo1.txt","studentinfo.txt");
}

