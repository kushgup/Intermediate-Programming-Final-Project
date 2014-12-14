#include <exception>

class noCamels: public exception
{
public:
  virtual const char* what() const throw() {return "No Camels in Field!";}
};

class wrongSellType: public exception
{
public:
  virtual const char* what() const throw() {return "Cannot Sell Cards of Different Types!";}
};

class sellPrecious: public exception
{
public:
  virtual const char* what() const throw() {return "For 'Precious Goods' (Diamonds, Silver, Gold), Must Sell at Least 2!";}
};

