#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	// ʵ����GLFW����
	glfwInit();//glfw��ʼ��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//���汾��
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//�ΰ汾��
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	//�����ߣ�������������һ��GLFWwindow���ʵ����window
	if (window == NULL)
	{
		// ���ɴ��������������Ϣ
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// ����GLFW����ϣ��ÿ�����ڵ�����С��ʱ����øı䴰�ڴ�С�ĺ���
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad����opengl����ָ�룬��ʼ��glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		// ���ɴ��������������Ϣ
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// ��Ⱦѭ��
	while (!glfwWindowShouldClose(window))
	{
		// ����
		processInput(window);

		// ��Ⱦָ��
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// ��鲢�����¼�����������
		glfwSwapBuffers(window);

		// ��鴥��ʲô�¼������´���״̬
		glfwPollEvents();
	}

	// �ͷ�֮ǰ�ķ����������Դ
	glfwTerminate();
	
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// ÿ�����ڸı��С��GLFW�������������������Ӧ�Ĳ������㴦��
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	// ������������Ƿ����ڱ�����
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)//�Ƿ����˷��ؼ�
		glfwSetWindowShouldClose(window, true);
}