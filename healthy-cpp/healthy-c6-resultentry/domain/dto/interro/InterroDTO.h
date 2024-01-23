#pragma once
#ifndef _INTERRO_DTO_
#define _INTERRO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ֢״ѯ�ʴ������
*/
class InterroDTO : public oatpp::DTO {
	DTO_INIT(InterroDTO, DTO);
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("interro2.field.id");
	}
	// �����Ŀ
	DTO_FIELD(String, project);
	DTO_FIELD_INFO(project) {
		info->description = ZH_WORDS_GETTER("interro2.field.project");
	}
	// Σ���̶�
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("interro2.field.degree");
	}
	// ����ʱ��
	DTO_FIELD(String, time);
	DTO_FIELD_INFO(time) {
		info->description = ZH_WORDS_GETTER("interro2.field.time");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _INTERRO_DTO_
