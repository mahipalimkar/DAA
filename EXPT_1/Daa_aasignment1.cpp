#include <iostream>
using namespace std;

// Program to calculate SPI and CPI
// SPI is semester-wise and CPI is the overall result of the student

int main() {
    cout << "Enter the number of subjects in your semester: ";
    int subjects;
    cin >> subjects;

    int credits[subjects];
    int grades[subjects];

    cout << "Enter credits for each subject one by one:" << endl;
    for(int i = 0; i < subjects; i++) {
        cin >> credits[i];
    }

    cout << "Enter grades you got for each subject one by one:" << endl;
    for(int i = 0; i < subjects; i++) {
        cin >> grades[i];
    }

    // SPI calculation
    int total = 0;
    int total_credits = 0;
    for(int i = 0; i < subjects; i++) {
        total += credits[i] * grades[i];
        total_credits += credits[i];
    }

    float spi = static_cast<float>(total) / total_credits;
    cout << "Your SPI is: " << spi << endl;

    // CPI calculation
    cout << "Enter SPI for all semesters (8 semesters of engineering):" << endl;
    float spi_arr[8];
    for(int i = 0; i < 8; i++) {
        cin >> spi_arr[i];
    }

    cout << "Enter total credits of all semesters, semester-wise:" << endl;
    int credits_arr[8];
    for(int i = 0; i < 8; i++) {
        cin >> credits_arr[i];
    }

    int total_final = 0;
    int credits_total = 0;
    for(int i = 0; i < 8; i++) {
        total_final += spi_arr[i] * credits_arr[i];
        credits_total += credits_arr[i];
    }

    float cpi = static_cast<float>(total_final) / credits_total;
    cout << "Your CPI is: " << cpi << endl;

    return 0;
}
