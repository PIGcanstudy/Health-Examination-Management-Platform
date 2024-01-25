#pragma once
#ifndef _PlanNameListQuery_
#define _PlanNameListQuery_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class PlanNameListQuery : public PageQuery
{

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_