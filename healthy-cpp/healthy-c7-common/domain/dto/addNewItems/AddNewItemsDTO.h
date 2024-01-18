#pragma once
#ifndef _ADDNEWITEMSDTO_H_
#define _ADDNEWITEMSDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  ����������Ŀ�������ݶ���ʵ��
*/
class AddNewItemsDTO : public oatpp::DTO
{
	DTO_INIT(AddNewItemsDTO, DTO);
	//��ѡ��Ŀ
	API_DTO_FIELD_DEFAULT(String, projectsToBeSelected, ZH_WORDS_GETTER("addNewItems.field.projectsToBeSelected"));
	//��ѡ��Ŀ
	API_DTO_FIELD_DEFAULT(String, selectedProjects, ZH_WORDS_GETTER("addNewItems.field.selectedProjects"));
	//����ԭ��
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

/**
*  �����б��ҳ����ʵ��
*/
class AddNewItemsPageDTO : public PageDTO<AddNewItemsDTO::Wrapper> {
	DTO_INIT(AddNewItemsPageDTO, PageDTO<AddNewItemsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSDTO_H_