#pragma once

#include "Komu/Core.h"
#include "Komu/Events/ApplicationEvent.h"
#include "Komu/Events/Event.h"
#include "Komu/LayerStack.h"
#include "Komu/Window.h"

namespace Komu
{
    class KOMU_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        bool m_IsRunning = true;

        LayerStack m_LayerStack;
    };

    // To be defined in CLIENT
    Application* CreateApplication();
};

