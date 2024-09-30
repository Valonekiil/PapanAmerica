///////////////////////////////////
// cuboid.cpp
//
// OpenGL program to draw a cuboid (board) with 3D effect without gluLookAt.
// Modified version with manual transformation to create a thin board-like object with a border.
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h>

// Variables for rotation.
static float angle = 0.0;

// Function to draw the board (thin cuboid) with a border.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// Apply translation to move the cuboid back into view
	glTranslatef(0.0, 0.0, -150.0);

	// Apply rotation to the cuboid
	glRotatef(angle, 0.0, 1.0, 0.0);

	// Draw a thin cuboid representing the main board (papan tulis)
	glColor3f(0.9, 0.9, 0.9); // Dark color for the board
	glBegin(GL_QUADS);

	// Front face (the main writing surface)
	glVertex3f(-50.0, -30.0, 0.25); // left bottom front
	glVertex3f(50.0, -30.0, 0.25);  // right bottom front
	glVertex3f(50.0, 30.0, 0.25);   // right top front
	glVertex3f(-50.0, 30.0, 0.25);  // left top front

	// Back face
	glVertex3f(-50.0, -30.0, -0.25); // left bottom back
	glVertex3f(50.0, -30.0, -0.25);  // right bottom back
	glVertex3f(50.0, 30.0, -0.25);   // right top back
	glVertex3f(-50.0, 30.0, -0.25);  // left top back

	// Left face
	glVertex3f(-50.0, -30.0, 0.25);  // front bottom left
	glVertex3f(-50.0, 30.0, 0.25);   // front top left
	glVertex3f(-50.0, 30.0, -0.25);  // back top left
	glVertex3f(-50.0, -30.0, -0.25); // back bottom left

	// Right face
	glVertex3f(50.0, -30.0, 0.25);  // front bottom right
	glVertex3f(50.0, 30.0, 0.25);   // front top right
	glVertex3f(50.0, 30.0, -0.25);  // back top right
	glVertex3f(50.0, -30.0, -0.25); // back bottom right

	// Top face
	glVertex3f(-50.0, 30.0, 0.25);  // front top left
	glVertex3f(50.0, 30.0, 0.25);   // front top right
	glVertex3f(50.0, 30.0, -0.25);  // back top right
	glVertex3f(-50.0, 30.0, -0.25); // back top left

	// Bottom face
	glVertex3f(-50.0, -30.0, 0.25);  // front bottom left
	glVertex3f(50.0, -30.0, 0.25);   // front bottom right
	glVertex3f(50.0, -30.0, -0.25);  // back bottom right
	glVertex3f(-50.0, -30.0, -0.25); // back bottom left

	glEnd();

	// Draw the border around the board (pinggiran)
	glColor3f(0.4, 0.4, 0.4); // Darker color for the border
	glBegin(GL_QUADS);

	// Front face (the main writing surface)
	glVertex3f(-52.0, -32.0, 1.25); // left bottom front
	glVertex3f(52.0, -32.0, 1.25);  // right bottom front
	glVertex3f(52.0, 32.0, 1.25);   // right top front
	glVertex3f(-52.0, 32.0, 1.25);  // left top front

	// Back face
	glVertex3f(-50.0, -30.0, -0.25); // left bottom back
	glVertex3f(50.0, -30.0, -0.25);  // right bottom back
	glVertex3f(50.0, 30.0, -0.25);   // right top back
	glVertex3f(-50.0, 30.0, -0.25);  // left top back

	// Left border
	glVertex3f(-52.0, -32.0, 0.3);
	glVertex3f(-50.0, -32.0, 0.3);
	glVertex3f(-50.0, 32.0, 0.3);
	glVertex3f(-52.0, 32.0, 0.3);

	// Right border
	glVertex3f(50.0, -32.0, 0.3);
	glVertex3f(52.0, -32.0, 0.3);
	glVertex3f(52.0, 32.0, 0.3);
	glVertex3f(50.0, 32.0, 0.3);

	// Top border
	glVertex3f(-52.0, 32.0, 0.3);
	glVertex3f(52.0, 32.0, 0.3);
	glVertex3f(52.0, 30.0, 0.3);
	glVertex3f(-52.0, 30.0, 0.3);

	// Bottom border
	glVertex3f(-52.0, -30.0, 0.3);
	glVertex3f(52.0, -30.0, 0.3);
	glVertex3f(52.0, -32.0, 0.3);
	glVertex3f(-52.0, -32.0, 0.3);

	glEnd();

	glutSwapBuffers(); // Double buffer for smoother rendering
}

// Update rotation angle.
void update(int value)
{
	angle += 1.0;
	if (angle > 360.0)
		angle -= 360.0;

	glutPostRedisplay(); // Redraw the scene
	glutTimerFunc(16, update, 0); // ~60 FPS
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0); // Set perspective

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Use double buffering

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("cuboid.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutTimerFunc(16, update, 0); // Start the rotation

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
