#include "common.h"
#include "platform/external_modules.h"
#include "core/IServiceCollection.h"
#include "core/IServiceProvider.h"
#include "Application.h"
#include "platform/WindowProps.h"


extern void SPCreatingWindow(sp::ref_ptr<sp::platform::WindowProps> windowProps)
{
    windowProps->IsFullScreen = false;
}

extern void SPConfigure(sp::ref_ptr<sp::IServiceCollection> configServiceCollection, sp::ref_ptr<sp::IServiceProvider> systemServiceProvider)
{
}

extern std::shared_ptr<sp::platform::IApplication> SPMain(sp::ref_ptr<sp::IServiceProvider> serviceProvider)
{
    return serviceProvider->FillObject<app::Application>();
}