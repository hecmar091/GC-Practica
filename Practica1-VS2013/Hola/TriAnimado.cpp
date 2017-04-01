#include "TriAnimado.h"


TriAnimado::TriAnimado()
{
}

TriAnimado::TriAnimado(int _radio)
{
	Triangulo = MallaTriangulo(_radio);
}

TriAnimado::TriAnimado(int _radio, float _anguloR, float _anguloRZ, float _radioR)
{
	Triangulo = MallaTriangulo(_radio);
	anguloR = _anguloR;
	anguloRZ = _anguloRZ;
	radioR = _radioR;
}

TriAnimado::~TriAnimado()
{
}

void TriAnimado::update(float _angulo)
{
	anguloRZ += _angulo;
	anguloR += _angulo;
}

void TriAnimado::draw()
{
	glPushMatrix();
	glRotatef(anguloRZ, 0.0f, 0.0f, 1.0f);//rota entorno al eje
	glTranslatef(radioR, 0, 0);
	glPushMatrix();
	glRotatef(anguloR, 0.0f, 0.0f, 1.0f);//rota entorno al eje del triangulo
	
	Triangulo.draw();

	glPopMatrix();
}
