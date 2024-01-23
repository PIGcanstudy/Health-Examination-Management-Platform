#pragma once
#ifndef _GROUP_PERSON_INFO_DTO_
#define _GROUP_PERSON_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��Ա���鴫�����ݶ���ʵ��
 */
class GroupPersonInfoDTO : public oatpp::DTO
{
	DTO_INIT(GroupPersonInfoDTO, DTO);
	//�Ƿ�ͨ�����
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("group_person.field.is_pass"));

	// �����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("group_person.field.id"));

	// ���֤��
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("group_person.field.id_card"));
	
	// ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("group_person.field.name"));

	// �Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("group_person.field.sex"));

	// ����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("group_person.field.age"));
	
	// �������
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("group_person.field.physical_type"));
	
	// ��������
	API_DTO_FIELD_DEFAULT(UInt32, sporadic_physical, ZH_WORDS_GETTER("group_person.field.sporadic_physical"));
	
	// Σ������
	API_DTO_FIELD_DEFAULT(String, hazard_factors, ZH_WORDS_GETTER("group_person.field.hazard_factors"));
	
	// �������
	API_DTO_FIELD_DEFAULT(String, jc_type, ZH_WORDS_GETTER("group_person.field.jc_type"));

	// ��λ����
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("group_person.field.dept"));
	
	// �Ǽ�ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("group_person.field.create_time"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_PERSON_INFO_DTO_