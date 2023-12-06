#include "kmpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Komu
{

#define BIND_EVENT_FUNC(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FUNC(Application::OnEvent));
    }

    Application::~Application()
    {}

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(Application::OnWindowClose));

        KM_CORE_TRACE("{0}", e);
    }

    void Application::Run()
    {
        while (m_IsRunning)
        {
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_IsRunning = false;
        return true;
    }

}
