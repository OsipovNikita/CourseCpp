#include <iostream>
#include <string>

using namespace std;

class Compression
{
  public:
    virtual ~Compression() {}
    virtual void compress( const int& f ) = 0;
};

class ZIP_Compression : public Compression
{
  public:
    void compress( const int& f ) 
	{
        cout << "ZIP compression " << f<< endl;
    }
};

class ARJ_Compression : public Compression
{
  public:
    void compress( const int& f ) 
	{
        cout << "ARJ compression " << f << endl;
    }
};

class RAR_Compression : public Compression
{
  public:
    void compress( const int& f ) 
	{
        cout << "RAR compression " << f << endl;
    }
};


class Compressor
{
  public:
    Compressor( Compression* comp): p(comp) {}
   ~Compressor() { delete p; }
    void compress( const int& f ) 
	{
      p->compress(f);
    }
  private:
    Compression* p;
};


int main()
{
  Compressor* p = new Compressor( new ZIP_Compression);
  p->compress(101);

  p = new Compressor(new RAR_Compression);
  p->compress(201);

  delete p;
  return 0;
}


