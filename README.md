An inheritance hierarchy that a bank might use to represent customers' bank accounts. All customers at this bank can deposit (i.e., credit) and withdraw money from their Accounts. An account has a unique ID number that is used to identify an account holder. There are two types of sub-accounts namely, Savings and Checking accounts. Savings accounts earn interest on the money they hold. Checking accounts, on the other hand, charges a constant fee per transaction (i.e., credit or debit). A search option searches for a customer ID and it prints all the saving and checking out details of that customer if present. A customer ID can at max have 1 saving and 1 checking account. Assume an account number is a 3-digit number. An account number for a savings account will be 1xx and for a checking account will be 2xx, where x can take any digit between 0 to 9. The account numbers are unique. The data about the customers are stored in an array of objects. Public inheritance is used for derived classes. Proper boundary conditions are maintained.

A menu-driven program with the following options, 

1. Open Account (Savings or Checking Account)
2. Credit (Savings or Checking Account)
3. Debit (Savings or Checking Account)
4. Change/Update Interest rate (Savings Account)
5. Calculate Interest (Savings Account - Print)
6. Calculate and Update the Principle Amount with Interest (Savings Account - Credit)
7. Change/Update Fee Amount (Checking Account)
8. Print Checking Fee (Checking Account)
