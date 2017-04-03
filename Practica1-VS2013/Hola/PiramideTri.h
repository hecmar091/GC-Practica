#pragma once

#include "MallaTriangulo.h";
#include "TriAnimado.h";

class PiramideTri
{
public:
	PiramideTri();
	PiramideTri(int _radio, int _altura);
	PiramideTri(TriAnimado tri, int _altura);

	~PiramideTri();

	int radio;
	int altura;

	MallaTriangulo triangulos[3];

	void draw();
	void drawDiabolo();
	void drawDiaboloTex();
	void drawTex();
};

