#include <iostream>
#include "gl_framework.cpp"
#include "model.hpp"


void renderGL(void) {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(csX75::leftShoulderAngle,+0.5,-1.0,0.0);
	//glTranslatef(0,1,0);
	/* The torso */
	

	glPushMatrix();
	{
		glTranslatef(0,0,0.0);

		glPushMatrix(); 
		{
			glCallList(6);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

int main(int argc, char *argv[]){
	GLFWwindow* window;

	// Setting up GLFW Error callback
	glfwSetErrorCallback(csX75::error_callback);

	if(!glfwInit()) {
		return -1;
	}

	int win_width=512;
	int win_height=512;

	//! Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(win_width, win_height, "Bumblebee is here", NULL, NULL);
	if (!window) {
		//! Free allocated resources and sets library to unintialised state 
		glfwTerminate();
		return -1;
	}

	//! Make the window's context current 
	glfwMakeContextCurrent(window);

	//Keyboard Callback
	glfwSetKeyCallback(window, csX75::key_callback);

	//Framebuffer resize callback
	// If you wish to be notified when the framebuffer of a window is resized
	glfwSetFramebufferSizeCallback(window, csX75::framebuffer_size_callback);

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// For directly retrieving the current size of the framebuffer of a window.
	glfwGetFramebufferSize(window, &win_width, &win_height);

	csX75::framebuffer_size_callback(window, win_width, win_height);
	//Initialize GL state
	csX75::initGL();

	model::makeModel();
 
	// Loop until the user closes the window
	// Run the state is set to close window by clicking in close or through keyboard like Alt+F4 
	while (glfwWindowShouldClose(window) == 0)
	{
	  // Render here
	  renderGL();

	  // Swap front and back buffers
	  glfwSwapBuffers(window);
	  
	  // Poll for and process events
	  glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}




	
