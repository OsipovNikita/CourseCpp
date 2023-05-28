
#include <iostream>
using namespace std;

// 1. 
class Widget
{
  public:
    virtual void draw() = 0;
};

// 3. 
class TextField: public Widget
{
    int width, height;
  public:
    TextField(int w, int h)
    {
        width = w;
        height = h;
    }

    /*virtual*/
    void draw()
    {
        cout << "TextField: " << width << ", " << height << '\n';
    }
};

// 2. 
class Decorator: public Widget  // 3. 
{
    Widget *wid; // 4. 
  public:
    Decorator(Widget *w)
    {
        wid = w;
    }

    /*virtual*/
    void draw()
    {
        wid->draw(); // 5. 
    }
};

// 6. 
class BorderDecorator: public Decorator
{
  public:
    BorderDecorator(Widget *w): Decorator(w){}

    /*virtual*/
    void draw()
    {
        // 7. 
        Decorator::draw();
        // 7. 
        cout << "   BorderDecorator" << '\n';
    }
};

// 6. 
class ScrollDecorator: public Decorator
{
  public:
    ScrollDecorator(Widget *w): Decorator(w){}

    /*virtual*/
    void draw()
    {
        // 7. 
        Decorator::draw();
        cout << "   ScrollDecorator" << '\n';
    }
};

int main()
{
  // 8. 
  Widget *aWidget = new BorderDecorator (new ScrollDecorator (new TextField(80, 24)));
  
  aWidget->draw();
}
