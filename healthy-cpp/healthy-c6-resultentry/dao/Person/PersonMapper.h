#pragma once
#ifndef _PERSON_MAPPER_
#define _PERSON_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Person/PersonDO.h"

class PersonMapper : public Mapper<PersonDO>
{
public:
	PersonDO mapper(ResultSet* resultSet) const override
	{
		PersonDO data;
		data.setName(resultSet->getString(1));
		data.setAge(resultSet->getInt(2));
		data.setSex(resultSet->getString(3));
		data.setPhysical_type(resultSet->getString(4));
		data.setSporadic_physical(resultSet->getInt(5));
		return data;
	}
};

#endif // !_PERSON_MAPPER_