#include"InterroService.h"
#include"stdafx.h"
#include"../../dao/interro/InterroDAO.h"

uint64_t InterroService::saveData(const InterroDTO::Wrapper& dto) {
	//组装DO数据
	InterroDO data;
	// data.setName(dto->name.getValue(""));
	// data.setSex(dto->sex.getValue(""));
	// data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Project, project, Degree, degree, Time, time);
	//执行数据添加
	InterroDAO dao;
	return dao.insert(data);
}
