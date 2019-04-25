class rank
{
public:
  void notif()
  {
    ifstream fin("studentinfo.txt");
    if（fin.fail())
    {
      cout<<"Error in file opening!"<<endl;
      exit(1);
    }
    else
    {
      n=0;
      while (getline(fin,line))
      {
        n+=1;
      }
      studentinfo *s=new studentinfo(n);
      i=0;
      while(getline(fin,line))
      {
        istringstream iss(line);
        iss>>name>>gender>>age>>code>>average;
        if (age<6)
        {
          rankscore=0;
        }
        else if (age<=12)
        {
          rankscore=age/12*20+score/300*80;
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
          if (s[i].rankscore>=s[j].rankscore)
          {
            s[i].rank-=1;
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
            cout<<s[i].name<<;
            j++;
          }
          else
          {
            cout<<","<<s[i].name;
          }
        }
      }
      cout<<" should be shipped."<<endl;
      ofstream fout("rank.txt");
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
              fout<<s[j].name<<" "<<s[j].rank<<endl;
            }
          }
        }
      }
      fout.close();
    }
  }
private:
  string name,gender,line;
  int code,n,i,j;
  double age,average,rankscore,rank;
  struct studentinfo
  {
    string name;
    double rankscore;
    double rank;
  }
};
