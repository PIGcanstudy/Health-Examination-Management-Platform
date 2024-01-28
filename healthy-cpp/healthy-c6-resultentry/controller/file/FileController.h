#pragma once

#ifndef _FILECONTROLLER_H_
#define _FILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/file/FileVO.h"
#include "domain/dto/file/FileDTO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class FileController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(FileController);
	// 3 定义接口
public:
	
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("file.upload.summary"), modifySample, Uint64JsonVO::Wrapper);
	
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/file/upload", modifySample, BODY_DTO(FileDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));

	
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifySample(const FileDTO::Wrapper& dto, const PayloadDTO& payload);
	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_FILECONTROLLER_H_