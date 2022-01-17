#include <iostream>
#include <string>
#include "shapes.h"

using namespace std;

Shape::Shape(){
	xpos_=0;
	ypos_=0;
	brush_=0;
}

double Rectangle::GetArea(){
	return width_* height_;
}

int Rectangle::GetPerimeter(){
	return 2*(width_ + height_);
}

void Rectangle::Draw(int can_width, int can_height){
	char** arr = new char*[can_height];
	for(int i=0; i < can_height; i++){
		arr[i] = new char[can_width];
	}
	for(int i=0; i < can_height; i++){
		for(int j=0; j < can_width; j++){
		arr[i][j] = '.';
		}
	}
	int h_max, w_max;
	if(xpos_ + width_ > can_width)
		w_max = can_width;
	else 
		w_max = xpos_ + width_;
	if(ypos_ + height_ > can_height)
		h_max = can_height;
	else 
		h_max = ypos_ + height_;
	for(int i=ypos_; i < h_max; i++){
		for(int j = xpos_; j < w_max; j++){
			arr[i][j] = brush_;
		}
	}
	cout <<" ";
        for(int i=0;i<can_width;i++){
		cout<<i;
        }
        cout << endl;
        for(int i=0; i<can_height; i++){
                cout << i ;
	        for(int j=0; j<can_width; j++){
	                cout << arr[i][j];
	        }
		cout << endl;
	}
	for(int i=0; i<can_height; i++)
		delete[] arr[i];
	delete[] arr;
}

double Square::GetArea(){
	return width_ * width_;
}

int Square::GetPerimeter(){
	return 4* width_;
}

void Square::Draw(int can_width, int can_height){
	char** arr = new char*[can_height];
	for(int i=0;i<can_height; i++){
		arr[i] = new char[can_width];
	}
	for(int i=0; i<can_height; i++){
		for(int j=0; j<can_width; j++){
			arr[i][j] = '.';
		}
	}
	int h_max, w_max;
	if(xpos_ + width_ > can_width)
		w_max = can_width;
	else 
		w_max = xpos_ + width_;
	if(ypos_ + width_ > can_height)
		h_max = can_height;
	else
		h_max = ypos_ + width_;
	for(int i=ypos_; i<h_max; i++){
		for(int j=xpos_; j < w_max; j++){
			arr[i][j] = brush_;
		}
	}
	cout << " ";
	for(int i=0; i < can_width; i++){
		cout<<i ;
	}
	cout << endl;
	for(int i=0; i<can_height; i++){
		cout<< i;
		for(int j=0; j < can_width; j++){
			cout << arr[i][j] ;
		}
		cout << endl;
	}
	for(int i=0; i<can_height; i++){
		delete[] arr[i];
	}
	delete[] arr;
}

double Diamond::GetArea(){
	double area = (float(dis_)*2 + 1)*(dis_*2 +1)/2;
	return area;
}

int Diamond::GetPerimeter(){
	return 4*(dis_+1)*2;
}

void Diamond::Draw(int can_width, int can_height){
	char** arr = new char*[can_height];
	for(int i = 0; i < can_height; i++){
		arr[i] = new char[can_width];
	}
	for(int i=0; i<can_height; i++){
		for(int j=0; j<can_width; j++){
			arr[i][j] = '.';
		}
	}
	int h_max, w_min, w_max;
	if(ypos_ + (2*dis_) > can_height)
		h_max = can_height - 1;
	else
		h_max = ypos_ + (2*dis_);
	for(int i=ypos_;i<=h_max; i++){
		if(i-ypos_ <= dis_){
			w_min = xpos_ - (i-ypos_);
			w_max = xpos_ + (i - ypos_);
			if(w_min < 0)
				w_min = 0;
			if(w_max > can_width)
				w_max = can_width -1;
		}
		else{
			w_min = xpos_ - (2*dis_ - (i - ypos_));
			w_max = xpos_ + (2*dis_ - (i - ypos_));
			if(w_min <0)
				w_min = 0;
			if(w_max > can_width)
				w_max = can_width -1;
		}
		for(int j = w_min; j <= w_max; j++){
			arr[i][j] = brush_;
		}
	}
	cout << " ";
	for(int i=0;i<can_width; i++){
		cout << i ;
	}
	cout << endl;
	for(int i=0;i<can_height; i++){
		cout << i ;
		for(int j=0; j < can_width; j++){
			cout << arr[i][j] ;
		}
		cout << endl;
	}
	for(int i=0; i < can_height; i++){
		delete[] arr[i];
	}
	delete[] arr;
}
