#include <xtl.h>

#ifndef POLYHEDRAL
#define POLYHEDRAL

#define OVERLAP 8.0f

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

typedef struct s_CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
	FLOAT tu, tv;
}t_CUSTOMVERTEX, * p_CUSTOMVERTEX;

void CreateInvertedBox(FLOAT x1, FLOAT x2, FLOAT y1, FLOAT y2, FLOAT z1, FLOAT z2, p_CUSTOMVERTEX Polyhedral_36, DWORD *Num_Vertexs);
void CreateInvertedBox2(FLOAT x1, FLOAT x2, FLOAT y1, FLOAT y2, FLOAT z1, FLOAT z2, p_CUSTOMVERTEX Polyhedral_36, DWORD *Num_Vertexs);
void CreateNormalBox(FLOAT x1, FLOAT x2, FLOAT y1, FLOAT y2, FLOAT z1, FLOAT z2, p_CUSTOMVERTEX Polyhedral_36, DWORD *Num_Vertexs);
void CreateNormalIcosahedron(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_20, DWORD *Num_Vertexs, DWORD transparency);
void CreateInvertedHemisphere108(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_108, DWORD *Num_Vertexs);
void CreateNormalSphere80(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_80, DWORD *Num_Vertexs);
void CreateNormalSphere180(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_180, DWORD *Num_Vertexs);

#endif