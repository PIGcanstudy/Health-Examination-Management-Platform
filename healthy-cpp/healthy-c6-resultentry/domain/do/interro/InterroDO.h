#pragma once
#ifndef _INTERRO_DO_
#define _INTERRO_DO_
#include"../DoInclude.h"

/**
* 数据库实体类
*/
class InterroDO
{
	// 体检人编号
	CC_SYNTHESIZE(string, id, Id);
	// 体检项目
	CC_SYNTHESIZE(string, project, Project);
	// 危机程度
	CC_SYNTHESIZE(string, degree, Degree);
	// 时间
	CC_SYNTHESIZE(string, time, Time);
public:
	InterroDO() {
		id = "";
		project = "";
		degree = "";
		time = "";
	}
};

#endif //_INTERRO_DO_