#pragma once
#ifndef _SAVE_INF_DTO_H_
#define _SAVE_INF_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸��û���Ϣ�����ݴ���ģ��
 */
class SaveInfoDTO : public oatpp::DTO
{
	DTO_INIT(SaveInfoDTO, DTO);
	// ���֤��
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("exalanding.saveinfo.field.id_card"));
	//����
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("exalanding.saveinfo.field.person_name"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("exalanding.saveinfo.field.sex"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("exalanding.saveinfo.field.age"));
	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("exalanding.saveinfo.field.mobile"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, is_marry, ZH_WORDS_GETTER("exalanding.saveinfo.field.is_marry"));
};

/**
 * ����һ���û���Ϣ��ҳ�������
 */
class SaveInfoPageDTO : public PageDTO<SaveInfoDTO::Wrapper>
{
	DTO_INIT(SaveInfoPageDTO, PageDTO<SaveInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _SAVE_INF_DTO_H_