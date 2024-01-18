#pragma once
#ifndef _INTERRO_DAO_
#define _INTERRO_DAO_
#include "BaseDAO.h"
#include"../../domain/do/interro/InterroDO.h"
#include"../../domain/query/interro/InterroQuery.h"
/**
 * 示例表数据库操作实现
 */
class InterroDAO : public BaseDAO
{
public:
	// 查询数据
	list<InterroDO> selectWith(const InterroQuery::Wrapper& query);
};
#endif // !_INTERRO_DAO_
