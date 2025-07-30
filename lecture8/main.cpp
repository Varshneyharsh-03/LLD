#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WalkableRobot
{
public:
  virtual void walk() = 0;
};

class NormalWalk : public WalkableRobot
{
public:
  void walk() override
  {
    cout << "Normal walking" << endl;
  }
};

class NoWalk : public WalkableRobot
{
public:
  void walk() override
  {
    cout << "Robot cannot walk" << endl;
  }
};

class FlyableRobot
{
public:
  virtual void fly() = 0;
};

class NormalFly : public FlyableRobot
{
public:
  void fly() override
  {
    cout << "Normal flying" << endl;
  }
};

class NoFly : public FlyableRobot
{
public:
  void fly() override
  {
    cout << "Robot cannot fly" << endl;
  }
};

class TalkableRobot
{
public:
  virtual void talk() = 0;
};

class NormalTalk : public TalkableRobot
{
public:
  void talk() override
  {
    cout << "Normal talking" << endl;
  }
};

class NoTalk : public TalkableRobot
{
public:
  void talk() override
  {
    cout << "Robot cannot talk" << endl;
  }
};

class Robot
{

public:
  WalkableRobot *walkable;
  FlyableRobot *flyable;
  TalkableRobot *talkable;

  Robot(WalkableRobot *walkable,
        FlyableRobot *flyable,
        TalkableRobot *talkable)
  {
    this->walkable = walkable;
    this->flyable = flyable;
    this->talkable = talkable;
  }

  void walk()
  {
    walkable->walk();
  }

  void fly()
  {
    flyable->fly();
  }

  void talk()
  {
    talkable->talk();
  }

  virtual void projection() = 0;
};

class CompanionRobot : public Robot
{
public:
  CompanionRobot(WalkableRobot *walkable,
                 FlyableRobot *flyable,
                 TalkableRobot *talkable)
      : Robot(walkable, flyable, talkable) {}

  void projection() override
  {
    cout << "Companion Robot Projection" << endl;
  }
};

class WorkerRobot : public Robot
{
public:
  WorkerRobot(WalkableRobot *walkable,
              FlyableRobot *flyable,
              TalkableRobot *talkable)
      : Robot(walkable, flyable, talkable) {}

  void projection() override
  {
    cout << "Worker Robot Projection" << endl;
  }
};

int main()
{
  WalkableRobot *normalWalk = new NormalWalk();
  FlyableRobot *normalFly = new NormalFly();
  TalkableRobot *normalTalk = new NormalTalk();

  Robot *companionRobot = new CompanionRobot(normalWalk, normalFly, normalTalk);
  companionRobot->walk();
  companionRobot->fly();
  companionRobot->talk();
  companionRobot->projection();

  Robot *workerRobot = new WorkerRobot(new NoWalk(), new NoFly(), new NoTalk());
  workerRobot->walk();
  workerRobot->fly();
  workerRobot->talk();
  workerRobot->projection();

  delete companionRobot;
  delete normalWalk;
  delete normalFly;
  delete normalTalk;
  return 0;
}
