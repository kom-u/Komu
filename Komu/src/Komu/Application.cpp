#include "kmpch.h"
#include "Application.h"

#include "Komu/Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Komu
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {}

    void Application::Run()
    {
        while (m_IsRunning)
        {
            m_Window->OnUpdate();
        }
    }
}
