#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Database
{
public:
  virtual void save(string user) = 0;
};

class MongoDbDatabase : public Database
{
public:
  void save(string user) override
  {
    cout << "Saving user " << user << " in MongoDB" << endl;
  }
};

class SqlDatabase : public Database
{
public:
  void save(string user) override
  {
    cout << "Saving user " << user << " in SQL Database" << endl;
  }
};

class UserService
{
private:
  Database *db;

public:
  UserService(Database *db)
  {
    this->db = db;
  }

  void saveIndb(string user)
  {
    db->save(user);
  }
};

int main()
{
  Database *mongoDb = new MongoDbDatabase();
  Database *sqlDb = new SqlDatabase();
  UserService *userService1 = new UserService(mongoDb);
  UserService *userService2 = new UserService(sqlDb);
  userService1->saveIndb("Alice");
  userService2->saveIndb("Bob");
  delete mongoDb;
  delete sqlDb;
  delete userService1;
  return 0;
}