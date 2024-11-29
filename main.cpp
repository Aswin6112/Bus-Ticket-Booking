#include<iostream>
using namespace std;

class account;
class bus{
    int no_of_seats;
    int seats_available;
    int seats_to_book;
    int seat_cost;
    int amount_to_pay;
    string bus_name;
    public:
    bus(){
        int choice;
        cout<<"Enter your bus of choice\n1.KPN Travels\tSeats Available = 26\tCost = Rs.700\n2.Aravind Travels\tSeats Available = 20\tCost = Rs.900\n"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
            bus_name="KPN Travels";
            no_of_seats=26;
            seat_cost=700;
            amount_to_pay=0;
            seats_available=no_of_seats;
            break;
            case 2:
            bus_name="Aravind Travels";
            no_of_seats=20;
            seat_cost=900;
            amount_to_pay=0;
            seats_available=no_of_seats;
            break;
            default:
            cout<<"Enter a valid choice"<<endl;
            break;
        }
    }

    void book_seats(){
        cout<<"Seats Available = "<<seats_available<<" Cost = "<<seat_cost<<endl;
        cout<<"Enter the no of seats to book : ";
        cin>>seats_to_book;
        if(seats_to_book<=seats_available){
            seats_available-=seats_to_book;
            amount_to_pay=seats_to_book*seat_cost;
            cout<<"Amount to pay : Rs."<<amount_to_pay<<"\nPay the amount to complete your booking process"<<endl;
        }
        else{
            cout<<"Try to book available no of seats"<<endl;
        }
    }

    friend void pay(bus &b,account &a);

};

class account{
    int acc_no;
    string name;
    float balance;
    public:
    account(){
        cout<<"Enter your account no : ";
        cin>>acc_no;
        cout<<"Enter your name : ";
        cin>>name;
        cout<<"Enter your account balance : ";
        cin>>balance;
    }

    void withdraw(){
        int amount;
        cout<<"Enter the amount to withdraw : ";
        cin>>amount;
        if(amount>balance){
            cout<<"Insufficient Balance"<<endl;
        }
        else{
            balance-=amount;
            cout<<"Amount Withdrawn"<<endl;
        }
    }

    void deposit(){
        int amount;
        cout<<"Enter the amount to deposit : ";
        cin>>amount;
        balance+=amount;
        cout<<"Amount deposited"<<endl;
    }

    void display(){
        cout<<"Remaining Balance : "<<balance<<endl;
    }

    friend void pay(bus &b,account &a);
};

void pay(bus &b,account &a){
    int payment_amt;
    cout<<"Enter your payment amount : ";
    cin>>payment_amt;
    if(payment_amt==b.amount_to_pay){
        a.balance -= b.amount_to_pay;
        cout<<"Payment successful"<<endl;
        cout<<"Your seat is booked succesfully"<<"\nNo of seats booked : "<<b.seats_to_book<<endl;
    }
    else{
        cout<<"Enter correct amount"<<endl;
    }
    
}

int main(){
    bus B1;
    account A1;
    B1.book_seats();
    pay(B1,A1);
}
