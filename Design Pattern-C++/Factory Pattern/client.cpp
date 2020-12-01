/*  Factory Design pattern  - Creational Pattern
It separates the object creation from Client to another class called factory

Client Program:
User Enters the choice of database to which it wants to connect
DatabaseObjectFactory.cpp : It acts as factory and creates the desired objects and return to client
according to input of client
Database.cpp : Have various databases 
*/

#include<iostream>
#include "DatabaseObjectFactory.cpp" 
using namespace std;

main(){
   int choice;
   Database *database; 
   while(1){
       cout<<"Enter choice for Object Creation 1.MySQL  2.Oracle"<<endl;
       cout<<"Type 0 for exit"<<endl;
       cin>>choice;    
       if(!choice)
          break;
       database = Factory::getObject(choice);
       if(database){
        database->insertData(50);
        cout<<"Data in database="<<database->showData()<<endl;
        delete database;
       }
    
   }
}