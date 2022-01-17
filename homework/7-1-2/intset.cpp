#include <iostream>
#include <algorithm>
#include "intset.h"

using namespace std;

void IntegerSet::AddNumber(int num){
	int cnt = 0;
	for(int i=0;i<numbers_.size();i++){
		if(num == numbers_[i])
			cnt++;
	}
	if(cnt == 0)
		numbers_.push_back(num);
	sort(numbers_.begin(),numbers_.end());
}

void IntegerSet::DeleteNumber(int num){
	for(int i = 0; i < numbers_.size(); i++){
		if(num == numbers_[i]){
			numbers_.erase(numbers_.begin()+i);
		}
	}
}

int IntegerSet::GetItem(int pos){
	if(numbers_.size()-1 > pos)
		return numbers_[pos];
	else 
		return -1;
}
vector<int> IntegerSet::GetAll(){
	return numbers_;
}


