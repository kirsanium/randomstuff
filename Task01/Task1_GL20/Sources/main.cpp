// vs2010.cpp : Defines the entry point for the console application.
//

#pragma comment(lib, "freeglut.lib")

//https://www.opengl.org/sdk/docs/man/
#include <stdio.h>
#include "glew.h" // Include the GLEW header file
#include "glut.h" // Include the GLUT header file
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define SUN_ROTATION_SPEED 0.1

float width;
float height;
float sunAngle = 0.0;
float earthAngle = 0.0;
float moonAngle = 0.0;

GLuint vertexShader;
GLuint fragmentShader;
GLuint program;

GLuint sun;
GLuint earth;
GLuint moon;
GLuint bufferColor;

GLuint attrConstColor;


void initSpaceBody(float size, GLuint* body) {
	GLfloat vertices[] = {
	-1.0f*size,-1.0f*size,-1.0f*size, // Треугольник 1 : начало
    -1.0f*size,-1.0f*size, 1.0f*size,
    -1.0f*size, 1.0f*size, 1.0f*size, // Треугольник 1 : конец
     1.0f*size, 1.0f*size,-1.0f*size, // Треугольник 2 : начало
    -1.0f*size,-1.0f*size,-1.0f*size,
    -1.0f*size, 1.0f*size,-1.0f*size, // Треугольник 2 : конец
     1.0f*size,-1.0f*size, 1.0f*size,
    -1.0f*size,-1.0f*size,-1.0f*size,
     1.0f*size,-1.0f*size,-1.0f*size,
     1.0f*size, 1.0f*size,-1.0f*size,
     1.0f*size,-1.0f*size,-1.0f*size,
    -1.0f*size,-1.0f*size,-1.0f*size,
    -1.0f*size,-1.0f*size,-1.0f*size,
    -1.0f*size, 1.0f*size, 1.0f*size,
    -1.0f*size, 1.0f*size,-1.0f*size,
     1.0f*size,-1.0f*size, 1.0f*size,
    -1.0f*size,-1.0f*size, 1.0f*size,
    -1.0f*size,-1.0f*size,-1.0f*size,
    -1.0f*size, 1.0f*size, 1.0f*size,
    -1.0f*size,-1.0f*size, 1.0f*size,
     1.0f*size,-1.0f*size, 1.0f*size,
     1.0f*size, 1.0f*size, 1.0f*size,
     1.0f*size,-1.0f*size,-1.0f*size,
     1.0f*size, 1.0f*size,-1.0f*size,
     1.0f*size,-1.0f*size,-1.0f*size,
     1.0f*size, 1.0f*size, 1.0f*size,
     1.0f*size,-1.0f*size, 1.0f*size,
     1.0f*size, 1.0f*size, 1.0f*size,
     1.0f*size, 1.0f*size,-1.0f*size,
    -1.0f*size, 1.0f*size,-1.0f*size,
     1.0f*size, 1.0f*size, 1.0f*size,
    -1.0f*size, 1.0f*size,-1.0f*size,
    -1.0f*size, 1.0f*size, 1.0f*size,
     1.0f*size, 1.0f*size, 1.0f*size,
    -1.0f*size, 1.0f*size, 1.0f*size,
     1.0f*size,-1.0f*size, 1.0f*size
	};

	glGenBuffers(1, body);
	glBindBuffer(GL_ARRAY_BUFFER, *body);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void initColors() {

	GLfloat colors[] = {
	0.583f,  0.771f,  0.014f,
    0.609f,  0.115f,  0.436f,
    0.327f,  0.483f,  0.844f,
    0.822f,  0.569f,  0.201f,
    0.435f,  0.602f,  0.223f,
    0.310f,  0.747f,  0.185f,
    0.597f,  0.770f,  0.761f,
    0.559f,  0.436f,  0.730f,
    0.359f,  0.583f,  0.152f,
    0.483f,  0.596f,  0.789f,
    0.559f,  0.861f,  0.639f,
    0.195f,  0.548f,  0.859f,
    0.014f,  0.184f,  0.576f,
    0.771f,  0.328f,  0.970f,
    0.406f,  0.615f,  0.116f,
    0.676f,  0.977f,  0.133f,
    0.971f,  0.572f,  0.833f,
    0.140f,  0.616f,  0.489f,
    0.997f,  0.513f,  0.064f,
    0.945f,  0.719f,  0.592f,
    0.543f,  0.021f,  0.978f,
    0.279f,  0.317f,  0.505f,
    0.167f,  0.620f,  0.077f,
    0.347f,  0.857f,  0.137f,
    0.055f,  0.953f,  0.042f,
    0.714f,  0.505f,  0.345f,
    0.783f,  0.290f,  0.734f,
    0.722f,  0.645f,  0.174f,
    0.302f,  0.455f,  0.848f,
    0.225f,  0.587f,  0.040f,
    0.517f,  0.713f,  0.338f,
    0.053f,  0.959f,  0.120f,
    0.393f,  0.621f,  0.362f,
    0.673f,  0.211f,  0.457f,
    0.820f,  0.883f,  0.371f,
    0.982f,  0.099f,  0.879f
	};

	glGenBuffers(1, &bufferColor);
	glBindBuffer(GL_ARRAY_BUFFER, bufferColor);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
}

void InitGeometry()
{
	initColors();
	initSpaceBody(1.0f, &sun);
	initSpaceBody(0.5f, &earth);
	initSpaceBody(0.25f, &moon);
}

void DeinitGeometry()
{
	
}

void drawSun(float rotationSpeed) {
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER, sun);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, bufferColor);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix(); { 
		glRotatef(sunAngle, 0.0, 1.0, 0.0);
		sunAngle += rotationSpeed;

		glDrawArrays(GL_TRIANGLES, 0, 36);
	} glPopMatrix();
}

