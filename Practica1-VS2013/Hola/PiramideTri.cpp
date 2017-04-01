#include "PiramideTri.h"


PiramideTri::PiramideTri()
{
	
}

PiramideTri::PiramideTri(int _radio, int _altura)
{
	radio = _radio;
	altura = _altura;
	
	triangulos[0] = MallaTriangulo(radio);
	triangulos[1] = MallaTriangulo(radio);
	triangulos[2] = MallaTriangulo(radio);
}

PiramideTri::~PiramideTri()
{
}

void PiramideTri::draw()
{
	triangulos[0].draw();
	triangulos[1].draw();
	triangulos[2].draw();
}
