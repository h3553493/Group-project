class score {
public:
  void import(string scorefile_txt)
  {
    ifstream fin(scorefile_txt.c_str());
    if (fin.fail())
    {
      cout<<"Error in file opening!"<<endl;
      exit(1);
    }
    else
    {
      while (getline(fin，line))
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
private:
  string line;
  string name;
  string score;
  string name_score;
  string scorefile;
};
