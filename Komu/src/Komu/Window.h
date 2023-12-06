#pragma once

#include "kmpch.h"

#include "Komu/Core.h"
#include "Komu/Events/Event.h"

namespace Komu
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(
            const std::string& title = "Komu Engine",
            unsigned int width = 1280,
            unsigned int height = 720
        ) :
            Title(title), Width(width), Height(height) {}
    };

    // Interface representing a desktop system based Window
    class KOMU_API Window
    {
    public:
        using EventCallbackFunc = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        // window attributes
        virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
        virtual void SetVSync(bool isEnabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}