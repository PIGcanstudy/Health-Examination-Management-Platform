#pragma once
#ifndef _SAMPLE_MAPPER_
#define _SAMPLE_MAPPER_

#include "Mapper.h"
#include"../../domain/do/interro/InterroDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class InterroMapper : public Mapper<InterroDO>
{
public:
	InterroDO mapper(ResultSet* resultSet) const override
	{
		InterroDO data;
		data.setId(resultSet->getString(1));
		data.setProject(resultSet->getString(2));
		data.setDegree(resultSet->getString(3));
		data.setTime(resultSet->getString(4));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_