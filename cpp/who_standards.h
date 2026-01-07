#ifndef WHO_STANDARDS_H
#define WHO_STANDARDS_H

#include <map>
#include <vector>

struct LMS {
    double L;
    double M;
    double S;
};

// Sex enum
enum class Sex {
    BOY,
    GIRL
};

// Data containers
// Key: Age in Months
// Value: LMS parameters
// NOTE: Using sample data points for demonstration. 
// In a real app, this would be a full map 0-60.
std::map<int, LMS> boys_data = {
    {0,  {-0.06, 13.4, 0.08}},
    {6,  {-0.06, 16.8, 0.08}},
    {12, {-0.06, 17.4, 0.09}},
    {24, {-0.06, 16.2, 0.09}},
    {36, {-0.06, 15.7, 0.09}},
    {48, {-0.06, 15.3, 0.09}},
    {60, {-0.06, 15.2, 0.09}}
};

std::map<int, LMS> girls_data = {
    {0,  {-0.06, 13.2, 0.08}},
    {6,  {-0.06, 16.2, 0.08}},
    {12, {-0.06, 16.8, 0.09}},
    {24, {-0.06, 15.8, 0.09}},
    {36, {-0.06, 15.4, 0.09}},
    {48, {-0.06, 15.1, 0.09}},
    {60, {-0.06, 15.0, 0.09}}
};

#endif
