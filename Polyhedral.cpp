#include "Polyhedral.h"

#define INVERTEDBOX_TILE 3.0f
#define NORMALBOX_TILE 1.0f

#define RANDOM_R 200
#define RANDOM_G 10
#define RANDOM_B 200


void CreateInvertedBox(FLOAT x1, FLOAT x2, FLOAT y1, FLOAT y2, FLOAT z1, FLOAT z2, p_CUSTOMVERTEX Polyhedral_36, DWORD *Num_Vertexs)
{
	//srand( (unsigned)time( NULL ) );

	// SIDE 1 Y1
	Polyhedral_36[0].x = x1;
	Polyhedral_36[0].y = y1;
	Polyhedral_36[0].z = z1;
	Polyhedral_36[0].color = 0xFFFFFFFF;

	Polyhedral_36[1].x = x2;
	Polyhedral_36[1].y = y1;
	Polyhedral_36[1].z = z2;
	Polyhedral_36[1].color = 0xFFFFFFFF;

	Polyhedral_36[2].x = x2;
	Polyhedral_36[2].y = y1;
	Polyhedral_36[2].z = z1;
	Polyhedral_36[2].color = 0xFFFFFFFF;

	Polyhedral_36[3].x = x1;
	Polyhedral_36[3].y = y1;
	Polyhedral_36[3].z = z1;
	Polyhedral_36[3].color = 0xFFFFFFFF;

	Polyhedral_36[4].x = x1;
	Polyhedral_36[4].y = y1;
	Polyhedral_36[4].z = z2;
	Polyhedral_36[4].color = 0xFFFFFFFF;

	Polyhedral_36[5].x = x2;
	Polyhedral_36[5].y = y1;
	Polyhedral_36[5].z = z2;
	Polyhedral_36[5].color = 0xFFFFFFFF;

	Polyhedral_36[0].tu = 0.0f;
	Polyhedral_36[0].tv = 1.0f;
	Polyhedral_36[1].tu = 8.0f;
	Polyhedral_36[1].tv = 0.0f;
	Polyhedral_36[2].tu = 8.0f;
	Polyhedral_36[2].tv = 1.0f;

	Polyhedral_36[3].tu = 0.0f;
	Polyhedral_36[3].tv = 1.0f;
	Polyhedral_36[4].tu = 0.0f;
	Polyhedral_36[4].tv = 0.0f;
	Polyhedral_36[5].tu = 8.0f;
	Polyhedral_36[5].tv = 0.0f;

	// SIDE 2 Y2
	Polyhedral_36[6].x = x1;
	Polyhedral_36[6].y = y2;
	Polyhedral_36[6].z = z1;
	Polyhedral_36[6].color = 0xFFFFFFFF;

	Polyhedral_36[7].x = x2;
	Polyhedral_36[7].y = y2;
	Polyhedral_36[7].z = z1;
	Polyhedral_36[7].color = 0xFFFFFFFF;

	Polyhedral_36[8].x = x2;
	Polyhedral_36[8].y = y2;
	Polyhedral_36[8].z = z2;
	Polyhedral_36[8].color = 0xFFFFFFFF;

	Polyhedral_36[9].x = x1;
	Polyhedral_36[9].y = y2;
	Polyhedral_36[9].z = z1;
	Polyhedral_36[9].color = 0xFFFFFFFF;

	Polyhedral_36[10].x = x2;
	Polyhedral_36[10].y = y2;
	Polyhedral_36[10].z = z2;
	Polyhedral_36[10].color = 0xFFFFFFFF;

	Polyhedral_36[11].x = x1;
	Polyhedral_36[11].y = y2;
	Polyhedral_36[11].z = z2;
	Polyhedral_36[11].color = 0xFFFFFFFF;

	Polyhedral_36[6].tu = 8.0f;
	Polyhedral_36[6].tv = 1.0f;
	Polyhedral_36[7].tu = 0.0f;
	Polyhedral_36[7].tv = 1.0f;
	Polyhedral_36[8].tu = 0.0f;
	Polyhedral_36[8].tv = 0.0f;

	Polyhedral_36[9].tu =  8.0f;
	Polyhedral_36[9].tv =  1.0f;
	Polyhedral_36[10].tu = 0.0f;
	Polyhedral_36[10].tv = 0.0f;
	Polyhedral_36[11].tu = 8.0f;
	Polyhedral_36[11].tv = 0.0f;

	// SIDE 3 X1
	Polyhedral_36[12].x = x1;
	Polyhedral_36[12].y = y1;
	Polyhedral_36[12].z = z1;
	Polyhedral_36[12].color = 0xFFFFFFFF;

	Polyhedral_36[13].x = x1;
	Polyhedral_36[13].y = y2;
	Polyhedral_36[13].z = z1;
	Polyhedral_36[13].color = 0xFFFFFFFF;

	Polyhedral_36[14].x = x1;
	Polyhedral_36[14].y = y2;
	Polyhedral_36[14].z = z2;
	Polyhedral_36[14].color = 0xFFFFFFFF;

	Polyhedral_36[15].x = x1;
	Polyhedral_36[15].y = y1;
	Polyhedral_36[15].z = z1;
	Polyhedral_36[15].color = 0xFFFFFFFF;

	Polyhedral_36[16].x = x1;
	Polyhedral_36[16].y = y2;
	Polyhedral_36[16].z = z2;
	Polyhedral_36[16].color = 0xFFFFFFFF;

	Polyhedral_36[17].x = x1;
	Polyhedral_36[17].y = y1;
	Polyhedral_36[17].z = z2;
	Polyhedral_36[17].color = 0xFFFFFFFF;

	Polyhedral_36[12].tu = 4.0f;
	Polyhedral_36[12].tv = 1.0f;
	Polyhedral_36[13].tu = 0.0f;
	Polyhedral_36[13].tv = 1.0f;
	Polyhedral_36[14].tu = 0.0f;
	Polyhedral_36[14].tv = 0.0f;

	Polyhedral_36[15].tu = 4.0f;
	Polyhedral_36[15].tv = 1.0f;
	Polyhedral_36[16].tu = 0.0f;
	Polyhedral_36[16].tv = 0.0f;
	Polyhedral_36[17].tu = 4.0f;
	Polyhedral_36[17].tv = 0.0f;

	// SIDE 4 X2
	Polyhedral_36[18].x = x2;
	Polyhedral_36[18].y = y1;
	Polyhedral_36[18].z = z1;
	Polyhedral_36[18].color = 0xFFFFFFFF;

	Polyhedral_36[19].x = x2;
	Polyhedral_36[19].y = y2;
	Polyhedral_36[19].z = z2;
	Polyhedral_36[19].color = 0xFFFFFFFF;

	Polyhedral_36[20].x = x2;
	Polyhedral_36[20].y = y2;
	Polyhedral_36[20].z = z1;
	Polyhedral_36[20].color = 0xFFFFFFFF;

	Polyhedral_36[21].x = x2;
	Polyhedral_36[21].y = y1;
	Polyhedral_36[21].z = z1;
	Polyhedral_36[21].color = 0xFFFFFFFF;

	Polyhedral_36[22].x = x2;
	Polyhedral_36[22].y = y1;
	Polyhedral_36[22].z = z2;
	Polyhedral_36[22].color = 0xFFFFFFFF;

	Polyhedral_36[23].x = x2;
	Polyhedral_36[23].y = y2;
	Polyhedral_36[23].z = z2;
	Polyhedral_36[23].color = 0xFFFFFFFF;

	Polyhedral_36[18].tu = 0.0f;
	Polyhedral_36[18].tv = 1.0f;
	Polyhedral_36[19].tu = 4.0f;
	Polyhedral_36[19].tv = 0.0f;
	Polyhedral_36[20].tu = 4.0f;
	Polyhedral_36[20].tv = 1.0f;

	Polyhedral_36[21].tu = 0.0f;
	Polyhedral_36[21].tv = 1.0f;
	Polyhedral_36[22].tu = 0.0f;
	Polyhedral_36[22].tv = 0.0f;
	Polyhedral_36[23].tu = 4.0f;
	Polyhedral_36[23].tv = 0.0f;

	// SIDE 5 Z1
	Polyhedral_36[24].x = x1;
	Polyhedral_36[24].y = y1;
	Polyhedral_36[24].z = z1;
	Polyhedral_36[24].color = 0xFFFFFFFF;

	Polyhedral_36[25].x = x2;
	Polyhedral_36[25].y = y1;
	Polyhedral_36[25].z = z1;
	Polyhedral_36[25].color = 0xFFFFFFFF;

	Polyhedral_36[26].x = x2;
	Polyhedral_36[26].y = y2;
	Polyhedral_36[26].z = z1;
	Polyhedral_36[26].color = 0xFFFFFFFF;

	Polyhedral_36[27].x = x1;
	Polyhedral_36[27].y = y1;
	Polyhedral_36[27].z = z1;
	Polyhedral_36[27].color = 0xFFFFFFFF;

	Polyhedral_36[28].x = x2;
	Polyhedral_36[28].y = y2;
	Polyhedral_36[28].z = z1;
	Polyhedral_36[28].color = 0xFFFFFFFF;

	Polyhedral_36[29].x = x1;
	Polyhedral_36[29].y = y2;
	Polyhedral_36[29].z = z1;
	Polyhedral_36[29].color = 0xFFFFFFFF;

	Polyhedral_36[24].tu = INVERTEDBOX_TILE;
	Polyhedral_36[24].tv = INVERTEDBOX_TILE;
	Polyhedral_36[25].tu = 0.0f;
	Polyhedral_36[25].tv = INVERTEDBOX_TILE;
	Polyhedral_36[26].tu = 0.0f;
	Polyhedral_36[26].tv = 0.0f;

	Polyhedral_36[27].tu = INVERTEDBOX_TILE;
	Polyhedral_36[27].tv = INVERTEDBOX_TILE;
	Polyhedral_36[28].tu = 0.0f;
	Polyhedral_36[28].tv = 0.0f;
	Polyhedral_36[29].tu = INVERTEDBOX_TILE;
	Polyhedral_36[29].tv = 0.0f;

	// SIDE 6 Z2
	Polyhedral_36[30].x = x1;
	Polyhedral_36[30].y = y1;
	Polyhedral_36[30].z = z2;
	Polyhedral_36[30].color = 0xFFFFFFFF;

	Polyhedral_36[31].x = x2;
	Polyhedral_36[31].y = y2;
	Polyhedral_36[31].z = z2;
	Polyhedral_36[31].color = 0xFFFFFFFF;

	Polyhedral_36[32].x = x2;
	Polyhedral_36[32].y = y1;
	Polyhedral_36[32].z = z2;
	Polyhedral_36[32].color = 0xFFFFFFFF;

	Polyhedral_36[33].x = x1;
	Polyhedral_36[33].y = y1;
	Polyhedral_36[33].z = z2;
	Polyhedral_36[33].color = 0xFFFFFFFF;

	Polyhedral_36[34].x = x1;
	Polyhedral_36[34].y = y2;
	Polyhedral_36[34].z = z2;
	Polyhedral_36[34].color = 0xFFFFFFFF;

	Polyhedral_36[35].x = x2;
	Polyhedral_36[35].y = y2;
	Polyhedral_36[35].z = z2;
	Polyhedral_36[35].color = 0xFFFFFFFF;

	Polyhedral_36[30].tu = 0.0f;
	Polyhedral_36[30].tv = INVERTEDBOX_TILE;
	Polyhedral_36[31].tu = INVERTEDBOX_TILE;
	Polyhedral_36[31].tv = 0.0f;
	Polyhedral_36[32].tu = INVERTEDBOX_TILE;
	Polyhedral_36[32].tv = INVERTEDBOX_TILE;

	Polyhedral_36[33].tu = 0.0f;
	Polyhedral_36[33].tv = INVERTEDBOX_TILE;
	Polyhedral_36[34].tu = 0.0f;
	Polyhedral_36[34].tv = 0.0f;
	Polyhedral_36[35].tu = INVERTEDBOX_TILE;
	Polyhedral_36[35].tv = 0.0f;

	*Num_Vertexs += 36;
}


