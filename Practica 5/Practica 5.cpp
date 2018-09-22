//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos ****//
//*************	Visual Studio 2017						******//
//*************	Ejercicio de clase 5: Brazo con movimiento ***//
//*************	Fecha: 21/09/2018						******//
//************************************************************//
#include "Main.h"



/*
Para trasladar hacia la izquierda con la tecla de flecha hacia la izquierda <-
		Para mover el hombro con H y con h
		Para mover el antebrazo con C y c
		Para mover la muñeca con M y m
		Para mover los dedos con Q y q

		Lo unico malo es que cuando rota el brazo completo u otra extremidad no se mueve al mismo tiempo
		la mano.
*/



float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float angHombro = 0.0f; //Variable para mover el hombro
float angAnte = 0.0f;  //Variable para mover el antebrazo
float angMun = 0.0f;   //Variable para mover la muñeca
float angDed = 0.0f;   //Variable para mover el dedo pulgar y los demas
float angDed2 = 0.0f;	//Variable de referencia
int screenW = 0.0;
int screenH = 0.0;


GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL(void)     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

														//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí. (0,0,0) 

	glPushMatrix(); //brazo

	glTranslatef(-5, 2, 0); //-2.5,1.25,0 "nuevo 0,0,0"
	glRotatef(angHombro, 0, 0, 1);
	glPushMatrix();
	glTranslatef(4, -2, 0); //0,0,0
	glScalef(8, 4, 2);
	prisma();
	glPopMatrix();

	/*ANTE BRAZO*/
	glTranslatef(8, -2, 0); //-2.5,1.25,0 "nuevo 0,0,0"
	glRotatef(angAnte, 0, 0, 1);

	glPushMatrix();
	glTranslatef(6.5, 0, 0); //0,0,0
	glScalef(13, 3, 2);
	prisma();
	glPopMatrix();

	/*MUÑECA*/
	glTranslatef(13, 0, 0);
	glRotatef(angMun, 0, 0, 1);

	glPushMatrix();
	glTranslatef(2, 0, 0);
	glScalef(4, 2.4, 2);
	prisma();
	glPopMatrix();
	
	/* 1er dedo*/

	glTranslatef(1.6, 1.2, 0.75);
	glRotatef(angDed, 1, 0, 0);

	glPushMatrix();
	glTranslatef(0, 0.6, 0.0);
	glScalef(0.8, 1.2, 0.5);
	prisma();
	glPopMatrix();

	//////////////////////////////////////////////////////
	/* Segunda parte*/
	glTranslatef(0.0, 1.2, -0.01);
	glRotatef(angDed, 1, 0, 0);
		glPushMatrix();
			glTranslatef(0, 0.6, 0.0);
			glScalef(0.8, 1.2, 0.5);
			prisma();
		glPopMatrix();
	////
	
	glPopMatrix();
	angDed2 = -angDed;
	glRotatef(angHombro, 0, 0, 1);
	glRotatef(angAnte, 0, 0, 1);
	glRotatef(angMun, 0, 0, 1);
	 //Mientras se mueve Q se mueve tambien Z
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//Dedo indice
	glPushMatrix();
	//Parte 1
	glTranslatef(20, 0.9, 0.75);
	glRotatef(angDed2, 0, 1, 0);


				glPushMatrix();
					glTranslatef(0.5, 0, 0.0);
					glScalef(1.0, 0.6, 0.5);
					prisma();
				glPopMatrix();
	
	
	//Parte 2
			glTranslatef(1.03, 0, 0.0);
			glRotatef(angDed2, 0, 1, 0);
				glPushMatrix();
					glTranslatef(0.47, 0, 0.0);
					glScalef(1.0, 0.6, 0.5);
					prisma();
				glPopMatrix();

	//parte 3
			glTranslatef(0.97, 0, 0.0);
			glRotatef(angDed2, 0, 1, 0);
				glPushMatrix();
					glTranslatef(0.5, 0, 0.0);
					glScalef(1.0, 0.6, 0.5);
					prisma();
				glPopMatrix();


	glPopMatrix();

	/////////////////////////////////////////////////////////////////////////////////////////////////

	//Dedo de en medio

	glPushMatrix();


	//Parte 1
		glTranslatef(20, 0.3, 0.75);
		glRotatef(angDed2, 0, 1, 0);
			glPushMatrix();
				glTranslatef(0.75, 0, 0.0);
				glScalef(1.5, 0.6, 0.5);
				prisma();
			glPopMatrix();

	//Parte 2
		glTranslatef(1.5, 0, 0.0);
		glRotatef(angDed2, 0, 1, 0);
			glPushMatrix();
				glTranslatef(0.5, 0, 0.0);
				glScalef(1, 0.6, 0.5);
				prisma();
			glPopMatrix();

	//Parte 3
		glTranslatef(0.98, 0, 0.0);
		glRotatef(angDed2, 0, 1, 0);
			glPushMatrix();
				glTranslatef(0.77, 0, 0.0);
				glScalef(1.5, 0.6, 0.5);
				prisma();
			glPopMatrix();
	glPopMatrix();

	////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Dedo de anular

	glPushMatrix();

	//Parte 1
		glTranslatef(20, -0.3, 0.75);
		glRotatef(angDed2, 0, 1, 0);
			glPushMatrix();
				glTranslatef(0.5, 0, 0.0);
				glScalef(1.0, 0.6, 0.5);
				prisma();
			glPopMatrix();

	//Parte 2
		glTranslatef(1.0, 0, 0.0);
		glRotatef(angDed2, 0, 1, 0);
			glPushMatrix();
				glTranslatef(0.5, 0, 0.0);
				glScalef(1, 0.6, 0.5);
				prisma();
			glPopMatrix();

	//Parte 3
		glTranslatef(1.0, 0, 0.0);
		glRotatef(angDed2, 0, 1, 0);
			glPushMatrix();
				glTranslatef(0.5, 0, 0.0);
				glScalef(1.0, 0.6, 0.5);
				prisma();
			glPopMatrix();
	
	
	glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	//Dedo de meñique

	glPushMatrix();

	//Parte 1
	glTranslatef(20, -0.9, 0.75);
	glRotatef(angDed2, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0.3, 0, 0.0);
	glScalef(0.6, 0.6, 0.5);
	prisma();
	glPopMatrix();

	//Parte 2
	glTranslatef(0.6, 0, 0.0);
	glRotatef(angDed2, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0.37, 0, 0.0);
	glScalef(0.75, 0.6, 0.5);
	prisma();
	glPopMatrix();

	//Parte 3
	glTranslatef(0.75, 0, 0.0);
	glRotatef(angDed2, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0.32, 0, 0.0);
	glScalef(0.65, 0.6, 0.5);
	prisma();
	glPopMatrix();


	glPopMatrix();
	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.2, 0.2, -0.2, 0.2, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();									
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		break;
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
	case 'H':
		if (angHombro < 90) {
			angHombro += 2.0f;
			
		}
		break;
	case 'h':
		if (angHombro > 0)
			angHombro -= 2.0f;
		break;
	case 'c':
		if (angAnte < 90)
			angAnte += 2.0f;
		break;
	case 'C':
		if (angAnte > 0)
			angAnte -= 2.0f;
		break;
	case 'm':
		if (angMun < 90)
			angMun += 2.0f;
		break;
	case 'M':
		if (angMun > 0)
			angMun -= 2.0f;
		break;

	case 'q':
		if (angDed < 90)
			angDed += 2.0f;
		break;

	case 'Q':
		if (angDed > 0)
			angDed -= 2.0f;
		break;

	case 'z':
		/*limita los movimientos de los dedos para que solo giren hacia adelante*/
		if (angDed2 < -90 || angDed2 < 0) {
			angDed2 += 2.0f;
		}
	
		
	break;

	case 'Z':
		/*limita los movimientos de los dedos para que solo giren hacia adelante*/
		if (angDed2 >= 0 || angDed2 >= -90) {
			angDed2 -= 2.0f;
		}
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 5"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}

