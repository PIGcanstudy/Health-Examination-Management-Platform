#pragma once

#ifndef _UNITPHYSICALEXAMINATIONORDERS_DO_
#define _UNITPHYSICALEXAMINATIONORDERS_DO_

#include "../DoInclude.h"

/**
 * 查询单位列表数据库实体类
 */
class UnitPhysicalExaminationOrdersDO
{
	// 单位名称
	CC_SYNTHESIZE(string, name, Name);
	// 订单编号
	CC_SYNTHESIZE(string, code, Code);
	// 订单日期
	CC_SYNTHESIZE(string, signingTime, SigningTime);
	// 是否上报
	CC_SYNTHESIZE(string, Escalation, Escalation);
	// 检测类型
	CC_SYNTHESIZE(string, detectionType, DetectionType);
public:
	UnitPhysicalExaminationOrdersDO() 
	{
		name = "";
		code = "";
		signingTime = "";
		Escalation = "";
		detectionType = "";
	}
};

#endif // !_SAMPLE_DO_