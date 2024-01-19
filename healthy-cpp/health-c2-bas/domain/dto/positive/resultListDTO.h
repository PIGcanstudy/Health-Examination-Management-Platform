#ifndef _RESULTLISTDTO_H_
#define _RESULTLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 阳性结果列表传输数据对象实体
 */
class resultListDTO : public oatpp::DTO
{
	DTO_INIT(resultListDTO, DTO);
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("positive.result.field.id");
	}
	// 名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("positive.results.field.name");
	}
	// 是否重度
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("positive.results.field.degree");
	}
	// 是否阳性
	DTO_FIELD(String, positive);
	DTO_FIELD_INFO(positive) {
		info->description = ZH_WORDS_GETTER("positive.results.field.positive");
	}
	// 科室id
	DTO_FIELD(String, deptld);
	DTO_FIELD_INFO(deptld) {
		info->description = ZH_WORDS_GETTER("positive.results.field.deptld");
	}
	// 职业建议
	DTO_FIELD(String, advice);
	DTO_FIELD_INFO(advice) {
		info->description = ZH_WORDS_GETTER("positive.results.field.advice");
	}
	// 健康建议
	DTO_FIELD(String, healthadvice);
	DTO_FIELD_INFO(healthadvice) {
		info->description = ZH_WORDS_GETTER("positive.results.field.healthadvice");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTLISTDTO_H_