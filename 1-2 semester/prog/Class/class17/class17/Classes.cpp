#include "Classes.h"
#include <cmath>

double Line::calc_y(double x) const {
    return (a*x+b);
}

double Elips::calc_y(double x) const
{
    if (std::abs(x) <= a) {
        return (b * std::sqrt(1.0 - (std::pow(x, 2) / std::pow(a, 2))));
    }
    else return (NAN);
}

double Hyperbola::calc_y(double x) const {
    if (std::abs(x) >= a) {
        return (b * std::sqrt((std::pow(x, 2) / std::pow(a, 2)) - 1.0));
    }
    else return(NAN);
}
