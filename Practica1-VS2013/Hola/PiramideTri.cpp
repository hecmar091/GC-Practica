#include "PiramideTri.h"


PiramideTri::PiramideTri()
{
	
}

PiramideTri::PiramideTri(int _radio, int _altura)
{
	radio = _radio;
	altura = _altura;
	
	MallaTriangulo tr1 = MallaTriangulo(radio);
	MallaTriangulo tr2 = MallaTriangulo(radio);
	MallaTriangulo tr3 = MallaTriangulo(radio);

	triangulos[0] = tr1;
	triangulos[1] = tr2;
	triangulos[2] = tr3;	
}

PiramideTri::~PiramideTri()
{
	delete[] triangulos;
}

void PiramideTri::draw()
{
	triangulos[0].draw();
	triangulos[1].draw();
	triangulos[2].draw();
}
