#include<iostream>
#include<vector>
using namespace std;

class Account
{   
    protected:
    
    int customer_id;
    int account_no;
    float balance;
    
    public:
    Account()
    {   
        customer_id=0;
        account_no=0;
        balance=0;
    }
    
    void set_customer_id(int customer_id)
    {
        this->customer_id=customer_id;
    }
    
    void set_account_no(int account_no)
    {
        this->account_no=account_no;
    }

    int get_customer_id()
    {
        return customer_id;
    }
    
    int get_account_no()
    {
        return account_no;
    }
    
    float get_balance()
    {
        return balance;
    }
    
    void credit(float amount)
    {
        balance = balance + amount;
    }
    
    void debit(float amount)
    {   
        if(balance - amount < 0)
        {
            cout<<"Not enough balance to debit\n";
            return;
        }
        balance = balance - amount;
    }
};

class Savings: public Account
{   
    float rate;
    
    public:
    
    Savings()
    {
        rate=0.2;   
    }
    
    float get_rate()
    {
        return rate;
    }
    
    void update_rate(float rate)
    {
        this->rate=rate;
    }
    
    float calculate_interest()
    {
        return balance * rate;
    }
    
    void calculate_update_interest()
    {
        credit(calculate_interest());
    }
};

class Checking: public Account
{   
    float fee;
    
    public:
    
    Checking()
    {
        fee=10;
    }
    
    float get_fee()
    {
        return fee;
    }
    
    void update_fee(float fee)
    {
        this->fee=fee;
    }
    
    void credit(float amount)
    {   
        if (balance + amount -fee<0)
        {
            cout<<"Not enough balance for transaction fee\n";
            return;
        }
        balance = balance + amount - fee;
    }
    
    void debit(float amount)
    {   
        if (balance -amount - fee<0)
        {
            cout<<"Not enough balance to debit\n";
            return;
        }
        balance = balance - amount - fee;
    }
};

Savings *check_savings_id(int customer_id,vector<Savings *> savings)
{
    for(auto customer:savings)
        if(customer->get_customer_id()==customer_id)
        {
            return customer;
        }
    Savings *temp=new Savings;
    return temp;
}

Savings *check_savings_no(int account_no,vector<Savings *> savings)
{
    for(auto customer:savings)
        if(customer->get_account_no()==account_no)
        {
            return customer;
        }
    Savings *temp=new Savings;
    return temp;
}

Checking *check_checking_id(int customer_id,vector<Checking *> checking)
{
    for(auto customer:checking)
        if(customer->get_customer_id()==customer_id)
        {
            return customer;
        }
    Checking *temp=new Checking;
    return temp;
}

Checking *check_checking_no(int account_no,vector<Checking *> checking)
{
    for(auto customer:checking)
        if(customer->get_account_no()==account_no)
        {
            return customer;
        }
    Checking *temp=new Checking;
    return temp;
}

Savings *savings_menu(int customer_id,vector<Savings *> savings)
{
    Savings *temp=check_savings_id(customer_id,savings);
    if(temp->get_customer_id()==0)
    {
        cout<<"Entered customer id does not exist\n";
        return temp;
    }
    
    if(temp->get_account_no()==0)
    {
        cout<<"You don't have a Savings account registered\n";
        return temp;
    }
    return temp;
}

Checking *checking_menu(int customer_id,vector<Checking *> checking)
{
    Checking *temp=check_checking_id(customer_id,checking);
    if(temp->get_customer_id()==0)
    {
        cout<<"Entered customer id does not exist\n";
        return temp;
    }
    
    if(temp->get_account_no()==0)
    {
        cout<<"You don't have a Checking account registered\n";
        return temp;
    }
    return temp;
}

void menu_input(int &customer_id,int &ch,int test=0)
{   
    cout<<"Customer ID : ";
    cin>>customer_id;
    if(test)
    {
        cout<<"1. Savings Account\n2. Checking Account\n";
        cout<<"Choice : ";
        cin>>ch;
    }
}

