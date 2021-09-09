#include "common.h"
#include "core/utils.h"
#include "core/ServiceEntry.h"

namespace sp
{
	const ServiceLifetime& ServiceEntry::GetServiceLifetime() const
	{
		return m_lifetime;
	}

	const std::type_index& ServiceEntry::GetServiceTypeInfo() const
	{
		return *m_serviceTypeInfo.get();
	}

	ServiceEntry::~ServiceEntry()
	{
	}
}

