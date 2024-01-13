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
		data.setName(resultSet->getString(1));
		data.setAge(resultSet->getInt(2));
		data.setSex(resultSet->getString(3));
		data.setPhysical_type(resultSet->getString(4));
		data.setSporadic_physical(resultSet->getInt(5));
		return data;
	}
};

#endif // !_GroupPerson_MAPPER_