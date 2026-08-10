#include<bits/stdc++.h>
using namespace std;

class Coffee{
   public:
   virtual string getDescription() = 0;
   virtual double getCost() = 0;

};

class simpleCoffee : public Coffee {
      public:
        string getDescription() override {
            return "SimpleCoffee";
        }
       
        double getCost() override {
               return 100.00;
        }
     
};

class Espresso : public Coffee {
      public:
        string getDescription() override {
            return "Espresso";
        }
       
        double getCost() override {
               return 150.00;
        }
     
};


// Decorater class -> haves "is-a" and "has-a" relation with cofee

class CoffeeDecorator : public Coffee { // "is-a"
   protected :
      Coffee* coffee;  // "has-a" relation

    public :
       CoffeeDecorator(Coffee* c){
            this->coffee = c;
       }

};

// concrate decorator classes
class MilkDecorator : public CoffeeDecorator{
   public : 
      MilkDecorator(Coffee* coffee): CoffeeDecorator(coffee){}

      string getDescription() override{
           return coffee->getDescription() + "+ Milk"; 
      }

       double getCost() override{
          // milk cost = 20
         return coffee->getCost()+20;
       }

};

class ChocolateDecorator  : public CoffeeDecorator{
   public : 
      ChocolateDecorator (Coffee* coffee): CoffeeDecorator(coffee){}

      string getDescription() override{
           return coffee->getDescription() + "+ chocolate"; 
      }

       double getCost() override{
          // milk cost = 30
         return coffee->getCost()+30;
       }

};

int main(){

      // step1 : start simeple coffee
      Coffee* coffee = new simpleCoffee();

    //   cout<<coffee->getDescription();  o/p =  SimpleCoffee

    // step 2 : lets add milk
      coffee = new MilkDecorator(coffee);

     //  cout<<coffee->getDescription()<<" = "<<coffee->getCost(); o/p SimpleCoffee+ Milk = 120

    //  step 3 : now lets add chocolate too
    coffee = new ChocolateDecorator(coffee);
    cout<<coffee->getDescription()<<" = "<<coffee->getCost(); // SimpleCoffee+ Milk+ chocolate = 150


    return 0;

}
