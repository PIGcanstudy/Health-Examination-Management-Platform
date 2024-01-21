#pragma once
#ifndef _ADDNEWITEMSQuery_H_
#define _ADDNEWITEMSQuery_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  新增复查项目实体
*/
class AddNewItemsQuery : public PageQuery {
	DTO_INIT(AddNewItemsQuery, PageQuery);
	//待选项目
	API_DTO_FIELD_DEFAULT(String, projectsToBeSelected, ZH_WORDS_GETTER("addNewItems.field.projectsToBeSelected"));
	//已选项目
	API_DTO_FIELD_DEFAULT(String, selectedProjects, ZH_WORDS_GETTER("addNewItems.field.selectedProjects"));
	//复查原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSQUERY_H_