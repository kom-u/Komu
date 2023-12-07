#pragma once

#include "Komu/Core.h"
#include "Layer.h"

#include <vector>

namespace Komu
{

    class KOMU_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_LayerList.begin(); }
        std::vector<Layer*>::iterator end() { return m_LayerList.end(); }

    private:
        std::vector<Layer*> m_LayerList;
        std::vector<Layer*>::iterator m_LayerInsert;
    };

}

