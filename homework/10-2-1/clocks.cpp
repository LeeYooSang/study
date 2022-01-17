#include <iostream>
#include "clocks.h"

using namespace std;

void Clock::reset() {
	_clockTime.reset();
}

void Clock::tick() {
	_clockTime.increment();
	_totalDrift += _driftPerSecond;
}

void SundialClock::displayTime() {
	cout << "SundialClock ";
	_clockTime.display();
	cout << ", total drift: " << _totalDrift << endl;
}

void CuckooClock::displayTime() {
	cout << "CuckooClock ";
        _clockTime.display();
        cout << ", total drift: " << _totalDrift << endl;
}

void GrandFatherClock::displayTime() {
	cout << "GrandFatherClock ";
        _clockTime.display();
        cout << ", total drift: " << _totalDrift << endl;
}

void WristClock::displayTime() {
	cout << "WristClock ";
        _clockTime.display();
        cout << ", total drift: " << _totalDrift << endl;
}

void AtomicClock::displayTime() {
	cout << "AtimicClock ";
        _clockTime.display();
        cout << ", total drift: " << _totalDrift << endl;
}
