#include "render.h"


Render* Render::currentInstance = nullptr;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

Render::Render(){
    //points = {};
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
 
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()){
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
 
    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(window))
    {
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
/*
void Render::drawCallback()
{
	currentInstance->Display();
}

void Render::setupDrawCallback()
{
	currentInstance = this;
	::glutDisplayFunc(Render::drawCallback);
}

int Render::Draw(){
	int foo = 1;
	char * bar[1] = {" "};
	glutInit(&foo, bar);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Points");

	setupDrawCallback();
	//glutDisplayFunc(Display);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);

	glutMainLoop();
	return 0;
}

void Render::Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POINTS);
    for(Vector2 v : points){
        glVertex2f(v.X(), v.Y());
    }
	//glVertex2f(150.0, 80.0);
	//glVertex2f(100.0, 20.0);
	//glVertex2f(200.0, 100.0);
	glEnd();
	glFlush();
}*/

void Render::SetDrawList(const py::list& vector2List){
    points.clear();
    for (auto item : vector2List){
        Vector2 bla = item.cast<Vector2>();
        //std::cout << std::string(std::to_string(bla.X())) << std::endl;
        points.push_back(bla);
    }
}