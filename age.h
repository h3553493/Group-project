class age
{
public:
  void getage(string str)
  {
    ifstringstream iss(str);
    for (int i=0;i<3;i++)
    {
      iss>>age;
    }
  }
  void upgrade()
  {
    ofstream fout("studentinfo.txt");
    if (fout.fail())
    {
      cout<<"Error in opening file"<<endl;
      exit(1);
    }
    else
    {
      while(getline(fout,line))
      {
        getage(line);
        age+=0.5;
      }
    }
    fout.close();
  }
private:
  string age,line;

};
