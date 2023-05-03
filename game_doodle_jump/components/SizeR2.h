#pragma once
#include <tuple>

class SizeR2 {
public:
	SizeR2(double width, double height): width(width), height(height) {}

	int getWidth() 
	{
		return width;
	}

	int getHeigth() 
	{
		return height;
	}

	void setWidth(double weigth)
	{
		this->width = weigth;
	}

	void setHeigth(double heigth)
	{
		this->height = heigth;
	}

	friend bool operator==(const SizeR2& lhs, const SizeR2& rhs)
	{
		return std::tie(lhs.width, lhs.height) == std::tie(rhs.width, rhs.height);
	}

private:
	double width;
	double height;
};