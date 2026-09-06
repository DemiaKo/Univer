#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <Windows.h>
using namespace std;

struct Route {
    string start_station;
    string end_station;
    int stops_count;
    double length_km;
};

istream& operator>>(istream& is, Route& r) {
    is >> r.start_station >> r.end_station >> r.stops_count >> r.length_km;
    return is;
}

ostream& operator<<(ostream& os, const Route& r) {
    os << r.start_station << " -> " << r.end_station
        << " | Зупинок: " << r.stops_count
        << ", Довжина: " << r.length_km << " км";
    return os;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    vector<Route> routes;

    ifstream file("routes.txt");
    copy(istream_iterator<Route>(file), istream_iterator<Route>(), back_inserter(routes));

    auto print = [](const Route& r) { cout << r << '\n'; };

    cout << "--- Початковий список маршрутів ---\n";
    for_each(routes.begin(), routes.end(), print);

    sort(routes.begin(), routes.end(), [](const Route& a, const Route& b) {
        return a.length_km < b.length_km;
        });

    cout << "\n--- Відсортовані за протяжністю ---\n";
    for_each(routes.begin(), routes.end(), print);

    double distance = 60;
    int short_stops_count = count_if(routes.begin(), routes.end(), [distance](const Route& r) {
        if (r.stops_count <= 1) return false;
        double avg_dist = r.length_km / (r.stops_count - 1);
        return avg_dist < distance;
        });
    cout << "\nКількість маршрутів (сер. відстань між зупинками < " << distance << " км): "
        << short_stops_count << "\n";

    string target_station = "Lviv";
    vector<Route> target_routes;

    remove_copy_if(routes.begin(), routes.end(), back_inserter(target_routes),
        [target_station](const Route& r) {
            return r.start_station != target_station;
        });

    cout << "\n--- Маршрути, що починаються у станції " << target_station << " ---\n";
    for_each(target_routes.begin(), target_routes.end(), print);

    auto max = max_element(routes.begin(), routes.end(), [](const Route& a, const Route& b) {
        return a.stops_count < b.stops_count;
        });
    int max_stops = max->stops_count;
     
    cout << "\n--- Маршрути з максимальною кількістю зупинок (" << max_stops << ") ---\n";
    for_each(routes.begin(), routes.end(), [max_stops](const Route& r) {
        if (r.stops_count == max_stops) {
            cout << r << '\n';
        }
    });

    return(0);
}