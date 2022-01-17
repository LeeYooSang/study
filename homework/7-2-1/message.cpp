#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "message.h"

using namespace std;

void MessageBook::AddMessage(int number, const string& message){
	map<int,string>::iterator it;
	if(messages_.find(number) == messages_.end()) 	
		messages_.insert(make_pair(number, message));
	else 
		messages_[number] = message;
}

void MessageBook::DeleteMessage(int number){
	messages_.erase(number);
}

vector<int> MessageBook::GetNumbers(){
	vector<int> intVec;
	map<int, string>::iterator it;
	for(it = messages_.begin(); it != messages_.end();it++)
		intVec.push_back(it->first);
	return intVec;
}

const string& MessageBook:: GetMessage(int number){
	map<int,string>::iterator it;
	it = messages_.find(number);
	return it->second;
}
MessageBook::MessageBook(){}
MessageBook::~MessageBook(){}
