#pragma once

#ifndef _GroupPerson_MAPPER_
#define _GroupPerson_MAPPER_

#include "Mapper.h"
#include "../../domain/do/GroupPerson/GroupPersonDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class GroupPersonMapper : public Mapper<GroupPersonDO>
{
public:
	GroupPersonDO mapper(ResultSet* resultSet) const override
	{
		GroupPersonDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};

#endif // !_GroupPerson_MAPPER_