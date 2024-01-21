#pragma once
#ifndef _POSITIVEListDTO_H_
#define _POSITIVEListDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 阳性结果列表传输数据对象实体
 * 阳性结果位于t_depart_item_result表中
 */
class PositiveListDTO : public oatpp::DTO {
	DTO_INIT(PositiveListDTO, DTO);
	// 唯一编号 
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.filed.id"));
	// 姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("positive.filed.personname"));
	// 体检编号 t_group_person表中
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("positive.filed.test_num"));
	// 体检科室
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("positive.filed.officename"));
	// 体检项目
	API_DTO_FIELD_DEFAULT(String, order_group_item_project_name, ZH_WORDS_GETTER("positive.filed.order_group_item_project_name"));
	// 结果 重度程度
	API_DTO_FIELD_DEFAULT(String, result, ZH_WORDS_GETTER("positive.filed.result"));
	// 单位
	API_DTO_FIELD_DEFAULT(String, unit_name, ZH_WORDS_GETTER("positive.filed.unit_name"));
	// 参考范围
	API_DTO_FIELD_DEFAULT(String, scope, ZH_WORDS_GETTER("positive.filed.scope"));
	// 提示

	// 危急程度
	API_DTO_FIELD_DEFAULT(String, crisis_degree, ZH_WORDS_GETTER("positive.filed.crisis_degree"));
	// 体检日期
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("positive.filed.checkdate"));
};

/**
 * 阳性结果列表分页数据实体
 */
class PositiveListPageDTO : public PageDTO<PositiveListDTO::Wrapper> {
	DTO_INIT(PositiveListPageDTO, PageDTO<PositiveListDTO::Wrapper>)
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_POSITIVEListDTO_H_