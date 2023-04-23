Observer_Pattern_1.cpp
===================================

This is a simple implementation of the Observer Design Pattern in C++. (or publish-subscribe mechanism/Subject- Observer mechanism)

The Observer Design Pattern is a software design pattern that allows one-to-many relationships between objects. In this pattern, there is a subject (also called observable or publisher) and one or more observers (also called listeners or subscribers) that depend on the subject. When the subject's state changes, all the observers are notified automatically.

OR


The Observer pattern is a design pattern in which an object, called the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.
This pattern is widely used in GUI applications, where a change in one control should be reflected in other controls.

In this code, there are three main classes:

ISubscriber: This is the interface that all subscribers must implement. It has only one method notify which is called by the subject ( Here in this example by Group class) when a change occurs.

User: This class represents a user (or an observer) that subscribes to the subject( here to Group class). It implements the ISubscriber interface and has a unique id (m_userId) to differentiate between different users.

Group: This class represents the subject (or the publisher) which users can subscribe to. It has a list of subscribers (of type ISubscriber *) and provides methods to users to subscribe/unsubscribe  and notify them ( users or observerss) when a change occurs.

Overall:
In this program, there is a Group class that acts as the subject, and it maintains a list of ISubscriber objects, which are the observers. The User class implements the ISubscriber interface and is a concrete observer. When a change occurs in the Group, the notify method of each observer is called to update the observer.

In the main function:
A Group object is created, and three User objects subscribe to it. Then, the Group object notifies all the subscribers about a change. After that, one User object unsubscribes from the Group, and the Group notifies the remaining subscribers again.

Overall, this code demonstrates how the Observer Design Pattern can be used to implement a simple publish-subscribe mechanism.

Note:
In the given code, we are using dynamic_cast to convert a pointer of type ISubscriber* to User*. This is because the notify() function in Group class needs to call getId() function of User class for each subscriber. However, the gp list/vector in Group class is of type ISubscriber*, which does not have the getId() function.

By using dynamic_cast, we can check if the object pointed to by the ISubscriber* pointer is actually an object of User class, and if so, convert the pointer to User*. Then, we can call the getId() function on the converted User* pointer.

Note that dynamic_cast returns a null pointer if the cast fails, so we can use it to check if the object pointed to by the ISubscriber* pointer is actually an object of User class before attempting the cast.