int main()
{   
    int ch=0, choice=0, customer_id, account_no;
    float amount, rate, fee;
    vector<Savings *> savings;
    vector<Checking *> checking;
    Savings *savings_temp;
    Checking *checking_temp;

    while(choice!=10)
    {
        cout<<"\n1.Open Account\n2.Credit\n3.Debit\n4.Update Interest Rate\n5.Calculate Interest\n6.Calculate and Update Interest\n7.Update Fee\n8.Print Fee\n9.Search customer details\n10.Exit\n";
        cout<<"Choice : ";
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                menu_input(customer_id,ch,1);
                if(ch==1)
                {   
                    if(check_savings_id(customer_id,savings)->get_customer_id()!=0)
                    {
                        cout<<"Already a Savings account exists, can't create a new one\n";
                        break;
                    }
                    cout<<"Enter account number for Savings account (1xx) : ";
                    cin>>account_no;
                    if(account_no/100!=1)
                    {
                        cout<<"Invalid account number (Savings account number should start with '1')\n";
                        break;
                    }
                    if(check_savings_no(account_no,savings)->get_account_no()!=0)
                    {
                        cout<<"Duplicate Savings account number already exists\n";
                        break;
                    }
                    else
                    {
                        Savings *new_account=new Savings;
                        new_account->set_customer_id(customer_id);
                        new_account->set_account_no(account_no);
                        savings.push_back(new_account);
                    }
                }
                
                if(ch==2)
                {   
                    if(check_checking_id(customer_id,checking)->get_customer_id()!=0)
                    {
                        cout<<"Already a Checkings account exists, can't create a new one\n";
                        break;
                    }
                    cout<<"Enter account number for Checking account (2xx) : ";
                    cin>>account_no;
                    if(account_no/100!=2)
                    {
                        cout<<"Invalid account number (Checkings account number should start with '2')\n";
                        break;
                    }
                    if(check_checking_no(account_no,checking)->get_account_no()!=0)
                    {
                        cout<<"Duplicate Checkings account number already exists\n";
                        break;
                    }
                    else
                    {
                        Checking *new_account=new Checking;
                        new_account->set_customer_id(customer_id);
                        new_account->set_account_no(account_no);
                        checking.push_back(new_account);
                    }
                }
                break;
                
            case 2:
                menu_input(customer_id,ch,1);
                if(ch==1)
                {   
                    savings_temp=savings_menu(customer_id,savings);
                    if(savings_temp->get_customer_id() && savings_temp->get_account_no())
                    {
                        cout<<"Enter the amount you want to credit : ";
                        cin>>amount;
                        savings_temp->credit(amount);
                    }
                }
                
                if(ch==2)
                {   
                    checking_temp=checking_menu(customer_id,checking);
                    if(checking_temp->get_customer_id() && checking_temp->get_account_no())
                    {
                        cout<<"Enter the amount you want to credit : ";
                        cin>>amount;
                        checking_temp->credit(amount);
                    }
                }
                break;
                
            case 3:
                menu_input(customer_id,ch,1);
                if(ch==1)
                {   
                    savings_temp=savings_menu(customer_id,savings);
                    if(savings_temp->get_customer_id() && savings_temp->get_account_no())
                    {
                        cout<<"Enter the amount you want to debit : ";
                        cin>>amount;
                        savings_temp->debit(amount);
                    }
                }
                
                if(ch==2)
                {   
                    checking_temp=checking_menu(customer_id,checking);
                    if(checking_temp->get_customer_id() && checking_temp->get_account_no())
                    {
                        cout<<"Enter the amount you want to debit : ";
                        cin>>amount;
                        checking_temp->debit(amount);
                    }
                }
                break;
            
            case 4:
                cout<<"Enter the new interest rate : ";
                cin>>rate;
                if(rate <0 || rate >1)
                {
                    cout<<"Invalid rate\n";
                    break;
                }
                for(auto savings_temp:savings)
                {
                    savings_temp->update_rate(rate);
                }
                break;
                
            case 5:
                menu_input(customer_id,ch);
                savings_temp=savings_menu(customer_id,savings);
                if(savings_temp->get_customer_id() && savings_temp->get_account_no())
                {
                    cout<<"Interest : "<<savings_temp->calculate_interest()<<endl;
                }
                break;
                
            case 6:
                menu_input(customer_id,ch);
                savings_temp=savings_menu(customer_id,savings);
                if(savings_temp->get_customer_id() && savings_temp->get_account_no())
                {   
                    savings_temp->calculate_update_interest();
                }
                break;
                
            case 7:
                cout<<"Enter the new transaction fee : ";
                cin>>fee;
                if(fee <0)
                {
                    cout<<"Invalid fee";
                    break;
                }
                for(auto checking_temp:checking)
                {
                    checking_temp->update_fee(fee);
                }
                break;
                
            case 8:
                menu_input(customer_id,ch);
                checking_temp=checking_menu(customer_id,checking);
                if(checking_temp->get_customer_id() && checking_temp->get_account_no())
                {
                    cout<<"Checking fee : "<<checking_temp->get_fee()<<endl;
                }
                break;
                
            case 9:
                menu_input(customer_id,ch);
                savings_temp=savings_menu(customer_id,savings);
                checking_temp=checking_menu(customer_id,checking);
                
                if(savings_temp->get_customer_id() && savings_temp->get_account_no())
                {   
                    cout<<"Savings Account Details"<<endl;
                    cout<<"Customer Id : "<<savings_temp->get_customer_id()<<endl;
                    cout<<"Account No : "<<savings_temp->get_account_no()<<endl;
                    cout<<"Balance : "<<savings_temp->get_balance()<<endl;
                    cout<<"Interest rate : "<<savings_temp->get_rate()<<endl;
                }
                if(checking_temp->get_customer_id() && checking_temp->get_account_no())
                {   
                    cout<<"Checking Account Details"<<endl;
                    cout<<"Customer Id : "<<checking_temp->get_customer_id()<<endl;
                    cout<<"Account No : "<<checking_temp->get_account_no()<<endl;
                    cout<<"Balance : "<<checking_temp->get_balance()<<endl;
                    cout<<"Transaction fee : "<<checking_temp->get_fee()<<endl;
                }
                break;
                
            case 10:
                break;
            default:
                cout<<"Invalid Entry\n";
                break;
        }
    }
    return 0;
}
