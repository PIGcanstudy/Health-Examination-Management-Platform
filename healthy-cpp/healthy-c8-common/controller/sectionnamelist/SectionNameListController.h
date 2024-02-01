#pragma once
#ifndef _SectionNameListController_
#define _SectionNameListController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/sectionnamelist/SectionNameListQuery.h"
#include "domain/dto/sectionnamelist/SectionNameListDTO.h"
#include "domain/vo/sectionnamelist/SectionNameListVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class SectionNameListController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(SectionNameListController);
	// 3 定义接口
public:
	// 3.1 定义测试声明式服务调用的接口1描述
	ENDPOINT_INFO(querySectionNameList) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("sectionnamelist.query-sectionnamelist.summary"), SectionNameListJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_QUERY_PARAMS(String, "keyword", ZH_WORDS_GETTER("sectionnamelist.field.keyword"), "", false);
	}
	// 3.2 定义测试声明式服务调用的接口1处理
	API_HANDLER_ENDPOINT_AUTH(API_M_GET, "/common/query-sectionnamelist", querySectionNameList, QUERY(String, keyword), execQuerySectionNameList(keyword, authObject->getPayload()));
private:
	// 3.3 测试声明式服务调用2
	SectionNameListJsonVO::Wrapper execQuerySectionNameList(const String& keyword, const PayloadDTO& payload);
};
// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif