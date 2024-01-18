#pragma once
#ifndef _ADDNEWITEMSVO_H_
#define _ADDNEWITEMSVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/addNewItems/AddNewItemsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*  ����������Ŀ��ʾJsonVOʵ��
*/
class AddNewItemsJsonVO : public JsonVO<AddNewItemsDTO::Wrapper> {
	DTO_INIT(AddNewItemsJsonVO, JsonVO<AddNewItemsDTO::Wrapper>);
};

/**
 * ����������Ŀ��ʾ��ҳJsonVO
 */
class AddNewItemsPageJsonVO : public JsonVO<AddNewItemsPageDTO::Wrapper> {
	DTO_INIT(AddNewItemsPageJsonVO, JsonVO<AddNewItemsPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ADDNEWITEMSVO_H_