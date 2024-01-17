#pragma once
#ifndef _SAVERES_DTO_
#define _SAVERES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class SaveResDTO : public oatpp::DTO
{
	DTO_INIT(SaveResDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("save.filed.id"));
	// 体检人id
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("save.filed.personId"));
	// 分组项目id
	API_DTO_FIELD_DEFAULT(String, groupItemId, ZH_WORDS_GETTER("save.filed.groupItemId"));
	// 分组项目名称
	API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("save.filed.groupItemName"));
	// 诊断提醒
	API_DTO_FIELD_DEFAULT(String, diagnoseTip, ZH_WORDS_GETTER("save.filed.diagnoseTip"));
	// 诊断小结
	API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("save.filed.diagnoseSum"));
	// 科室id
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("save.filed.officeId"));
	// 科室名称
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("save.filed.officeName"));
	// 检查医生
	API_DTO_FIELD_DEFAULT(String, checkDoc, ZH_WORDS_GETTER("save.filed.checkDoc"));
	// 检查日期
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("save.filed.checkDate"));
	// 是否检查
	API_DTO_FIELD_DEFAULT(String, isCheck, ZH_WORDS_GETTER("save.filed.isCheck"));
	// del flag
	API_DTO_FIELD_DEFAULT(String, delFlag, ZH_WORDS_GETTER("save.filed.delFlag"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVERES_DTO_