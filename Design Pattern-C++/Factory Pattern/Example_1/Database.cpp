/*Database.cpp : Have various databases */

#include <bits/stdc++.h> 
using namespace std;

class Database{
  protected:
  int data;
  public:
  virtual void insertData(int x)=0;
  virtual int showData()=0;

};

class Mysql:public Database{
  public:
  Mysql(){
      cout<<"Connected to Mysql Database"<<endl;
  }
  void insertData(int x){
       data=x;
  }

  int showData(){
      return data;
  }
};

class Oracle:public Database{
  public:
  Oracle(){
      cout<<"Connected to Oracle Database"<<endl;
  }
  void insertData(int x){
       data=x;
  }

  int showData(){
      return data;
  }
};
