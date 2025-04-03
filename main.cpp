#include <iostream>
using namespace std;

class Customeraccount {
    private:
    string name;
    int nights;
    double totalbill;
    public:
    Customeraccount() {
        name = " ";
        nights = 0;
        totalbill = 0;
    }
    void setcustomerdetails(string name,int n) {
        this->name = name;
        this->nights = n;
    }
    void addroomcharges(double amount) {
        totalbill += amount;
    }
    void addservice(double amount) {
        totalbill += amount;
    }
    double gettotalbill() {
        return totalbill;
    }
    void display() {
        cout << "Name: " << this->name << endl;
        cout << "Nights: " << this->nights << endl;
        cout << "Total bill: " << this->totalbill << endl;
    }
};

class Room {
    private:
    double roomrates[3];
    public:
    Room() {
        roomrates[1] = 100;
        roomrates[2] = 200;
        roomrates[3] = 300;
    }
    void bookroom(Customeraccount &account,int roomtype,int nights) {
        double charge = roomrates[roomtype] * nights;
        account.addroomcharges(charge);
    }
};

class Service {
    private:
    double servicerates[4];
    public:
    Service() {
        servicerates[1] = 15;
        servicerates[2] = 25;
        servicerates[3] = 50;
        servicerates[4] = 10;
    }
    void addservice(Customeraccount &account,int servicetype) {
        account.addservice(servicerates[servicetype]);
    }
};


int main() {
    Customeraccount customer1;
    Room room1;
    Service service1;
    string name;
    int nights;

    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter nights: ";
    cin >> nights;
    customer1.setcustomerdetails(name,nights);

    int roomtype;
    cout << "Enter room number: ";
    cin >> roomtype;
    room1.bookroom(customer1,roomtype,nights);

    int servicetype;
    cout << "\nSelect additional services (-1 to stop):\n";
    cout << "0 - Breakfast ($15)\n1 - Laundry ($25)\n2 - Spa ($50)\n3 - WiFi ($10)\n";
    cin >> servicetype;
    service1.addservice(customer1,servicetype);

    customer1.display();

    return 0;
}
