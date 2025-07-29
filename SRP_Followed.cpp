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

class CartDB
{
private:
  Cart *cart;

public:
  CartDB(Cart *cart)
  {
    this->cart = cart;
  }
  void saveInDB()
  {
    cout << "Saving cart in DB" << endl;
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

  CartDB *cartDB = new CartDB(mycart);
  cartDB->saveInDB();
  CartPrinter *cartPrinter = new CartPrinter(mycart);
  cartPrinter->printInvoice();
  cout << "Total price: " << mycart->calculatePrice() << endl;
  // Clean up memory
  return 0;
}
