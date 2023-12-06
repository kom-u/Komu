#pragma once

#ifdef KM_PLATFORM_WINDOWS

extern Komu::Application* Komu::CreateApplication();

int main(int argc, char** argv)
{
    Komu::Log::Init();
    KM_CORE_WARN("Initialized Log!");

    Komu::Application* app = Komu::CreateApplication();
    app->Run();
    delete app;

    return 0;
}

#endif
