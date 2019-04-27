#include<iostream>
#include<fstream>
#include <iomanip>
#include<sstream>
#include<string>
//#include"rank.h"
using namespace std;
struct studentinfo
{
	string name;
	double rankscore;
	double rank;
};
void notif(int n)
{
	string line,name,gender;
	int code,i,j,rank;
	double age,average,rankscore;
	ifstream fin("storage/studentinfo.txt");
    if(fin.fail())
    {
      cout<<"Error in file opening!"<<endl;
      exit(1);
    }
    else
    {
	  	studentinfo *s=new studentinfo [n];
	  	i=0;
      	while(getline(fin,line))
      	{
        	istringstream iss(line);
        	iss>>name>>code>>age>>gender>>average;
        	if (age<6)
        	{
          		rankscore=0;
        	}
        	else if (age<12)
        	{
          		rankscore=age/12*20+average/300*80;
        	}
        	else
        	{
          		rankscore=100;
        	}
        	s[i].name=name;
        	s[i].rankscore=rankscore;
        	s[i].rank=n;
        	i++;
      	}
      	for (i=0;i<n;i++)
    	{
    		for (j=0;j<n;j++)
        	{
          		if (j==i)
          		{
          			continue;
		  		}
		  		else
		  		{
          			if (s[i].rankscore>=s[j].rankscore)
          			{
            			s[i].rank--;
          			}
          		}
    		}
		}
    	j=0;
    	for (i=0;i<n;i++)
    	{
    		if (s[i].rank==1)
        	{
          		if (j==0)
          		{
            		cout<<s[i].name;
            		j++;
          		}
          		else
          		{
            		cout<<", "<<s[i].name;
          		}
        	}
    	}
    	if (j==0)
    	{
    		cout<<"No one should be shipped."<<endl;
		}
		else
		{
			cout<<" should be shipped."<<endl;
		}
    	ofstream fout("storage/rank.txt");
    	if (fout.fail())
    	{
    		cout<<"Error in file opening!"<<endl;
        	exit(1);
    	}
    	else
    	{
    		for (i=1;i<n+1;i++)
        	{
          		for (j=0;j<n;j++)
          		{
            		if (s[j].rank==i)
            		{
              			fout<<s[j].name<<"\t"<<s[j].rankscore<<"\t"<<s[j].rank<<endl;
            		}
          		}
        	}
    	}
    	fout.close();
    	delete [] s;
    }
	fin.close();
}
void getn(int &n)
{
	n=0;
	string line;
	ifstream fin("storage/studentinfo.txt");
	if(fin.fail())
	{
		cout<<"Error in file opening!"<<endl;
		exit(1);
	}
	else
	{
		while (getline(fin,line))
		{
			n++;
		}
	}
	fin.close();
}
void showrank()
{
	cout<<setfill(' ')<<setw(10)<<left<<"NAME"<<setw(11)<<"RANK-SCORE"<<setw(10)<<"RANK"<<endl;
	string line;
	ifstream fin("storage/rank.txt");
	if (fin.fail())
	{
		cout<<"Error in file opening!"<<endl;
		exit(1);
	}
	else
	{
		while (getline(fin,line))
		{
		    string name, score, rank;
		    istringstream iss(line);
		    iss>>name>>score>>rank;
            cout<<setw(10)<<left<<name<<setw(11)<<score<<setw(10)<<rank<<endl;
		}
	}
	fin.close();
}

