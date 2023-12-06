#pragma once

#ifdef KM_PLATFORM_WINDOWS

extern Komu::Application* Komu::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Komu::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#endif