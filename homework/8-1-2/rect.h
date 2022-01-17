#pragma once

class Rectangle{
	public:
		Rectangle(){};
		Rectangle(int width, int height){
			width_ = width;
			height_ = height;
		}
		int getArea();
		int getPerimeter();
	protected:
		int width_;
		int height_;
};

class Square: public Rectangle{
	public:
		Square(int width){
			width_ = width;
			height_ = width;
		}
		void print();
};

class NonSquare: public Rectangle{
	public:
		NonSquare(int width, int height){
			width_ = width;
			height_ = height;
		}
		void print();
};
