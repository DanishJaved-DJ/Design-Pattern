A coffee shop has:

Base coffees (type)
- Simple Coffee → ₹100
- Espresso → ₹120
- Cappuccino → ₹150

Optional add-ons
- Milk → ₹20
- Sugar → ₹10
- Chocolate → ₹30
- Whipped Cream → ₹40

A customer can combine any number of add-ons.

for ex :
``` 
Cappuccino
+ Milk
+ Chocolate
+ Whipped Cream
```
total : 
```
150 + 20 + 30 + 40 = ₹240
```


#### STEP 1 : lets implement using classic OOPs concepts
 ```
   class Coffee{
     // see Bad_Design

   };
 ```
 - Problem 1 -> TOO many if-else 
     
     Now imagine the business says:

     * Add Caramel:
         We need to modify the Coffee class:Every new topping requires modifying the existing class.

     **That's an OCP violation.**

  - Problem 2 -> Combinatorial Explosion
             Suppose we have 4 toppings.
       ```
       No topping
       Milk
       Sugar
       Milk + Sugar
       Milk + Chocolate
       Sugar + Chocolate
       Milk + Sugar + Chocolate

       ```
     We obviously don't want a class for every combination.
    