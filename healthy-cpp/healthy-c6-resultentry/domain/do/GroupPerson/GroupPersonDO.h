#pragma once

#ifndef _GroupPerson_DO_
#define _GroupPerson_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class GroupPersonDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
public:
	GroupPersonDO() {
		id = 0;
		name = "";
		//sex = "";
		//age = -1;
	}
};

#endif // !_GroupPerson_DO_
