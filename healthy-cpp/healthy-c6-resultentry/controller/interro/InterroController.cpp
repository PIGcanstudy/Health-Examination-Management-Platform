#include"InterroController.h"
#include "stdafx.h"
#include"../../service/interro/InterroService.h"
#include "../ApiDeclarativeServicesHelper.h"
InterroJsonVO::Wrapper InterroController::execQueryInterro(const InterroQuery::Wrapper& query, const PayloadDTO& payload) {

	InterroService service;
	auto dto = service.listAll(query);
	auto vo = InterroJsonVO::createShared();
	vo->success(dto);
	return vo;
}