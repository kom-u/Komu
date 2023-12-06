#include "Application.h"

#include "Komu/Log.h"
#include "Komu/Events/ApplicationEvent.h"

namespace Komu
{
    Application::Application()
    {}

    Application::~Application()
    {}

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        KM_TRACE(e);

        while (true);
    }
}
