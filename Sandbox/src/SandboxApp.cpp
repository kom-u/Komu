#include <Komu.h>

class Sandbox : public Komu::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Komu::Application* Komu::CreateApplication()
{
    return new Sandbox();
}