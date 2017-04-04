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

	PVec3 verticeCeroModif = PVec3(0, 0, altura);
	triangulos[0].modificarVertice(verticeCeroModif, 0);

	PVec3 verticeUnoModif = PVec3(0, 0, altura);
	triangulos[1].modificarVertice(verticeUnoModif, 1);

	PVec3 verticeDosModif = PVec3(0, 0, altura);
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

void PiramideTri::drawTex()
{
	triangulos[0].drawTex();
	triangulos[1].drawTex();
	triangulos[2].drawTex();
}

void PiramideTri::drawDiabolo()
{
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	glRotated(-90, 1, 0, 0);
	glTranslated(0.0f, 0.0f, -altura);
	draw();
	glRotated(30, 0, 0, 1);
	draw();
	glTranslated(0.0f, 0.0f, 2 * altura);
	glRotated(180, 1, 0, 0);
	draw();
	glRotated(30, 0, 0, 1);
	draw();
	glPopMatrix();
}

void PiramideTri::drawDiaboloTex(){
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	glRotated(-90, 1, 0, 0);
	glTranslated(0.0f, 0.0f, -altura);
	drawTex();
	glRotated(30, 0, 0, 1);
	drawTex();
	glTranslated(0.0f, 0.0f, 2*altura);
	glRotated(180, 1, 0, 0);
	drawTex();
	glRotated(30, 0, 0, 1);
	drawTex();
	glPopMatrix();
}

void PiramideTri::setCoordenadasTextura(CTex2* coordenadas){
	for (int i = 0; i < 3; i++){
		triangulos[i].setCoordenadasTextura(coordenadas);
	}
};