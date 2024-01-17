#pragma once
#ifndef _MODIFYRESULTDTO_H_
#define _MODIFYRESULTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
    class ModifyResultDTO : public oatpp::DTO
{
        DTO_INIT(ModifyResultDTO, DTO);
		DTO_FIELD(UInt64, id);
		DTO_FIELD_INFO(id) {
			info->description = ZH_WORDS_GETTER("deatil.field.id)");
		}
		// 名称
		DTO_FIELD(String, name);
		DTO_FIELD_INFO(name) {
			info->description = ZH_WORDS_GETTER("deatil.field.name");
		}
		// 简拼
		DTO_FIELD(Int32, namePinyin);
		DTO_FIELD_INFO(namePinyin) {
			info->description = ZH_WORDS_GETTER("deatil.field.namePinyin");
		}
		// 是否严重
		DTO_FIELD(String, degree);
		DTO_FIELD_INFO(degree) {
			info->description = ZH_WORDS_GETTER("deatil.field.degree");
		}
		//是否阳性
		DTO_FIELD(String, positive);
		DTO_FIELD_INFO(positive) {
			info->description = ZH_WORDS_GETTER("deatil.field.positive");
		}
		//科室
		DTO_FIELD(String, sectionName);
		DTO_FIELD_INFO(sectionName) {
			info->description = ZH_WORDS_GETTER("deatil.field.sectionName");
		}
		//职业建议
		DTO_FIELD(String, advise);
		DTO_FIELD_INFO(advise) {
			info->description = ZH_WORDS_GETTER("deatil.field.advise");
		}
		//健康建议
		DTO_FIELD(String, healthKnowledge);
		DTO_FIELD_INFO(healthKnowledge) {
			info->description = ZH_WORDS_GETTER("deatili.field.healthKnowledge");
		}
};
#include OATPP_CODEGEN_END(DTO)
#endif // _MODIFYRESULTDTO_H_