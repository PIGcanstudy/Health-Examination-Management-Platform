#include "stdafx.h"
#include "ModifyUnitController.h"

//�޸ĵ�λ	�����ˣ�kzz
//ǰ�ˡ�UnitDetailDTO����ˡ�Uint64JsonVO(�����ɹ�/ʧ��)��ǰ��
StringJsonVO::Wrapper ModifyUnitController::execModifyUnit(const UnitDetailDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����У��
	// idУ�顢ͳһ������ô��롢����У��
	
	jvo->success(dto->id);

	// ��Ӧ���
	return jvo;
}

