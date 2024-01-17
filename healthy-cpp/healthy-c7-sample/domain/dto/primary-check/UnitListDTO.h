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
	
	//科室
	//检查项目
	//体检小结

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITLISTDTO_H_
