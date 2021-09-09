#pragma once

#include "core/utils.h"

namespace sp
{
	class IServiceContext
	{
	public:
		virtual bool IsScoped() = 0;
		virtual void AddScopedInstance(const std::type_index& serviceTypeInfo, std::shared_ptr<void> scopedService) = 0;
		virtual std::shared_ptr<IServiceProvider> GetServiceProvider() = 0;

		virtual ~IServiceContext(){}
	};
}