import Request from '@/apis/request.js'
const baseUrl = ''

// 获取体检人员名称列表(分页+条件)
export const queryMedicalPersonName = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}
// 获取体检人员详情信息
export const queryMedicalPersonInfo = (params) => {
  return Request.requestJson(Request.GET, baseUrl + '', params)
}
