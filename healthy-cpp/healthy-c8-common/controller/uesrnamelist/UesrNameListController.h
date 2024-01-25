#pragma once
#ifndef _UesrNameListController_
#define _UesrNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/uesrnamelist/UesrNameListQuery.h"
#include "domain/dto/uesrnamelist/UesrNameListDTO.h"
#include "domain/vo/uesrnamelist/UesrNameListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class UesrNameListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(UesrNameListController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口1描述
	ENDPOINT_INFO(queryUesrNameList) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("uesrnamelist.query-uesrnamelist.summary"), UesrNameListJsonVO::Wrapper);
	}
	// 3.2 定义测试声明式服务调用的接口1处理
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/common/query-uesrnamelist", queryUesrNameList, execQueryUesrNameList(authObject->getPayload()));
private:
	// 3.3 测试声明式服务调用1
	UesrNameListJsonVO::Wrapper execQueryUesrNameList(const PayloadDTO& payload);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif