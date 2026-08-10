#include<bits/stdc++.h>
using namespace std;

class Coffee {
  private :
      string type ; // simple Coffee ,  Espresso

      bool milk ;
      bool sugar ;
      bool chocolate ;
      bool whippedCream;

  public :
     
    Coffee(string type){
         this->type = type;
    }
 
    void addMilk(){
        milk = true;
    }

    void addSugar(){
        sugar = true;
    }

    void addChocolate(){
        chocolate = true;
    }

    void addWhippedCream(){
        whippedCream = true;
    }


    // calculate the total amount
     double getCost(){
        double price = 0;

        // Base coffee price
        if(type == "Simple")
            price = 100;

        else if(type == "Espresso")
            price = 120;

        else if(type == "Cappuccino")
            price = 150;

        // add-ons 
            if(milk)
            price += 20;

        if(sugar)
            price += 10;

        if(chocolate)
            price += 30;

        if(whippedCream)
            price += 40;

        return price;

     }

};


int main(){
    Coffee coffee("Espresso");
    coffee.addMilk();
    coffee.addSugar();
    
    cout<<coffee.getCost();

    return 0;
}