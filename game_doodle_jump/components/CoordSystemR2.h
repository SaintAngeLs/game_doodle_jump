#pragma once

class CoordSystemR2 {
public:
	CoordSystemR2(double& x, double& y) : x(x), y(y) {}
	CoordSystemR2(double&& x, double&& y) : x(x), y(y) {}

	double getXCor() {
		return x;
	}

	void setXCor(double x)
	{
		this->x = x;
	}

	double getYCor() {
		return y;
	}

	void setYCor(double y)
	{
		this->y = y;
	}

private:
	double x;
	double y;
};