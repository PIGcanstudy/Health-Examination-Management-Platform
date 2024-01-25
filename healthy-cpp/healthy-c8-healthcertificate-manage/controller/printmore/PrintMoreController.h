#pragma once
#ifndef _PrintMoreController_
#define _PrintMoreController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/printmore/PrintMoreDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class PrintMoreController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(PrintMoreController);
	// 3 定义接口
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("printmore.put.summary"), modifyPrintMore, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/healthcertificate-manage/modify-printmore", modifyPrintMore, BODY_DTO(PrintMoreDTO::Wrapper, dto), execModifyPrintMore(dto));
private:
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyPrintMore(const PrintMoreDTO::Wrapper& dto);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_