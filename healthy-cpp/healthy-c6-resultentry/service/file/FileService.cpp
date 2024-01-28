#include "stdafx.h"
#include "FileService.h"
#include "../../dao/file/FileDAO.h"

//uint64_t FileService::saveData(const FileDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	SampleDO data;
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
//		// 执行数据添加
//		SampleDAO dao;
//	return dao.insert(data);
//}

bool FileService::updateData(const FileDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	FileDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Url, url)
		// 执行数据修改
		FileDAO dao;
	return dao.update(data) == 1;
}
