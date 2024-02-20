#include <iostream>

//showing the working of Deep copy using cpp constructor
//the deep copy is preferred in practical software development and in real world scenarios 

using namespace std;

class Box
{
   private:
   int length;
   int *breadth;
   int width;


   public:
   Box()
   {
      breadth=new int;
   }
   //setters
   void setData(int len, int bre, int wid)
   {
      length=len;
      *breadth=bre;
      width=wid;
   }
   void showdata()
     {
      cout<<"Dimensions: "<<length <<" * "<< *breadth << " * " << width << " " << endl;
     }
   Box(Box& copied)
     {
         length=copied.length;
         breadth=new int;
         *breadth=*(copied.breadth);
         width=copied.width;
         
     }
    //setting a destructor
     ~Box()
     {
      delete breadth;
      cout<<"Heap memory deleted successfully" << endl;
     }
     

};
 int main()
 {
   Box first,copied, second;
   first.setData(10,100,1000);
   first.showdata();
   second=first;
   second.showdata();
   copied=first;
   copied.showdata();
   copied.setData(11,111,1111);
   copied.showdata();
    return 0;
 }