#pragma once
#ifndef _SAVERES_DTO_
#define _SAVERES_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class SaveResDTO : public oatpp::DTO
{
	DTO_INIT(SaveResDTO, DTO);
	// Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("save.filed.id"));
	// �����id
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("save.filed.personId"));
	// ������Ŀid
	API_DTO_FIELD_DEFAULT(String, groupItemId, ZH_WORDS_GETTER("save.filed.groupItemId"));
	// ������Ŀ����
	API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("save.filed.groupItemName"));
	// �������
	API_DTO_FIELD_DEFAULT(String, diagnoseTip, ZH_WORDS_GETTER("save.filed.diagnoseTip"));
	// ���С��
	API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("save.filed.diagnoseSum"));
	// ����id
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("save.filed.officeId"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("save.filed.officeName"));
	// ���ҽ��
	API_DTO_FIELD_DEFAULT(String, checkDoc, ZH_WORDS_GETTER("save.filed.checkDoc"));
	// �������
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("save.filed.checkDate"));
	// �Ƿ���
	API_DTO_FIELD_DEFAULT(String, isCheck, ZH_WORDS_GETTER("save.filed.isCheck"));
	// del flag
	API_DTO_FIELD_DEFAULT(String, delFlag, ZH_WORDS_GETTER("save.filed.delFlag"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVERES_DTO_