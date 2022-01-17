#include <algorithm>
#include <functional>
#include <iostream>
#include "sorted.h"

using namespace std;

SortedArray::SortedArray(){}
SortedArray::~SortedArray(){}

void SortedArray::AddNumber(int num){
	numbers_.push_back(num);
	numbers_ = GetSortedAscending();
}

std::vector<int> SortedArray::GetSortedAscending(){
	sort(numbers_.begin(),numbers_.end());
	return numbers_;
}

std::vector<int> SortedArray::GetSortedDescending(){
	sort(numbers_.rbegin(),numbers_.rend());
	return numbers_;
}

int SortedArray::GetMax(){
	GetSortedAscending();
	int max;
	max = numbers_.back();
	return max;
}

int SortedArray::GetMin(){
	GetSortedAscending();
	int min;
	min = numbers_.front();
	return min;
}