void CreateInvertedBox2(FLOAT x1, FLOAT x2, FLOAT y1, FLOAT y2, FLOAT z1, FLOAT z2, p_CUSTOMVERTEX Polyhedral_36, DWORD *Num_Vertexs)
{
	//srand( (unsigned)time( NULL ) );

	// SIDE 1 Y1
	Polyhedral_36[0].x = x1-OVERLAP;
	Polyhedral_36[0].y = y1;
	Polyhedral_36[0].z = z1-OVERLAP;
	Polyhedral_36[0].color = 0xFFFFFFFF;

	Polyhedral_36[1].x = x2+OVERLAP;
	Polyhedral_36[1].y = y1;
	Polyhedral_36[1].z = z2+OVERLAP;
	Polyhedral_36[1].color = 0xFFFFFFFF;

	Polyhedral_36[2].x = x2+OVERLAP;
	Polyhedral_36[2].y = y1;
	Polyhedral_36[2].z = z1-OVERLAP;
	Polyhedral_36[2].color = 0xFFFFFFFF;

	Polyhedral_36[3].x = x1-OVERLAP;
	Polyhedral_36[3].y = y1;
	Polyhedral_36[3].z = z1-OVERLAP;
	Polyhedral_36[3].color = 0xFFFFFFFF;

	Polyhedral_36[4].x = x1-OVERLAP;
	Polyhedral_36[4].y = y1;
	Polyhedral_36[4].z = z2+OVERLAP;
	Polyhedral_36[4].color = 0xFFFFFFFF;

	Polyhedral_36[5].x = x2+OVERLAP;
	Polyhedral_36[5].y = y1;
	Polyhedral_36[5].z = z2+OVERLAP;
	Polyhedral_36[5].color = 0xFFFFFFFF;

	Polyhedral_36[0].tu = 0.0f;
	Polyhedral_36[0].tv = 1.0f;
	Polyhedral_36[1].tu = 8.0f;
	Polyhedral_36[1].tv = 0.0f;
	Polyhedral_36[2].tu = 8.0f;
	Polyhedral_36[2].tv = 1.0f;

	Polyhedral_36[3].tu = 0.0f;
	Polyhedral_36[3].tv = 1.0f;
	Polyhedral_36[4].tu = 0.0f;
	Polyhedral_36[4].tv = 0.0f;
	Polyhedral_36[5].tu = 8.0f;
	Polyhedral_36[5].tv = 0.0f;

	// SIDE 2 Y2
	Polyhedral_36[6].x = x1-OVERLAP;
	Polyhedral_36[6].y = y2;
	Polyhedral_36[6].z = z1-OVERLAP;
	Polyhedral_36[6].color = 0xFFFFFFFF;

	Polyhedral_36[7].x = x2+OVERLAP;
	Polyhedral_36[7].y = y2;
	Polyhedral_36[7].z = z1-OVERLAP;
	Polyhedral_36[7].color = 0xFFFFFFFF;

	Polyhedral_36[8].x = x2+OVERLAP;
	Polyhedral_36[8].y = y2;
	Polyhedral_36[8].z = z2+OVERLAP;
	Polyhedral_36[8].color = 0xFFFFFFFF;

	Polyhedral_36[9].x = x1-OVERLAP;
	Polyhedral_36[9].y = y2;
	Polyhedral_36[9].z = z1-OVERLAP;
	Polyhedral_36[9].color = 0xFFFFFFFF;

	Polyhedral_36[10].x = x2+OVERLAP;
	Polyhedral_36[10].y = y2;
	Polyhedral_36[10].z = z2+OVERLAP;
	Polyhedral_36[10].color = 0xFFFFFFFF;

	Polyhedral_36[11].x = x1-OVERLAP;
	Polyhedral_36[11].y = y2;
	Polyhedral_36[11].z = z2+OVERLAP;
	Polyhedral_36[11].color = 0xFFFFFFFF;

	Polyhedral_36[6].tu = 8.0f;
	Polyhedral_36[6].tv = 1.0f;
	Polyhedral_36[7].tu = 0.0f;
	Polyhedral_36[7].tv = 1.0f;
	Polyhedral_36[8].tu = 0.0f;
	Polyhedral_36[8].tv = 0.0f;

	Polyhedral_36[9].tu =  8.0f;
	Polyhedral_36[9].tv =  1.0f;
	Polyhedral_36[10].tu = 0.0f;
	Polyhedral_36[10].tv = 0.0f;
	Polyhedral_36[11].tu = 8.0f;
	Polyhedral_36[11].tv = 0.0f;

	// SIDE 3 X1
	Polyhedral_36[12].x = x1;
	Polyhedral_36[12].y = y1-OVERLAP;
	Polyhedral_36[12].z = z1-OVERLAP;
	Polyhedral_36[12].color = 0xFFFFFFFF;

	Polyhedral_36[13].x = x1;
	Polyhedral_36[13].y = y2+OVERLAP;
	Polyhedral_36[13].z = z1-OVERLAP;
	Polyhedral_36[13].color = 0xFFFFFFFF;

	Polyhedral_36[14].x = x1;
	Polyhedral_36[14].y = y2+OVERLAP;
	Polyhedral_36[14].z = z2+OVERLAP;
	Polyhedral_36[14].color = 0xFFFFFFFF;

	Polyhedral_36[15].x = x1;
	Polyhedral_36[15].y = y1-OVERLAP;
	Polyhedral_36[15].z = z1-OVERLAP;
	Polyhedral_36[15].color = 0xFFFFFFFF;

	Polyhedral_36[16].x = x1;
	Polyhedral_36[16].y = y2+OVERLAP;
	Polyhedral_36[16].z = z2+OVERLAP;
	Polyhedral_36[16].color = 0xFFFFFFFF;

	Polyhedral_36[17].x = x1;
	Polyhedral_36[17].y = y1-OVERLAP;
	Polyhedral_36[17].z = z2+OVERLAP;
	Polyhedral_36[17].color = 0xFFFFFFFF;

	Polyhedral_36[12].tu = 4.0f;
	Polyhedral_36[12].tv = 1.0f;
	Polyhedral_36[13].tu = 0.0f;
	Polyhedral_36[13].tv = 1.0f;
	Polyhedral_36[14].tu = 0.0f;
	Polyhedral_36[14].tv = 0.0f;

	Polyhedral_36[15].tu = 4.0f;
	Polyhedral_36[15].tv = 1.0f;
	Polyhedral_36[16].tu = 0.0f;
	Polyhedral_36[16].tv = 0.0f;
	Polyhedral_36[17].tu = 4.0f;
	Polyhedral_36[17].tv = 0.0f;

	// SIDE 4 X2
	Polyhedral_36[18].x = x2;
	Polyhedral_36[18].y = y1-OVERLAP;
	Polyhedral_36[18].z = z1-OVERLAP;
	Polyhedral_36[18].color = 0xFFFFFFFF;

	Polyhedral_36[19].x = x2;
	Polyhedral_36[19].y = y2+OVERLAP;
	Polyhedral_36[19].z = z2+OVERLAP;
	Polyhedral_36[19].color = 0xFFFFFFFF;

	Polyhedral_36[20].x = x2;
	Polyhedral_36[20].y = y2+OVERLAP;
	Polyhedral_36[20].z = z1-OVERLAP;
	Polyhedral_36[20].color = 0xFFFFFFFF;

	Polyhedral_36[21].x = x2;
	Polyhedral_36[21].y = y1-OVERLAP;
	Polyhedral_36[21].z = z1-OVERLAP;
	Polyhedral_36[21].color = 0xFFFFFFFF;

	Polyhedral_36[22].x = x2;
	Polyhedral_36[22].y = y1-OVERLAP;
	Polyhedral_36[22].z = z2+OVERLAP;
	Polyhedral_36[22].color = 0xFFFFFFFF;

	Polyhedral_36[23].x = x2;
	Polyhedral_36[23].y = y2+OVERLAP;
	Polyhedral_36[23].z = z2+OVERLAP;
	Polyhedral_36[23].color = 0xFFFFFFFF;

	Polyhedral_36[18].tu = 0.0f;
	Polyhedral_36[18].tv = 1.0f;
	Polyhedral_36[19].tu = 4.0f;
	Polyhedral_36[19].tv = 0.0f;
	Polyhedral_36[20].tu = 4.0f;
	Polyhedral_36[20].tv = 1.0f;

	Polyhedral_36[21].tu = 0.0f;
	Polyhedral_36[21].tv = 1.0f;
	Polyhedral_36[22].tu = 0.0f;
	Polyhedral_36[22].tv = 0.0f;
	Polyhedral_36[23].tu = 4.0f;
	Polyhedral_36[23].tv = 0.0f;

	// SIDE 5 Z1
	Polyhedral_36[24].x = x1;
	Polyhedral_36[24].y = y1;
	Polyhedral_36[24].z = z1;
	Polyhedral_36[24].color = 0xFFFFFFFF;

	Polyhedral_36[25].x = x2;
	Polyhedral_36[25].y = y1;
	Polyhedral_36[25].z = z1;
	Polyhedral_36[25].color = 0xFFFFFFFF;

	Polyhedral_36[26].x = x2;
	Polyhedral_36[26].y = y2;
	Polyhedral_36[26].z = z1;
	Polyhedral_36[26].color = 0xFFFFFFFF;

	Polyhedral_36[27].x = x1;
	Polyhedral_36[27].y = y1;
	Polyhedral_36[27].z = z1;
	Polyhedral_36[27].color = 0xFFFFFFFF;

	Polyhedral_36[28].x = x2;
	Polyhedral_36[28].y = y2;
	Polyhedral_36[28].z = z1;
	Polyhedral_36[28].color = 0xFFFFFFFF;

	Polyhedral_36[29].x = x1;
	Polyhedral_36[29].y = y2;
	Polyhedral_36[29].z = z1;
	Polyhedral_36[29].color = 0xFFFFFFFF;

	Polyhedral_36[24].tu = INVERTEDBOX_TILE;
	Polyhedral_36[24].tv = INVERTEDBOX_TILE;
	Polyhedral_36[25].tu = 0.0f;
	Polyhedral_36[25].tv = INVERTEDBOX_TILE;
	Polyhedral_36[26].tu = 0.0f;
	Polyhedral_36[26].tv = 0.0f;

	Polyhedral_36[27].tu = INVERTEDBOX_TILE;
	Polyhedral_36[27].tv = INVERTEDBOX_TILE;
	Polyhedral_36[28].tu = 0.0f;
	Polyhedral_36[28].tv = 0.0f;
	Polyhedral_36[29].tu = INVERTEDBOX_TILE;
	Polyhedral_36[29].tv = 0.0f;

	// SIDE 6 Z2
	Polyhedral_36[30].x = x1;
	Polyhedral_36[30].y = y1;
	Polyhedral_36[30].z = z2;
	Polyhedral_36[30].color = 0xFFFFFFFF;

	Polyhedral_36[31].x = x2;
	Polyhedral_36[31].y = y2;
	Polyhedral_36[31].z = z2;
	Polyhedral_36[31].color = 0xFFFFFFFF;

	Polyhedral_36[32].x = x2;
	Polyhedral_36[32].y = y1;
	Polyhedral_36[32].z = z2;
	Polyhedral_36[32].color = 0xFFFFFFFF;

	Polyhedral_36[33].x = x1;
	Polyhedral_36[33].y = y1;
	Polyhedral_36[33].z = z2;
	Polyhedral_36[33].color = 0xFFFFFFFF;

	Polyhedral_36[34].x = x1;
	Polyhedral_36[34].y = y2;
	Polyhedral_36[34].z = z2;
	Polyhedral_36[34].color = 0xFFFFFFFF;

	Polyhedral_36[35].x = x2;
	Polyhedral_36[35].y = y2;
	Polyhedral_36[35].z = z2;
	Polyhedral_36[35].color = 0xFFFFFFFF;

	Polyhedral_36[30].tu = 0.0f;
	Polyhedral_36[30].tv = INVERTEDBOX_TILE;
	Polyhedral_36[31].tu = INVERTEDBOX_TILE;
	Polyhedral_36[31].tv = 0.0f;
	Polyhedral_36[32].tu = INVERTEDBOX_TILE;
	Polyhedral_36[32].tv = INVERTEDBOX_TILE;

	Polyhedral_36[33].tu = 0.0f;
	Polyhedral_36[33].tv = INVERTEDBOX_TILE;
	Polyhedral_36[34].tu = 0.0f;
	Polyhedral_36[34].tv = 0.0f;
	Polyhedral_36[35].tu = INVERTEDBOX_TILE;
	Polyhedral_36[35].tv = 0.0f;

	*Num_Vertexs += 36;
}


