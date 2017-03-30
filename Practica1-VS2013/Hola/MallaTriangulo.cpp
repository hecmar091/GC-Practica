#include <cmath>

#include "MallaTriangulo.h"

MallaTriangulo::MallaTriangulo()
{
	numDat = 3;
	vertices = normales = nullptr;
}

MallaTriangulo::MallaTriangulo(int radio)
{
	numDat = 3;
	vertices = new PVec3[numDat];
	normales = new PVec3[numDat];
	
	//X =R cos(ang)   tenemos que aumentar 2*pi/3 para cada vertice
	//Y =R sin(ang)


	vertices[0] = PVec3(radio*cos(0), radio*sin(0), 0.0);
	vertices[1] = PVec3(radio*cos(2*PI/3), radio*sin(2*PI/3), 0.0);
	vertices[2] = PVec3(radio*cos(4*PI/3), radio*sin(4*PI/3), 0.0);

	normales[0] = vertices[0].cross(vertices[1]);
	normales[1] = vertices[1].cross(vertices[2]);
	normales[2] = vertices[2].cross(vertices[0]);
}

MallaTriangulo::MallaTriangulo(PVec3 v1, PVec3 v2, PVec3 v3)
{
	numDat = 3;
	vertices = new PVec3[numDat];
	normales = new PVec3[numDat];

	vertices[0] = v1;
	vertices[1] = v2;
	vertices[2] = v3;

	normales[0] = vertices[0].cross(vertices[1]);
	normales[1] = vertices[1].cross(vertices[2]);
	normales[2] = vertices[2].cross(vertices[0]);
}

MallaTriangulo::~MallaTriangulo()
{
	delete[] vertices;
	delete[] normales;
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
	glDrawArrays(GL_TRIANGLES, 0, numDat); 
	desactivar();
}
