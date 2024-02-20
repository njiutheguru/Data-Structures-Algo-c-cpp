#include <iostream>
//implementation of shallow copy  in cpp consructors
using namespace std;
class box
{
    private:
    int length;
    int width;
    int breadth;
    public:
    void set_Data(int x, int y, int z)
    {
        length=x;
        width=y;
        breadth=z;
    }
    void showdata()
    {
        cout << length << " " << width << " " << breadth <<endl;
    }
   
};

int main()
{
 box B1, B2, B3;
 B1.set_Data(10,21,39);
 B1.showdata();
 B2=B1;
 B2.showdata();
 B3=B1;
 B3.showdata();
 box B4=B3;
 B4.showdata();
 B4.set_Data(34,66,88);
 B4.showdata();

    return 0;
}
