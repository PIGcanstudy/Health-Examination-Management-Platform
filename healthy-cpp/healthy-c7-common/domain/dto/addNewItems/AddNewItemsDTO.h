#pragma once
#ifndef _ADDNEWITEMSDTO_H_
#define _ADDNEWITEMSDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
*  新增复查项目传输数据对象实体
*/
class AddNewItemsDTO : public oatpp::DTO
{
	DTO_INIT(AddNewItemsDTO, DTO);
	//待选项目
	API_DTO_FIELD_DEFAULT(String, projectsToBeSelected, ZH_WORDS_GETTER("addNewItems.field.projectsToBeSelected"));
	//已选项目
	API_DTO_FIELD_DEFAULT(String, selectedProjects, ZH_WORDS_GETTER("addNewItems.field.selectedProjects"));
	//复查原因
	API_DTO_FIELD_DEFAULT(String, reason, ZH_WORDS_GETTER("addNewItems.field.reason"));
};

/**
*  复查列表分页数据实体
*/
class AddNewItemsPageDTO : public PageDTO<AddNewItemsDTO::Wrapper> {
	DTO_INIT(AddNewItemsPageDTO, PageDTO<AddNewItemsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ADDNEWITEMSDTO_H_