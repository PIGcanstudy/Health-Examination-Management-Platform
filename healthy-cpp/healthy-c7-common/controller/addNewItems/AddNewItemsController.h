#pragma once
#ifndef _ADDNEWITEMSCONTROLLER_H_
#define _ADDNEWITEMSCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/addNewItems/AddNewItemsQuery.h"
#include "domain/dto/addNewItems/AddNewItemsDTO.h"
#include "domain/vo/addNewItems/AddNewItemsVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AddNewItemsController : public oatpp::web::server::api::ApiController {
	//定义控制器访问入口
	API_ACCESS_DECLARE(AddNewItemsController);
public: //定义接口
	// 1 复查记录列表 定义分页查询复查记录接口描述
	ENDPOINT_INFO(queryAddNewItems) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addNewItems.query.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AddNewItemsPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		//待选项目
		API_DEF_ADD_QUERY_PARAMS(String, "projectsToBeSelected", ZH_WORDS_GETTER("addNewItems.field.projectsToBeSelected"), "aaaaa", false);
		//已选项目
		API_DEF_ADD_QUERY_PARAMS(String, "selectedProjects", ZH_WORDS_GETTER("addNewItems.field.selectedProjects"), "bbb", false);
		//复查原因
		API_DEF_ADD_QUERY_PARAMS(String, "reason", ZH_WORDS_GETTER("addNewItems.field.reason"), "fall ill", false);

	}
	// 1 复查记录列表 定义分页查询复查记录接口
	ENDPOINT(API_M_GET, "/review/query-AddNewItems", queryAddNewItems, QUERIES(QueryParams, params), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(rq, AddNewItemsQuery, params);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAddNewItems(rq));
	}

private: //定义接口执行函数
	AddNewItemsPageJsonVO::Wrapper execQueryAddNewItems(const AddNewItemsQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)

#endif //!_ADDNEWITEMSCONTROLLER_H_