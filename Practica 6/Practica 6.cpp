// Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos ****//
//*************	 Visual Studio 2017						  ****//
//*************	 Ejercicio de clase 6: Sistema solar	 ****//
//*************  Fecha: 28/09/2018                       ****//
//************************************************************//
#include "Main.h"


/* Para ver desde arriba con la tecla de arriba en el teclado y para abajo con la tecla de abajo.
	Para alejarse con la tecla s o S y para acercarse con la tecla w o W
*/


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;

float camaraZ = 0.0;
float camaraX = 0.0;
/* Arreglo para las variables de los planetas*/
float posicion[8] = { 0.0f };
/*Arreglo para las lunas*/
float lunas[5] = { 0.0 };
float angleX = 0.0f; //Para rotar la vista en el eje X

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix(); //Sistema solar
	glRotatef(angleX, 1, 0, 0);
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje GIRAR todos

	glPushMatrix(); //Sol
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(2.0, 20, 20);  //Draw Sun (radio,H,V);
	glPopMatrix();


	/*Mercurio*/
	glPushMatrix();
	glRotatef(posicion[0], 0, 1, 0); //traslacion
	glTranslatef(3.5, 0, 0);
	glRotatef(posicion[0], 0, 1, 0); //rotacion
	glColor3d(0.5, 0.5, 0.5); //Color gris
	glutSolidSphere(0.3, 500, 500);
	glPopMatrix();


	/*Venus*/

	glPushMatrix();
	glRotatef(-posicion[1], 0, 1, 0); //traslacion
	glTranslatef(5, 0, 0);
	glRotatef(posicion[1], 0, 1, 0); //rotacion
	glColor3f(0.6, 0.4, 0); //Color cafe claro
	glutSolidSphere(0.5, 500, 500);
	glPopMatrix();


	/*Tierra*/
	glPushMatrix();
	glRotatef(posicion[2], 0, 1, 0); //traslacion
	glTranslatef(7.5, 0, 0);
	glRotatef(posicion[2], 0, 1, 0); //rotacion
	glColor3f(0, 0.5, 0.9); //color azul
	glutSolidSphere(0.7, 500, 500);
	/*Luna*/
	glPushMatrix();
	glRotatef(lunas[0], 0, 1, 0); //traslacion
	glTranslatef(1.0, 0, 0);
	glRotatef(lunas[0], 0, 1, 0); //rotacion
	glColor3f(0.2, 0.3, 0.4); //color azul
	glutSolidSphere(0.2, 500, 500);
	glPopMatrix();

	glPopMatrix();


	/*Marte*/
	glPushMatrix();
	glRotatef(-posicion[3], 0, 1, 0); //traslacion
	glTranslatef(10.5, 0, 0);
	glRotatef(posicion[3], 0, 1, 0); //rotacion
	glColor3f(0.9, 0.1, 0.2); //Color rojo
	glutSolidSphere(0.4, 500, 500);

	/*Luna 1*/
	glPushMatrix();
	glRotatef(lunas[1], 0, 1, 0); //traslacion
	glTranslatef(0.6, 0, 0);
	glRotatef(lunas[1], 0, 1, 0); //rotacion
	glColor3f(0.2, 0.3, 0.4); //color gris
	glutSolidSphere(0.2, 500, 500);
	glPopMatrix();
	/*Luna 2*/
	glPushMatrix();
	glRotatef(-lunas[2], 0, 1, 0); //traslacion
	glTranslatef(1.0, 0, 0);
	glRotatef(lunas[2], 0, 1, 0); //rotacion
	glColor3f(0.2, 0.3, 0.4); //color gris
	glutSolidSphere(0.2, 500, 500);
	glPopMatrix();

	glPopMatrix();


	/*Jupiter*/

	glPushMatrix();
	glRotatef(posicion[4], 0, 1, 0); //traslacion
	glTranslatef(15.2, 0, 0);
	glRotatef(posicion[4], 0, 1, 0); //rotacion
	glColor3f(0.8, 0.6, 0.3); //color beige
	glutSolidSphere(1.0, 500, 500);

	/*Luna 1*/
	glPushMatrix();
	glRotatef(lunas[3], 0, 1, 0); //traslacion
	glTranslatef(1.4, 0, 0);
	glRotatef(lunas[3], 0, 1, 0); //rotacion
	glColor3f(0.2, 0.3, 0.4); //color gris
	glutSolidSphere(0.3, 500, 500);
	glPopMatrix();

	/*Luna 2*/
	glPushMatrix();
	glRotatef(-lunas[3], 0, 1, 0); //traslacion
	glTranslatef(2.05, 0, 0);
	glRotatef(lunas[3], 0, 1, 0); //rotacion
	glColor3f(0.2, 0.3, 0.4); //color gris
	glutSolidSphere(0.2, 500, 500);
	glPopMatrix();

	/*Luna 3*/
	glPushMatrix();
	glRotatef(lunas[4], 0, 1, 0); //traslacion
	glTranslatef(2.8, 0, 0);
	glRotatef(lunas[4], 0, 1, 0); //rotacion
	glColor3f(0.2, 0.3, 0.4); //color gris
	glutSolidSphere(0.4, 500, 500);
	glPopMatrix();


	glPopMatrix();

	/*Saturno*/
	glPushMatrix();
	glRotatef(-posicion[5], 0, 1, 0); //traslacion
	glTranslatef(23.5, 0, 0);
	glRotatef(posicion[5], 0, 1, 0); //rotacion
	glColor3f(0.9, 1.0, 0.5);
	glutSolidSphere(0.85, 500, 500);

	/*Anillo 1*/
		glPushMatrix();
			glRotatef(90, 1, 0, 0);
			glColor3f(0.2, 0.3, 0.4);
			glutSolidTorus(0.5, 2.0, 30, 30);
		glPopMatrix();

	/*Anillo 2*/
		glPushMatrix();
			glRotatef(90, 1, 0, 0);
			glColor3f(0.2, 0.3, 0.4);
			glutSolidTorus(0.5, 3.5, 30, 30);
		glPopMatrix();

	glPopMatrix();



	/*Urano*/
	glPushMatrix();
	glRotatef(posicion[6], 0, 1, 0); //traslacion
	glTranslatef(30.0, 0, 0);
	glRotatef(posicion[6], 0, 1, 0); //rotacion
	glColor3f(0.0, 0.2, 0.9); //color azul
	glutSolidSphere(0.8, 500, 500);
	glPopMatrix();

	/*Neptuno*/

	glPushMatrix();
	glRotatef(-posicion[7], 0, 1, 0); //traslacion
	glTranslatef(34.0, 0, 0);
	glRotatef(posicion[7], 0, 1, 0); //rotacion
	glColor3f(0.2, 0.2, 0.9); //color azul
	glutSolidSphere(0.7, 500, 500);
	glPopMatrix();

	glPopMatrix(); //Fin sistema solar

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 50)
	{
		sol = (sol - 1) % 360; //Define movimiento
		posicion[0] = fmod(posicion[0] - 10.0, 360); //Mercurio
		posicion[1] = fmod(posicion[1] - 9.5, 360); //Venus
		posicion[2] = fmod(posicion[2] - 8.5, 360); //Tierra
		posicion[3] = fmod(posicion[3] - 7.5, 360); //Marte
		posicion[4] = fmod(posicion[4] - 6.5, 360); //Jupiter
		posicion[5] = fmod(posicion[5] - 5.5, 360); //Saturno
		posicion[6] = fmod(posicion[6] - 4.5, 360); //Urano
		posicion[7] = fmod(posicion[7] - 3.5, 360); //Neptuno

		/*Para las lunas*/
		lunas[0] = fmod(lunas[0] - 10, 360); //Luna de la tierra
		lunas[1] = fmod(lunas[1] - 15, 360); //Luna de marte
		lunas[2] = fmod(lunas[2] - 20, 360); //Luna 2 de marte 
		lunas[3] = fmod(lunas[3] - 20.5, 360); //Luna 1 de jupiter
		lunas[4] = fmod(lunas[4] - 23.5, 360); //Luna 2 de jupiter
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.5;    //Mueve la camara hacia arriba
		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.5f;		//Mueve la camara hacia abajo
		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

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
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}