#pragma once

#ifndef _UNITLISTDTO_H_
#define _UNITLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  列表DTO实体
 */
class UnitListDTO : public oatpp::DTO
{
	DTO_INIT(UnitListDTO, DTO);
	//唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//科室
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("unit.field.officeName"));
	//检查项目
	API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("unit.field.groupItemName"));
	//体检小结
	API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("unit.field.diagnoseSum"));
};

class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper>
{
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITLISTDTO_H_