void CreateNormalBox(FLOAT x1, FLOAT x2, FLOAT y1, FLOAT y2, FLOAT z1, FLOAT z2, p_CUSTOMVERTEX Polyhedral_36, DWORD *Num_Vertexs)
{
	//srand( (unsigned)time( NULL ) );

	// SIDE 1 Y1
	Polyhedral_36[0].x = x1;
	Polyhedral_36[0].y = y1;
	Polyhedral_36[0].z = z1;
	Polyhedral_36[0].color = 0xFFFFFFFF;

	Polyhedral_36[1].x = x2;
	Polyhedral_36[1].y = y1;
	Polyhedral_36[1].z = z1;
	Polyhedral_36[1].color = 0xFFFFFFFF;

	Polyhedral_36[2].x = x2;
	Polyhedral_36[2].y = y1;
	Polyhedral_36[2].z = z2;
	Polyhedral_36[2].color = 0xFFFFFFFF;

	Polyhedral_36[3].x = x1;
	Polyhedral_36[3].y = y1;
	Polyhedral_36[3].z = z1;
	Polyhedral_36[3].color = 0xFFFFFFFF;

	Polyhedral_36[4].x = x2;
	Polyhedral_36[4].y = y1;
	Polyhedral_36[4].z = z2;
	Polyhedral_36[4].color = 0xFFFFFFFF;

	Polyhedral_36[5].x = x1;
	Polyhedral_36[5].y = y1;
	Polyhedral_36[5].z = z2;
	Polyhedral_36[5].color = 0xFFFFFFFF;

	Polyhedral_36[0].tu = NORMALBOX_TILE;
	Polyhedral_36[0].tv = NORMALBOX_TILE;
	Polyhedral_36[1].tu = 0.0f;
	Polyhedral_36[1].tv = NORMALBOX_TILE;
	Polyhedral_36[2].tu = 0.0f;
	Polyhedral_36[2].tv = 0.0f;

	Polyhedral_36[3].tu = NORMALBOX_TILE;
	Polyhedral_36[3].tv = NORMALBOX_TILE;
	Polyhedral_36[4].tu = 0.0f;
	Polyhedral_36[4].tv = 0.0f;
	Polyhedral_36[5].tu = NORMALBOX_TILE;
	Polyhedral_36[5].tv = 0.0f;

	// SIDE 2 Y2
	Polyhedral_36[6].x = x1;
	Polyhedral_36[6].y = y2;
	Polyhedral_36[6].z = z1;
	Polyhedral_36[6].color = 0xFFFFFFFF;

	Polyhedral_36[7].x = x2;
	Polyhedral_36[7].y = y2;
	Polyhedral_36[7].z = z2;
	Polyhedral_36[7].color = 0xFFFFFFFF;

	Polyhedral_36[8].x = x2;
	Polyhedral_36[8].y = y2;
	Polyhedral_36[8].z = z1;
	Polyhedral_36[8].color = 0xFFFFFFFF;

	Polyhedral_36[9].x = x1;
	Polyhedral_36[9].y = y2;
	Polyhedral_36[9].z = z1;
	Polyhedral_36[9].color = 0xFFFFFFFF;

	Polyhedral_36[10].x = x1;
	Polyhedral_36[10].y = y2;
	Polyhedral_36[10].z = z2;
	Polyhedral_36[10].color = 0xFFFFFFFF;

	Polyhedral_36[11].x = x2;
	Polyhedral_36[11].y = y2;
	Polyhedral_36[11].z = z2;
	Polyhedral_36[11].color = 0xFFFFFFFF;

	Polyhedral_36[6].tu =  NORMALBOX_TILE;
	Polyhedral_36[6].tv =  NORMALBOX_TILE;
	Polyhedral_36[7].tu =  0.0f;
	Polyhedral_36[7].tv =  0.0f;
	Polyhedral_36[8].tu =  0.0f;
	Polyhedral_36[8].tv =  NORMALBOX_TILE;

	Polyhedral_36[9].tu =  NORMALBOX_TILE;
	Polyhedral_36[9].tv =  NORMALBOX_TILE;
	Polyhedral_36[10].tu = NORMALBOX_TILE;
	Polyhedral_36[10].tv = 0.0f;
	Polyhedral_36[11].tu = 0.0f;
	Polyhedral_36[11].tv = 0.0f;

	// SIDE 3 X1
	Polyhedral_36[12].x = x1;
	Polyhedral_36[12].y = y1;
	Polyhedral_36[12].z = z1;
	Polyhedral_36[12].color = 0xFFFFFFFF;

	Polyhedral_36[13].x = x1;
	Polyhedral_36[13].y = y2;
	Polyhedral_36[13].z = z2;
	Polyhedral_36[13].color = 0xFFFFFFFF;

	Polyhedral_36[14].x = x1;
	Polyhedral_36[14].y = y2;
	Polyhedral_36[14].z = z1;
	Polyhedral_36[14].color = 0xFFFFFFFF;

	Polyhedral_36[15].x = x1;
	Polyhedral_36[15].y = y1;
	Polyhedral_36[15].z = z1;
	Polyhedral_36[15].color = 0xFFFFFFFF;

	Polyhedral_36[16].x = x1;
	Polyhedral_36[16].y = y1;
	Polyhedral_36[16].z = z2;
	Polyhedral_36[16].color = 0xFFFFFFFF;

	Polyhedral_36[17].x = x1;
	Polyhedral_36[17].y = y2;
	Polyhedral_36[17].z = z2;
	Polyhedral_36[17].color = 0xFFFFFFFF;

	Polyhedral_36[12].tu = NORMALBOX_TILE;
	Polyhedral_36[12].tv = NORMALBOX_TILE;
	Polyhedral_36[13].tu = 0.0f;
	Polyhedral_36[13].tv = 0.0f;
	Polyhedral_36[14].tu = 0.0f;
	Polyhedral_36[14].tv = NORMALBOX_TILE;
						   
	Polyhedral_36[15].tu = NORMALBOX_TILE;
	Polyhedral_36[15].tv = NORMALBOX_TILE;
	Polyhedral_36[16].tu = NORMALBOX_TILE;
	Polyhedral_36[16].tv = 0.0f;
	Polyhedral_36[17].tu = 0.0f;
	Polyhedral_36[17].tv = 0.0f;

	// SIDE 4 X2
	Polyhedral_36[18].x = x2;
	Polyhedral_36[18].y = y1;
	Polyhedral_36[18].z = z1;
	Polyhedral_36[18].color = 0xFFFFFFFF;

	Polyhedral_36[19].x = x2;
	Polyhedral_36[19].y = y2;
	Polyhedral_36[19].z = z1;
	Polyhedral_36[19].color = 0xFFFFFFFF;

	Polyhedral_36[20].x = x2;
	Polyhedral_36[20].y = y2;
	Polyhedral_36[20].z = z2;
	Polyhedral_36[20].color = 0xFFFFFFFF;

	Polyhedral_36[21].x = x2;
	Polyhedral_36[21].y = y1;
	Polyhedral_36[21].z = z1;
	Polyhedral_36[21].color = 0xFFFFFFFF;

	Polyhedral_36[22].x = x2;
	Polyhedral_36[22].y = y2;
	Polyhedral_36[22].z = z2;
	Polyhedral_36[22].color = 0xFFFFFFFF;

	Polyhedral_36[23].x = x2;
	Polyhedral_36[23].y = y1;
	Polyhedral_36[23].z = z2;
	Polyhedral_36[23].color = 0xFFFFFFFF;

	Polyhedral_36[18].tu = NORMALBOX_TILE;
	Polyhedral_36[18].tv = NORMALBOX_TILE;
	Polyhedral_36[19].tu = 0.0f;
	Polyhedral_36[19].tv = NORMALBOX_TILE;
	Polyhedral_36[20].tu = 0.0f;
	Polyhedral_36[20].tv = 0.0f;
						   
	Polyhedral_36[21].tu = NORMALBOX_TILE;
	Polyhedral_36[21].tv = NORMALBOX_TILE;
	Polyhedral_36[22].tu = 0.0f;
	Polyhedral_36[22].tv = 0.0f;
	Polyhedral_36[23].tu = NORMALBOX_TILE;
	Polyhedral_36[23].tv = 0.0f;

	// SIDE 5 Z1
	Polyhedral_36[24].x = x1;
	Polyhedral_36[24].y = y1;
	Polyhedral_36[24].z = z1;
	Polyhedral_36[24].color = 0xFFFFFFFF;

	Polyhedral_36[25].x = x2;
	Polyhedral_36[25].y = y2;
	Polyhedral_36[25].z = z1;
	Polyhedral_36[25].color = 0xFFFFFFFF;

	Polyhedral_36[26].x = x2;
	Polyhedral_36[26].y = y1;
	Polyhedral_36[26].z = z1;
	Polyhedral_36[26].color = 0xFFFFFFFF;

	Polyhedral_36[27].x = x1;
	Polyhedral_36[27].y = y1;
	Polyhedral_36[27].z = z1;
	Polyhedral_36[27].color = 0xFFFFFFFF;

	Polyhedral_36[28].x = x1;
	Polyhedral_36[28].y = y2;
	Polyhedral_36[28].z = z1;
	Polyhedral_36[28].color = 0xFFFFFFFF;

	Polyhedral_36[29].x = x2;
	Polyhedral_36[29].y = y2;
	Polyhedral_36[29].z = z1;
	Polyhedral_36[29].color = 0xFFFFFFFF;

	Polyhedral_36[24].tu = NORMALBOX_TILE;
	Polyhedral_36[24].tv = NORMALBOX_TILE;
	Polyhedral_36[25].tu = 0.0f;
	Polyhedral_36[25].tv = 0.0f;
	Polyhedral_36[26].tu = 0.0f;
	Polyhedral_36[26].tv = NORMALBOX_TILE;
						   
	Polyhedral_36[27].tu = NORMALBOX_TILE;
	Polyhedral_36[27].tv = NORMALBOX_TILE;
	Polyhedral_36[28].tu = NORMALBOX_TILE;
	Polyhedral_36[28].tv = 0.0f;
	Polyhedral_36[29].tu = 0.0f;
	Polyhedral_36[29].tv = 0.0f;

	// SIDE 6 Z2
	Polyhedral_36[30].x = x1;
	Polyhedral_36[30].y = y1;
	Polyhedral_36[30].z = z2;
	Polyhedral_36[30].color = 0xFFFFFFFF;

	Polyhedral_36[31].x = x2;
	Polyhedral_36[31].y = y1;
	Polyhedral_36[31].z = z2;
	Polyhedral_36[31].color = 0xFFFFFFFF;

	Polyhedral_36[32].x = x2;
	Polyhedral_36[32].y = y2;
	Polyhedral_36[32].z = z2;
	Polyhedral_36[32].color = 0xFFFFFFFF;

	Polyhedral_36[33].x = x1;
	Polyhedral_36[33].y = y1;
	Polyhedral_36[33].z = z2;
	Polyhedral_36[33].color = 0xFFFFFFFF;

	Polyhedral_36[34].x = x2;
	Polyhedral_36[34].y = y2;
	Polyhedral_36[34].z = z2;
	Polyhedral_36[34].color = 0xFFFFFFFF;

	Polyhedral_36[35].x = x1;
	Polyhedral_36[35].y = y2;
	Polyhedral_36[35].z = z2;
	Polyhedral_36[35].color = 0xFFFFFFFF;

	Polyhedral_36[30].tu = NORMALBOX_TILE;
	Polyhedral_36[30].tv = NORMALBOX_TILE;
	Polyhedral_36[31].tu = 0.0f;
	Polyhedral_36[31].tv = NORMALBOX_TILE;
	Polyhedral_36[32].tu = 0.0f;
	Polyhedral_36[32].tv = 0.0f;
						   
	Polyhedral_36[33].tu = NORMALBOX_TILE;
	Polyhedral_36[33].tv = NORMALBOX_TILE;
	Polyhedral_36[34].tu = 0.0f;
	Polyhedral_36[34].tv = 0.0f;
	Polyhedral_36[35].tu = NORMALBOX_TILE;
	Polyhedral_36[35].tv = 0.0f;

	*Num_Vertexs += 36;
}

