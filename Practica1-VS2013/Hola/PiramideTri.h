#pragma once

#include "MallaTriangulo.h";

class PiramideTri
{
public:
	PiramideTri();
	PiramideTri(int _radio, int _altura);
	~PiramideTri();

	int radio;
	int altura;

	MallaTriangulo triangulos[3];

	void draw();
	void drawDiabolo();
};

