#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _QUERYPEOPLE_MAPPER_
#define _QUERYPEOPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/addpeople/AddDO.h"

/**
 * ʾ�����ֶ�ƥ��ӳ��
 */
class QueryPeopleMapper : public Mapper<QueryDO>
{
public:
	QueryDO mapper(ResultSet* resultSet) const override
	{
		QueryDO data;
		data.setAge(resultSet->getInt(1));
		data.setBirth(resultSet->getString(2));
		data.setidCard(resultSet->getString(3));
		data.setisMarry(resultSet->getString(4));
		data.setMobile(resultSet->getString(5));
		data.setpersonName(resultSet->getString(6));
		data.setSex(resultSet->getString(7));
		return data;
	}
};

#endif // !_QUERYPEOPLE_MAPPER_