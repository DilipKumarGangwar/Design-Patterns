#include "Notify.h"
#include "WhatsappNotifier.cpp"
#include "FacebookNotifier.cpp"

#include "Notifier.cpp"

int main()
{
    //construct BaseNotifier
    INotify * ntfy1 =  new Notifier();
    //ntfy1->sendMessage("Hello, New Event came..");
    
    //Decorate it with WhatsappNotifier
    INotify * ntfy2 = new WhatsappNotifier(ntfy1);
    
    //send message
    ntfy2->sendMessage("Hello, New Event1 came..");

    //Construct base Notifier and Decorate it with WhatsappNotifier, facebookNotifier
    INotify * ntfy3 = new WhatsappNotifier(new FacebookNotifier(new Notifier()));
    
    //send message
    ntfy3->sendMessage("Hello, New Event2 came..");


    return 0;
}