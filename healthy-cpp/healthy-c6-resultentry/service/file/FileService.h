#pragma once
#ifndef _FILE_SERVICE_
#define _FILE_SERVICE_
#include <list>
#include "domain/vo/file/FileVO.h"
#include "domain/dto/file/FileDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class FileService
{
public:
	
	// ��������
	//uint64_t saveData(const EditorImageDTO::Wrapper& dto);
	
	// �޸�����
	bool updateData(const FileDTO::Wrapper& dto, const PayloadDTO& payload);

	// ͨ��IDɾ������
	//bool removeData(uint64_t id);
};

#endif // !_FILE_SERVICE_
