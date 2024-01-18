#include "stdafx.h"
#include "InterroService.h"
#include"../../dao/interro/InterroDAO.h"
#include"../../domain/do/interro/InterroDO.h"

InterroDTO::Wrapper InterroService::listAll(const InterroQuery::Wrapper& query)
{
	auto dto = InterroDTO::createShared();
	InterroDAO dao;
	list<InterroDO> result = dao.selectWith(query);
	if (result.empty()) {
		return dto;
	}
	// ½«DO×ª»»³ÉDTO
	ZO_STAR_DOMAIN_DO_TO_DTO(dto, result.front(), id, Id, project, Project, degree, Degree, time, Time)
		return dto;
}
