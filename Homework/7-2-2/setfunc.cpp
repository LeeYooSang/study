#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include "setfunc.h"

using namespace std;

set<int>parseSet(const string& str){
	set<int> st;
	string temp;
	stringstream split_stream(str);
	while(split_stream >> temp){
		st.insert(stoi(temp));
	}
	return st;
}

void printSet(const set<int>& st){
	set<int>::iterator it = st.begin();
	cout<<"{ ";
	for(it;it!=st.end();it++){
		cout<<*it<<" ";
	}
	cout << "}\n";
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1){
	set<int> st_;
	for(set<int>::iterator it = set0.begin();it != set0.end();it++)
		st_.insert(*it);
	for(set<int>::iterator it = set1.begin();it != set1.end();it++)
		st_.insert(*it);
	return st_;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1){
	set<int> set_0 = set0;
	set<int>::iterator it = set0.begin();
	for(int i=0;i<set0.size();i++){
		set<int>::iterator it1 = set1.begin();
		for(it1; it1!=set1.end();it1++){
			if(*it == *it1){
				set_0.erase(*it);
				break;
			}
		}
		it++;
	}
	return set_0;
}

set<int> getUnion(const set<int>& set0, const set<int>& set1){
	set<int> st_;
	set<int>::iterator it =set0.begin();
	for(int i=0;i<set0.size();i++){
		set<int>::iterator it1 = set1.begin();
		for(it1; it1 != set1.end(); it1++){
			if(*it == *it1){
				st_.insert(*it);
				break;
			}
		}
		it++;
	}
	return st_;
}
