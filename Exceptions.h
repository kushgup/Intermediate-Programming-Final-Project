#include <exception>

using std::exception;

class inputTooLongException: public exception
{
public:
  virtual const char* what() const throw() {return "Invalid Input! Please Enter Only 1 Character!";}
};

class invalidNumCamelsToGive: public exception
{
public:
  virtual const char* what() const throw() {return "Giving an invalid number of Camels! Give between 0 camels and the # in your herd!";}
};

class invalidInitialSelectionException: public exception
{
public:
  virtual const char* what() const throw() {return "Invalid Input! Please enter a character between 'a' and 'd' to indicate which move to make!";}
};

class invalidInputforMarketException: public exception
{
public:
  virtual const char* what() const throw() {return "Invalid Selection for Market Card! Enter character between 'a' and 'e'!";}
};

class invalidInputforHandException: public exception
{
public:
  virtual const char* what() const throw() {return "Invalid Selection for Hand Card! Enter the proper number denoting the card in your hand!";}
};

class noCamelsException: public exception
{
public:
  virtual const char* what() const throw() {return "No Camels in Field!";}
};

class wrongSellTypeException: public exception
{
public:
  virtual const char* what() const throw() {return "Cannot Sell Cards of Different Types!";}
};

class sellPreciousException: public exception
{
public:
  virtual const char* what() const throw() {return "For 'Precious Goods' (Diamonds, Silver, Gold), Must Sell at Least 2!";}
};

class invalidHandSizeException: public exception
{
public:
  virtual const char* what() const throw() {return "Make sure you have enough cards in your hand to exchange!";}
};

class equalExchangeException: public exception
{
public:
  virtual const char* what() const throw() {return "Make sure that for an exchange, you are Giving and Taking from market the same # of cards!";}
};

class givingMarketTooManyException: public exception
{
public:
  virtual const char* what() const throw() {return "Make sure you do not give the market more than 5 cards!";}
};

class herdNotBigEnoughException: public exception
{
public:
  virtual const char* what() const throw() {return "Make sure that if you are giving camels to market, your herd is adequate!";}
};

class takingTooManyCardsException: public exception
{
public:
  virtual const char* what() const throw() {return "Make sure you are not taking more than 7 cards into Hand!";}
};

class notEnoughToExchangeException: public exception
{
public:
  virtual const char* what() const throw() {return "Make sure you are exchanging at least 2+ cards with the market!";}
};

class tradingSameException: public exception
{
public:
  virtual const char* what() const throw() {return "Cannot Give and Take a Good of the Same Type!";}
};

class exchangeTakingCamelsException: public exception
{
public:
  virtual const char* what() const throw() {return "When Exchanging Goods, You Cannot Take a Mixture of Camels and Goods!";}
};

class takeMoreThanSevenException: public exception
{
public:
  virtual const char* what() const throw() {return "Cannot Take More Than 7 Cards into Hand!";}
};

class takeSingleCamelException: public exception
{
public:
  virtual const char* what() const throw() {return "Cannot Take a Single Camel! Must 'Take All Camels'!";}
};

class repeatedCardsException: public exception
{
public:
  virtual const char* what() const throw() {return "Cannot Move Repeated Cards! Select A Card Only Once!";}
};