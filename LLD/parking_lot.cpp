#include<bits/stdc++.h>
using namespace std;
class Vehicle{
    public:
    string id;
    string type;
    Vehicle(string id, string type){
        this -> id = id;
        this -> type = type;
    }
    string getId(){
        return this -> id;
    }
    virtual string getType() {return "VEHICLE" ;}
};

class Bike : public Vehicle{
    public: 
    Bike(string id) : Vehicle(id, "BIKE") {}
    string getType() override {
        return "BIKE";
    }

   
};

class Car : public Vehicle{
    public: 
    Car(string id) : Vehicle(id, "CAR") {}
    string getType() override {
        return "CAR";
    }
};

class Slot{
    public: 
    map<string,set<int> > mp;
    map<string,int> mp2;

    int getSlot(string &type){
        if(mp[type].size() == 0) return -1;
        return *mp[type].begin();
    }
    int getSlotid(string vehicle_id){
        return mp2[vehicle_id];
    }
};

class TimeParked{
    public:
    map<string, pair<int,int> > timeMap;

    int getHours(string id){
        return timeMap[id].second - timeMap[id].first;
    }
};

class Payment{
    public:

    virtual int cost(int hours){return 0;}
};

class BikePayment : public Payment{
    public:


    int cost(int hours) override {
        return hours * 10;
    }
};
class CarPayment : public Payment{
    public:
    int cost(int hours) override {
        return hours * 10;
    }
};

class PrintPayment{
    public : 
    Payment * ptr;
    int cost;
    int hours;
    PrintPayment(int hours){
        this -> hours = hours;
    }
    void print(string type){
        if(type == "BIKE") {
            ptr = new BikePayment();
            cost = ptr -> cost(hours);
        }
        else if(type == "CAR"){
            ptr = new CarPayment();
            cost = ptr -> cost(hours);
        }
        cout<<"Pay rupees "<<cost<<endl;
        return;
    }
};


class lot{
    public:
    Slot * st;
    TimeParked * time;
    PrintPayment * pp;
    void park(Vehicle *v){
        string type = v -> getType();
        int slotId = st -> getSlot(type);
        if(slotId == -1){
            cout<<"No spot available"<<endl;
            return;
        }
        else{
            cout<<"Parked Successfully"<<endl;
            st -> mp[type].erase(slotId);
            string id = v -> getId();
            auto now = std::chrono::system_clock::now();
            std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            std::tm local_tm = *std::localtime(&now_time);
            time -> timeMap[id].first = local_tm.tm_hour;
        }
    }
    void unpark(Vehicle *v){
        string type = v -> getType();
        cout<<"Unparked Successfully"<<endl;
        string id = v -> getId();
        int slotId = st -> getSlotid(id);
        st -> mp[type].insert(slotId);
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        std::tm local_tm = *std::localtime(&now_time);
        time -> timeMap[id].second = local_tm.tm_hour;
        int hours = time -> getHours(id);
        pp = new PrintPayment(hours);
        pp -> print(type);
    }
};