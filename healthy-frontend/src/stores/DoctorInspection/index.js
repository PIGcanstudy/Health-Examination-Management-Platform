import { defineStore } from 'pinia'
import {
  queryDangerousInfo,
  queryAddConclusionList,
  querySaveInfoInspect,
  queryPreviewReport,
  queryTermsList,
  queryPositiveResultsList,
  queryExaminationItemResult,
  queryEvaluateDetails,
  queryReviewItemList,
  modifyReviewItems,
  deleteReview,
  queryReviewReport,
  addReview,
  updatePersonalReview,
  downloadPersonalReport,
  ignoreAssignedProject,
  queryPersonDetails,
  queryExaminerNameList
} from '@/apis/DoctorInspection/index.js'

export const useDoctorInspectionStore = defineStore('DoctorInspection', () => {
  // 重写方法(顺序参考同名api文件的方法自上而下一一对应)
  const getDangerousInfo = async (params) => {
    return await queryDangerousInfo(params)
  }
  const getAddConclusionList = async (params) => {
    return await queryAddConclusionList(params)
  }
  const getSaveInfoInspect = async (params) => {
    return await querySaveInfoInspect(params)
  }
  const getPreviewReport = async (params) => {
    return await queryPreviewReport(params)
  }
  const getTermsList = async (params) => {
    return await queryTermsList(params)
  }
  const getPositiveResultsList = async (params) => {
    return await queryPositiveResultsList(params)
  }
  const getExaminationItemResult = async (params) => {
    return await queryExaminationItemResult(params)
  }
  const getEvaluateDetails = async (params) => {
    return await queryEvaluateDetails(params)
  }
  const getReviewItemList = async (params) => {
    return await queryReviewItemList(params)
  }
  const postReviewItems = async (params) => {
    return await modifyReviewItems(params)
  }
  const deleteReviewItems = async (params) => {
    return await deleteReview(params)
  }
  const getReviewReport = async (params) => {
    return await queryReviewReport(params)
  }
  const addReviewItems = async (params) => {
    return await addReview(params)
  }
  const postPersonalReview = async (params) => {
    return await updatePersonalReview(params)
  }
  const getDownloadPersonalReport = async (params) => {
    return await downloadPersonalReport(params)
  }
  const postAssignedProject = async (params) => {
    return await ignoreAssignedProject(params)
  }
  const getPersonDetails = async (params) => {
    return await queryPersonDetails(params)
  }
  const getExaminerNameList = async (params) => {
    return await queryExaminerNameList(params)
  }

  // 暴露出数据
  return {
    getDangerousInfo,
    getAddConclusionList,
    getSaveInfoInspect,
    getPreviewReport,
    getTermsList,
    getPositiveResultsList,
    getExaminationItemResult,
    getEvaluateDetails,
    getReviewItemList,
    postReviewItems,
    deleteReviewItems,
    getReviewReport,
    addReviewItems,
    postPersonalReview,
    getDownloadPersonalReport,
    postAssignedProject,
    getPersonDetails,
    getExaminerNameList
  }
})
