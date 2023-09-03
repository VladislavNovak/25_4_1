#include <iostream>
#include "../include/utility.h"
#include "../include/surgical.h"

void SurgicalData::setPoints() {
    std::cout << "Enter first X: ";
    beg.x = putInput();
    std::cout << "Enter first Y: ";
    beg.y = putInput();
    std::cout << "Enter second X: ";
    end.x = putInput();
    std::cout << "Enter second Y: ";
    end.y = putInput();
}

void SurgicalData::doFirstHemostat() const {
    printf("First hemostat with point (%.1lf X %.1lf) was successful\n", beg.x, beg.y);
}

void SurgicalData::doFirstTweezers() const {
    printf("First tweezers with point (%.1lf X %.1lf) was successful\n", beg.x, beg.y);
}

void SurgicalData::doSecondHemostat() const {
    printf("Second hemostat with point (%.1lf X %.1lf) was successful\n", end.x, end.y);
}

void SurgicalData::doSecondTweezers() const {
    printf("Second tweezers with point (%.1lf X %.1lf) was successful\n", end.x, end.y);
}

void SurgicalData::doSuture() const {
    printf("Suture with points (%.1lf X %.1lf : %.1lf X %.1lf) was successful\n", beg.x, beg.y, end.x, end.y);
    std::cout << "Necessary operations completed successfully" << std::endl;
}

void SurgicalData::doScalpel() {
    setPoints();
    doFirstHemostat();
    doFirstTweezers();
    doSecondHemostat();
    doSecondTweezers();
    doSuture();
}

void SurgicalData::start() {
    doScalpel();
}
