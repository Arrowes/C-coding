#include <iostream>        //头文件
using namespace std;     //名称空间

class Fish     //定义Fish类作为基类
{
   public:
      virtual Fish* Clone()=0;   //声明一个纯虚函数Clone 用于克隆对象
      virtual void Swim()=0;     //声明一个纯虚函数Swim
      virtual ~Fish() {};     //声明虚析构函数
};

class Tuna: public Fish    //定义Tuna类，继承自Fish
{
   public:
      Fish* Clone() override  //实现Clone函数，返回一个克隆对象指针
      {
         return new Tuna (*this);   //*this表示当前对象的指针
      }

   void Swim() override final //final使它的派生类无法覆盖swim
   {
      cout << "Tuna swims fast in the sea" << endl;
   }
};

class BluefinTuna final:public Tuna // 定义BluefinTuna类，继承自Tuna
{
   public:
      Fish* Clone() override  //无法覆盖Tuna类中的Swim函数
      {//调用 Swim()时执行 Tuna::Swim()
         return new BluefinTuna(*this);
      }
};

class Carp final: public Fish // 定义Carp类，继承自Fish
{
   Fish* Clone() override{
      return new Carp(*this); 
   }
   void Swim() override final  // 实现Carp的Swim函数
   {
      cout << "Carp swims slow in the lake" << endl;
   }
} ;

int main()
{
   const int ARRAY_SIZE =4;

   Fish* myFishes[ARRAY_SIZE]={NULL};  //声明静态基类指针（Fish *）数组，创建对象
   myFishes[0]=new Tuna();
   myFishes[1]=new Carp();
   myFishes[2]=new BluefinTuna();
   myFishes[3]=new Carp();

   Fish* myNewFishes[ARRAY_SIZE];
   for (int index=0; index < ARRAY_SIZE; ++index)
      myNewFishes[index]=myFishes[index]->Clone(); // 使用Clone函数克隆原对象到另一个数组

   for (int index=0; index<ARRAY_SIZE; ++index)
      myNewFishes[index]->Swim();   // 调用克隆对象的Swim函数，以验证 Clone( )复制了整个派生类对象

   for (int index=0; index<ARRAY_SIZE; ++index)
      {  // 释放内存
         delete myFishes[index];
         delete myNewFishes[index];
      }

      return 0;
}
