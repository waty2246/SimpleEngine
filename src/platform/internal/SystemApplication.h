#pragma once

#include "core/ref_ptr.h"
#include "platform/internal/input/KeyboardInputWrapper.h"

namespace sp
{
	class IServiceProvider;
	class IServiceCollection;

	namespace platform
	{
		class IApplication;
		class SystemSpecsWrapper;
		class WindowSpecsWrapper;
		struct WindowProps;

		class SystemApplication
		{
		public:

			void Init();
			bool Run();

			sp::ref_ptr<sp::platform::input::KeyboardInputWrapper> GetKeyboardInput();

		private:

			void CreateSpecs(sp::ref_ptr<sp::IServiceCollection> preServiceCollection,sp::ref_ptr<WindowProps> windowProps);

		private:
			std::shared_ptr<sp::IServiceProvider> m_serviceProvider;
			std::shared_ptr<sp::IServiceCollection> m_serviceCollection;
			std::shared_ptr<sp::platform::IApplication> m_application;
			sp::scoped_ptr<sp::platform::input::KeyboardInputWrapper> m_keyboardInput;
			SystemSpecsWrapper* m_systemSpecs;
			WindowSpecsWrapper* m_windowSpecs;
		};
	}
}