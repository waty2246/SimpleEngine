#pragma once

#include "platform/IApplication.h"

namespace app
{
    class Application : public sp::platform::IApplication
    {
    public:
        INJECT(Application())
        {
        }

        virtual void OnCreate() override;
        virtual void OnResume() override;
        virtual void OnUpdate() override;
        virtual void OnSuspend() override;
        virtual void OnDestroy() override;
        virtual void OnInputConnected(sp::ref_ptr<sp::platform::input::IInput> input) override;
    };
}