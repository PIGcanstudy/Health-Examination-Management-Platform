#pragma once
#ifndef _ADDNEWITEMSQuery_H_
#define _ADDNEWITEMSQuery_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  ����������Ŀʵ��
*/
class AddNewItemsQuery : public PageQuery {
	DTO_INIT(AddNewItemsQuery, PageQuery);
	//��ѡ��Ŀ
	API_DTO_FIELD_DEFAULT(String, projectsToBeSelected, ZH_WORDS_GETTER("addNewItems.field.projectsToBeSelected"));
	//��ѡ��Ŀ
	API_DTO_FIELD_DEFAULT(String, selectedProjects, ZH_WORDS_GETTER("addNewItems.field.selectedProjects"));
	//����ԭ��
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSQUERY_H_