#pragma once
#include <iostream>
#include <string>

class Shape{
	public:
		Shape();

		double GetArea() {};
		int GetPerimeter() {};
		void Draw(int canvas_width, int canvas_height) {};

	protected:
		int xpos_;
		int ypos_;
		char brush_;
};

class Rectangle:public Shape{
	public:
		Rectangle(int xpos, int ypos, int width, int height, char brush){
			xpos_ = xpos;
			ypos_ = ypos;
			brush_ = brush;
			height_ = height;
			width_ = width;
		}
		double GetArea();
		int GetPerimeter();
		void Draw(int can_width, int can_height);
	protected:
		int width_;
		int height_;
};

class Square:public Shape{
	public:
		Square(int xpos, int ypos, int width, char brush){
			xpos_ = xpos;
			ypos_ = ypos;
			brush_ = brush;
			width_ = width;
		}
		double GetArea();
		int GetPerimeter();
		void Draw(int can_width, int can_height);
	protected:
		int width_;
};

class Diamond:public Shape{
	public:
		Diamond(int xpos, int ypos, int dis, char brush){
			xpos_ = xpos;
			ypos_ = ypos;
			brush_ = brush;
			dis_ = dis;
		}
		double GetArea();
		int GetPerimeter();
		void Draw(int can_width, int can_height);
	protected:
		int dis_;
};
