#include <iostream>
#include <vector>
#include "clock_time.h"
#include "clocks.h"

using namespace std;

int main() {
	vector<Clock*> clock;
	clock.push_back(new SundialClock(0, 0, 0));
	clock.push_back(new CuckooClock(0, 0, 0));
	clock.push_back(new GrandFatherClock(0, 0, 0));
	clock.push_back(new WristClock(0, 0, 0));
	clock.push_back(new AtomicClock(0, 0, 0));
	for(Clock* clock_ : clock){
	       	clock_->reset();
	}
	int sec;
	cin >> sec;
	cout << "Reported clock times after resetting:" << endl;
	for(Clock* clock_ : clock){
	       	clock_->displayTime();
	}
	cout << endl << "Running the clocks..." << endl << endl;
	cout << "Reported clock times after running:" << endl;
	for(Clock* clock_ : clock) {
		for(int i = 0; i < sec; i++) {
			clock_->tick();
		}
		clock_->displayTime();
	}
	for(Clock* clock_ : clock){
		delete clock_;
	}
	return 0;
}
