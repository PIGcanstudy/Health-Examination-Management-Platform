#include "stdafx.h"
#include "UpFileDAO.h"
#include <sstream>


int UpFileDAO::update(const UpFileDO& uObj,const string download)
{


		string sql = "UPDATE `t_depart_result` SET `url`=?,`is_file`='yes' WHERE `id`= ? ";
		return sqlSession->executeUpdate(sql, "%s%s",download,uObj.getId());
			
}
