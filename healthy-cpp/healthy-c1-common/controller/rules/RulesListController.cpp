#include "stdafx.h"
#include "RulesListController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "tree/TreeUtil.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

/**
 * ע�⣺����Ĳ��ִ��뱾Ӧ�÷ŵ�service���У�Ϊ�˷�����ʾ��д��һ����
 */

RulesListPageJsonVO::Wrapper RulesListController::executeQueryAll(const RulesListQuery::Wrapper& query)
{
	// ����һ��JsonVO����
	auto vo = RulesListPageJsonVO::createShared();
	// ����һ����ҳ����
	auto page = RulesListPageDTO::createShared();
	page->hitCount = 20;
	page->maxLimit = 20;

	// ģ������ҳ����
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// �߽�ֵֵ����
	if (start >= page->total.getValue(0) || start < 0) {
		vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// ѭ�����ɲ�������
	for (int64_t i = start; i < end; i++)
	{
		auto rules = RulesListDTO::createShared();
		rules->short_name = query->short_name;
		rules->min_Age = (uint32_t)(i + 1) * 10;
		rules->max_Age = (uint32_t)(i + 5) * 10;
		rules->name = query->name;
		rules->type = query->type;
		rules->allow_Sex = query->allow_Sex;
		rules->base_project_id = query->base_project_id;
		rules->career_advice = query->career_advice;
		rules->create_id = query->create_id;
		rules->create_time = query->create_time;
		rules->department_id = query->department_id;
		rules->dietary_guidance = query->dietary_guidance;
		rules->health_advice = query->health_advice;
		rules->health_knowledge = query->health_knowledge;
		rules->interval_value = query->interval_value;
		rules->positive = query->positive;
		rules->reminder = query->reminder;
		rules->sports_guidance = query->sports_guidance;
		rules->id = "12345678901234567" + oatpp::utils::conversion::uint64ToStdStr(i);
		page->addData(rules);
	}
	vo->success(page);
	return vo;
}

StringJsonVO::Wrapper RulesListController::executeModifyRules(const String& fileBody, const RulesListDTO::Wrapper& dto)
{
	// ��ͷ���ϴ���FastDFS�ļ�������
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	std::string fieldName = dfs.uploadFile(fileBody->data(), fileBody->size(), "png");
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	// ƴ���ļ�����·��
	std::stringstream ss;
	ss << urlPrefix << fieldName;

	// TODO:�����û����ݵ����ݿ�����Թ�

	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));
	return vo;
}
