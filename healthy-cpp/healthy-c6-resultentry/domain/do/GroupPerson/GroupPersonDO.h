#pragma once

#ifndef _GroupPerson_DO_
#define _GroupPerson_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GroupPersonDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ����
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
