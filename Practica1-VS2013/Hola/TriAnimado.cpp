#include "TriAnimado.h"


TriAnimado::TriAnimado()
{
}

TriAnimado::TriAnimado(int _radio)
{
	Triangulo = MallaTriangulo(_radio);
}

TriAnimado::TriAnimado(int _radio, double _anguloR, double _anguloRZ, double _radioR)
{
	Triangulo = MallaTriangulo(_radio);
	anguloR = _anguloR;
	anguloRZ = _anguloRZ;
	radioR = _radioR;
}

TriAnimado::~TriAnimado()
{
}

void TriAnimado::update(double _angulo)
{
	anguloRZ += _angulo;
	anguloR += _angulo;
}

void TriAnimado::draw()
{
	glPushMatrix();
	glRotated(anguloRZ, 0.0, 0.0, 1.0);
	glTranslated(radioR, 0, 0);
	glRotated(anguloR, 0.0, 0.0, 1.0);
	
	Triangulo.draw();

	glPopMatrix();
}

void TriAnimado::drawTex()
{
	glPushMatrix();
	
	glRotated(anguloRZ, 0.0f, 0.0f, 1.0f);
	glTranslated(radioR, 0, 0);
	glRotatef(anguloR, 0.0f, 0.0f, 1.0f);
	
	Triangulo.drawTex();

	glPopMatrix();
}
