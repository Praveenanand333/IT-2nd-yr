#include <iostream>
using namespace std;

class Distance {
    private:
        int meters;
        int kilometers;
    
    public:
        Distance(int m, int km) {
            meters = m;
            kilometers = km;
        }
    
        friend Distance* compareDistance(Distance* d1, Distance* d2);
};

Distance* compareDistance(Distance* d1, Distance* d2) {
    int total_distance1 = (d1->kilometers * 1000) + d1->meters;
    int total_distance2 = (d2->kilometers * 1000) + d2->meters;

    if (total_distance1 > total_distance2) {
        cout<<"D1";
        return d1;
    } else {
        cout<<"D2";
        return d2;
    }
}

int main() {
    Distance* d1 = new Distance(100, 2);
    Distance* d2 = new Distance(200, 1);
    cout << "The distance object with greater distance is: " << endl;
     Distance* greaterDistance = compareDistance(d1, d2);
}
