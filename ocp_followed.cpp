#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
public:
  string name;
  int price;

public:
  Product(string name, int price)
  {
    this->name = name;
    this->price = price;
  }
};

class Cart
{
private:
  vector<Product *> arr;

public:
  void addProduct(Product *p)
  {
    arr.push_back(p);
    cout << "Product added successfully";
  }
  const vector<Product *> &getProducts()
  {
    return arr;
  }
  int calculatePrice()
  {
    int sum = 0;
    for (auto p : arr)
    {
      sum += p->price;
    }
    return sum;
  }
};

class Persistance
{
private:
  Cart *cart;

public:
  Persistance(Cart *cart)
  {
    this->cart = cart;
  }
  virtual void save() = 0; // Pure virtual function
};

class CartMongoDB : public Persistance
{

public:
  CartMongoDB(Cart *cart) : Persistance(cart) {}
  void save() override
  {
    cout << "Saving cart in MongoDB" << endl;
  }
};

class CartPrinter
{
private:
  Cart *cart;

public:
  CartPrinter(Cart *cart)
  {
    this->cart = cart;
  }
  void printInvoice()
  {
    cout << "CART INVOICE" << endl;
    for (auto p : cart->getProducts())
    {
      cout << "Product name : " << p->name << " || price : " << p->price << endl;
    }
  }
};

int main()
{
  Cart *mycart = new Cart();
  Product *p1 = new Product("Apple", 100);
  Product *p2 = new Product("Banana", 50);

  mycart->addProduct(p1);
  mycart->addProduct(p2);

  Persistance *cartDB = new CartMongoDB(mycart);
  cartDB->save();

  CartPrinter *cartPrinter = new CartPrinter(mycart);
  cartPrinter->printInvoice();
  cout << "Total price: " << mycart->calculatePrice() << endl;
  // Clean up memory
  return 0;
}
