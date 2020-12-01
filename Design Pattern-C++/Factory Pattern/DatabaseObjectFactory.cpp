/*DatabaseObjectFactory.cpp : It acts as factory and creates the desired objects and return to client
according to input of client*/

#include "Database.cpp"

class Factory{

    public:
    static Database * getObject(int choice){
        if(choice==1)
          return new Mysql();
        else if(choice==2)
          return new Oracle();
        else
            return NULL;    
      
    }
};