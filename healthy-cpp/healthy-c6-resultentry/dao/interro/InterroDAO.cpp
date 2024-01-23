#include "stdafx.h"
#include "InterroDAO.h"
#include "InterroMapper.h"
#include <sstream>

uint64_t InterroDAO::insert(const InterroDO& iObj){
	string sql = "INSERT INTO `sample` (`id`, `project`, `degree`, `time`) VALUES(? , ? , ? , ? )";
	return sqlSession->executeInsert(sql, "%s%s%i", iObj.getId(), iObj.getProject(), iObj.getDegree(), iObj.getTime());
}
