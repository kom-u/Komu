#pragma once

#include "Core.h"

namespace Komu
{
    class KOMU_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}

