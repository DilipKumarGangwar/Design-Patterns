//Bad Design:
//Adding  a new  operation  in the existing well tested old class
//=> disturbing the exsisting functionality and creating room for bugs in code

/*
#include<bits/stdc++.h>
using namespace std;

class AreaCalculator
{
    public:
     int calculateSquareArea(int side)
     {
        return side * side;
     }
     int calculateRectangleArea(int length,int breadth)
     {
        return length * breadth;
     } 

     //adding new methods for new shapes in this class itself as and when they come 
      //thus disturbing/modifying the existing tested class  
};

int main()
{
    AreaCalculator cal;
    cout<<"Area of Square="<<cal.calculateSquareArea(3)<<endl;
    cout<<"Area of Rectangle="<<cal.calculateRectangleArea(2,5);
    return 0;
}

*/


#include<bits/stdc++.h>
using namespace std;


//Interface

class IShapes
{
    public:
      virtual int calculateArea()=0;
};

class Square:public IShapes
{
   int m_side; 
   public:
    Square(int side)
     {
        m_side = side;
     }
     int calculateArea()
     {
         return m_side * m_side;
     }
};

class Rectangle:public IShapes
{
   int m_len,m_breadth;
   public:
     Rectangle(int len,int breadth)
     {
        m_len = len;
        m_breadth = breadth;
     }
     int calculateArea()
     {
        return  m_len*m_breadth;
     }
};

class AreaCalculator
{
    vector<IShapes*> m_shapes;
    public:
    //    void calculateShapesArea(IShapes * shape) 
    //    {
    //     shape->calculateArea();
    //    }
       AreaCalculator(vector<IShapes*> shapes)
       {
        m_shapes = shapes;
       }
       int calculateShapesArea() 
       {
             int totalArea=0;
            for(IShapes *sh : m_shapes)
            {
               totalArea += sh->calculateArea();
            }
            return totalArea;
        
       }
    
};

int main()
{
    // IShapes * shapes = new Square(2); //each side = 2 unit
    // cout<<"Area of Square="<<shapes->calculateArea()<<endl;
    // shapes = new Rectangle(2,3);  //len =2, breadth = 3
    // cout<<"Area of Rectangle="<<shapes->calculateArea();
    // return 0;

    //If we want to add the areas of various shapes.
    vector<IShapes*> sh;
    IShapes * shapes = new Square(2); //each side = 2 unit
    sh.push_back(shapes);
    shapes = new Rectangle(2,3); 
    sh.push_back(shapes);

    AreaCalculator acal(sh);
    cout<<"Total Area of All shapes="<<acal.calculateShapesArea()<<endl;
    
    //We could also make a function say Additem() in AreaCalculator class and call this to push 
    //the shapes one by one in the vector defined in AreaCalculator 
    
}