void drawEarth(float rotationSpeed) {
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER, earth);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, bufferColor);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix(); {
		//glTranslatef(-3.0, 0.0, 0.0);
		glRotatef(earthAngle, 0.0, 1.0, 0.0);
		glTranslatef(7.0, 0.0, 0.0);
		//glRotatef(earthAngle-0.03, 0.0, 1.0, 0.0);

		earthAngle += rotationSpeed;
		glDrawArrays(GL_TRIANGLES, 0, 36);

	} glPopMatrix();
}

void drawMoon(float rotationSpeed) {
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	
	glBindBuffer(GL_ARRAY_BUFFER, moon);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, bufferColor);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix(); {
		//glTranslatef(-3.0, 0.0, 0.0);
		glRotatef(earthAngle, 0.0, 1.0, 0.0);
		glTranslatef(7.0, 0.0, 0.0);
		glRotatef(moonAngle, 0.0, 1.0, 0.0);
		glTranslatef(2.0, 0.0, 0.0);
		glRotatef(moonAngle-0.03, 0.0, 1.0, 0.0);

		moonAngle += rotationSpeed;
		glDrawArrays(GL_TRIANGLES, 0, 36);

	} glPopMatrix();
}

void Render (void)
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the colour buffer (more buffers later on)  
	glClearColor(0.0f, 0.0f, 0.5f, 1.0f); // Clear the background of our window to red  
	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations

	glUseProgram(program);

	// Matrix Projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLdouble)width/(GLdouble)height, 1.0f, 100.0) ;
	
	// Matrix View
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(0.0f, 3.0f, 5.0f,	0.0f, 0.0f, 0.0f,	0.0f, 1.0f*size, 0.0f);

	glm::mat4x4 matWorld = glm::mat4x4();
	glm::mat4x4 matView  = glm::lookAt(glm::vec3(0, 20, 20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
		
	glm::mat4x4 matWorldView = matView * matWorld;
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadMatrixf(&matWorldView[0][0]);

	{
		glUniform4f(attrConstColor, 3, 3, 3, 1);
		
		drawSun(0.1f);		
		drawEarth(0.1f);
		drawMoon(0.1f);

		// glEnableVertexAttribArray(1);
		// glEnableVertexAttribArray(0);
	}



	glUseProgram(0);
	
	glFlush(); // Flush the OpenGL buffers to the window  
}

// Calls in loop
void Cycle() 
{
	// Âûçâàåì ïåðåðèñîâêó ýêðàíà (ôóíêöèþ Render)
	glutPostRedisplay();
}

// Reshapes the window appropriately
void Reshape(int w, int h)
{
	width  = w;
	height = h;

	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLdouble)width/(GLdouble)height, 0.01, 100.0) ;

}

