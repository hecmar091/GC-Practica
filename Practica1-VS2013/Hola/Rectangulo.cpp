#include "Rectangulo.h"

Rectangulo::Rectangulo()
{
}

Rectangulo::Rectangulo(int _ancho, int _alto)
{
	ancho = _ancho;
	alto = _alto;

	vertices[0] = PVec3(-ancho / 2, -alto / 2, 0.0);
	vertices[1] = PVec3(-ancho / 2, alto / 2, 0.0);
	vertices[2] = PVec3(ancho / 2, alto / 2, 0.0);
	vertices[3] = PVec3(ancho / 2, -alto / 2, 0.0);

	coordenadasTextura[0] = CTex2(0, 0);
	coordenadasTextura[1] = CTex2(0, 1);
	coordenadasTextura[2] = CTex2(1, 1);
	coordenadasTextura[3] = CTex2(1, 0);

	color = Color4(1, 1, 1, 1);

	normal = vertices[0].cross(vertices[3]);
}

Rectangulo::~Rectangulo()
{
}

void Rectangulo::set(int _ancho, int _alto)
{
	ancho = _ancho;
	alto = _alto;

	vertices[0].set(-ancho / 2, -alto / 2, 0.0);
	vertices[1].set(-ancho / 2, alto / 2, 0.0);
	vertices[2].set(ancho / 2, alto / 2, 0.0);
	vertices[3].set(ancho / 2, -alto / 2, 0.0);

	normal = vertices[0].cross(vertices[3]);
}

void Rectangulo::draw()
{
	//Dibujar los vertices del rectangulo
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
	
	//Dibujar las coordenadas de textura del rectangulo
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_DOUBLE, 0, coordenadasTextura);

	glNormal3f(normal.x, normal.y, normal.z);

	glColor4f(color.r, color.g, color.b, color.a);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}
