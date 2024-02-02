import Request from '@/apis/request.js'
const baseUrl = 'http://localhost:8090'

// 获取订单名称列表（条件+分页）
export const orderList = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/query-order', params)
}
// 获取订单详情
export const orderDetail = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-detail/{id}', params)
}
// 获取订单体检项目信息
export const orderItemInfo = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-item', params)
}
// 获取订单体检人员信息
export const orderPersonInfo = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-person', params)
}
// 新增订单
export const addOrder = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/sales/order/add', params)
}
// 修改订单
export const updateOrder = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/sales/order/update', params)
}
// 删除订单
export const deleteOrder = (params) => {
  return Request.requestForm(Request.DELETE, baseUrl + '/sales/order/{id}', params)
}
// 订单确认
export const confirmOrder = (params) => {
  return Request.requestForm(Request.PUT, baseUrl + '/sales/order/confirm/{id}', params)
}
// 查看审批信息
export const approvalInfo = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/get-approval/{orderId}', params)
}
// 生成导入模板
export const downloadPerson = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/download-person/{id}', params)
}
// 导出人员信息
export const exportPerson = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/export-person', params)
}
// 下载模板
export const downloadEntrust = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/download-entrust/{id}', params)
}
// 附件预览
export const previewEntrust = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/order/preview-entrust/{orderId}', params)
}

// 获取单位名称列表（用于输入表单下拉列表框）
export const getUnitNameList = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/unit/get-name', params)
}
// 获取单位列表（条件+分页）
export const getUnitList = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/unit/get-list', params)
}
// 获取单位详情
export const getUnitDetail = (params) => {
  return Request.requestForm(Request.GET, baseUrl + '/sales/unit/get-detail/{id}', params)
}
// 新增单位
export const addUnit = (params) => {
  return Request.requestJson(Request.POST, baseUrl + '/sales/unit/add', params)
}
// 修改单位
export const updateUnit = (params) => {
  return Request.requestJson(Request.PUT, baseUrl + '/sales/unit/update', params)
}
// 删除单位（支持批量删除）
export const deleteUnit = (params) => {
  return Request.requestJson(Request.DELETE, baseUrl + '/sales/unit/delete', params)
}
