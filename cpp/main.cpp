#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include "who_standards.h"

// Calculate BMI: kg / (m * m)
double calculateBMI(double weightKg, double heightCm) {
    if (heightCm <= 0) return 0.0;
    double heightM = heightCm / 100.0;
    return weightKg / (heightM * heightM);
}

// Linear Interpolation for LMS
LMS getLMS(int ageMonths, const std::map<int, LMS>& data) {
    // Check for exact match
    if (data.count(ageMonths)) {
        return data.at(ageMonths);
    }

    // Find upper and lower bounds
    auto upper = data.lower_bound(ageMonths);
    
    // If age is past the last data point
    if (upper == data.end()) {
        return data.rbegin()->second;
    }

    // If age is before the first data point
    if (upper == data.begin()) {
        return upper->second;
    }

    auto lower = std::prev(upper);

    int m1 = lower->first;
    int m2 = upper->first;
    LMS lms1 = lower->second;
    LMS lms2 = upper->second;

    double fraction = (double)(ageMonths - m1) / (double)(m2 - m1);

    LMS result;
    result.L = lms1.L + (lms2.L - lms1.L) * fraction;
    result.M = lms1.M + (lms2.M - lms1.M) * fraction;
    result.S = lms1.S + (lms2.S - lms1.S) * fraction;

    return result;
}

double calculateZScore(double bmi, int ageMonths, Sex sex) {
    const auto& data = (sex == Sex::BOY) ? boys_data : girls_data;
    LMS params = getLMS(ageMonths, data);

    double L = params.L;
    double M = params.M;
    double S = params.S;

    double zScore = 0.0;

    if (std::abs(L) < 0.01) {
        zScore = std::log(bmi / M) / S;
    } else {
        zScore = (std::pow(bmi / M, L) - 1.0) / (L * S);
    }

    return zScore;
}

std::string getStatus(double zScore) {
    if (zScore > 3) return "Obese";
    if (zScore > 2) return "Overweight";
    if (zScore > 1) return "Possible risk of overweight";
    if (zScore >= -2) return "Normal";
    if (zScore >= -3) return "Wasted";
    return "Severely Wasted";
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "   WHO Child Growth Monitor (C++)" << std::endl;
    std::cout << "   Standards: 0-5 Years (BMI-for-age)" << std::endl;
    std::cout << "========================================" << std::endl;

    while(true) {
        int sexInput;
        std::cout << "\nSelect Sex (1=Boy, 2=Girl, 0=Exit): ";
        if (!(std::cin >> sexInput)) {
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (sexInput == 0) break;
        if (sexInput != 1 && sexInput != 2) {
            std::cout << "Invalid selection." << std::endl;
            continue;
        }
        Sex sex = (sexInput == 1) ? Sex::BOY : Sex::GIRL;

        int age;
        std::cout << "Enter Age (Months, 0-60): ";
        std::cin >> age;

        double weight;
        std::cout << "Enter Weight (kg): ";
        std::cin >> weight;

        double height;
        std::cout << "Enter Height (cm): ";
        std::cin >> height;

        // Calculations
        double bmi = calculateBMI(weight, height);
        double zScore = calculateZScore(bmi, age, sex);
        std::string status = getStatus(zScore);

        // Output
        std::cout << "\n--- Results ---" << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "BMI: " << bmi << std::endl;
        std::cout << "Z-Score: " << zScore << std::endl;
        std::cout << "Status: " << status << std::endl;
        std::cout << "---------------" << std::endl;
    }

    return 0;
}
