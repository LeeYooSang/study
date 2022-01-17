#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Canvas{
	public:
		vector<vector<char>> temp;
		Canvas(size_t row, size_t col);
		~Canvas();
		void Resize(size_t w, size_t h);
		void DrawPixel(int x, int y, char brush);
		void Print();
		void Clear();

		int row(){
			return row_;
		}
		int col(){
			return col_;
		}
		int row_;
		int col_;
		int d_row;
		int d_col;
};

class Shape{
	public:
		virtual ~Shape(){};
		virtual void Draw(Canvas* canvas){};
		virtual void showInfo(){};
	protected:
		int xpos_;
		int ypos_;
		char brush_;
};

class Rectangle:public Shape{
	public:
		Rectangle(int xpos, int ypos, int width, int height, char brush){
			this->xpos_ = xpos;
			this->ypos_ = ypos;
			this->brush_ = brush;
			this->height_ = height;
			this->width_ = width;
		}
		void Draw(Canvas *canvas);
		void showInfo();
	protected:
		int height_;
		int width_;
};

class UpTriangle:public Shape{
	public:
		UpTriangle(int xpos, int ypos, int height, char brush){
			this->xpos_ = xpos;
			this->ypos_ = ypos;
			this->brush_ = brush;
			this->height_ = height;
		}
		void Draw(Canvas* canvas);
		void showInfo();
	protected:
		int height_;
};

class DownTriangle:public Shape{
	public:
		DownTriangle(int xpos, int ypos, int height, char brush){
			this->xpos_ = xpos;
			this->ypos_ = ypos;
			this->height_ = height;
			this->brush_ = brush;
		}
		void Draw(Canvas* canvas);
		void showInfo();
	protected:
		int height_;
};

class Diamond:public Shape{
	public:
		Diamond(int xpos, int ypos, int height, char brush){
			this->xpos_ = xpos;
			this->ypos_ = ypos;
			this->brush_ = brush;
			this->height_ = height;
			this->brush_ = brush;
		}
		void Draw(Canvas* canvas);
		void showInfo();
	protected:
		int height_;
};	
