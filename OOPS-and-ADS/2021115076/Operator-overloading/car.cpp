#include <iostream>
#include <string>
using namespace std;
class Car {
public:
    Car(int model, const string& name, double price) : model_number(model), car_name(name), car_price(price) {}
    friend double find_car_difference(const Car& car1, const Car& car2);
private:
    int model_number;
   string car_name;
    double car_price;
};
double find_car_difference(const Car& car1, const Car& car2) {
    return (car1.car_price - car2.car_price);
}

int main() {
    Car car1(2021, "Tesla Model S", 189990.00);
    Car car2(2022, "Porsche Taycan", 181600.00);
    double difference = find_car_difference(car1, car2);
    cout << "The difference in price between Car 1 and Car 2 is :" << difference <<endl;
}
