#pragma once
#ifndef _UNITLIST_DTO_H_
#define _UNITLIST_DTO_H_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

//��λ�б������ݶ���ʵ��
class UnitListDTO : public oatpp::DTO
{
public:
	DTO_INIT(UnitListDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//���ô���
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	//�������
	API_DTO_FIELD_DEFAULT(UInt32, mytype, ZH_WORDS_GETTER("unit.field.type"));
	//��������
	API_DTO_FIELD_DEFAULT(String, regionName, ZH_WORDS_GETTER("unit.field.regionName"));
	//��ҵ���
	API_DTO_FIELD_DEFAULT(String, industryName, ZH_WORDS_GETTER("unit.field.industryName"));
	//��������
	API_DTO_FIELD_DEFAULT(String, economicTypeName, ZH_WORDS_GETTER("unit.field.economicTypeName"));
	//��ҵ��ģ
	API_DTO_FIELD_DEFAULT(String, businessScaleName, ZH_WORDS_GETTER("unit.field.businessScaleName")); 
	//��ϵ��
	API_DTO_FIELD_DEFAULT(String, linkMan, ZH_WORDS_GETTER("unit.field.linkMan"));
	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(String, linkPhone, ZH_WORDS_GETTER("unit.field.linkPhone"));

};

//��λ�б��ҳ����ʵ��
class UnitListPageDTO :public PageDTO<UnitListDTO::Wrapper> {
	DTO_INIT(UnitListPageDTO, PageDTO <UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif