//Ardy Teguh Yulanda(522360002)
//Hiroya Herdinanto(5223600022)

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
    glRotatef(45, 0.0, 1.0, 0.0);

    //Draw Board
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_QUADS);

    // Front Face
    glVertex3f(-50.0, -30.0, 1.25); 
    glVertex3f(50.0, -30.0, 1.25);  
    glVertex3f(50.0, 30.0, 1.25);  
    glVertex3f(-50.0, 30.0, 1.25);  
    glEnd();

    // Back face
    glColor3f(0.7, 0.4, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-50.0, -30.0, -0.25); 
    glVertex3f(50.0, -30.0, -0.25); 
    glVertex3f(50.0, 30.0, -0.25); 
    glVertex3f(-50.0, 30.0, -0.25); 
    glEnd();

    // Left face
    glColor3f(0.9, 0.9, 0.9);  
    glBegin(GL_QUADS);
    glVertex3f(-50.0, -30.0, 1.25);  
    glVertex3f(-50.0, 30.0, 1.25);   
    glVertex3f(-50.0, 30.0, -0.25);  
    glVertex3f(-50.0, -30.0, -0.25); 

    // Right face
    glVertex3f(50.0, -30.0, 1.25);  
    glVertex3f(50.0, 30.0, 1.25);   
    glVertex3f(50.0, 30.0, -0.25);  
    glVertex3f(50.0, -30.0, -0.25); 

    // Top face
    glVertex3f(-50.0, 30.0, 1.25);  
    glVertex3f(50.0, 30.0, 1.25);   
    glVertex3f(50.0, 30.0, -0.25); 
    glVertex3f(-50.0, 30.0, -0.25);

    // Bottom face
    glVertex3f(-50.0, -30.0, 1.25);  
    glVertex3f(50.0, -30.0, 1.25);  
    glVertex3f(50.0, -30.0, -0.25); 
    glVertex3f(-50.0, -30.0, -0.25); 
    glEnd();

    // Draw Border
    glColor3f(0.6, 0.6, 0.6); 
    glBegin(GL_QUADS);

    // Front face 
    glVertex3f(-50.0, -30.0, 1.25); 
    glVertex3f(50.0, -30.0, 1.25);  
    glVertex3f(50.0, 30.0, 1.25);   
    glVertex3f(-50.0, 30.0, 1.25);  

    // Left border (thick volume)
    glVertex3f(-52.0, -32.0, 1.5);  
    glVertex3f(-50.0, -30.0, 1.25);
    glVertex3f(-50.0, 30.0, 1.25); 
    glVertex3f(-52.0, 32.0, 1.5);   

    glVertex3f(-52.0, -32.0, -0.5); 
    glVertex3f(-50.0, -30.0, -0.25);
    glVertex3f(-50.0, 30.0, -0.25); 
    glVertex3f(-52.0, 32.0, -0.5);  

    // Right border (thick volume)
    glVertex3f(52.0, -32.0, 1.5);  
    glVertex3f(50.0, -30.0, 1.25);  
    glVertex3f(50.0, 30.0, 1.25);  
    glVertex3f(52.0, 32.0, 1.5);   

    glVertex3f(52.0, -32.0, -0.5);  
    glVertex3f(50.0, -30.0, -0.25); 
    glVertex3f(50.0, 30.0, -0.25);  
    glVertex3f(52.0, 32.0, -0.5);   

    // Top border (thick volume)
    glVertex3f(-52.0, 32.0, 1.5);   
    glVertex3f(52.0, 32.0, 1.5);    
    glVertex3f(50.0, 30.0, 1.25);  
    glVertex3f(-50.0, 30.0, 1.25);  

    glVertex3f(-52.0, 32.0, -0.5); 
    glVertex3f(52.0, 32.0, -0.5);   
    glVertex3f(50.0, 30.0, -0.25); 
    glVertex3f(-50.0, 30.0, -0.25); 

    // Bottom border (thick volume)
    glVertex3f(-52.0, -32.0, 1.5); 
    glVertex3f(52.0, -32.0, 1.5);   
    glVertex3f(50.0, -30.0, 1.25);  
    glVertex3f(-50.0, -30.0, 1.25); 

    glVertex3f(-52.0, -32.0, -0.5);  
    glVertex3f(52.0, -32.0, -0.5);  
    glVertex3f(50.0, -30.0, -0.25); 
    glVertex3f(-50.0, -30.0, -0.25); 

    // Fill in the missing faces for the border
    // Outer left side (vertical)
    glVertex3f(-52.0, -32.0, 1.5);   
    glVertex3f(-52.0, -32.0, -0.5); 
    glVertex3f(-52.0, 32.0, -0.5);   
    glVertex3f(-52.0, 32.0, 1.5);    

    // Outer right side (vertical)
    glVertex3f(52.0, -32.0, 1.5);   
    glVertex3f(52.0, -32.0, -0.5);   
    glVertex3f(52.0, 32.0, -0.5);    
    glVertex3f(52.0, 32.0, 1.5);     

    glEnd(); 

    glutSwapBuffers(); 
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

// Main .
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("cuboid.cpp");

    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);


    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}
