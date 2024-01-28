#pragma once
#ifndef _FILEVO_H_
#define _FILEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/file/FileDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editor响应图片上传结果数据
 */
//class FileVO : public JsonVO<FileDTO::Wrapper>
//{
//	DTO_INIT(FileVO, JsonVO<FileDTO::Wrapper>);
//};

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class FileJsonVO : public JsonVO<FileDTO::Wrapper> {
	DTO_INIT(FileJsonVO, JsonVO<FileDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEVO_H_
