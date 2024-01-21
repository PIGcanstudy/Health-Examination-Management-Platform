#include "stdafx.h"
#include "InterroService.h"
#include"../../dao/interro/InterroDAO.h"
#include"../../domain/do/interro/InterroDO.h"

oatpp::List<InterroDTO::Wrapper> InterroService::listAll(const InterroQuery::Wrapper& query)
{
	auto dto = InterroDTO::createShared();
	auto lsdto = oatpp::List<InterroDTO::Wrapper>::createShared();
	InterroDAO dao;
	list<InterroDO> result = dao.selectWith(query);
	if (result.empty()) {
		return lsdto;
	}
	for (InterroDO sub : result)
	{
		auto dto = InterroDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, project, Project, degree, Degree, time, Time)
			lsdto->push_back(dto);
	}
		return lsdto;
}
