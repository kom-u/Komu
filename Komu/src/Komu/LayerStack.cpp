#include "kmpch.h"
#include "LayerStack.h"

namespace Komu
{

    LayerStack::LayerStack()
    {
        m_LayerInsert = m_LayerList.begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_LayerList)
        {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_LayerInsert = m_LayerList.emplace(m_LayerInsert, layer);
    }

    void LayerStack::PushOverlay(Layer* overlay)
    {
        m_LayerList.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer)
    {
        std::vector<Layer*>::iterator it = std::find(m_LayerList.begin(), m_LayerList.end(), layer);
        if (it != m_LayerList.end())
        {
            m_LayerList.erase(it);
            m_LayerInsert--;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay)
    {
        std::vector<Layer*>::iterator it = std::find(m_LayerList.begin(), m_LayerList.end(), overlay);
        if (it != m_LayerList.end())
        {
            m_LayerList.erase(it);
        }
    }

}