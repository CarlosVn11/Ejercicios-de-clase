// Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Salazar Santiago Juan Carlos ****//
//*************	 Visual Studio 2017						  ****//
//*************	 Ejercicio de clase 7: Sistema solar con  ****//
//*************  fuente de iluminacion y materiales.      *****//
//*************  Fecha: 05/10/2018                        ****//
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


GLfloat LuzAmbientalSol[] = { 0.5, 0.5, 0.5, 1.0 };			// Diffuse Light Values
GLfloat LuzDifusaSol[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LuzEspecularSol[] = { 1.0, 1.0, 1.0, 1.0 };			// Light Position
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Diffuse Light Values

/*Mercurio*/
GLfloat MercurioAmbiente[] = { 0.0f,0.1f,0.06f,1.0f };
GLfloat MercurioDifuso[] = { 1.0f,0.509804f,0.509804f,1.0f };
GLfloat MercurioEspecular[] = { 0.501961f,0.501961f,1.0f,1.0f };
GLfloat MarsShininess[] = { 32.0 };


/*Venus*/

GLfloat VenusAmbiente[] = { 0.19125f,0.0735f,0.0225f,1.0f };
GLfloat VenusDifuso[] = { 0.7038f,0.27048f,0.0828f,1.0f };
GLfloat VenusEspecular[] = { 0.256777f,0.137622f,0.086014f,1.0f };
GLfloat VenusShininess[] = { 12.8 };

/*Tierra*/

GLfloat TierraAmbiente[] = { 0.0f,0.0f,0.74f,1.0f };
GLfloat TierraDifuso[] = { 0.35f,0.53f,0.82f,1.0f };
GLfloat TierraEspecular[] = { 0.0f,0.75f,1.0f,1.0f };
GLfloat TierraShininess[] = { 10.0 };

/*Luna*/
GLfloat LunaAmbiente[] = { 0.19225f,0.19225f,0.19225f,1.0f };
GLfloat LunaDifuso[] = { 0.50754f,0.50754f,0.50754f,1.0f };
GLfloat LunaEspecular[] = { 0.508273f,0.508273f,0.508273f,1.0f };
GLfloat LunaShininess[] = { 51.2 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


	glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbientalSol);				// Setup The Ambient Light
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusaSol);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT0, GL_SPECULAR, LuzEspecularSol);				// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol);															//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
																	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light
																	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);							// Enable Light One							//glEnable(GL_LIGHT0);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glLightfv(GL_LIGHT0, GL_POSITION, LuzPosicionSol);
	glEnable(GL_LIGHTING);


	glPushMatrix(); //Sistema solar
		glRotatef(angleX, 1, 0, 0);
		glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje GIRAR todos

			glPushMatrix(); //Sol
				glDisable(GL_LIGHTING);
				glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
				glutSolidSphere(2.0, 200, 200);  //Draw Sun (radio,H,V);
				glEnable(GL_LIGHTING);
			glPopMatrix();


	/*Mercurio*/
			glPushMatrix();
				glRotatef(posicion[0], 0, 1, 0); //traslacion
				glTranslatef(3.5, 0, 0);
				glRotatef(posicion[0], 0, 1, 0); //rotacion
				/*Materiales */ /*Color cyan plastico*/
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, MercurioAmbiente);
				glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE, MercurioDifuso);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, MercurioEspecular);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS,MarsShininess);
				glutSolidSphere(0.3, 500, 500); //Esfera
			glPopMatrix();


	/*Venus*/

			glPushMatrix();
				glRotatef(-posicion[1], 0, 1, 0); //traslacion
				glTranslatef(5, 0, 0);
				glRotatef(posicion[1], 0, 1, 0); //rotacion
				/*Materiales */ /*Color cooper*/
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, VenusAmbiente);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, VenusDifuso);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, VenusEspecular);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, VenusShininess);
				glutSolidSphere(0.5, 500, 500);
			glPopMatrix();


	/*Tierra*/
			glPushMatrix();
				glRotatef(posicion[2], 0, 1, 0); //traslacion
				glTranslatef(7.5, 0, 0);
				glRotatef(posicion[2], 0, 1, 0); //rotacion
				glColor3f(0, 0.5, 0.9); //color azul
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, TierraAmbiente);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, TierraDifuso);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, TierraEspecular);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, TierraShininess);
				glutSolidSphere(0.7, 500, 500);
					/*Luna*/
					glPushMatrix();
						glRotatef(lunas[0], 0, 1, 0); //traslacion
						glTranslatef(1.0, 0, 0);
						glRotatef(lunas[0], 0, 1, 0); //rotacion
						glColor3f(0.2, 0.3, 0.4); //color gris
						glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, LunaAmbiente);
						glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, LunaDifuso);
						glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, LunaEspecular);
						glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, LunaShininess);
						glutSolidSphere(0.2, 500, 500); //Esfera
					glPopMatrix();

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

	if (dwElapsedTime >= 70)
	{
		sol = (sol - 1) % 360; //Define movimiento
		posicion[0] = fmod(posicion[0] - 4.5, 360); //Mercurio
		posicion[1] = fmod(posicion[1] - 3.5, 360); //Venus
		posicion[2] = fmod(posicion[2] - 2.5, 360); //Tierra

		/*Para las lunas*/
		lunas[0] = fmod(lunas[0] - 1.5, 360); //Luna de la tierra

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
	glutCreateWindow("Practica 7"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}