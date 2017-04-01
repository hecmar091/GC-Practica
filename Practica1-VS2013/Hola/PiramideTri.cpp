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


	PVec3 verticeCero = triangulos[0].obtenerVertice(0);
	PVec3 verticeCeroModif = PVec3(0, 0, 2 * altura);
	triangulos[0].modificarVertice(verticeCeroModif, 0);

	PVec3 verticeUno = triangulos[1].obtenerVertice(1);
	PVec3 verticeUnoModif = PVec3(0, 0, 2 * altura);
	triangulos[1].modificarVertice(verticeUnoModif, 1);

	PVec3 verticeDos = triangulos[2].obtenerVertice(2);
	PVec3 verticeDosModif = PVec3(0, 0, 2 * altura);
	triangulos[2].modificarVertice(verticeDosModif, 2);
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
