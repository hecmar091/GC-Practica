#include <cmath>

#include "MallaTriangulo.h"

MallaTriangulo::MallaTriangulo()
{
}

MallaTriangulo::MallaTriangulo(int _radio)
{
	//X =R cos(ang)   tenemos que aumentar 2*pi/3 para cada vertice
	//Y =R sin(ang)
	radio = _radio;
	
	vertices[0] = PVec3(radio*cos(0), radio*sin(0), 0.0);
	vertices[1] = PVec3(radio*cos(2*PI/3), radio*sin(2*PI/3), 0.0);
	vertices[2] = PVec3(radio*cos(4*PI/3), radio*sin(4*PI/3), 0.0);

	normales[0] = vertices[0].cross(vertices[1]);
	normales[1] = vertices[1].cross(vertices[2]);
	normales[2] = vertices[2].cross(vertices[0]);

	centro = PVec3((vertices[0].x + vertices[1].x + vertices[2].x) / 3, (vertices[0].y + vertices[1].y + vertices[2].y) / 3, 0.0);

	color = Color4(1, 1, 1, 1);

	coordenadasTextura[0] = CTex2(0, 0);
	coordenadasTextura[1] = CTex2(1, 0);
	coordenadasTextura[2] = CTex2(1, 1);
}

MallaTriangulo::~MallaTriangulo()
{
}

void MallaTriangulo::activar(){
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_DOUBLE, 0, normales); // (Tipo, Offset, PtrArray)
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
}

void MallaTriangulo::desactivar(){
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

void MallaTriangulo::draw(){
	activar(); 

	glColor4d(1.0, 0.0, 0.0, 0.0); // color red
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, 3); 

	desactivar();
}

void MallaTriangulo::drawTex(){
	activar();

	// activar texturas
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_DOUBLE, 0, coordenadasTextura);

	glColor4d(1.0, 0.0, 0.0, 0.0); // color red
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// desactivar texturas
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	desactivar();
}

void MallaTriangulo::modificarVertice(PVec3 cero, int index){
	vertices[index] = cero;
	//Recalcular normales, porque se ha modificado..
	normales[0] = vertices[0].cross(vertices[1]);
	normales[1] = vertices[1].cross(vertices[2]);
	normales[2] = vertices[2].cross(vertices[0]);
}

PVec3 MallaTriangulo::obtenerVertice(int index){
	return vertices[index];
}
