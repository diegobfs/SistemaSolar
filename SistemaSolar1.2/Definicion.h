#define CR 0.0175
#define MYTIEMPO 41

typedef struct {
	float x;
	float y;
	float z;
} punto;

typedef struct {
	float x;
	float y;
	float z;
} vector;

typedef struct {
	float R;
	float G;
	float B;
}colorRGB;

//Defino el objecto
typedef struct {
	float distancia;
	float velocidad_trans;
	float angulo_trans;
	float velocidad_rot;
	float angulo_rot;
	float tamaño;
	int listarender;
	int satelite;
	colorRGB color;
	int anillo;
	int tiene_satelite;
	int textura;
} objeto;

void myCamara();
