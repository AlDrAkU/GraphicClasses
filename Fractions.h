#pragma once

class Fractions {

private:
	int m_Numerator;
	int m_Denominator;


public:
	Fractions();
	Fractions(int numerator, int denominator);
	void Draw(const Point2f& pos, float size);
	float GetValue();






};