void CreateInvertedHemisphere108(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_108, DWORD *Num_Vertexs)
{
	t_CUSTOMVERTEX InvHemisphere108[] = 
	{{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{+0.1989667f, +0.1148769f, +0.9732500f, 0x00FFFF00},
{+0.0000000f, -0.2297529f, +0.9732490f, 0x00FFFFFF},
{+0.1989667f, +0.1148769f, +0.9732500f, 0x0000FF00},
{+0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFF00},
{+0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFFFF},
{+0.1989667f, +0.1148769f, +0.9732500f, 0x0000FF00},
{+0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{+0.0000000f, -0.2297529f, +0.9732490f, 0x00FFFFFF},
{+0.0000000f, -0.2297529f, +0.9732490f, 0x0000FF00},
{+0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{+0.0000000f, -0.4472136f, +0.8944272f, 0x00FFFFFF},
{+0.3872887f, +0.2236078f, +0.8944311f, 0x0000FF00},
{+0.6123626f, +0.3535581f, +0.7071130f, 0x00FFFF00},
{+0.5282476f, -0.0686696f, +0.8463090f, 0x00FFFFFF},
{+0.6123626f, +0.3535581f, +0.7071130f, 0x0000FF00},
{+0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFF00},
{+0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFFFF},
{+0.6123626f, +0.3535581f, +0.7071130f, 0x0000FF00},
{+0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{+0.5282476f, -0.0686696f, +0.8463090f, 0x00FFFFFF},
{+0.5282476f, -0.0686696f, +0.8463090f, 0x0000FF00},
{+0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{+0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFFFF},
{+0.0000000f, -0.4472136f, +0.8944272f, 0x0000FF00},
{+0.3235907f, -0.4231522f, +0.8463045f, 0x00FFFF00},
{+0.0000000f, -0.7071068f, +0.7071068f, 0x00FFFFFF},
{+0.3235907f, -0.4231522f, +0.8463045f, 0x0000FF00},
{+0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFF00},
{+0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFFFF},
{+0.3235907f, -0.4231522f, +0.8463045f, 0x0000FF00},
{+0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{+0.0000000f, -0.7071068f, +0.7071068f, 0x00FFFFFF},
{+0.0000000f, -0.7071068f, +0.7071068f, 0x0000FF00},
{+0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{+0.0000000f, -0.8944272f, +0.4472136f, 0x00FFFFFF},
{+0.6123612f, -0.3535573f, +0.7071146f, 0x0000FF00},
{+0.3235907f, -0.4231522f, +0.8463045f, 0x00FFFF00},
{+0.5282476f, -0.0686696f, +0.8463090f, 0x00FFFFFF},
{+0.3235907f, -0.4231522f, +0.8463045f, 0x0000FF00},
{+0.0000000f, -0.4472136f, +0.8944272f, 0x00FFFF00},
{+0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFFFF},
{+0.3235907f, -0.4231522f, +0.8463045f, 0x0000FF00},
{+0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{+0.5282476f, -0.0686696f, +0.8463090f, 0x00FFFFFF},
{+0.5282476f, -0.0686696f, +0.8463090f, 0x0000FF00},
{+0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{+0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFFFF},
{+0.7745875f, +0.4472215f, +0.4472215f, 0x0000FF00},
{+0.8428507f, +0.4866344f, +0.2297597f, 0x00FFFF00},
{+0.9419628f, +0.2373881f, +0.2373881f, 0x00FFFFFF},
{+0.8428507f, +0.4866344f, +0.2297597f, 0x0000FF00},
{+0.8660000f, +0.5000000f, +0.0000000f, 0x00FFFF00},
{+0.9659249f, +0.2588224f, +0.0000000f, 0x00FFFFFF},
{+0.8428507f, +0.4866344f, +0.2297597f, 0x0000FF00},
{+0.9659249f, +0.2588224f, +0.0000000f, 0x00FFFF00},
{+0.9419628f, +0.2373881f, +0.2373881f, 0x00FFFFFF},
{+0.9419628f, +0.2373881f, +0.2373881f, 0x0000FF00},
{+0.9659249f, +0.2588224f, +0.0000000f, 0x00FFFF00},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{+0.6123612f, -0.3535573f, +0.7071146f, 0x0000FF00},
{+0.8978756f, -0.1968855f, +0.3937709f, 0x00FFFF00},
{+0.6194336f, -0.6791516f, +0.3937704f, 0x00FFFFFF},
{+0.8978756f, -0.1968855f, +0.3937709f, 0x0000FF00},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFF00},
{+0.8660222f, -0.5000055f, +0.0000000f, 0x00FFFFFF},
{+0.8978756f, -0.1968855f, +0.3937709f, 0x0000FF00},
{+0.8660222f, -0.5000055f, +0.0000000f, 0x00FFFF00},
{+0.6194336f, -0.6791516f, +0.3937704f, 0x00FFFFFF},
{+0.6194336f, -0.6791516f, +0.3937704f, 0x0000FF00},
{+0.8660222f, -0.5000055f, +0.0000000f, 0x00FFFF00},
{+0.4999890f, -0.8660318f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, +0.4472136f, 0x0000FF00},
{+0.2653963f, -0.9344593f, +0.2373829f, 0x00FFFF00},
{+0.0000000f, -0.9732490f, +0.2297529f, 0x00FFFFFF},
{+0.2653963f, -0.9344593f, +0.2373829f, 0x0000FF00},
{+0.4999890f, -0.8660318f, +0.0000000f, 0x00FFFF00},
{+0.2588129f, -0.9659275f, +0.0000000f, 0x00FFFFFF},
{+0.2653963f, -0.9344593f, +0.2373829f, 0x0000FF00},
{+0.2588129f, -0.9659275f, +0.0000000f, 0x00FFFF00},
{+0.0000000f, -0.9732490f, +0.2297529f, 0x00FFFFFF},
{+0.0000000f, -0.9732490f, +0.2297529f, 0x0000FF00},
{+0.2588129f, -0.9659275f, +0.0000000f, 0x00FFFF00},
{+0.0000000f, -1.0000000f, +0.0000000f, 0x00FFFFFF},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x0000FF00},
{+0.8978756f, -0.1968855f, +0.3937709f, 0x00FFFF00},
{+0.9419628f, +0.2373881f, +0.2373881f, 0x00FFFFFF},
{+0.8978756f, -0.1968855f, +0.3937709f, 0x0000FF00},
{+0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFF00},
{+0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFFFF},
{+0.8978756f, -0.1968855f, +0.3937709f, 0x0000FF00},
{+0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{+0.9419628f, +0.2373881f, +0.2373881f, 0x00FFFFFF},
{+0.9419628f, +0.2373881f, +0.2373881f, 0x0000FF00},
{+0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{+0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFFFF},
{+0.4999890f, -0.8660318f, +0.0000000f, 0x0000FF00},
{+0.2653963f, -0.9344593f, +0.2373829f, 0x00FFFF00},
{+0.6194336f, -0.6791516f, +0.3937704f, 0x00FFFFFF},
{+0.2653963f, -0.9344593f, +0.2373829f, 0x0000FF00},
{+0.0000000f, -0.8944272f, +0.4472136f, 0x00FFFF00},
{+0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFFFF},
{+0.2653963f, -0.9344593f, +0.2373829f, 0x0000FF00},
{+0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{+0.6194336f, -0.6791516f, +0.3937704f, 0x00FFFFFF},
{+0.6194336f, -0.6791516f, +0.3937704f, 0x0000FF00},
{+0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{+0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{-0.1989667f, +0.1148769f, +0.9732500f, 0x00FFFF00},
{+0.1989667f, +0.1148769f, +0.9732500f, 0x00FFFFFF},
{-0.1989667f, +0.1148769f, +0.9732500f, 0x0000FF00},
{-0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFF00},
{+0.0000000f, +0.2425356f, +0.9701425f, 0x00FFFFFF},
{-0.1989667f, +0.1148769f, +0.9732500f, 0x0000FF00},
{+0.0000000f, +0.2425356f, +0.9701425f, 0x00FFFF00},
{+0.1989667f, +0.1148769f, +0.9732500f, 0x00FFFFFF},
{+0.1989667f, +0.1148769f, +0.9732500f, 0x0000FF00},
{+0.0000000f, +0.2425356f, +0.9701425f, 0x00FFFF00},
{+0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFFFF},
{-0.3872887f, +0.2236078f, +0.8944311f, 0x0000FF00},
{-0.6123626f, +0.3535581f, +0.7071130f, 0x00FFFF00},
{-0.2046557f, +0.4918192f, +0.8463037f, 0x00FFFFFF},
{-0.6123626f, +0.3535581f, +0.7071130f, 0x0000FF00},
{-0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFF00},
{-0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFFFF},
{-0.6123626f, +0.3535581f, +0.7071130f, 0x0000FF00},
{-0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{-0.2046557f, +0.4918192f, +0.8463037f, 0x00FFFFFF},
{-0.2046557f, +0.4918192f, +0.8463037f, 0x0000FF00},
{-0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{+0.0000000f, +0.7071068f, +0.7071068f, 0x00FFFFFF},
{+0.3872887f, +0.2236078f, +0.8944311f, 0x0000FF00},
{+0.2046557f, +0.4918192f, +0.8463037f, 0x00FFFF00},
{+0.6123626f, +0.3535581f, +0.7071130f, 0x00FFFFFF},
{+0.2046557f, +0.4918192f, +0.8463037f, 0x0000FF00},
{+0.0000000f, +0.7071068f, +0.7071068f, 0x00FFFF00},
{+0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFFFF},
{+0.2046557f, +0.4918192f, +0.8463037f, 0x0000FF00},
{+0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{+0.6123626f, +0.3535581f, +0.7071130f, 0x00FFFFFF},
{+0.6123626f, +0.3535581f, +0.7071130f, 0x0000FF00},
{+0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{+0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFFFF},
{+0.0000000f, +0.7071068f, +0.7071068f, 0x0000FF00},
{+0.2046557f, +0.4918192f, +0.8463037f, 0x00FFFF00},
{-0.2046557f, +0.4918192f, +0.8463037f, 0x00FFFFFF},
{+0.2046557f, +0.4918192f, +0.8463037f, 0x0000FF00},
{+0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFF00},
{+0.0000000f, +0.2425356f, +0.9701425f, 0x00FFFFFF},
{+0.2046557f, +0.4918192f, +0.8463037f, 0x0000FF00},
{+0.0000000f, +0.2425356f, +0.9701425f, 0x00FFFF00},
{-0.2046557f, +0.4918192f, +0.8463037f, 0x00FFFFFF},
{-0.2046557f, +0.4918192f, +0.8463037f, 0x0000FF00},
{+0.0000000f, +0.2425356f, +0.9701425f, 0x00FFFF00},
{-0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFFFF},
{-0.7745875f, +0.4472215f, +0.4472215f, 0x0000FF00},
{-0.8428507f, +0.4866344f, +0.2297597f, 0x00FFFF00},
{-0.6765525f, +0.6970823f, +0.2373877f, 0x00FFFFFF},
{-0.8428507f, +0.4866344f, +0.2297597f, 0x0000FF00},
{-0.8660000f, +0.5000000f, +0.0000000f, 0x00FFFF00},
{-0.7070957f, +0.7071179f, +0.0000000f, 0x00FFFFFF},
{-0.8428507f, +0.4866344f, +0.2297597f, 0x0000FF00},
{-0.7070957f, +0.7071179f, +0.0000000f, 0x00FFFF00},
{-0.6765525f, +0.6970823f, +0.2373877f, 0x00FFFFFF},
{-0.6765525f, +0.6970823f, +0.2373877f, 0x0000FF00},
{-0.7070957f, +0.7071179f, +0.0000000f, 0x00FFFF00},
{-0.4999890f, +0.8660318f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, +0.7071068f, +0.7071068f, 0x0000FF00},
{-0.2784275f, +0.8760294f, +0.3937646f, 0x00FFFF00},
{+0.2784275f, +0.8760294f, +0.3937646f, 0x00FFFFFF},
{-0.2784275f, +0.8760294f, +0.3937646f, 0x0000FF00},
{-0.4999890f, +0.8660318f, +0.0000000f, 0x00FFFF00},
{+0.0000000f, +1.0000000f, +0.0000000f, 0x00FFFFFF},
{-0.2784275f, +0.8760294f, +0.3937646f, 0x0000FF00},
{+0.0000000f, +1.0000000f, +0.0000000f, 0x00FFFF00},
{+0.2784275f, +0.8760294f, +0.3937646f, 0x00FFFFFF},
{+0.2784275f, +0.8760294f, +0.3937646f, 0x0000FF00},
{+0.0000000f, +1.0000000f, +0.0000000f, 0x00FFFF00},
{+0.4999890f, +0.8660318f, +0.0000000f, 0x00FFFFFF},
{+0.7745875f, +0.4472215f, +0.4472215f, 0x0000FF00},
{+0.6765525f, +0.6970823f, +0.2373877f, 0x00FFFF00},
{+0.8428507f, +0.4866344f, +0.2297597f, 0x00FFFFFF},
{+0.6765525f, +0.6970823f, +0.2373877f, 0x0000FF00},
{+0.4999890f, +0.8660318f, +0.0000000f, 0x00FFFF00},
{+0.7070957f, +0.7071179f, +0.0000000f, 0x00FFFFFF},
{+0.6765525f, +0.6970823f, +0.2373877f, 0x0000FF00},
{+0.7070957f, +0.7071179f, +0.0000000f, 0x00FFFF00},
{+0.8428507f, +0.4866344f, +0.2297597f, 0x00FFFFFF},
{+0.8428507f, +0.4866344f, +0.2297597f, 0x0000FF00},
{+0.7070957f, +0.7071179f, +0.0000000f, 0x00FFFF00},
{+0.8660000f, +0.5000000f, +0.0000000f, 0x00FFFFFF},
{-0.4999890f, +0.8660318f, +0.0000000f, 0x0000FF00},
{-0.2784275f, +0.8760294f, +0.3937646f, 0x00FFFF00},
{-0.6765525f, +0.6970823f, +0.2373877f, 0x00FFFFFF},
{-0.2784275f, +0.8760294f, +0.3937646f, 0x0000FF00},
{+0.0000000f, +0.7071068f, +0.7071068f, 0x00FFFF00},
{-0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFFFF},
{-0.2784275f, +0.8760294f, +0.3937646f, 0x0000FF00},
{-0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{-0.6765525f, +0.6970823f, +0.2373877f, 0x00FFFFFF},
{-0.6765525f, +0.6970823f, +0.2373877f, 0x0000FF00},
{-0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{-0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFFFF},
{+0.4999890f, +0.8660318f, +0.0000000f, 0x0000FF00},
{+0.6765525f, +0.6970823f, +0.2373877f, 0x00FFFF00},
{+0.2784275f, +0.8760294f, +0.3937646f, 0x00FFFFFF},
{+0.6765525f, +0.6970823f, +0.2373877f, 0x0000FF00},
{+0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFF00},
{+0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFFFF},
{+0.6765525f, +0.6970823f, +0.2373877f, 0x0000FF00},
{+0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{+0.2784275f, +0.8760294f, +0.3937646f, 0x00FFFFFF},
{+0.2784275f, +0.8760294f, +0.3937646f, 0x0000FF00},
{+0.4286801f, +0.6388401f, +0.6388401f, 0x00FFFF00},
{+0.0000000f, +0.7071068f, +0.7071068f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{+0.0000000f, -0.2297529f, +0.9732490f, 0x00FFFF00},
{-0.1989667f, +0.1148769f, +0.9732500f, 0x00FFFFFF},
{+0.0000000f, -0.2297529f, +0.9732490f, 0x0000FF00},
{+0.0000000f, -0.4472136f, +0.8944272f, 0x00FFFF00},
{-0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFFFF},
{+0.0000000f, -0.2297529f, +0.9732490f, 0x0000FF00},
{-0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{-0.1989667f, +0.1148769f, +0.9732500f, 0x00FFFFFF},
{-0.1989667f, +0.1148769f, +0.9732500f, 0x0000FF00},
{-0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{-0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFFFF},
{+0.0000000f, -0.4472136f, +0.8944272f, 0x0000FF00},
{+0.0000000f, -0.7071068f, +0.7071068f, 0x00FFFF00},
{-0.3235907f, -0.4231522f, +0.8463045f, 0x00FFFFFF},
{+0.0000000f, -0.7071068f, +0.7071068f, 0x0000FF00},
{+0.0000000f, -0.8944272f, +0.4472136f, 0x00FFFF00},
{-0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFFFF},
{+0.0000000f, -0.7071068f, +0.7071068f, 0x0000FF00},
{-0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{-0.3235907f, -0.4231522f, +0.8463045f, 0x00FFFFFF},
{-0.3235907f, -0.4231522f, +0.8463045f, 0x0000FF00},
{-0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{-0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFFFF},
{-0.3872887f, +0.2236078f, +0.8944311f, 0x0000FF00},
{-0.5282476f, -0.0686696f, +0.8463090f, 0x00FFFF00},
{-0.6123626f, +0.3535581f, +0.7071130f, 0x00FFFFFF},
{-0.5282476f, -0.0686696f, +0.8463090f, 0x0000FF00},
{-0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFF00},
{-0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFFFF},
{-0.5282476f, -0.0686696f, +0.8463090f, 0x0000FF00},
{-0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{-0.6123626f, +0.3535581f, +0.7071130f, 0x00FFFFFF},
{-0.6123626f, +0.3535581f, +0.7071130f, 0x0000FF00},
{-0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{-0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFFFF},
{-0.6123612f, -0.3535573f, +0.7071146f, 0x0000FF00},
{-0.5282476f, -0.0686696f, +0.8463090f, 0x00FFFF00},
{-0.3235907f, -0.4231522f, +0.8463045f, 0x00FFFFFF},
{-0.5282476f, -0.0686696f, +0.8463090f, 0x0000FF00},
{-0.3872887f, +0.2236078f, +0.8944311f, 0x00FFFF00},
{-0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFFFF},
{-0.5282476f, -0.0686696f, +0.8463090f, 0x0000FF00},
{-0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{-0.3235907f, -0.4231522f, +0.8463045f, 0x00FFFFFF},
{-0.3235907f, -0.4231522f, +0.8463045f, 0x0000FF00},
{-0.2100366f, -0.1212672f, +0.9701437f, 0x00FFFF00},
{+0.0000000f, -0.4472136f, +0.8944272f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, +0.4472136f, 0x0000FF00},
{+0.0000000f, -0.9732490f, +0.2297529f, 0x00FFFF00},
{-0.2653963f, -0.9344593f, +0.2373829f, 0x00FFFFFF},
{+0.0000000f, -0.9732490f, +0.2297529f, 0x0000FF00},
{+0.0000000f, -1.0000000f, +0.0000000f, 0x00FFFF00},
{-0.2588129f, -0.9659275f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, -0.9732490f, +0.2297529f, 0x0000FF00},
{-0.2588129f, -0.9659275f, +0.0000000f, 0x00FFFF00},
{-0.2653963f, -0.9344593f, +0.2373829f, 0x00FFFFFF},
{-0.2653963f, -0.9344593f, +0.2373829f, 0x0000FF00},
{-0.2588129f, -0.9659275f, +0.0000000f, 0x00FFFF00},
{-0.4999890f, -0.8660318f, +0.0000000f, 0x00FFFFFF},
{-0.6123612f, -0.3535573f, +0.7071146f, 0x0000FF00},
{-0.6194336f, -0.6791516f, +0.3937704f, 0x00FFFF00},
{-0.8978756f, -0.1968855f, +0.3937709f, 0x00FFFFFF},
{-0.6194336f, -0.6791516f, +0.3937704f, 0x0000FF00},
{-0.4999890f, -0.8660318f, +0.0000000f, 0x00FFFF00},
{-0.8660222f, -0.5000055f, +0.0000000f, 0x00FFFFFF},
{-0.6194336f, -0.6791516f, +0.3937704f, 0x0000FF00},
{-0.8660222f, -0.5000055f, +0.0000000f, 0x00FFFF00},
{-0.8978756f, -0.1968855f, +0.3937709f, 0x00FFFFFF},
{-0.8978756f, -0.1968855f, +0.3937709f, 0x0000FF00},
{-0.8660222f, -0.5000055f, +0.0000000f, 0x00FFFF00},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{-0.7745875f, +0.4472215f, +0.4472215f, 0x0000FF00},
{-0.9419628f, +0.2373881f, +0.2373881f, 0x00FFFF00},
{-0.8428507f, +0.4866344f, +0.2297597f, 0x00FFFFFF},
{-0.9419628f, +0.2373881f, +0.2373881f, 0x0000FF00},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFF00},
{-0.9659249f, +0.2588224f, +0.0000000f, 0x00FFFFFF},
{-0.9419628f, +0.2373881f, +0.2373881f, 0x0000FF00},
{-0.9659249f, +0.2588224f, +0.0000000f, 0x00FFFF00},
{-0.8428507f, +0.4866344f, +0.2297597f, 0x00FFFFFF},
{-0.8428507f, +0.4866344f, +0.2297597f, 0x0000FF00},
{-0.9659249f, +0.2588224f, +0.0000000f, 0x00FFFF00},
{-0.8660000f, +0.5000000f, +0.0000000f, 0x00FFFFFF},
{-0.4999890f, -0.8660318f, +0.0000000f, 0x0000FF00},
{-0.6194336f, -0.6791516f, +0.3937704f, 0x00FFFF00},
{-0.2653963f, -0.9344593f, +0.2373829f, 0x00FFFFFF},
{-0.6194336f, -0.6791516f, +0.3937704f, 0x0000FF00},
{-0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFF00},
{-0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFFFF},
{-0.6194336f, -0.6791516f, +0.3937704f, 0x0000FF00},
{-0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{-0.2653963f, -0.9344593f, +0.2373829f, 0x00FFFFFF},
{-0.2653963f, -0.9344593f, +0.2373829f, 0x0000FF00},
{-0.3388996f, -0.6906732f, +0.6388409f, 0x00FFFF00},
{+0.0000000f, -0.8944272f, +0.4472136f, 0x00FFFFFF},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x0000FF00},
{-0.9419628f, +0.2373881f, +0.2373881f, 0x00FFFF00},
{-0.8978756f, -0.1968855f, +0.3937709f, 0x00FFFFFF},
{-0.9419628f, +0.2373881f, +0.2373881f, 0x0000FF00},
{-0.7745875f, +0.4472215f, +0.4472215f, 0x00FFFF00},
{-0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFFFF},
{-0.9419628f, +0.2373881f, +0.2373881f, 0x0000FF00},
{-0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{-0.8978756f, -0.1968855f, +0.3937709f, 0x00FFFFFF},
{-0.8978756f, -0.1968855f, +0.3937709f, 0x0000FF00},
{-0.7675843f, +0.0518369f, +0.6388485f, 0x00FFFF00},
{-0.6123612f, -0.3535573f, +0.7071146f, 0x00FFFFFF}
	};

	for(int i=0; i<324; i++)
	{
		Polyhedral_108[i].x = InvHemisphere108[i].x * scale_r + translation_x;
		Polyhedral_108[i].y = InvHemisphere108[i].y * scale_r + translation_y;
		Polyhedral_108[i].z = InvHemisphere108[i].z * scale_r + translation_z;
		Polyhedral_108[i].color = 0xFFFFFFFF;

		Polyhedral_108[i].tu = (FLOAT)((1.0 - (InvHemisphere108[i].x)) / 2.0f);
		Polyhedral_108[i].tv = (FLOAT)((1.0 - (InvHemisphere108[i].y)) / 2.0f);
	}
	*Num_Vertexs += 324;
}
void CreateNormalIcosahedron(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_20, DWORD *Num_Vertexs, DWORD transparency)
{
	//srand( (unsigned)time( NULL ) );

	t_CUSTOMVERTEX Icosahedron[] = 
	{
		{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
		{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
		{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
		{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
		{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
		{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
		{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
		{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
		{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
		{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
		{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
		{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
		{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
		{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
		{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
		{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
		{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
		{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
		{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
		{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
		{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
		{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
		{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF}
	};

	for(int i=0; i<60; i++)
	{
		Polyhedral_20[i].x = Icosahedron[i].x * scale_r + translation_x;
		Polyhedral_20[i].y = Icosahedron[i].y * scale_r + translation_y;
		Polyhedral_20[i].z = Icosahedron[i].z * scale_r + translation_z;
		Polyhedral_20[i].color = transparency;

		Polyhedral_20[i].tu = (FLOAT)((1.0 - (Polyhedral_20[i].y / scale_r)) / 2.0f);
		Polyhedral_20[i].tv = (FLOAT)((1.0 - (Polyhedral_20[i].z / scale_r)) / 2.0f);
	}
	*Num_Vertexs += 60;
}

void CreateNormalSphere80(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_80, DWORD *Num_Vertexs)
{
	//srand( (unsigned)time( NULL ) );

	t_CUSTOMVERTEX Sphere80[] = 
	{

{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
{+0.0000000f, +0.5257311f, +0.8506508f, 0x00FFFFFF},
{-0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{+0.0000000f, +0.5257311f, +0.8506508f, 0x00FFFFFF},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
{-0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.0000000f, +0.5257311f, +0.8506508f, 0x00FFFFFF},
{-0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{-0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{-0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{-0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
{-0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{-0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{-0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{-0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{-0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{-0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{-0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{-0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{-0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
{-0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{+0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{-0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, -0.8506508f, +0.5257311f, 0x00FFFFFF},
{-0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{+0.0000000f, -0.8506508f, +0.5257311f, 0x00FFFFFF},
{+0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{+0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{+0.0000000f, -0.8506508f, +0.5257311f, 0x00FFFFFF},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
{+0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{+0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{+0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{+0.3090170f, -0.4253254f, +0.8506508f, 0x00FFFFFF},
{+0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{+0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{+0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{+0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x00FFFFFF},
{+0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{+0.0000000f, +0.5257311f, +0.8506508f, 0x00FFFFFF},
{+0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.5000000f, +0.1624598f, +0.8506508f, 0x00FFFFFF},
{+0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.0000000f, +0.5257311f, +0.8506508f, 0x00FFFFFF},
{+0.0000000f, +0.5257311f, +0.8506508f, 0x00FFFFFF},
{+0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
{+0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.8506508f, -0.5257311f, 0x00FFFFFF},
{+0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, +0.8506508f, -0.5257311f, 0x00FFFFFF},
{-0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, +0.8506508f, -0.5257311f, 0x00FFFFFF},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{-0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{-0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{-0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{-0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{-0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{-0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{-0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
{+0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{+0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{+0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{-0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{-0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{-0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{-0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{-0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{-0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{-0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{-1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{-0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
{+0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, -0.8506508f, +0.5257311f, 0x00FFFFFF},
{+0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, -0.8506508f, +0.5257311f, 0x00FFFFFF},
{-0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{-0.3090170f, -0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, -0.8506508f, +0.5257311f, 0x00FFFFFF},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{+1.0000000f, +0.0000000f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{+0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, -0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, -0.2628656f, +0.5257311f, 0x00FFFFFF},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
{+0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.3090170f, +0.9510565f, +0.0000000f, 0x00FFFFFF},
{+0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.8090170f, +0.5877852f, +0.0000000f, 0x00FFFFFF},
{+0.5000000f, +0.6881909f, +0.5257311f, 0x00FFFFFF},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
{-0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{+0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{-0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.8506508f, -0.5257311f, 0x00FFFFFF},
{-0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{+0.0000000f, +0.8506508f, -0.5257311f, 0x00FFFFFF},
{+0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{+0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{+0.0000000f, +0.8506508f, -0.5257311f, 0x00FFFFFF},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
{-0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{-0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{-0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{-0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{-0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{-0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{-0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{-0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{-0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
{+0.0000000f, -0.5257311f, -0.8506508f, 0x00FFFFFF},
{-0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{+0.0000000f, -0.5257311f, -0.8506508f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
{-0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.0000000f, -0.5257311f, -0.8506508f, 0x00FFFFFF},
{-0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{-0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{-0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{-0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
{+0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{+0.0000000f, -0.5257311f, -0.8506508f, 0x00FFFFFF},
{+0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{+0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{+0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.0000000f, -0.5257311f, -0.8506508f, 0x00FFFFFF},
{+0.0000000f, -0.5257311f, -0.8506508f, 0x00FFFFFF},
{+0.5000000f, -0.6881909f, -0.5257311f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x00FFFFFF},
{+0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{+0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{+0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{+0.3090170f, +0.4253254f, -0.8506508f, 0x00FFFFFF},
{+0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{+0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{+0.5000000f, -0.1624598f, -0.8506508f, 0x00FFFFFF},
{+0.8090170f, +0.2628656f, -0.5257311f, 0x00FFFFFF},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF}

	};

	for(int i=0; i<240; i++)
	{
		Polyhedral_80[i].x = Sphere80[i].x * scale_r + translation_x;
		Polyhedral_80[i].y = Sphere80[i].y * scale_r + translation_y;
		Polyhedral_80[i].z = Sphere80[i].z * scale_r + translation_z;
		Polyhedral_80[i].color = 0xFFFFFFFF;
	}

	for(int i=0; i<80; i++)
	{
		if(	Polyhedral_80[3*i+0].x >= 0.0f &&
			Polyhedral_80[3*i+1].x >= 0.0f  &&
			Polyhedral_80[3*i+2].x >= 0.0f )
		{
			Polyhedral_80[3*i+0].tu = (FLOAT)((1.0 - (Polyhedral_80[3*i+0].y / scale_r)) / 2.0f);
			Polyhedral_80[3*i+0].tv = (FLOAT)((1.0 - (Polyhedral_80[3*i+0].z / scale_r)) / 2.0f);
			Polyhedral_80[3*i+1].tu = (FLOAT)((1.0 - (Polyhedral_80[3*i+1].y / scale_r)) / 2.0f);
			Polyhedral_80[3*i+1].tv = (FLOAT)((1.0 - (Polyhedral_80[3*i+1].z / scale_r)) / 2.0f);
			Polyhedral_80[3*i+2].tu = (FLOAT)((1.0 - (Polyhedral_80[3*i+2].y / scale_r)) / 2.0f);
			Polyhedral_80[3*i+2].tv = (FLOAT)((1.0 - (Polyhedral_80[3*i+2].z / scale_r)) / 2.0f);
		}
		else
		{
			Polyhedral_80[3*i+0].tu = 0.0f;
			Polyhedral_80[3*i+0].tv = 0.0f;
			Polyhedral_80[3*i+1].tu = 0.0f;
			Polyhedral_80[3*i+1].tv = 0.0f;
			Polyhedral_80[3*i+2].tu = 0.0f;
			Polyhedral_80[3*i+2].tv = 0.0f;
		}
	}
	*Num_Vertexs += 240;
}

void CreateNormalSphere180(FLOAT translation_x, FLOAT translation_y, FLOAT translation_z, FLOAT scale_r, p_CUSTOMVERTEX Polyhedral_180, DWORD *Num_Vertexs)
{
	//srand( (unsigned)time( NULL ) );

	t_CUSTOMVERTEX Sphere180[] = 
	{
{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{+0.0000000f, +0.3432786f, +0.9392337f, 0x00FFFF00},
{-0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFFFF},
{+0.0000000f, +0.3432786f, +0.9392337f, 0x0000FF00},
{+0.0000000f, +0.6865572f, +0.7270758f, 0x00FFFF00},
{-0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFFFF},
{-0.3264774f, +0.1060789f, +0.9392337f, 0x0000FF00},
{-0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFF00},
{-0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFFFF},
{-0.3568221f, +0.4911235f, +0.7946545f, 0x0000FF00},
{-0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFF00},
{+0.0000000f, +0.3432786f, +0.9392337f, 0x00FFFFFF},
{+0.0000000f, +0.6865572f, +0.7270758f, 0x0000FF00},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFF00},
{-0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFFFF},
{-0.3568221f, +0.4911235f, +0.7946545f, 0x0000FF00},
{-0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFF00},
{-0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFFFF},
{-0.6529547f, +0.2121578f, +0.7270758f, 0x0000FF00},
{-0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFF00},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{-0.3264773f, +0.7926362f, +0.5149179f, 0x0000FF00},
{-0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFF00},
{+0.0000000f, +0.6865572f, +0.7270758f, 0x00FFFFFF},
{-0.6529548f, +0.5554365f, +0.5149179f, 0x0000FF00},
{-0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFF00},
{-0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{-0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFF00},
{-0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFFFF},
{-0.3264774f, +0.1060789f, +0.9392337f, 0x0000FF00},
{-0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFF00},
{-0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFFFF},
{-0.2017741f, -0.2777182f, +0.9392337f, 0x0000FF00},
{-0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFF00},
{-0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFFFF},
{-0.5773502f, -0.1875925f, +0.7946545f, 0x0000FF00},
{-0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFF00},
{-0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFFFF},
{-0.6529547f, +0.2121578f, +0.7270758f, 0x0000FF00},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFF00},
{-0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFFFF},
{-0.5773502f, -0.1875925f, +0.7946545f, 0x0000FF00},
{-0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFF00},
{-0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFFFF},
{-0.4035482f, -0.5554365f, +0.7270758f, 0x0000FF00},
{-0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFF00},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{-0.8547288f, -0.0655604f, +0.5149179f, 0x0000FF00},
{-0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFF00},
{-0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFFFF},
{-0.7300255f, -0.4493575f, +0.5149179f, 0x0000FF00},
{-0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFF00},
{-0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{-0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFF00},
{+0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFFFF},
{-0.2017741f, -0.2777182f, +0.9392337f, 0x0000FF00},
{-0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFF00},
{+0.0000000f, -0.6070620f, +0.7946544f, 0x00FFFFFF},
{+0.2017741f, -0.2777182f, +0.9392337f, 0x0000FF00},
{+0.0000000f, -0.6070620f, +0.7946544f, 0x00FFFF00},
{+0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFFFF},
{+0.0000000f, -0.6070620f, +0.7946544f, 0x0000FF00},
{+0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFF00},
{-0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFFFF},
{-0.4035482f, -0.5554365f, +0.7270758f, 0x0000FF00},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFF00},
{-0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFFFF},
{+0.0000000f, -0.6070620f, +0.7946544f, 0x0000FF00},
{-0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFF00},
{+0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFFFF},
{+0.4035482f, -0.5554365f, +0.7270758f, 0x0000FF00},
{+0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFF00},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{-0.2017741f, -0.8331547f, +0.5149179f, 0x0000FF00},
{+0.0000000f, -0.6070620f, +0.7946544f, 0x00FFFF00},
{-0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFFFF},
{+0.2017741f, -0.8331547f, +0.5149179f, 0x0000FF00},
{+0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFF00},
{+0.0000000f, -0.6070620f, +0.7946544f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{+0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFF00},
{+0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFFFF},
{+0.2017741f, -0.2777182f, +0.9392337f, 0x0000FF00},
{+0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFF00},
{+0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFFFF},
{+0.3264774f, +0.1060789f, +0.9392337f, 0x0000FF00},
{+0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFF00},
{+0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFFFF},
{+0.5773502f, -0.1875925f, +0.7946545f, 0x0000FF00},
{+0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFF00},
{+0.2017741f, -0.2777182f, +0.9392337f, 0x00FFFFFF},
{+0.4035482f, -0.5554365f, +0.7270758f, 0x0000FF00},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFF00},
{+0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFFFF},
{+0.5773502f, -0.1875925f, +0.7946545f, 0x0000FF00},
{+0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFF00},
{+0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFFFF},
{+0.6529547f, +0.2121578f, +0.7270758f, 0x0000FF00},
{+0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFF00},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.7300255f, -0.4493575f, +0.5149179f, 0x0000FF00},
{+0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFF00},
{+0.4035482f, -0.5554365f, +0.7270758f, 0x00FFFFFF},
{+0.8547288f, -0.0655604f, +0.5149179f, 0x0000FF00},
{+0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFF00},
{+0.5773502f, -0.1875925f, +0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, +1.0000000f, 0x0000FF00},
{+0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFF00},
{+0.0000000f, +0.3432786f, +0.9392337f, 0x00FFFFFF},
{+0.3264774f, +0.1060789f, +0.9392337f, 0x0000FF00},
{+0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFF00},
{+0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.3432786f, +0.9392337f, 0x0000FF00},
{+0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFF00},
{+0.0000000f, +0.6865572f, +0.7270758f, 0x00FFFFFF},
{+0.3568221f, +0.4911235f, +0.7946545f, 0x0000FF00},
{+0.0000000f, +0.3432786f, +0.9392337f, 0x00FFFF00},
{+0.3264774f, +0.1060789f, +0.9392337f, 0x00FFFFFF},
{+0.6529547f, +0.2121578f, +0.7270758f, 0x0000FF00},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFF00},
{+0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFFFF},
{+0.3568221f, +0.4911235f, +0.7946545f, 0x0000FF00},
{+0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFF00},
{+0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFFFF},
{+0.0000000f, +0.6865572f, +0.7270758f, 0x0000FF00},
{+0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFF00},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
{+0.6529548f, +0.5554365f, +0.5149179f, 0x0000FF00},
{+0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFF00},
{+0.6529547f, +0.2121578f, +0.7270758f, 0x00FFFFFF},
{+0.3264773f, +0.7926362f, +0.5149179f, 0x0000FF00},
{+0.0000000f, +0.6865572f, +0.7270758f, 0x00FFFF00},
{+0.3568221f, +0.4911235f, +0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x0000FF00},
{+0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFF00},
{-0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFFFF},
{+0.2017741f, +0.9642755f, +0.1716393f, 0x0000FF00},
{+0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFF00},
{+0.0000000f, +0.9822469f, -0.1875925f, 0x00FFFFFF},
{-0.2017741f, +0.9642755f, +0.1716393f, 0x0000FF00},
{+0.0000000f, +0.9822469f, -0.1875925f, 0x00FFFF00},
{-0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFFFF},
{+0.0000000f, +0.9822469f, -0.1875925f, 0x0000FF00},
{-0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFF00},
{+0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFFFF},
{+0.4035482f, +0.8987151f, -0.1716393f, 0x0000FF00},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFF00},
{+0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFFFF},
{+0.0000000f, +0.9822469f, -0.1875925f, 0x0000FF00},
{+0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFF00},
{-0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFFFF},
{-0.4035482f, +0.8987151f, -0.1716393f, 0x0000FF00},
{-0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFF00},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.2017741f, +0.8331547f, -0.5149179f, 0x0000FF00},
{+0.0000000f, +0.9822469f, -0.1875925f, 0x00FFFF00},
{+0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFFFF},
{-0.2017741f, +0.8331547f, -0.5149179f, 0x0000FF00},
{-0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFF00},
{+0.0000000f, +0.9822469f, -0.1875925f, 0x00FFFFFF},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x0000FF00},
{-0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFF00},
{-0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFFFF},
{-0.8547288f, +0.4898761f, +0.1716393f, 0x0000FF00},
{-0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFF00},
{-0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFFFF},
{-0.9794321f, +0.1060789f, +0.1716393f, 0x0000FF00},
{-0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFF00},
{-0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFFFF},
{-0.9341723f, +0.3035310f, -0.1875925f, 0x0000FF00},
{-0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFF00},
{-0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFFFF},
{-0.7300255f, +0.6615154f, -0.1716393f, 0x0000FF00},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFF00},
{-0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFFFF},
{-0.9341723f, +0.3035310f, -0.1875925f, 0x0000FF00},
{-0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFF00},
{-0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFFFF},
{-0.9794321f, -0.1060789f, -0.1716393f, 0x0000FF00},
{-0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFF00},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{-0.7300255f, +0.4493575f, -0.5149179f, 0x0000FF00},
{-0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFF00},
{-0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFFFF},
{-0.8547288f, +0.0655604f, -0.5149179f, 0x0000FF00},
{-0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFF00},
{-0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFFFF},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x0000FF00},
{-0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFF00},
{-0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFFFF},
{-0.7300255f, -0.6615154f, +0.1716393f, 0x0000FF00},
{-0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFF00},
{-0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFFFF},
{-0.4035482f, -0.8987151f, +0.1716393f, 0x0000FF00},
{-0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFF00},
{-0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFFFF},
{-0.5773502f, -0.7946545f, -0.1875925f, 0x0000FF00},
{-0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFF00},
{-0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFFFF},
{-0.8547288f, -0.4898761f, -0.1716393f, 0x0000FF00},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFF00},
{-0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFFFF},
{-0.5773502f, -0.7946545f, -0.1875925f, 0x0000FF00},
{-0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFF00},
{-0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFFFF},
{-0.2017741f, -0.9642755f, -0.1716393f, 0x0000FF00},
{-0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFF00},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
{-0.6529548f, -0.5554365f, -0.5149179f, 0x0000FF00},
{-0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFF00},
{-0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFFFF},
{-0.3264773f, -0.7926362f, -0.5149179f, 0x0000FF00},
{-0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFF00},
{-0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFFFF},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x0000FF00},
{+0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFF00},
{+0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFFFF},
{+0.4035482f, -0.8987151f, +0.1716393f, 0x0000FF00},
{+0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFF00},
{+0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFFFF},
{+0.7300255f, -0.6615154f, +0.1716393f, 0x0000FF00},
{+0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFF00},
{+0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFFFF},
{+0.5773502f, -0.7946545f, -0.1875925f, 0x0000FF00},
{+0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFF00},
{+0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFFFF},
{+0.2017741f, -0.9642755f, -0.1716393f, 0x0000FF00},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFF00},
{+0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFFFF},
{+0.5773502f, -0.7946545f, -0.1875925f, 0x0000FF00},
{+0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFF00},
{+0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFFFF},
{+0.8547288f, -0.4898761f, -0.1716393f, 0x0000FF00},
{+0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFF00},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{+0.3264773f, -0.7926362f, -0.5149179f, 0x0000FF00},
{+0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFF00},
{+0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFFFF},
{+0.6529548f, -0.5554365f, -0.5149179f, 0x0000FF00},
{+0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFF00},
{+0.5773502f, -0.7946545f, -0.1875925f, 0x00FFFFFF},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x0000FF00},
{+0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFF00},
{+0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFFFF},
{+0.9794321f, +0.1060789f, +0.1716393f, 0x0000FF00},
{+0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFF00},
{+0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFFFF},
{+0.8547288f, +0.4898761f, +0.1716393f, 0x0000FF00},
{+0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFF00},
{+0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFFFF},
{+0.9341723f, +0.3035310f, -0.1875925f, 0x0000FF00},
{+0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFF00},
{+0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFFFF},
{+0.9794321f, -0.1060789f, -0.1716393f, 0x0000FF00},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFF00},
{+0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFFFF},
{+0.9341723f, +0.3035310f, -0.1875925f, 0x0000FF00},
{+0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFF00},
{+0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFFFF},
{+0.7300255f, +0.6615154f, -0.1716393f, 0x0000FF00},
{+0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFF00},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{+0.8547288f, +0.0655604f, -0.5149179f, 0x0000FF00},
{+0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFF00},
{+0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFFFF},
{+0.7300255f, +0.4493575f, -0.5149179f, 0x0000FF00},
{+0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFF00},
{+0.9341723f, +0.3035310f, -0.1875925f, 0x00FFFFFF},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x0000FF00},
{-0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFF00},
{-0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFFFF},
{-0.7300255f, +0.6615154f, -0.1716393f, 0x0000FF00},
{-0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFF00},
{-0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFFFF},
{-0.4035482f, +0.8987151f, -0.1716393f, 0x0000FF00},
{-0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFF00},
{-0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFFFF},
{-0.5773502f, +0.7946545f, +0.1875925f, 0x0000FF00},
{-0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFF00},
{-0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFFFF},
{-0.8547288f, +0.4898761f, +0.1716393f, 0x0000FF00},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFF00},
{-0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFFFF},
{-0.5773502f, +0.7946545f, +0.1875925f, 0x0000FF00},
{-0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFF00},
{-0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFFFF},
{-0.2017741f, +0.9642755f, +0.1716393f, 0x0000FF00},
{-0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFF00},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFFFF},
{-0.6529548f, +0.5554365f, +0.5149179f, 0x0000FF00},
{-0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFF00},
{-0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFFFF},
{-0.3264773f, +0.7926362f, +0.5149179f, 0x0000FF00},
{-0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFF00},
{-0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFFFF},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x0000FF00},
{-0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFF00},
{-0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFFFF},
{-0.8547288f, -0.4898761f, -0.1716393f, 0x0000FF00},
{-0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFF00},
{-0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFFFF},
{-0.9794321f, -0.1060789f, -0.1716393f, 0x0000FF00},
{-0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFF00},
{-0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFFFF},
{-0.9341723f, -0.3035310f, +0.1875925f, 0x0000FF00},
{-0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFF00},
{-0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFFFF},
{-0.7300255f, -0.6615154f, +0.1716393f, 0x0000FF00},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFF00},
{-0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFFFF},
{-0.9341723f, -0.3035310f, +0.1875925f, 0x0000FF00},
{-0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFF00},
{-0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFFFF},
{-0.9794321f, +0.1060789f, +0.1716393f, 0x0000FF00},
{-0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFF00},
{-0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{-0.7300255f, -0.4493575f, +0.5149179f, 0x0000FF00},
{-0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFF00},
{-0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFFFF},
{-0.8547288f, -0.0655604f, +0.5149179f, 0x0000FF00},
{-0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFF00},
{-0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFFFF},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x0000FF00},
{+0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFF00},
{-0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFFFF},
{+0.2017741f, -0.9642755f, -0.1716393f, 0x0000FF00},
{+0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFF00},
{+0.0000000f, -0.9822469f, +0.1875925f, 0x00FFFFFF},
{-0.2017741f, -0.9642755f, -0.1716393f, 0x0000FF00},
{+0.0000000f, -0.9822469f, +0.1875925f, 0x00FFFF00},
{-0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFFFF},
{+0.0000000f, -0.9822469f, +0.1875925f, 0x0000FF00},
{-0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFF00},
{+0.2017741f, -0.9642755f, -0.1716393f, 0x00FFFFFF},
{+0.4035482f, -0.8987151f, +0.1716393f, 0x0000FF00},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFF00},
{+0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFFFF},
{+0.0000000f, -0.9822469f, +0.1875925f, 0x0000FF00},
{+0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFF00},
{-0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFFFF},
{-0.4035482f, -0.8987151f, +0.1716393f, 0x0000FF00},
{-0.2017741f, -0.8331547f, +0.5149179f, 0x00FFFF00},
{-0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.2017741f, -0.8331547f, +0.5149179f, 0x0000FF00},
{+0.0000000f, -0.9822469f, +0.1875925f, 0x00FFFF00},
{+0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFFFF},
{-0.2017741f, -0.8331547f, +0.5149179f, 0x0000FF00},
{-0.4035482f, -0.8987151f, +0.1716393f, 0x00FFFF00},
{+0.0000000f, -0.9822469f, +0.1875925f, 0x00FFFFFF},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x0000FF00},
{+0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFF00},
{+0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFFFF},
{+0.9794321f, -0.1060789f, -0.1716393f, 0x0000FF00},
{+0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFF00},
{+0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFFFF},
{+0.8547288f, -0.4898761f, -0.1716393f, 0x0000FF00},
{+0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFF00},
{+0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFFFF},
{+0.9341723f, -0.3035310f, +0.1875925f, 0x0000FF00},
{+0.8547288f, -0.4898761f, -0.1716393f, 0x00FFFF00},
{+0.9794321f, -0.1060789f, -0.1716393f, 0x00FFFFFF},
{+0.9794321f, +0.1060789f, +0.1716393f, 0x0000FF00},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFF00},
{+0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFFFF},
{+0.9341723f, -0.3035310f, +0.1875925f, 0x0000FF00},
{+0.8547288f, -0.0655604f, +0.5149179f, 0x00FFFF00},
{+0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFFFF},
{+0.7300255f, -0.6615154f, +0.1716393f, 0x0000FF00},
{+0.7300255f, -0.4493575f, +0.5149179f, 0x00FFFF00},
{+0.5257311f, -0.7236068f, +0.4472136f, 0x00FFFFFF},
{+0.8547288f, -0.0655604f, +0.5149179f, 0x0000FF00},
{+0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFF00},
{+0.9794321f, +0.1060789f, +0.1716393f, 0x00FFFFFF},
{+0.7300255f, -0.4493575f, +0.5149179f, 0x0000FF00},
{+0.7300255f, -0.6615154f, +0.1716393f, 0x00FFFF00},
{+0.9341723f, -0.3035310f, +0.1875925f, 0x00FFFFFF},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x0000FF00},
{+0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFF00},
{+0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFFFF},
{+0.4035482f, +0.8987151f, -0.1716393f, 0x0000FF00},
{+0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFF00},
{+0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFFFF},
{+0.7300255f, +0.6615154f, -0.1716393f, 0x0000FF00},
{+0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFF00},
{+0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFFFF},
{+0.5773502f, +0.7946545f, +0.1875925f, 0x0000FF00},
{+0.7300255f, +0.6615154f, -0.1716393f, 0x00FFFF00},
{+0.4035482f, +0.8987151f, -0.1716393f, 0x00FFFFFF},
{+0.2017741f, +0.9642755f, +0.1716393f, 0x0000FF00},
{+0.0000000f, +0.8944272f, +0.4472136f, 0x00FFFF00},
{+0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFFFF},
{+0.5773502f, +0.7946545f, +0.1875925f, 0x0000FF00},
{+0.3264773f, +0.7926362f, +0.5149179f, 0x00FFFF00},
{+0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFFFF},
{+0.8547288f, +0.4898761f, +0.1716393f, 0x0000FF00},
{+0.6529548f, +0.5554365f, +0.5149179f, 0x00FFFF00},
{+0.8506508f, +0.2763932f, +0.4472136f, 0x00FFFFFF},
{+0.3264773f, +0.7926362f, +0.5149179f, 0x0000FF00},
{+0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFF00},
{+0.2017741f, +0.9642755f, +0.1716393f, 0x00FFFFFF},
{+0.6529548f, +0.5554365f, +0.5149179f, 0x0000FF00},
{+0.8547288f, +0.4898761f, +0.1716393f, 0x00FFFF00},
{+0.5773502f, +0.7946545f, +0.1875925f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x0000FF00},
{-0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFF00},
{+0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFFFF},
{-0.2017741f, +0.2777182f, -0.9392337f, 0x0000FF00},
{-0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFF00},
{+0.0000000f, +0.6070620f, -0.7946544f, 0x00FFFFFF},
{+0.2017741f, +0.2777182f, -0.9392337f, 0x0000FF00},
{+0.0000000f, +0.6070620f, -0.7946544f, 0x00FFFF00},
{+0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFFFF},
{+0.0000000f, +0.6070620f, -0.7946544f, 0x0000FF00},
{+0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFF00},
{-0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFFFF},
{-0.4035482f, +0.5554365f, -0.7270758f, 0x0000FF00},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFF00},
{-0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFFFF},
{+0.0000000f, +0.6070620f, -0.7946544f, 0x0000FF00},
{-0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFF00},
{+0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFFFF},
{+0.4035482f, +0.5554365f, -0.7270758f, 0x0000FF00},
{+0.2017741f, +0.8331547f, -0.5149179f, 0x00FFFF00},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{-0.2017741f, +0.8331547f, -0.5149179f, 0x0000FF00},
{+0.0000000f, +0.6070620f, -0.7946544f, 0x00FFFF00},
{-0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFFFF},
{+0.2017741f, +0.8331547f, -0.5149179f, 0x0000FF00},
{+0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFF00},
{+0.0000000f, +0.6070620f, -0.7946544f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x0000FF00},
{-0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFF00},
{-0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFFFF},
{-0.3264774f, -0.1060789f, -0.9392337f, 0x0000FF00},
{-0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFF00},
{-0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFFFF},
{-0.2017741f, +0.2777182f, -0.9392337f, 0x0000FF00},
{-0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFF00},
{-0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFFFF},
{-0.5773502f, +0.1875925f, -0.7946545f, 0x0000FF00},
{-0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFF00},
{-0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFFFF},
{-0.6529547f, -0.2121578f, -0.7270758f, 0x0000FF00},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFF00},
{-0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFFFF},
{-0.5773502f, +0.1875925f, -0.7946545f, 0x0000FF00},
{-0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFF00},
{-0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFFFF},
{-0.4035482f, +0.5554365f, -0.7270758f, 0x0000FF00},
{-0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFF00},
{-0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFFFF},
{-0.8547288f, +0.0655604f, -0.5149179f, 0x0000FF00},
{-0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFF00},
{-0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFFFF},
{-0.7300255f, +0.4493575f, -0.5149179f, 0x0000FF00},
{-0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFF00},
{-0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x0000FF00},
{+0.0000000f, -0.3432786f, -0.9392337f, 0x00FFFF00},
{-0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFFFF},
{+0.0000000f, -0.3432786f, -0.9392337f, 0x0000FF00},
{+0.0000000f, -0.6865572f, -0.7270758f, 0x00FFFF00},
{-0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFFFF},
{-0.3264774f, -0.1060789f, -0.9392337f, 0x0000FF00},
{-0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFF00},
{-0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFFFF},
{-0.3568221f, -0.4911235f, -0.7946545f, 0x0000FF00},
{-0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFF00},
{+0.0000000f, -0.3432786f, -0.9392337f, 0x00FFFFFF},
{+0.0000000f, -0.6865572f, -0.7270758f, 0x0000FF00},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFF00},
{-0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFFFF},
{-0.3568221f, -0.4911235f, -0.7946545f, 0x0000FF00},
{-0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFF00},
{-0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFFFF},
{-0.6529547f, -0.2121578f, -0.7270758f, 0x0000FF00},
{-0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFF00},
{-0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{-0.3264773f, -0.7926362f, -0.5149179f, 0x0000FF00},
{-0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFF00},
{+0.0000000f, -0.6865572f, -0.7270758f, 0x00FFFFFF},
{-0.6529548f, -0.5554365f, -0.5149179f, 0x0000FF00},
{-0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFF00},
{-0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x0000FF00},
{+0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFF00},
{+0.0000000f, -0.3432786f, -0.9392337f, 0x00FFFFFF},
{+0.3264774f, -0.1060789f, -0.9392337f, 0x0000FF00},
{+0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFF00},
{+0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFFFF},
{+0.0000000f, -0.3432786f, -0.9392337f, 0x0000FF00},
{+0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFF00},
{+0.0000000f, -0.6865572f, -0.7270758f, 0x00FFFFFF},
{+0.3568221f, -0.4911235f, -0.7946545f, 0x0000FF00},
{+0.0000000f, -0.3432786f, -0.9392337f, 0x00FFFF00},
{+0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFFFF},
{+0.6529547f, -0.2121578f, -0.7270758f, 0x0000FF00},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFF00},
{+0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFFFF},
{+0.3568221f, -0.4911235f, -0.7946545f, 0x0000FF00},
{+0.6529548f, -0.5554365f, -0.5149179f, 0x00FFFF00},
{+0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFFFF},
{+0.0000000f, -0.6865572f, -0.7270758f, 0x0000FF00},
{+0.3264773f, -0.7926362f, -0.5149179f, 0x00FFFF00},
{+0.0000000f, -0.8944272f, -0.4472136f, 0x00FFFFFF},
{+0.6529548f, -0.5554365f, -0.5149179f, 0x0000FF00},
{+0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFF00},
{+0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFFFF},
{+0.3264773f, -0.7926362f, -0.5149179f, 0x0000FF00},
{+0.0000000f, -0.6865572f, -0.7270758f, 0x00FFFF00},
{+0.3568221f, -0.4911235f, -0.7946545f, 0x00FFFFFF},
{+0.0000000f, +0.0000000f, -1.0000000f, 0x0000FF00},
{+0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFF00},
{+0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFFFF},
{+0.2017741f, +0.2777182f, -0.9392337f, 0x0000FF00},
{+0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFF00},
{+0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFFFF},
{+0.3264774f, -0.1060789f, -0.9392337f, 0x0000FF00},
{+0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFF00},
{+0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFFFF},
{+0.5773502f, +0.1875925f, -0.7946545f, 0x0000FF00},
{+0.3264774f, -0.1060789f, -0.9392337f, 0x00FFFF00},
{+0.2017741f, +0.2777182f, -0.9392337f, 0x00FFFFFF},
{+0.4035482f, +0.5554365f, -0.7270758f, 0x0000FF00},
{+0.5257311f, +0.7236068f, -0.4472136f, 0x00FFFF00},
{+0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFFFF},
{+0.5773502f, +0.1875925f, -0.7946545f, 0x0000FF00},
{+0.7300255f, +0.4493575f, -0.5149179f, 0x00FFFF00},
{+0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFFFF},
{+0.6529547f, -0.2121578f, -0.7270758f, 0x0000FF00},
{+0.8547288f, +0.0655604f, -0.5149179f, 0x00FFFF00},
{+0.8506508f, -0.2763932f, -0.4472136f, 0x00FFFFFF},
{+0.7300255f, +0.4493575f, -0.5149179f, 0x0000FF00},
{+0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFF00},
{+0.4035482f, +0.5554365f, -0.7270758f, 0x00FFFFFF},
{+0.8547288f, +0.0655604f, -0.5149179f, 0x0000FF00},
{+0.6529547f, -0.2121578f, -0.7270758f, 0x00FFFF00},
{+0.5773502f, +0.1875925f, -0.7946545f, 0x00FFFFFF}

	};

	for(int i=0; i<540; i++)
	{
		Polyhedral_180[i].x = Sphere180[i].x * scale_r + translation_x;
		Polyhedral_180[i].y = Sphere180[i].y * scale_r + translation_y;
		Polyhedral_180[i].z = Sphere180[i].z * scale_r + translation_z;
		Polyhedral_180[i].color = 0xFFFFFFFF;
	}

	for(int i=0; i<180; i++)
	{
		if(	Polyhedral_180[3*i+0].x >= 0.0f &&
			Polyhedral_180[3*i+1].x >= 0.0f &&
			Polyhedral_180[3*i+2].x >= 0.0f )
		{
			Polyhedral_180[3*i+0].tu = (FLOAT)((1.0 - (Polyhedral_180[3*i+0].y / scale_r)) / 2.0f);
			Polyhedral_180[3*i+0].tv = (FLOAT)((1.0 - (Polyhedral_180[3*i+0].z / scale_r)) / 2.0f);
			Polyhedral_180[3*i+1].tu = (FLOAT)((1.0 - (Polyhedral_180[3*i+1].y / scale_r)) / 2.0f);
			Polyhedral_180[3*i+1].tv = (FLOAT)((1.0 - (Polyhedral_180[3*i+1].z / scale_r)) / 2.0f);
			Polyhedral_180[3*i+2].tu = (FLOAT)((1.0 - (Polyhedral_180[3*i+2].y / scale_r)) / 2.0f);
			Polyhedral_180[3*i+2].tv = (FLOAT)((1.0 - (Polyhedral_180[3*i+2].z / scale_r)) / 2.0f);
		}
		else
		{
			Polyhedral_180[3*i+0].tu = 0.0f;
			Polyhedral_180[3*i+0].tv = 0.0f;
			Polyhedral_180[3*i+1].tu = 0.0f;
			Polyhedral_180[3*i+1].tv = 0.0f;
			Polyhedral_180[3*i+2].tu = 0.0f;
			Polyhedral_180[3*i+2].tv = 0.0f;
		}
	}
	*Num_Vertexs += 540;
}