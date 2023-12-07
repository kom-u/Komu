#include <Komu.h>

class ExampleLayer : public Komu::Layer
{

public:
    ExampleLayer()
        : Layer("Example") {}

    void OnUpdate() override
    {
        KM_INFO("ExampleLayer::OnUpdate()");
    }

    void OnEvent(Komu::Event& e) override
    {
        KM_TRACE("{0}", e);
    }

};

class Sandbox : public Komu::Application
{

public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {}

};

Komu::Application* Komu::CreateApplication()
{
    return new Sandbox();
}