void InitShaders()
{
	//! Èñõîäíûé êîä øåéäåðîâ
	const char* vsSource = 
		//"attribute vec3 coord;\n"
		//"out vec3 fragmentColor;\n"
		"attribute vec4 position;"
		"attribute vec4 color;"
		"uniform vec4 constColor;"
		"void main() {\n"
		//"  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
		//"  gl_FrontColor = gl_Color;\n"
		"  gl_Position = gl_ModelViewProjectionMatrix * position;\n"		
		"  gl_FrontColor = color * constColor;\n"
		"}\n";
	const char* fsSource = 
		//"uniform vec4 color;\n"
		//"in vec3 fragmentColor;\n"
		"void main() {\n"
		//"  gl_FragColor = color;\n"
		"  gl_FragColor = gl_Color;\n"
		//"  gl_FragColor = vec4(fragmentColor, 1.0);\n"
		"}\n";
	int success = 0;

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource (vertexShader, 1, &vsSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv  (vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		const int MAX_INFO_LOG_SIZE = 1024;
		GLchar infoLog[MAX_INFO_LOG_SIZE];
		glGetShaderInfoLog(vertexShader, MAX_INFO_LOG_SIZE, NULL, infoLog);
		fprintf(stderr, "Error in vertex shader compilation!\n");
		fprintf(stderr, "Info log: %s\n", infoLog);
	}

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource (fragmentShader, 1, &fsSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv  (fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		const int MAX_INFO_LOG_SIZE = 1024;
		GLchar infoLog[MAX_INFO_LOG_SIZE];
		glGetShaderInfoLog(fragmentShader, MAX_INFO_LOG_SIZE, NULL, infoLog);
		fprintf(stderr, "Error in vertex shader compilation!\n");
		fprintf(stderr, "Info log: %s\n", infoLog);
	}

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "color");

	glLinkProgram (program);
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success)
	{
		const int MAX_INFO_LOG_SIZE = 1024;
		GLchar infoLog[MAX_INFO_LOG_SIZE];
		glGetProgramInfoLog(program, MAX_INFO_LOG_SIZE, NULL, infoLog);
		fprintf(stderr, "Error in program linkage!\n");
		fprintf(stderr, "Info log: %s\n", infoLog);
	}

	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
	if (!success)
	{
		const int MAX_INFO_LOG_SIZE = 1024;
		GLchar infoLog[MAX_INFO_LOG_SIZE];
		glGetProgramInfoLog(program, MAX_INFO_LOG_SIZE, NULL, infoLog);
		fprintf(stderr, "Error in program validation!\n");
		fprintf(stderr, "Info log: %s\n", infoLog);
	}

	attrConstColor = glGetUniformLocation(program, "constColor");	
}

void DeinitShaders()
{
	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	glDeleteProgram(program);

	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);	
}

//int _tmain(int argc, _TCHAR* argv[])
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // Initialize GLUT  
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH  /*| GLUT_DOUBLE*/); // Set up a basic display buffer (only single buffered for now)
	//glEnable(GL_DEPTH_TEST);
	// Create the application's window
	{
		glutInitWindowPosition(100, 100);			// Set the position of the window
		glutInitWindowSize(512, 512);				// Set the width and height of the window
		glutCreateWindow("OpenGL First Window");	// Set the title for the window
	}

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	GLenum err = glewInit(); 
	if (GLEW_OK != err) 
	{ 
		return 0;
	}

	glutDisplayFunc(Render); // Tell GLUT to use the method "display" for rendering  
	glutReshapeFunc(Reshape);
	glutIdleFunc(Cycle);
	
	InitGeometry();
	InitShaders();


	glutMainLoop(); // Enter GLUT's main loop

	// TODO: Ïîéìàòü ñîáûòèå çàêðûòèÿ îêíà è îñâîáîäèòü ðåñóðñû
	DeinitShaders();

	int i = 0;

	return 0;
}
