#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "canvas.h"

using namespace std;

bool d_isinshape(int nx, int ny, int I){
	double s = (ny-nx);
	double t = (ny+nx);
	if((t>=0 && t<=2*I) && (s>=0 && s<=2*I))
		return true;
	else 
		return false;
}

bool ut_isinshape(int nx, int ny, int height){
	double s = (ny-nx);
	double t = (ny+nx);
	if(s>=0 && s<= 2 * height && t >= 0 && t <= 2 * height && ny < height)
		return true;
	else 
		return false;
}

bool dt_isinshape(int nx, int ny, int height){
	double s = (ny + nx);
	double t = (nx - ny);
	if(s <= 0 && s >= (-2)*height && t >= 0 && t <= 2*height&& ny > -height)
		return true;
	else
		return false;
}

Canvas::Canvas(size_t row, size_t col){
	row_ = row;
	col_ = col;
	temp.resize(row);
	for(int i=0; i<row_; i++){
		for(int j=0; j<col_; j++){
			temp[i].push_back('.');
		}
	}
}

Canvas::~Canvas(){}

void Canvas::Resize(size_t w, size_t h){
	row_ = h;
	col_ = w;
	d_row = h - row_;
	d_col = w - col_;
	temp.resize(h);
	for(int i=0; i<temp.size();i++){
		temp[i].resize(w);
	}
	for(int i=0; i<row_; i++){
		for(int j=0; j<col_; j++){
			temp[i][j] = '.';
		}
	}
}

void Canvas::DrawPixel(int x, int y, char brush){
	temp[y][x] = brush;
}

void Canvas::Print(){
	cout<< " ";
	for(int i = 0; i< col_; i++){
		cout << i%10;
	}
	cout << endl;
	for(int i=0; i<row_; i++){
		cout << i%10;
		for(int j=0; j< col_;j++){
			cout << temp[i][j];
		}
		cout << endl;
	}
	for(int i=0; i< row_; i++){
		for(int j=0; j< col_; j++){
			temp[i][j] = '.';
		}
	}
}

void Rectangle::Draw(Canvas *canvas){
	int row = canvas->row();
	int col  = canvas->col();
	for(int i=0; i<row; i++){
		for(int j=0; j<col ; j++){
			if(i >= ypos_ && i < ypos_ + height_ && j >= xpos_ && j < xpos_ + width_){
				canvas->DrawPixel(j,i,brush_);
			}
		}
	}
}

void Rectangle::showInfo(){
	cout << "rect " << xpos_ << " " << ypos_ << " " << width_ << " " << height_ << " " << brush_ << endl;
}

void UpTriangle::Draw(Canvas *canvas){
	int row = canvas->row();
	int col = canvas->col();
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(ut_isinshape(j- xpos_, i- ypos_ , height_))
				canvas->DrawPixel(j,i, brush_);
		}
	}
}

void UpTriangle::showInfo(){
	cout << "tri_up " << xpos_ << " " << ypos_ << " " << height_ << " " << brush_ << endl;
}

void DownTriangle::Draw(Canvas *canvas){
	int row = canvas->row();
	int col = canvas->col();
	for(int i=0; i<row;i++){
		for(int j=0; j<col; j++){
			if(dt_isinshape(j- xpos_, i- ypos_, height_))
				canvas->DrawPixel(j,i,brush_);
		}
	}
}

void DownTriangle::showInfo(){
	cout << "tri_down " << xpos_ << " " << ypos_ << " " << height_ << " " << brush_ << endl;
}

void Diamond::Draw(Canvas *canvas){
	int row = canvas->row();
	int col = canvas->col();
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(d_isinshape(j- xpos_, i- ypos_, height_))canvas->DrawPixel(j,i,brush_);
		}
	}
}

void Diamond::showInfo(){
	cout << "diamond " << xpos_ << " " << ypos_ << " " << height_ << " " << brush_ << endl;
}
