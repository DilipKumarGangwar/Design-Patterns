#include <bits/stdc++.h> 
using namespace std; 

//Interface
class ISubscriber
{
   public:
     virtual void notify(string msg)=0;
};

class User:public ISubscriber
{
    int m_userId;
    public:
       User(int id)
       {
           m_userId = id;

       }
       int getId()
       {
        return m_userId;
       }
       void notify(string msg)
       {
           cout<<"User "<<m_userId<<" Received Message from Publisher: "<<msg<<endl;
       }       
};

class Group
{
    list<ISubscriber *> gp; //group will have people of type ISubscriber
    //vector<ISubscriber *> gp;   if using vector

    public:
        void subscribe(ISubscriber * user)
        {
            gp.push_back(user);
        }

        void unSubscribe(ISubscriber * user)
        {
            gp.remove(user);

            //If using vector
            // if(find(gp.begin(),gp.end(),user) != gp.end())
            //    gp.erase(remove(gp.begin(),gp.end(),user),gp.end());
        }

        void notify(string msg)
        {
            //All users/Observers are notified one by one
            for(auto user : gp)
            {
                cout<<"Sending Message to user "<< dynamic_cast<User*>(user)->getId() <<endl;
                user->notify(msg);  
            }
        }

    
};



//client
int main()
{
  //Subject or Notifier or Publisher  
  Group *group = new Group;

  //These are basically Observers
  User *u1 = new User(1);
  User *u2 = new User(2);
  User *u3 = new User(3);

  //Observers are adding themselves to the group as listeners
  group->subscribe(u1);
  group->subscribe(u2);
  group->subscribe(u3);

  //Group is publishing a change /message
  group->notify("New Update No. 1 has come");

  //Now one user unsubscribed/left from the group
  group->unSubscribe(u1);

  group->notify("Update no. 2 has come");
  
  return 0;
}