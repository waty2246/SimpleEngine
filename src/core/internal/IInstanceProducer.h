#pragma once

#include "core/internal/IServiceContext.h"

namespace sp
{
	class IInstanceProducer
	{
	public:
		virtual std::shared_ptr<void> GetInstance(sp::ref_ptr<IServiceContext> serviceContext) = 0;

		virtual ~IInstanceProducer(){}
	};
}