### State Design Pattern
 
 The State Pattern allows an object to change its behavior when its internal state changes.

 In simple words:

*Instead of writing a huge if-else / switch based on the current state, we create separate classes for each state.*

example :
An ATM can be
```
Idle -> Card Inserted -> Pin Verified -> Transaction -> Card Ejected -> Idle  
```
The same operation can behave differently depending on the state.

eg: ``` insertcard()``` :

- IDLE : card inserted successfully 
- Transaction : Cannot insert Card now 

so :
 ```
 Same Method -> Different Behavior -> Depending on state
 ``` 
 thats exactly where ** State Pattern ** helps.

 