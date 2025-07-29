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
  void printInvoice()
  {
    cout << "CART INVOICE" << endl;
    for (auto p : arr)
    {
      cout << "Product name : " << p->name << " || price : " << p->price << endl;
    }
  }
  void saveInDB()
  {
    cout << "Saving cart in DB" << endl;
  }
};

int main()
{
  Cart *mycart = new Cart();
  Product *p1 = new Product("Apple", 100);
  Product *p2 = new Product("Banana", 50);

  mycart->addProduct(p1);
  mycart->addProduct(p2);
  mycart->printInvoice();
  cout << "Total Price: " << mycart->calculatePrice() << endl;
  mycart->saveInDB();
  delete mycart;
  return 0;
}
