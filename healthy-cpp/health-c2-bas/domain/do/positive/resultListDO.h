#ifndef _RESULTLISTDO_H_
#define _RESULTLISTDO_H_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class resultListDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 名称
	CC_SYNTHESIZE(string, name, Name);
	// 是否重度
	CC_SYNTHESIZE(string, degree, Degree);
	// 是否阳性
	CC_SYNTHESIZE(string, positive, Positive);
	// 科室编号
	CC_SYNTHESIZE(string, deptld, Deptld);
	// 职业建议
	CC_SYNTHESIZE(string, advise, Advise);
	// 健康建议
	CC_SYNTHESIZE(string, healthAdvice, HealthAdvice);
private:
	resultListDO() {
		id = "0";
		name = "";
		degree = "";
		positive = "";
		deptld = "";
		advise = "";
		healthAdvice = "";
	}
};

#endif // !_RESULTLISTDO_H_